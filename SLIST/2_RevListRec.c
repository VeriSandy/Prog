//https://www.geeksforgeeks.org/reverse-a-linked-list/
//Reverse a linked list (recursion)

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

void RevListRec(NODE **head)
{
    NODE *first = *head;
    NODE *sec = NULL;
   
    if(first == NULL) return;
    sec = first->next;
    if(sec == NULL) return;
   
//  printf("first %d amnd sec %d \n", first->data, sec->data);

    RevListRec(&sec);

    first->next->next = first;
    //sec->next = first; //this wouldnt work as we are modifying its value, see carefully as we are passing sec as head.
    first->next = NULL;

//  printf("first %d amnd sec %d \n", first->data, sec->data);
    *head = sec;

//  printf("*head %d \n", (*head)->data);
    return;
}

int main()
{
    NODE *head = NULL;
    NODE *temp = NULL;
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
    InsertNode(&head, 10);
    InsertNode(&head, 20);
    InsertNode(&head, 30);
    InsertNode(&head, 40);
    DisplayList(head);
    RevListRec(&head);
    DisplayList(head);
    return 0;
}
