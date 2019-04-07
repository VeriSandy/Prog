//https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
//Diameter of a Binary Tree

/*
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 


Diameter --> height of (left subtree + right subtree) +1 
find the max of this value

or 

Diameter -- 
Max (height(left+right)subtree + 1, max(dia(left subtree, right subtree))

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

int Height(TREE *root)
{
    if(root)
    {
        int l = Height(root->left);
        int r = Height(root->right);

        return (l>r)?l+1:r+1;

    }
    return 0;
}

//O(n2)
void DiaUtility(TREE *root, int *max)
{
    if(root)
    {
        int l = Height(root->left);
        int r = Height(root->right);

        *max = *max > (l+r+1) ? *max: l+r+1;

        DiaUtility(root->left, max);
        DiaUtility(root->right, max);
    }
    return;
}

int Diameter(TREE *root)
{
    if(!root) return 0;

    int max = 0;

    DiaUtility(root, &max);
    return max;
}

//O(n2)
int Diameter1(TREE *root)
{
    if(root)
    {
        int lh = Height(root->left);
        int rh = Height(root->right);

        int ld = Diameter1(root->left);
        int rd = Diameter1(root->right);

        return lh+rh+1>(ld>rd?ld:rd)?lh+rh+1:(ld>rd?ld:rd);
    }
    return 0;
}

//O(n)
int DiaUtility2(TREE *root, int *h)
{
    if(!root)
    {
        *h = 0;
        return 0;
    }

    int l = 0;//left subtree height
    int r = 0;//right subtree height

    int dl = DiaUtility2(root->left, &l);
    int dr = DiaUtility2(root->right, &r);

    *h = l>r?l+1:r+1;

    return l+r+1>(dl>dr?dl:dr)?l+r+1:(dl>dr?dl:dr);
}

int Diameter2(TREE *root)
{
    if(!root) return 0;
    int h = 0;
    return DiaUtility2(root, &h);
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
    printf("%d\n", Diameter(root));
    printf("%d\n", Diameter1(root));
    printf("%d\n", Diameter2(root));
    printf("%d\n", Height(root)); 
    return 0;
}


