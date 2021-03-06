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
    char* data;
    LinkedListElement* nextElement;
};

LinkedList* makeNewLinkedList()
{
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->linkedListSize = 0;
    return list;
}

LinkedListElement* makeNewLinkedListElement(const char* data)
{
    LinkedListElement* newElement = malloc(sizeof(LinkedListElement));
    newElement->data = strdup(data);
    newElement->nextElement = NULL;
    return newElement;
}

char* getElementDataByIndex(LinkedList* list, int index)
{
    LinkedListElement* current = list->head;
    for (int i = 0; i < index; i++)
        current = current->nextElement;
    return current->data;
}

void addElement(struct LinkedList* list, const char* data)
{
    LinkedListElement* newElement = makeNewLinkedListElement(data);
    if (list->linkedListSize == 0)
        list->head = newElement;
    else
        list->tail->nextElement = newElement;
    list->tail = newElement;
    list->linkedListSize++;
}

int getSizeList(LinkedList* list)
{
    return list->linkedListSize;
}

void freeLinkedList(LinkedList* list)
{
    LinkedListElement* currentElement = list->head;
    while (currentElement) {
        currentElement = currentElement->nextElement;
        free(list->head->data);
        free(list->head);
        list->head = currentElement;
    }
    list->linkedListSize = 0;
    free(list);
}