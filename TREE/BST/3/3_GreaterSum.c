//Transform a BST to greater sum tree
//https://www.geeksforgeeks.org/transform-bst-sum-tree/

/*
Given a BST, transform it into greater sum tree where each node contains sum of all nodes greater than that node.
If we do the inorder it gives everything in incresing sequence

Use Inorddr somehow -- 
Reverse inorder traversal of a BST gives us keys in decreasing order.
Before visiting a node, we visit all greater nodes of that node.
While traversing we keep track of sum of keys which is the sum of all the keys greater than the key of current node. 
*/

#include  "../../../COMMON/common.h"

typedef struct tree
{
    struct tree *left, *right;
    int data;
}TREE;


TREE *newNode(int data)
{
    TREE *temp = malloc(sizeof(TREE));
    temp->right = temp->left = NULL;
    temp->data = data;
    return temp;
}

void RevInOrder(TREE *root, int *sum)
{
    if(root)
    {
        RevInOrder(root->right, sum);
        *sum += root->data;
        root->data = *sum - root->data; //root->data contains only prvious sum
        RevInOrder(root->left, sum);
    }
    return;
}

void transformTree(TREE *root)
{
    int sum = 0;

    RevInOrder(root, &sum);

    return;
}

void printInorder(TREE *root)
{
    if(root)
    {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
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

    printf("Inorder Traversal of given tree\n");
    printInorder(root);
    printf("\n");
    transformTree(root);
    printf("Inorder Traversal of transformed tree\n");
    printInorder(root);
    printf("\n");
    return 0;
}
