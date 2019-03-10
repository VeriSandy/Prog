
//Print Left View of a Binary Tree
//https://www.geeksforgeeks.org/print-left-view-binary-tree/

/*
    IDEA -- 

    Level order traversal can be used here 
    and first node at each label should be printed
    
    Also, this can be done recursively, no need to use queue;
*/

#include "../../../COMMON/common.h"
typedef struct tree
{   
    int data;
    struct tree *left, *right;
}TREE;

TREE *NewNode(int data)
{
    TREE *temp = malloc(sizeof(TREE));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void LeftViewUtil(TREE *root, int label, int *max)
{
    if(!root) return;

    if(label > *max)
    {
        printf("%d ", root->data);
        *max = label;
    }
   
    LeftViewUtil(root->left, label+1, max);
    LeftViewUtil(root->right, label+1, max);
   
    return;
}

void LeftView(TREE *root)
{
    int max = 0;
    LeftViewUtil(root, 1, &max);
    return;
}

int main()
{
    TREE *root = NewNode(10);
    root->left = NewNode(5);
    root->right = NewNode(11);
    root->right->right = NewNode(12);
    printf("Left View \n");
    LeftView(root);
    printf("\n");
    return 0;
}
