//Merge two sorted linked lists
//https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
//Using recursion

#include "../../COMMON/common.h"

typedef struct node
{
    int data;
    struct node *next;
}Node;

void AddNode(Node **head, int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
    return;
}


void PrintList(Node *head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

Node *SortedMerge(Node *a, Node *b)
{
    if(a == NULL) return b;
   
    if(b == NULL) return a;

    if(a->data <= b->data)
    {
        a->next = SortedMerge(a->next, b);
        return a;
    }
   
    if(a->data >= b->data)
    {
        b->next = SortedMerge(a, b->next);
        return b;
    }

    return NULL;
}

int main()
{
    Node *head1 = NULL, *head2 = NULL, *res= NULL;
    AddNode(&head1, 15);
    AddNode(&head1, 10);
    AddNode(&head1, 5);
    printf("******A*******\n");
    PrintList(head1);
    AddNode(&head2, 20);
    AddNode(&head2, 3);
    AddNode(&head2, 2);
    printf("******B*******\n");
    PrintList(head2);
    printf("******Sorted********\n");
    res = SortedMerge(head1, head2);
    PrintList(res);
    return 0;
}
