#define MAX_SIZE 30
typedef struct Queue
{
    int arr[MAX_SIZE];
    int head;
    int tail;
} Queue;
// make it circular
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
        queue->tail++;
        queue->arr[queue->tail] = val;
    }
}
void dequeue(Queue* queue)
{
    if(!isEmpty(queue))
    {
        queue->head++;
    }
}
int isEmpty(Queue* queue)
{
    if (queue->tail-queue->head<=0)
    {
        return 1;
    }
    return 0;
    
}