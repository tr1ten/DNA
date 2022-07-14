#include <stdio.h>
#define MAX_SIZE 30
typedef struct Stack
{
    int leftTop;
    int rightTop;
    int arr[MAX_SIZE];
} Stack;

int isEmpty(Stack *stack, int right)
{
    if (right)
    {
        if (stack->rightTop == MAX_SIZE)
        {
            return 1;
        }
    }
    else
    {
        if (stack->leftTop == -1)
        {
            return 1;
        }
    }
    return 0;
}
int isFull(Stack *stack)
{
    if (stack->leftTop + 1 == stack->rightTop)
    {
        return 1;
    }
    return 0;
}
void push(Stack *stack, int right, int val)
{
    if (isFull(stack))
    {
        printf("overflow!");
        return;
    }
    if (!right)
    {
        stack->leftTop++;
        stack->arr[stack->leftTop] = val;
    }
    else
    {
        stack->rightTop--;
        stack->arr[stack->rightTop] = val;
    }
}
int pop(Stack *stack, int right)
{
    if (isEmpty(stack, right))
    {
        printf("underflow");
        return 0;
    }
    if (!right)
    {
        stack->leftTop--;
        return stack->arr[stack->leftTop + 1];
    }
    stack->rightTop++;
    return stack->arr[stack->rightTop - 1];
}
int peek(Stack *stack,int right)
{
    if (isEmpty(stack, right))
    {
        printf("underflow");
        return -1;
    }
    if (!right)
    {
        return stack->arr[stack->leftTop];
    }
    return stack->arr[stack->rightTop];
}
void display(Stack *stack,int right)
{
    int i;
    if(!right)
    {
        for (i = stack->leftTop; i >= 0; i--)
        {
            printf("%d ", stack->arr[i]);
        }
    }
    else
    {
        for (i = stack->rightTop; i < MAX_SIZE; i++)
        {
            printf("%d ", stack->arr[i]);
        }
    }
    printf("\n");
}

void testOverlappingStacks(){
    Stack stack;
    stack.leftTop=-1;
    stack.rightTop=MAX_SIZE;
    push(&stack,0,1);
    push(&stack,0,2);
    push(&stack,0,3);
    push(&stack,1,4);
    push(&stack,1,5);
    push(&stack,1,6);
    display(&stack,0);
    display(&stack,1);
    printf("%d\n",pop(&stack,0));
    printf("%d\n",pop(&stack,0));
    printf("%d\n",pop(&stack,0));
    printf("%d\n",pop(&stack,1));
    printf("%d\n",pop(&stack,1));
    printf("%d\n",pop(&stack,1));
}
int main(int argc, char const *argv[])
{
    testOverlappingStacks();
    return 0;
}
