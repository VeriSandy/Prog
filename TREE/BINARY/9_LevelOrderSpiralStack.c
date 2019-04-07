
//Level order traversal in spiral form
//https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

//Complexity n + O(n) space 
//Using Two Stacks one for left to right and vice versa, use list implementation

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

typedef struct stack
{
    NODE *top;
}STACK;

STACK *CreateStack()
{
    STACK *temp = malloc(sizeof(STACK));
    temp->top = NULL;
    return temp;
}

TREE *newNode(int data)
{
    TREE *temp = malloc(sizeof(TREE));
    temp->right = temp->left = NULL;
    temp->data = data;
    return temp;
}


void Push(STACK *stk, TREE *root)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = root;
    temp->next = stk->top;
    stk->top = temp;
    return;
}

TREE *Pop(STACK *stk)
{
    if(stk->top == NULL) return NULL;

    NODE *temp = stk->top;
    stk->top = stk->top->next;
    TREE *t = temp->data;
    free(temp);
    temp = NULL;
    return t;
}

int IsStkEmpty(STACK *stk)
{
    return !stk->top?1:0;
}

void LevelOrderSpiral(TREE *root)
{
    if(root == NULL) return;
    STACK *stk1 = CreateStack();
    STACK *stk2 = CreateStack();
    TREE *t = NULL;
    Push(stk1, root);

    while(!IsStkEmpty(stk1) || !IsStkEmpty(stk2))
    {
        while(!IsStkEmpty(stk1))
        {
            t = Pop(stk1);
            printf("%d ", t->data);
            if(t->left)
                Push(stk2, t->left);
            if(t->right)
                Push(stk2, t->right);
        }
        while(!IsStkEmpty(stk2))
        {
            t = Pop(stk2);
            printf("%d ", t->data);
            if(t->right)
                Push(stk1, t->right);
            if(t->left)
                Push(stk1, t->left);
        }
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

    LevelOrderSpiral(root);
    printf("\n");
    return 0;
}
