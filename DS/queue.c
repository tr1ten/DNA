#define MAX_SIZE 30
typedef struct Queue
{
    int arr[MAX_SIZE];
    int head;
    int tail;
} Queue;
// make it circular
int peek(Queue *q)
{
    return q->arr[q->head];
}
int isFull(Queue* queue)
{
    if(queue->tail>=MAX_SIZE-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(Queue* queue,int val)
{

    if(!isFull(queue))
    {
        if(queue->tail==-1)
        {
            queue->tail=0;
            queue->head=0;
        }
        else{
            queue->tail++;
        }
        queue->arr[queue->tail] = val;
    }
}
void dequeue(Queue* queue)
{
    if(!isEmpty(queue))
    {
        if(queue->head==queue->tail)
        {
            queue->head = queue->tail = -1;
        }
        else{
            queue->head++;
        }
    }
}
int isEmpty(Queue* queue)
{
    if (queue->tail=queue->head)
    {
        return 1;
    }
    return 0;
    
}
void displayQueue(Queue* queue)
{
    int i;
    if(!isEmpty(queue))
    {
        for(i=queue->head;i<=queue->tail;i++)
        {
            printf("%d ",queue->arr[i]);
        }
    }
    else{
        printf("Queue is empty");
    }
}
void testQueue(){
    Queue queue;
    queue.head = queue.tail = -1;
    enqueue(&queue,1);
    enqueue(&queue,2);
    enqueue(&queue,3);
    enqueue(&queue,4);
    enqueue(&queue,5);
    // dequeue(&queue);
    displayQueue(&queue);
}
int main()
{
    testQueue();
    return 0;
}
