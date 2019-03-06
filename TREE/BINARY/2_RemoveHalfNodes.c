//Given a binary tree, how do you remove all the half nodes?
//Given A binary Tree, how do you remove all the half nodes (which has only one child)? Note leaves should not be touched as they have both children as NULL.
//https://www.geeksforgeeks.org/given-a-binary-tree-how-do-you-remove-all-the-half-nodes/
/*
    Idea - 
    Delete the node which has only one child recursively
    This will tale care in case the parent of deleted node also has one child
*/
#include "../../../COMMON/common.h"

typedef struct node
{   
    struct node *right, *left;
    int data;
}TREE;

TREE *NewNode(int data)
{   
    TREE *temp = malloc(sizeof(TREE));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void DisplayTree(TREE *root)
{   
    if(root)
    {   
        DisplayTree(root->left);
        printf("%d ", root->data);
        DisplayTree(root->right);
    }
    return;
}

TREE *RemoveHalfNodes(TREE *root)
{   
    if(root)
    {   
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        
        if(root->left == NULL && root->right == NULL)
            return root;
        
        if(root->left == NULL)
        {   
            TREE *temp = root->right;
            free(root);
            root = NULL;
            return temp;
        }

        else if(root->right == NULL)
        {
            TREE *temp = root->left;
            free(root);
            root = NULL;
            return temp;
        }

        return root;
    }
    return NULL;
}

int main()
{
    TREE *root = NewNode(1);
    root->left = NewNode(2);
    root->left->left = NewNode(4);
    root->left->left->right = NewNode(7);
    root->right = NewNode(3);
    root->right->right = NewNode(6);
    root->right->left  = NewNode(5);
    root->right->left->left  = NewNode(8);
    root->right->left->right  = NewNode(9);
   
    DisplayTree(root);
    printf("\n");

    RemoveHalfNodes(root);

    DisplayTree(root);
    printf("\n");
    return 0;
}
