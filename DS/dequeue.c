#include <stdio.h>
#include <malloc.h>
typedef struct
{
    int *arr;
    int front;
    int rear;
    int capacity;
} Dequeue;

int DequeueIsEmpty(Dequeue *obj)
{
    return obj->front == -1;
}

int DequeueIsFull(Dequeue *obj)
{
    return obj->front == (obj->rear + 1) % obj->capacity;
}

Dequeue *DequeueCreate(int k)
{
    Dequeue *queue = (Dequeue *)malloc(sizeof(Dequeue));
    queue->arr = (int *)malloc(sizeof(int) * k);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = k;
    return queue;
}

int DequeueEnQueue(Dequeue *queue, int value)
{
    if (DequeueIsFull(queue))
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

int DequeueDeQueueStart(Dequeue *queue)
{
    if (DequeueIsEmpty(queue))
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
int DequeueDeQueueEnd(Dequeue *queue)
{
    if (DequeueIsEmpty(queue))
    {
        return 0;
    }
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->rear = ((queue->rear - 1)%queue->capacity + queue->capacity)%queue->capacity;
    }
    return 1;
}
int DequeueFront(Dequeue *obj)
{
    if (DequeueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[obj->front];
}

int DequeueRear(Dequeue *obj)
{
    if (DequeueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[obj->rear];
}

void DequeueFree(Dequeue *obj)
{
    free(obj->arr);
}
void DequeueDisplay(Dequeue *obj)
{
    int i;
    if (!DequeueIsEmpty(obj))
    {
        for (i = obj->front; i != obj->rear;)
        {
            printf("%d ", obj->arr[i]);
            i = (i + 1) % obj->capacity;
        }
        printf("%d ", obj->arr[i]);
    }
}

void testDequeue()
{
    Dequeue *queue = DequeueCreate(3);
    DequeueEnQueue(queue, 1);
    DequeueEnQueue(queue, 2);
    DequeueEnQueue(queue, 3);
    DequeueDeQueueStart(queue);
    DequeueEnQueue(queue, 4);
    DequeueDeQueueEnd(queue);
    DequeueDisplay(queue);
}
int main(int argc, char const *argv[])
{
    testDequeue();
    return 0;
}