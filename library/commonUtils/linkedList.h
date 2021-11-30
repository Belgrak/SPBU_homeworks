#ifndef SPBU_C_HOMEWORKS_LINKEDLIST_H
#define SPBU_C_HOMEWORKS_LINKEDLIST_H
#include <stdbool.h>
#include "values.h"

typedef struct LinkedList List;
typedef struct LinkedListElement LinkedListElement;

List* makeNewLinkedList();
LinkedListElement* makeNewLinkedListElement(Value data);

Value getElementDataByIndex(List* list, int index);
void putElement(struct LinkedList* list, Value data);
int getSizeList(List* list);
void freeLinkedList(List* list);

#endif // SPBU_C_HOMEWORKS_LINKEDLIST_H