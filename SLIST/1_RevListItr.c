//https://www.geeksforgeeks.org/reverse-a-linked-list/
//Reverse a linked list(iteration & recursion)

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
void RevListItr(NODE **head)
{
    NODE *cur = *head;
    NODE *prev = NULL;
    NODE *temp = cur;
   
    while(cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    *head = prev;

    return;
}

int main()
{
    NODE *head = NULL;
    //InsertNode(&head, 10);
    //InsertNode(&head, 20);
    //InsertNode(&head, 30);
    //InsertNode(&head, 40);
    //InsertNode(&head, 50);
    //================
    //pass null case
    //===============
    //pass one node
    //InsertNode(&head, 10);
    //=====================
    //pass 2 nodes  
    //InsertNode(&head, 10);
    //InsertNode(&head, 20);
    //====================
    //pass 3 nodes  
    //InsertNode(&head, 10);
    //InsertNode(&head, 20);
    //InsertNode(&head, 30);
    DisplayList(head);
    RevListItr(&head);
    DisplayList(head);
    return 0;
}
