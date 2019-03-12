
//Binary Search Tree | Set 1 (Search and Insertion)
//https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-Insertion/

#include "../../../COMMON/common.h"

typedef struct tree
{   
    int data;
    struct tree *left, *right;
}TREE;

TREE *NewNode(int data)
{   
    TREE *temp = malloc(sizeof(TREE));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    
    return temp;
}

TREE *Insert(TREE *root, int data)
{   
    if(root == NULL) return NewNode(data);
    
    if(data < root->data)
        root->left = Insert(root->left, data);
    
    else if(data > root->data)
        root->right = Insert(root->right, data);
        
    return root;
}

void Inorder(TREE *root)
{
    if(root)
    {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
    return ;
}


TREE *Search(TREE *root, int key)
{
    if(root == NULL) return NULL;
    if(root->data == key) return root;
    else if(root->data < key)
        return Search(root->right, key);
    else
        return Search(root->left, key);
}

int main()
{
    TREE *root = NULL;
    root = Insert(root, 50);

    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);

    Inorder(root);
    printf("\n");

    //TREE *node = Search(root, 20);
    TREE *node = Search(root, 10);
    if(node)
            printf("Node Exist \n");
    else
            printf("Node Does not Exist \n");
    return 0;
}
