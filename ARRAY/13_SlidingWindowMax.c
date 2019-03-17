
//Sliding Window Maximum (Maximum of all subarrays of size k)
//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

/*

Ideas - 

Naive - Use two loops, find max in each window - O(nk)

Other - Use DeQueue and only elements ay a particular moment, which are in decreasing order. 
        Here keep removing the elements out of window when move to next window and then add another element in queue
        O(n) + O(k) - space
*/

#include "../../COMMON/common.h"

typedef struct
{
    int size;
    int cap;
    int *a;
    int front, rear;
}DEQUEUE;


DEQUEUE *CreateQueue(int k)
{
    DEQUEUE *temp = malloc(sizeof(DEQUEUE));

    temp->front= -1;
    temp->rear = -1;
    temp->size = 0;
    temp->cap = k;
    temp->a  = malloc(sizeof(int)*k);

    return temp;
}


int IsQueueFull(DEQUEUE *que)
{
    return (que->size == que->cap ? 1 : 0);
}

int IsQueueEmpty(DEQUEUE *que)
{
    return (!que->size ? 1 : 0);
}

void EnQueueFront(DEQUEUE *que, int pos)
{
    if(IsQueueFull(que))
        return;

    if(que->front == -1)
    {
        que->rear = 0;
        que->front = 0;
    }
    else if(!que->front)
        que->front = que->cap - 1;
    else
        que->front--;

    que->size++;
    que->a[que->front] = pos;
    return;
}

void EnQueueBack(DEQUEUE *que, int pos)
{
    //printf("EnBack%d %d %d \n", que->rear, que->front, que->size);
    if(IsQueueFull(que))
        return;

    que->size++;
    que->rear = (que->rear +1)%que->cap;
    que->a[que->rear] = pos;

    if(que->front == -1)
        que->front = 0;

    return;
}

void DeQueueBack(DEQUEUE *que)
{   
    if(IsQueueEmpty(que))
        return;
    
    int pos = que->a[que->rear];
    
    que->size--;
    
    if(!que->size)
    {   
        que->rear = -1;
        que->front = -1;
    }
    else if(!que->rear)
        que->rear = que->cap -1;
    else 
        que->rear--;
    
    return;
}


void DeQueueFront(DEQUEUE *que)
{
    if(IsQueueEmpty(que))
        return;

    int pos = que->a[que->front];
    que->size--;

    if(!que->size)
    {
        que->front = -1;
        que->rear = -1;
    }
    else
        que->front = (que->front +1)%que->cap;

    return;
}

void printKMax(int *a, int n, int k)
{
    DEQUEUE *que = CreateQueue(k);

    //First Process First k Elements
    int i = 1;
    EnQueueFront(que, 0);

    for(; i < k ; i++)
    {
        while(!IsQueueEmpty(que) && a[que->a[que->rear]] <= a[i])
            DeQueueBack(que);

        EnQueueBack(que, i);
    }

    while(i < n)
    {
        printf("%d ", a[que->a[que->front]]);

        //Remove all elements from front which is not in this window    
        while(!IsQueueEmpty(que) && que->a[que->front] <= i-k)
            DeQueueFront(que);

        while(!IsQueueEmpty(que) && a[que->a[que->rear]] <= a[i])
            DeQueueBack(que);

        EnQueueBack(que, i);
        i++;
    }

    printf("%d ", a[que->a[que->front]]);

    printf("\n");

    return;
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}

