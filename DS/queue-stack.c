#include "./stacks.c"
#include <stdio.h>
typedef struct QueueStack
{
    Stack mainStack;
    Stack otherStack;
    int front;

} QueueStack;

int isQEmpty(QueueStack *queueStack)
{
    return isEmpty(&queueStack->mainStack);
}
int isQFull(QueueStack *queueStack)
{
    return isFull(&queueStack->mainStack);
}
int qpeek(QueueStack *queueStack)
{
    return queueStack->front;
}
void enqueue(QueueStack *queueStack, int val)
{
    if (isQFull(queueStack))
    {
        printf("overflow!");
        return;
    }
    if (isQEmpty(queueStack))
    {
        queueStack->front = val;
    }
    push(&queueStack->mainStack, val);
}
int dequeue(QueueStack *queueStack)
{
    if (isQEmpty(queueStack))
    {
        printf("underflow");
        return 0;
    }
    while (!isEmpty(&queueStack->mainStack))
    {
        push(&queueStack->otherStack, pop(&queueStack->mainStack));
    }
    int val = pop(&queueStack->otherStack);
    queueStack->front = peek(&queueStack->otherStack);
    while (!isEmpty(&queueStack->otherStack))
    {
        push(&queueStack->mainStack, pop(&queueStack->otherStack));
    }

    return val;
}
void qDisplay(QueueStack *queueStack)
{
    display(&queueStack->mainStack);
}
void testQueueStack()
{
    QueueStack queueStack;
    queueStack.mainStack.top = -1;
    queueStack.otherStack.top = -1;
    enqueue(&queueStack, 1);
    enqueue(&queueStack, 2);
    enqueue(&queueStack, 3);
    dequeue(&queueStack);
    printf("qpeek -:%d\n", qpeek(&queueStack));
    qDisplay(&queueStack);
}
int main()
{
    testQueueStack();
    return 0;
}
