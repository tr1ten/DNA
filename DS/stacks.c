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
void push(Stack* stack,int val)
{
    if(stack->top<MAX_SIZE-1)
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