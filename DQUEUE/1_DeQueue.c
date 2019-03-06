//Implementation of Deque using circular array
//https://www.geeksforgeeks.org/implementation-deque-using-circular-array/
//Similar to QUEUE but some other additional options are here
//like delete from back and push at front
/*
Mainly the following four basic operations are performed on queue:
insetFront(): Adds an item at the front of Deque.
insertRear(): Adds an item at the rear of Deque.
deleteFront(): Deletes an item from front of Deque.
deleteRear(): Deletes an item from rear of Deque.
*/

#include "../../COMMON/common.h"

typedef struct
{
    int front;
    int rear;
    int size;
    int cap;
    int *q;
}DQUEUE;

DQUEUE *CreateQueue(int k)
{
    DQUEUE *que = malloc(sizeof(DQUEUE));
    que->cap = k;
    que->size = 0;
    que->front = que->rear = -1;
    que->q = malloc(sizeof(int)*k);
    return que;
}

void InsertAtFront(DQUEUE *que, int data)
{
    if(que->size == que->cap)
        return;

    que->size++;
    if(que->front == 0)
        que->front = que->cap -1;
   
    else if(que->front == -1)
    {
        que->front = 0;
        que->rear = 0;
    }
    else
        que->front--;

    que->q[que->front] = data;
    return;
}

void InsertAtRear(DQUEUE *que, int data)
{
    if(que->size == que->cap)
        return;

    que->size++;
    que->rear = (que->rear +1)%que->cap;

    if(que->front == -1)
        que->front = 0;

    que->q[que->rear] = data;

    return;
}

int DeleteAtFront(DQUEUE *que)
{
    if(que->size == 0)
        return INT_MIN;

    int temp = que->q[que->front];
    que->front = (que->front + 1)%que->cap;
    que->size--;

    if(que->size == 0)
    {
        que->front = -1;
        que->rear = -1;
    }

    return temp;
}

int DeleteAtRear(DQUEUE *que)
{
    if(que->size == 0)
        return INT_MIN;

    int temp = que->q[que->rear];
    que->size--;
    if(que->size && !que->rear)
        que->rear = que->cap -1;
    else
        que->rear--;

    if(que->size == 0)
        que->front = -1;

    return temp;
}

int Front(DQUEUE *que)
{
    if(que->size == 0)
        return INT_MIN;

    return que->q[que->front];
}

int Rear(DQUEUE *que)
{
    if(que->size == 0)
        return INT_MIN;

    return que->q[que->rear];
}

void Display(DQUEUE *que)
{
    if(que->size == 0)
        return;

    int i = que->front;
    int q = 0;
    for(; q< que->size;q++)
    {
        printf("%d ", que->q[i]);
        i = (i+1)%que->cap;
    }
    printf("\n");
    return;
}

int main()
{
    DQUEUE *que = CreateQueue(5);
    InsertAtFront(que, 50);
    InsertAtRear(que, 40);
    InsertAtRear(que, 30);
    InsertAtRear(que, 20);
    InsertAtRear(que, 10);
    Display(que);
    DeleteAtFront(que);
    Display(que);
    InsertAtRear(que, 50);
    Display(que);
    DeleteAtRear(que);
    Display(que);
    printf("Front - %d \n", Front(que));
    printf("Rear - %d\n", Rear(que));
    return 0;
}
