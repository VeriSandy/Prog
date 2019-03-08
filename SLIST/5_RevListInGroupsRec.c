
//Reverse a Linked List in groups of given size
//https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

/*
Use recursion
First reverse the given size
and if list is there
then reverse it recursivley and make this next of head
*/

#include "../../COMMON/common.h"
typedef struct node
{   
    int data;
    struct node *next;
}NODE;

void InsertNode(NODE **head, int data)
{   
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->next = *head;
    *head = temp;
    return;
}

void DisplayList(NODE *head)
{   
    while(head)
    {   
        printf("%d ", head->data);
        head = head->next;
    }
    
    printf("\n");
    return;
}

NODE *RevListInGroups(NODE *head, int k)
{   
    int i = 0;
    NODE *cur = head, *prev, *temp = NULL;
    
    while(i < k && cur)
    {   
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        i++;
    }
    
    if(cur)
        head->next = RevListInGroups(cur, k);
    
    return prev;
}

int main()
{
    NODE *head = NULL;
/*  InsertNode(&head, 10);
    InsertNode(&head, 20);
    InsertNode(&head, 30);
    InsertNode(&head, 40);
    InsertNode(&head, 50);
*/  //================
    //pass null case
    //===============
    //pass one node
//  InsertNode(&head, 10);
    //=====================
    //pass 2 nodes  
    //InsertNode(&head, 10);
    //InsertNode(&head, 20);
    //====================
    //pass 3 nodes  
    //InsertNode(&head, 10);
    //InsertNode(&head, 20);
    //InsertNode(&head, 30);
    //====================
    //pass 4 nodes  
/*  InsertNode(&head, 10);
    InsertNode(&head, 20);
    InsertNode(&head, 30);
    InsertNode(&head, 40);
*/
    InsertNode(&head, 10);
    InsertNode(&head, 20);
    InsertNode(&head, 30);
    InsertNode(&head, 40);
    InsertNode(&head, 50);
    InsertNode(&head, 60);
    InsertNode(&head, 70);
    DisplayList(head);
    //int k = 3;
    //int k = 7;
    //int k = 1;
    int k = 2;
    head = RevListInGroups(head, k);
    DisplayList(head);
    return 0;
}
