//Bottom View of a Binary Tree
//https://www.geeksforgeeks.org/bottom-view-binary-tree/
/*
Use level order traversal concept. 
Only the difference is print the nodes, visited last at one horizontol distance, left and right
Use Queue for this
*/

#include "../../../COMMON/common.h"

typedef struct tree
{   
    int data;
    struct tree *left, *right;
}TREE;

typedef struct
{   
    TREE *t;
    int hd;//horrizontol distance
}NODE;

typedef struct queue
{   
    int size;
    int cap;
    int front;
    int rear;
    NODE *q;
}QUEUE;

typedef struct
{   
    int hd;
    int data;
}DATA;

TREE *NewNode(int data)
{   
    TREE *temp = malloc(sizeof(TREE));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

int Height(TREE *root)
{
    if(root)
    {
        int l = Height(root->left);
        int r = Height(root->right);
        return (l > r ? l+1 : r +1);
    }
    return 0;
}

QUEUE *CreateQueue(int size)
{
    QUEUE *que = malloc(sizeof(QUEUE));
    que->size = 0;
    que->cap = size;
    que->front = -1;
    que->rear = -1;
    que->q = malloc(sizeof(NODE)*size);
    return que;
}

void EnQueue(QUEUE *que, int hd, TREE *node)
{
    if(que->size == que->cap)
        return;

    que->size++;
    que->rear = (que->rear+1)%que->cap;
    que->q[que->rear].hd = hd;
    que->q[que->rear].t = node;
    if(que->front == -1)
        que->front = 0;
    return;
}

NODE *DeQueue(QUEUE *que)
{
    if(!que->size) return NULL;

    NODE *temp = malloc(sizeof(NODE));
    temp->hd = que->q[que->front].hd;
    temp->t = que->q[que->front].t;


    que->size--;

    if(!que->size)
    {
        que->front = -1;
        que->rear = -1;
    }
    else
        que->front = (que->front+1)%que->cap;
    return temp;
}

int IsQueueEmpty(QUEUE *que)
{
    return (!que->size?1:0);
}

void BottomView(TREE *root)
{
    int h = Height(root);
    int size = 2*h+1;
    DATA a[size];
    int i = 0;
    int p = pow(2, h+1);
    QUEUE *que = CreateQueue(p);
    EnQueue(que, 0, root);

    for(i = 0; i< size; i++)
        a[i].hd = 0;

    a[h].hd = 1;
    a[h].data = root->data;


    while(!IsQueueEmpty(que))
    {
        NODE *temp = DeQueue(que);
        int hd = temp->hd;
        a[h+hd].hd = 1;
        a[h+hd].data = temp->t->data;

        if(temp->t->left)
            EnQueue(que, hd-1, temp->t->left);
        if(temp->t->right)
            EnQueue(que, hd+1, temp->t->right);
    }

    for(i = 0; i < size; i++)
        if(a[i].hd)
            printf("%d ", a[i].data);

    printf("\n");
    return;
}

int main()
{
    TREE *root = NewNode(20);
    root -> left =  NewNode(8);
    root -> right =  NewNode(22);
    root -> left -> left =  NewNode(5);
    root -> left -> right =  NewNode(3);
    root -> right -> left =  NewNode(4);
    root -> right -> right =  NewNode(25);
    root -> left -> right -> left =  NewNode(10);
    root -> left -> right -> right =  NewNode(14);

    BottomView(root);
    return 0;
}
