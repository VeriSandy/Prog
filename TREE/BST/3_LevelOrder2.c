//Level Order Tree Traversal
//https://www.geeksforgeeks.org/level-order-tree-traversal/

//Complexity n  
//Using Queue, use list implementation

#include  "../../../COMMON/common.h"

typedef struct tree
{
    struct tree *left, *right;
    int data;
}TREE;

typedef struct node
{
    TREE *data;
    struct node *next;
}NODE;

typedef struct queue
{
    NODE *front;
    NODE *rear;
}QUEUE;

QUEUE *CreateQ()
{
    QUEUE *temp = malloc(sizeof(QUEUE));
    temp->front = temp->rear = NULL;
    return temp;
}

TREE *newNode(int data)
{
    TREE *temp = malloc(sizeof(TREE));
    temp->right = temp->left = NULL;
    temp->data = data;
    return temp;
}

void EnQueue(QUEUE *que, TREE *root)
{   
    NODE *temp = malloc(sizeof(NODE));
    temp->data = root;
    temp->next = NULL;
    
    if(que->front == NULL)
        que->front = temp;
    else
        que->rear->next = temp;
    
    que->rear = temp;
    return;
}

TREE *DeQueue(QUEUE *que)
{
    if(que->rear == NULL) return NULL;

    NODE *temp = que->front;
    que->front = que->front->next;
   
    if(que->front == NULL)
        que->rear = NULL;

    TREE *t = temp->data;
    free(temp);
    temp = NULL;
    return t;
}

int IsQEmpty(QUEUE *que)
{
    return !que->rear?1:0;
}

void LevelOrder(TREE *root)
{
    if(root == NULL) return;
    QUEUE *que = CreateQ();
    TREE *t = NULL;
    EnQueue(que, root);

    while(!IsQEmpty(que))
    {
    t = DeQueue(que);
        printf("%d ", t->data);
        if(t->left)
            EnQueue(que, t->left);

        if(t->right)
            EnQueue(que, t->right);
    }
    return;
}

int main()
{
    TREE *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);

    LevelOrder(root);
    printf("\n");
    return 0;
}
