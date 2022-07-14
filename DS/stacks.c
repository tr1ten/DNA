#include <stdio.h>
#define MAX_SIZE 30
typedef struct Stack
{
    int top;
    int arr[MAX_SIZE];
} Stack;

int isEmpty(Stack *stack)
{
    if(stack->top==-1)
    {
        return 1;
    }
    return 0;
}
int isFull(Stack *stack)
{
    if(stack->top==MAX_SIZE-1)
    {
        return 1;
    }
    return 0;
}
void push(Stack* stack,int val)
{
    if(!isFull(stack))
    {
        stack->top++;
        stack->arr[stack->top] = val;
    }
}
int pop(Stack* stack)
{
    if(!isEmpty(stack))
    {
        stack->top--;
        return stack->arr[stack->top+1];
    }
}
int peek(Stack* stack)
{
    if(!isEmpty(stack))
    {
        return stack->arr[stack->top];
    }
}
void display(Stack* stack)
{
    int i;
    for(i=stack->top;i>=0;i--)
    {
        printf("%d ",stack->arr[i]);
    }
    printf("\n");
}
void testStack(){
    Stack stack;
    stack.top=-1;
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    pop(&stack);
    display(&stack);
}
int isPalidrome(char *str)
{
    int i = 0;
    Stack stack;
    stack.top=-1;
    
    while (str[i]!=0)
    {
        push(&stack,(int)str[i]);
        i++;
    }
    i = 0;
    while (str[i]!=0)
    {
        if(str[i]!=pop(&stack))
        {
            return 0;
        }
        i++;
    }
    return 1;
    
}
void testPalidrome(){
    char str[] = "madam";
    printf("%d\n",isPalidrome(str));
}
int checkParenthesis(char *str)
{
    int i = 0;
    Stack stack;
    stack.top=-1;
    while (str[i]!=0)
    {
        if(str[i]=='(')
        {
            push(&stack,(int)str[i]);
        }
        else if(str[i]==')')
        {
            if(isEmpty(&stack))
            {
                return 0;
            }
            pop(&stack);
        }
        i++;
    }
    if(isEmpty(&stack))
    {
        return 1;
    }
    return 0;
}
void testCheckParenthesis(){
    char str[] = "((()))";
    printf("%d\n",checkParenthesis(str));
}
// int main()
// {
//     testCheckParenthesis();
//     return 0;
// }
