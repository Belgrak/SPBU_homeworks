#include "linkedList.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
    LinkedListElement* head;
    LinkedListElement* tail;
    int linkedListSize;
};

struct LinkedListElement {
    Value data;
    LinkedListElement* nextElement;
};

List* makeNewLinkedList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->linkedListSize = 0;
    return list;
}

LinkedListElement* makeNewLinkedListElement(Value data)
{
    LinkedListElement* newElement = malloc(sizeof(LinkedListElement));
    newElement->data = data;
    newElement->nextElement = NULL;
    return newElement;
}

Value getElementDataByIndex(List* list, int index)
{
    LinkedListElement* current = list->head;
    for (int i = 0; i < index; i++)
        current = current->nextElement;
    return current->data;
}

void putElement(struct LinkedList* list, Value data)
{
    LinkedListElement* newElement = makeNewLinkedListElement(data);
    if (list->linkedListSize == 0)
        list->head = newElement;
    else
        list->tail->nextElement = newElement;
    list->tail = newElement;
    list->linkedListSize++;
}

int getSizeList(List* list)
{
    return list->linkedListSize;
}

void freeLinkedList(List* list)
{
    LinkedListElement* currentElement = list->head->nextElement;
    for (int i = 0; i < list->linkedListSize - 1; i++) {
        free(list->head);
        list->head = currentElement;
        currentElement = currentElement->nextElement;
    }
    list->linkedListSize = 0;
    free(list);
}