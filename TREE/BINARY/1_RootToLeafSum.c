
//Root to leaf path sum equal to a given number
//https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/


#include "../../../COMMON/common.h"
typedef struct tree
{   
    int data;
    struct tree *left, *right;
}TREE;

TREE *NewNode(int data)
{
    TREE *temp = malloc(sizeof(TREE));
    temp->right = temp->left = NULL;
    temp->data = data;
   
    return temp;
}

int SumOfPaths(TREE *root, int sum)
{
    if(root == NULL) return 0;
   
    if(!root->left && !root->right)
    {
        //printf("%d\n", sum + root->data);
        if(sum - root->data == 0)
        {
            printf("path exist\n");
            return 1;
        }
        return 0;
    }

    SumOfPaths(root->left, sum - root->data);
    SumOfPaths(root->right, sum - root->data);
    return 0;
}

int main()
{
    TREE *root = NewNode(10);
    root->right = NewNode(15);
    root->right->left  = NewNode(14);
    root->right->right  = NewNode(20);
    root->left = NewNode(7);
    root->left->left  = NewNode(4);
    root->left->left->left  = NewNode(3);
    root->left->right  = NewNode(8);

    int sum = 24;
    SumOfPaths(root, 24);

    return 0;
}
