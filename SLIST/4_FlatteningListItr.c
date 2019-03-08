


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
    Using Iteration
    
    Have two lists seprately
    one root(temp1) and another one root->right(temp2)
    keep referene to root->right->right(temp3)
    mark temp1->right = NULL and temp2->right
    Now these are normal list to merge

    After returning, let say temp1
    mark temp2 = temp3;
        temp3 = temp2->right
        and temp2->right = NULL;
        now again merge temp1 and temp2

        At the end you will be left with temp1 and that would be new root
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
    NODE *temp = root1;
    NODE *temp1 = NULL;
    NODE *prev = NULL;
    while(root1 && root2)
    {
        if(root1->data > root2->data)
        {
            temp1 = root2;
            root2 = root2->down;
            temp1->down = root1;
            if(prev)
                prev->down = temp1;
            prev = temp1;
        }
        else
        {
            prev = root1;
            root1 = root1->down;
        }
    }

    if(root2)
        prev->down = root2;

    return temp;
}

NODE *FlattenList(NODE *root)
{
    NODE *temp1 = NULL;
    NODE *temp2 = NULL;

    while(root && root->right)
    {
        temp1 = root->right;
        root->right = NULL;
        if(temp1)
        {
            temp2 = temp1->right;
            temp1->right = NULL;
        }
        root = MergeList(root, temp1);
        root->right= temp2;
    }
    return root;
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

   Push( &( root->right ), 20 );
    Push( &( root->right ), 10 );

    Push( &( root->right->right ), 50 );
    Push( &( root->right->right ), 22 );
    Push( &( root->right->right ), 19 );

 /* 
    Push( &( root->right->right->right ), 45 ); 
    Push( &( root->right->right->right ), 40 ); 
    Push( &( root->right->right->right ), 35 ); 
    Push( &( root->right->right->right ), 28 ); 
  */
    root = FlattenList(root);
    PrintList(root);
    return 0;
}
