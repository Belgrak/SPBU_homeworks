#ifndef SPBU_C_HOMEWORKS_LINKEDLIST_H
#define SPBU_C_HOMEWORKS_LINKEDLIST_H
#include <stdbool.h>
#include "values.h"

typedef struct LinkedList List;
typedef struct LinkedListElement LinkedListElement;

Value getElementKey(LinkedListElement* current);
Value getElementValue(LinkedListElement* current);

List* makeNewLinkedList();
LinkedListElement* makeNewLinkedListElement(Value key, Value data);

Value getElementDataByKey(List* list, Value key);
LinkedListElement* getElementByIndex(List* list, int index);
void putElement(struct LinkedList* list, Value key, Value data);
int getSizeList(List* list);
void deleteFromList(List* list, Value key);
void freeLinkedList(List* list);

#endif // SPBU_C_HOMEWORKS_LINKEDLIST_H