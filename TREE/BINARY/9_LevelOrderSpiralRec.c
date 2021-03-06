//Level order traversal in spiral form
//https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

//complexity n2 -- for nth label you have traverse all nodes for abother label  
//think in terms of skewed tree O(n-1)+O(n-2)+ ....

//using recursion
//use one flag, go left ro right once and 
// once right to left

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

int Height(TREE *root)
{
    if(root)
    {
        int l = Height(root->left);
        int r = Height(root->right);

        return l>r?l+1:r+1;
    }
    return 0;
}

void PrintLevel(TREE *root, int level, int base, int flag)
{   
    if(root == NULL || level < base) return;
    
    if(level == base) 
        printf("%d ", root->data);
    
    if(!flag)
    {   
        PrintLevel(root->left, level -1, base, flag); 
        PrintLevel(root->right, level -1, base, flag);
    }
    else
    {   
        PrintLevel(root->right, level -1, base, flag);
        PrintLevel(root->left, level -1, base, flag);
    }
    
    return;
}
void LevelOrder(TREE *root)
{
    int h = Height(root);
    int i = 0;
    int flag = 0;

    for(i = 0; i < h ; i++)
    {
        PrintLevel(root, i, 0, flag);
        flag = !flag;
    }
    return ;
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
