#include "list.h"
#include <stddef.h>
#include <stdlib.h>

struct List {
    ListElement* head;
    int ListSize;
};

struct ListElement {
    int data;
    ListElement* nextElement;
};

List* makeNewList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->ListSize = 0;
    return list;
}

ListElement* makeNewListElement(int data)
{
    ListElement* newElement = malloc(sizeof(ListElement));
    newElement->data = data;
    newElement->nextElement = NULL;
    return newElement;
}

void putElement(List* list, int data)
{
    ListElement* newElement = makeNewListElement(data);
    newElement->nextElement = list->head;
    list->head = newElement;
    list->ListSize++;
}

int getListSize(List* list)
{
    return list->ListSize;
}

int getByIndex(List* list, int index, int defaultValue)
{
    if (index >= getListSize(list))
        return defaultValue;
    ListElement* currentElement = list->head;
    for (int i = 0; i < index; i++)
        currentElement = currentElement->nextElement;
    return currentElement->data;
}

void freeList(List* list)
{
    if (!list->head) {
        free(list);
        return;
    }
    ListElement* currentElement = list->head->nextElement;
    for (int i = 0; i < list->ListSize - 1; i++) {
        free(list->head);
        list->head = currentElement;
        currentElement = currentElement->nextElement;
    }
    free(list->head);
    free(list);
}
