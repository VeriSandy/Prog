
//https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
//Basic operations of Queue, it is implemented ad circular QUEUE.
//EnQueue
//DeQueue
//Get Front item
//Get Last item

#include "../../COMMON/common.h"
typedef struct queue
{   
    int front;
    int rear;
    int *q;
    int cap;
    int size;
}QUEUE;

QUEUE *CreateQueue(int k)
{   
    QUEUE *que = malloc(sizeof(QUEUE));
    que->cap = k;
    que->size = 0;
    que->front = -1;
    que->rear = -1;
    que->q = malloc(sizeof(int) * k);
    
    return que;
}

void EnQueue(QUEUE *que, int data)
{   
    if(que->size == que->cap)
    {   
        printf("queue is full, cant accomodate\n");
        return;
    }
    que->size++;
    que->rear = (que->rear+1)%que->cap;
    que->q[que->rear] = data;
    if(que->front == -1)
        que->front =0;
        
    return;
}

int DeQueue(QUEUE *que)
{   
    if(que->size == 0)
    {   
        printf("Underflow\n");
        return INT_MIN;
    }
    
    que->front = (que->front+1)%que->cap;
    int data = que->q[que->front];
    que->size--;
    if(!que->size)
    {   
        que->front = que->rear = -1;
    }
    return data;
}

int Front(QUEUE *que)
{   
    if(que->size == 0)
    {   
        printf("Underflow\n");
        return INT_MIN;
    }   
        
    int data = que->q[que->front];
    return data;
}

int Rear(QUEUE *que)
{
    if(que->size == 0)
    {
        printf("Underflow\n");
        return INT_MIN;
    }

    int data = que->q[que->rear];
    return data;
}

int main()
{
    QUEUE *que = CreateQueue(5);
    EnQueue(que, 10);
    EnQueue(que, 20);
    EnQueue(que, 30);
    EnQueue(que, 40);
    EnQueue(que, 50);
    EnQueue(que, 60);
    printf("Front %d \n", Front(que));
    printf("REAR %d \n", Rear(que));
    DeQueue(que);
    DeQueue(que);
    DeQueue(que);
    EnQueue(que, 60);
    printf("Front %d \n", Front(que));
    printf("REAR %d \n", Rear(que));
    DeQueue(que);
    DeQueue(que);
    printf("Front %d \n", Front(que));
    printf("REAR %d \n", Rear(que));
    EnQueue(que, 70);
    printf("Front %d \n", Front(que));
    printf("REAR %d \n", Rear(que));
    DeQueue(que);
    DeQueue(que);
    DeQueue(que);
    DeQueue(que);
    printf("Front %d \n", Front(que));
    printf("REAR %d \n", Rear(que));
    return 0;
}
