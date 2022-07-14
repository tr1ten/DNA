#include <stdio.h>
#include <malloc.h>
typedef struct
{
    int *arr;
    int front;
    int rear;
    int capacity;
} MyCircularQueue;

int myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    return obj->front == -1;
}

int myCircularQueueIsFull(MyCircularQueue *obj)
{
    return obj->front == (obj->rear + 1) % obj->capacity;
}

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue->arr = (int *)malloc(sizeof(int) * k);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = k;
    return queue;
}

int myCircularQueueEnQueue(MyCircularQueue *queue, int value)
{
    if (myCircularQueueIsFull(queue))
    {
        return 0;
    }
    if (queue->rear == -1)
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->arr[queue->rear] = value;
    return 1;
}

int myCircularQueueDeQueue(MyCircularQueue *queue)
{
    if (myCircularQueueIsEmpty(queue))
    {
        return 0;
    }
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return 1;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[obj->rear];
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->arr);
}
void myCircularQueueDisplay(MyCircularQueue *obj)
{
    int i;
    if (!myCircularQueueIsEmpty(obj))
    {
        for (i = obj->front; i != obj->rear;)
        {
            printf("%d ", obj->arr[i]);
            i = (i + 1) % obj->capacity;
        }
        printf("%d ", obj->arr[i]);

    }
}

void testMyCircularQueue()
{
    MyCircularQueue *queue = myCircularQueueCreate(3);
    myCircularQueueEnQueue(queue, 1);
    myCircularQueueEnQueue(queue, 2);
    myCircularQueueEnQueue(queue, 3);
    myCircularQueueDeQueue(queue);
    myCircularQueueEnQueue(queue, 4);
    myCircularQueueDisplay(queue);
}
int main(int argc, char const *argv[])
{
    testMyCircularQueue();
    return 0;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * int param_1 = myCircularQueueEnQueue(obj, value);

 * int param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * int param_5 = myCircularQueueIsEmpty(obj);

 * int param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/