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
    Value key;
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

LinkedListElement* makeNewLinkedListElement(Value key, Value data)
{
    LinkedListElement* newElement = malloc(sizeof(LinkedListElement));
    newElement->key = key;
    newElement->data = data;
    newElement->nextElement = NULL;
    return newElement;
}

Value getElementDataByIndex(List* list, Value key)
{
    LinkedListElement* current = list->head;
    for (int i = 0; i < list->linkedListSize && compare(key, current->key) != 0; i++)
        current = current->nextElement;
    return compare(key, current->key) != 0 ? wrapNone() : current->data;
}

void putElement(struct LinkedList* list, Value key, Value data)
{
    LinkedListElement* newElement = makeNewLinkedListElement(key, data);
    if (list->linkedListSize == 0)
        list->head = newElement;
    else
        list->tail->nextElement = newElement;
    list->tail = newElement;
    list->linkedListSize++;
}

void deleteFromList(List* list, Value key)
{
    LinkedListElement* current = list->head;
    for (int i = 0; i < list->linkedListSize && compare(key, current->nextElement->key) != 0; i++)
        current = current->nextElement;
    if (compare(key, current->nextElement->key) == 0) {
        LinkedListElement* next = current->nextElement->nextElement;
        free(current->nextElement);
        current->nextElement = next;
    }
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