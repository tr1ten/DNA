#include <string.h>
#include <stdio.h>
// stack implementation
#define MAX_SIZE 40
typedef struct Stack
{
    int top;
    int arr[MAX_SIZE];
} Stack;

int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(Stack *stack)
{
    if (stack->top == MAX_SIZE - 1)
    {
        return 1;
    }
    return 0;
}
void push(Stack *stack, int val)
{
    if (!isFull(stack))
    {
        stack->top++;
        stack->arr[stack->top] = val;
    }
}
int pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        stack->top--;
        return stack->arr[stack->top + 1];
    }
}
int peek(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->arr[stack->top];
    }
}
// main
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
int isRTL(char c)
{
    return c == '^';
}
int getPrecedance(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '^')
    {
        return 3;
    }
}
// To-Do
void infixToPostfix(const char *infix)
{
    Stack stack;
    stack.top = -1;
    int n = strlen(infix);
    for (int i = 0; i < n; i++)
    {
        char c = infix[i];
        if (!isOperator(c))
        {
            printf("%c", c);
            continue;
        }
        if (isEmpty(&stack) || (getPrecedance(peek(&stack)) < getPrecedance(c)))
        {
            push(&stack, c);
        }
        else if (getPrecedance(peek(&stack)) == getPrecedance(c))
        {
            if (isRTL(c))
            {
                push(&stack, c);
            }
            else
            {
                printf("%c", pop(&stack));
                push(&stack, c);
            }
        }
        else
        {
            while (!isEmpty(&stack) && (getPrecedance(peek(&stack)) >getPrecedance(c) || (getPrecedance(peek(&stack))==getPrecedance(c) && !isRTL(c)) ))
            {
                printf("%c", pop(&stack));
            }
            push(&stack, c);
        }
    }
    while (!isEmpty(&stack))
    {
        printf("%c", pop(&stack));
    }
}
int main()
{
    infixToPostfix("A-B/C*D+E");
    return 0;
}
