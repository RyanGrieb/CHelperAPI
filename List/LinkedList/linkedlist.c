#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"

LinkedList* createLinkedList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->data = -1;
    list->next = NULL;

    return list;
}

//Push to front
void push(LinkedList** listHead, int data)
{
    LinkedList* p = createLinkedList();
    p->data = data;
    p->next = *listHead;
    *listHead = p;
}

void printLinkedList(LinkedList* listHead)
{
    if (listHead == NULL) {
        printf("Error: list NULL\n");
    }

    LinkedList* p = listHead;
    while (p->next != NULL) {
        printf("Num %d\n", p->data);
        p = p->next;
    }
}

int main()
{
    LinkedList* listHead = createLinkedList();

    push(&listHead, 5);
    push(&listHead, 10);
    push(&listHead, 15);

    printLinkedList(listHead);

    return 0;
}
