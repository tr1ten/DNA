#include <stdio.h>
#define MAX_SIZE 30
typedef struct OverlapQueue
{
    int leftHead;
    int leftTail;
    int rightHead;
    int rightTail;
    int arr[MAX_SIZE];
} OverlapQueue;
int isEmpty(OverlapQueue *queue, int right)
{
    if (right)
    {
        if (queue->rightHead == MAX_SIZE)
        {
            return 1;
        }
    }
    else
    {
        if (queue->leftHead == -1)
        {
            return 1;
        }
    }
    return 0;
}
int isFull(OverlapQueue *queue)
{
    if (queue->leftTail + 1 == queue->rightHead)
    {
        return 1;
    }
    return 0;
}
void enqueue(OverlapQueue *queue, int right, int val)
{
    if (!isFull(queue))
    {
        if (right)
        {
            if (queue->rightTail == MAX_SIZE)
            {
                queue->rightTail = MAX_SIZE - 1;
                queue->rightHead = MAX_SIZE - 1;
            }
            else
            {
                queue->rightTail--;
            }
            queue->arr[queue->rightTail] = val;
        }
        else
        {
            if (queue->leftTail == -1)
            {
                queue->leftTail = 0;
                queue->leftHead = 0;
            }
            else
            {
                queue->leftTail++;
            }
            queue->arr[queue->leftTail] = val;
        }
    }
    else{
        printf("overflow!");
    }
}
int dequeue(OverlapQueue *queue, int right)
{
    if (isEmpty(queue, right))
    {
        printf("underflow");
        return 0;
    }
    if (!right)
    {
        if(queue->leftHead==queue->leftTail)
        {
            queue->leftHead = queue->leftTail = -1;
        }
        else{
            queue->leftHead++;
        }
        return queue->arr[queue->leftHead-1];
    }
    else
    {
        if(queue->rightHead==queue->rightTail)
        {
            queue->rightHead = queue->rightTail = MAX_SIZE;
        }
        else{
            queue->rightHead--;
        }
        return queue->arr[queue->rightHead+1];
    }
}
void display(OverlapQueue *queue,int right)
{
    int i;
    if(!right)
    {
        for (i = queue->leftHead; i <= queue->leftTail; i++)
        {
            printf("%d ", queue->arr[i]);
        }
    }
    else
    {
        for (i = queue->rightHead; i >= queue->rightTail; i--)
        {
            printf("%d ", queue->arr[i]);
        }
    }
}
void testOverlapQueue(){
    OverlapQueue queue;
    queue.leftHead = -1;
    queue.leftTail = -1;
    queue.rightHead = MAX_SIZE;
    queue.rightTail = MAX_SIZE;
    enqueue(&queue, 0, 1);
    enqueue(&queue, 0, 2);
    enqueue(&queue, 0, 3);
    enqueue(&queue, 1, 4);
    enqueue(&queue, 1, 5);
    enqueue(&queue, 1, 6);
    enqueue(&queue, 1, 7);
    dequeue(&queue, 0);
    dequeue(&queue, 1);
    
    printf("Queue 1-:\n");
    display(&queue, 0);
    printf("\nQueue 2-:\n");
    display(&queue, 1);
    printf("\n");

}
int main()
{
    testOverlapQueue();
    return 0;
}
