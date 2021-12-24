#include "linkedMap.h"
#include <stddef.h>
#include <stdlib.h>

struct LinkedMap {
    LinkedMapElement* head;
    int linkedMapSize;
};

struct LinkedMapElement {
    int data;
    LinkedMapElement* nextElement;
};

LinkedMap* makeNewLinkedMap()
{
    LinkedMap* map = malloc(sizeof(LinkedMap));
    map->head = NULL;
    map->linkedMapSize = 0;
    return map;
}

LinkedMapElement* makeNewLinkedMapElement(int data)
{
    LinkedMapElement* newElement = malloc(sizeof(LinkedMapElement));
    newElement->data = data;
    newElement->nextElement = NULL;
    return newElement;
}

void put(LinkedMap* map, int data)
{
    LinkedMapElement* newElement = makeNewLinkedMapElement(data);
    newElement->nextElement = map->head;
    map->head = newElement;
    map->linkedMapSize++;
}

int getSize(LinkedMap* map)
{
    return map->linkedMapSize;
}

int getByIndex(LinkedMap* map, int index, int defaultValue)
{
    if (index >= getSize(map))
        return defaultValue;
    LinkedMapElement* currentElement = map->head;
    for (int i = 0; i < index; i++)
        currentElement = currentElement->nextElement;
    return currentElement->data;
}

void freeLinkedMap(LinkedMap* map)
{
    if (!map->head) {
        free(map);
        return;
    }
    LinkedMapElement* currentElement = map->head->nextElement;
    for (int i = 0; i < map->linkedMapSize - 1; i++) {
        free(map->head);
        map->head = currentElement;
        currentElement = currentElement->nextElement;
    }
    free(map->head);
    free(map);
}
