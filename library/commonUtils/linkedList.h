#ifndef SPBU_C_HOMEWORKS_LINKEDLIST_H
#define SPBU_C_HOMEWORKS_LINKEDLIST_H
#include <stdbool.h>

typedef struct LinkedList LinkedList;
typedef struct LinkedListElement LinkedListElement;

LinkedList* makeNewLinkedList();
LinkedListElement* makeNewLinkedListElement(const char* data);

char* getElementDataByIndex(LinkedList* list, int index);
void addElement(struct LinkedList* list, const char* data);
int getSizeList(LinkedList* list);
void freeLinkedList(LinkedList* list);

#endif // SPBU_C_HOMEWORKS_LINKEDLIST_H