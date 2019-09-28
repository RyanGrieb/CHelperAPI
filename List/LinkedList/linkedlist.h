typedef struct LinkedList {
    int data;
    struct LinkedList* next;
} LinkedList;

LinkedList* createLinkedList(void);
void push(LinkedList** listHead, int data);
void printLinkedList(LinkedList* listHead);
