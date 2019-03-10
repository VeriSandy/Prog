
//https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
//Print Nodes in Top View of Binary Tree

/*
Use level order traversal concept 
only the difference is print the nodes, visited first at one horizontol distance, either left or right
*/

#include "../../../COMMON/common.h"

typedef struct tree{
    int data;
    struct tree *left, *right;
}TREE;

typedef struct
{
    TREE *tree;
    int hd;
}NODE;

typedef struct
{
    int cap;
    int size;
    int rear;
    int front;
    NODE *q;
}QUEUE;

TREE *NewNode(int data)
{
    TREE *temp = malloc(sizeof(TREE));
    temp->right = temp->left = NULL;
    temp->data = data;

    return temp;
}
QUEUE *CreateQueue(int size)
{
    QUEUE *que = malloc(sizeof(QUEUE));
    que->cap = size;
    que->size = 0;
    que->rear = -1;
    que->front = -1;
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
    que->q[que->rear].tree = node;
    if(que->front == -1)
            que->front = 0;
    return;
}

NODE *DeQueue(QUEUE *que)
{
     if(que->size == 0)
        return NULL;

    NODE *temp = malloc(sizeof(NODE));
    temp->hd = que->q[que->front].hd;
    temp->tree = que->q[que->front].tree;
    que->size--;
    if(!que->size)
    {
        que->rear = -1;
        que->front = -1;
    }
    else
        que->front = (que->front +1)%que->cap;

    return temp;
}

int Height(TREE *root)
{
    if(root)
    {
        int l = Height(root->left);
        int r = Height(root->right);

        return l> r ? l+1 : r+1;
    }
    return 0;
}

typedef struct
{
    int hd;
    int data;
}Arr;


int Empty(QUEUE *que)
{
    return (!que->size ? 1: 0);
}

void TopView(TREE *root)
{
    int h = Height(root);
    int i = 0;
    Arr a[2*h+1];//Keep array size which can keep the worst case left most and right most nodes
    //Quue at a time there can be max elements equal to tree size
    int size = pow(2, h+1);
    QUEUE *que = CreateQueue(size);
    EnQueue(que, 0, root);
    //NODE *temp = DeQueue(que);

//  printf("%d %d\n", temp->tree->data, temp->hd);
    for(i = 0; i < 2*h+1; i++)
    {
        a[i].hd = 0;
        a[i].data = 0;
    }
    a[h].hd = 1;
    a[h].data= root->data;


    while(!Empty(que))
    {
        NODE *temp = DeQueue(que);
        int hd = temp->hd;
//      printf("hd = %d \n", hd);
        if(!a[hd+h].hd)
        {
            a[hd+h].hd = 1;
            a[hd+h].data = temp->tree->data;
        }

        if(temp->tree->left)
            EnQueue(que, hd-1, temp->tree->left);

        if(temp->tree->right)
            EnQueue(que, hd+1, temp->tree->right);
    }
    for(i = 0; i < 2*h+1; i++)
        if(a[i].hd == 1)
            printf("%d ", a[i].data);

    printf("\n");
    return;
}

int main()
{
    /*
    TREE* root = NewNode(1); 
    root->left = NewNode(2); 
    root->right = NewNode(3); 
    root->left->right = NewNode(4); 
    root->left->right->right = NewNode(5); 
    root->left->right->right->right = NewNode(6); 
    */
    TREE* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right->right = NewNode(7);
    root->right->left = NewNode(6);
    TopView(root);
    return 0;
}
