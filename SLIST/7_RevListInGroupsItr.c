
//Reverse a Linked List in groups of given size
//https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

/*
Use iteration
Take care of the just prev node(if it is first group then take care of head node)
before the next group.
then reverse the k size group
Here first node of this group should be pointing to k+1th node
and last node of this group should be next of prev node(which we marked before starting)
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

void RevListInGroups(NODE **head, int k)
{   
    int i = 0, flag = 1;;
    NODE *start = *head, *end, *prevstart = NULL;
    NODE *cur = *head, *prev, *temp = NULL;
    
    while(1)
    {   
        i = 0;
        start = cur;
        prev = NULL;
        
        while(i < k && cur)
        {   
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            i++;
        }
        
        if(flag)
        {   
            *head = prev;
            flag = 0;
        }
        else    
            prevstart->next = prev;
        
        if(!cur) break;
        
        start->next = cur;
        prevstart = start;
    }
    
    return;
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
    int k = 1;
    RevListInGroups(&head, k);
    DisplayList(head);
    return 0;
}
