//Binary Search Tree | Set 2 (Delete)
//https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

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

TREE *MinNode(TREE *root)
{
    while(root->left)
        root = root->left;

    return root;
}

TREE *Delete(TREE *root, int key)
{
    if(root == NULL) return root;

    if(root->data < key)
        root->right = Delete(root->right, key);
   
    else if(root->data > key)
        root->left = Delete(root->left, key);

    else
    {
        //nodes with only one child or no child
        if(root->left == NULL)
        {
            TREE *node = root->right;
            free(root);
            root = NULL;
            return node;
        }
        //nodes with only one child or no child
        else if(root->right == NULL)
        {
            TREE *node = root->left;
            free(root);
            root = NULL;
            return node;
        }

        //node with two child
/*      TREE *min = MinNode(root->right);
        root->data = min->data;

        root->right = Delete(root->right, min->data);

*/
               TREE *p = root->right; //Parent
        TREE *s= root->right; //Successor
   
        while(s->left)
        {
            p = s;
            s = s->left;
        }
        p->left = s->right;
        root->data = s->data;
        free(s);
        s= NULL;
    }
    return root;
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

    Delete(root, 20);
    Inorder(root);
    printf("\n");

    Delete(root, 30);
    Inorder(root);
    printf("\n");

    Delete(root, 50);
    Inorder(root);
    printf("\n");

    return 0;
}
