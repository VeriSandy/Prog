
//Flattening a Linked List
//https://www.geeksforgeeks.org/flattening-a-linked-list/
/*
Given a linked list where every node represents a linked list and contains two pointers of its type:
(i) Pointer to next node in the main list (we call it ‘right’ pointer in below code)
(ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
All linked lists are sorted. See the following example

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted. For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.
*/
/*
    Using Recursion
    Recursively flatten list with the remaining
    And recursively Merge the lists
*/

#include "../../COMMON/common.h"

typedef struct node
{
    int data;
    struct node *right, *down;
}NODE;

void Push(NODE **head, int data)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->right = NULL;
    temp->down = *head;
    *head = temp;
}

NODE *MergeList(NODE *root1, NODE *root2)
{
    if(!root1) return root2;

    if(!root2) return root1;

    NODE *temp = NULL;

    if(root1->data < root2->data)
    {
        temp = root1;
        root1->down = MergeList(root1->down, root2);
    }

    if(root1->data > root2->data)
    {
        temp = root2;
        root2->down = MergeList(root1, root2->down);
    }
    return temp;
}

NODE *FlattenList(NODE *root)
{

    if(!root || !root->right)
        return root;

    return MergeList(root, FlattenList(root->right));
}

void PrintList(NODE *root)
{
    while(root)
    {
        printf("%d ", root->data);
        root = root->down;
    }
    printf("\n");
}

int main()
{
    NODE* root = NULL;
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    Push( &root, 30 );
    Push( &root, 8 );
    Push( &root, 7 );
    Push( &root, 5 );

 /* 
   Push( &( root->right ), 20 ); 
    Push( &( root->right ), 10 ); 

    Push( &( root->right->right ), 50 ); 
    Push( &( root->right->right ), 22 ); 
    Push( &( root->right->right ), 19 ); 
  
    Push( &( root->right->right->right ), 45 ); 
    Push( &( root->right->right->right ), 40 ); 
    Push( &( root->right->right->right ), 35 ); 
    Push( &( root->right->right->right ), 28 ); 
  */
    root = FlattenList(root);
    PrintList(root);
    return 0;
}
