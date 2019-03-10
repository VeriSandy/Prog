//Print Right View of a Binary Tree
//https://www.geeksforgeeks.org/print-right-view-binary-tree-2/

/*
    IDEA -- 

    Level order traversal can be used here 
    and last node at each label should be printed
    
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

    LeftViewUtil(root->right, label+1, max);
    LeftViewUtil(root->left, label+1, max);

    return;
}
