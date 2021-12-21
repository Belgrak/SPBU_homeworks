#include "linkedMap.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct LinkedMap {
    LinkedMapElement* head;
    int linkedMapSize;
};

struct LinkedMapElement {
    int data;
    LinkedMapElement* nextElement;
    int key;
};

LinkedMap* makeNewLinkedMap()
{
    LinkedMap* map = malloc(sizeof(LinkedMap));
    map->head = NULL;
    map->linkedMapSize = 0;
    return map;
}


LinkedMapElement* makeNewLinkedMapElement(int key, int data)
{
    LinkedMapElement* newElement = malloc(sizeof(LinkedMapElement));
    newElement->key = key;
    newElement->data = data;
    newElement->nextElement = NULL;
    return newElement;
}


LinkedMapElement* getElement(LinkedMap* map, int key)
{
    for (LinkedMapElement* currentElement = map->head; currentElement; currentElement = currentElement->nextElement) {
        if (currentElement->key == key)
            return currentElement;
    }
    return NULL;
}


bool hasKey(LinkedMap* map, int key)
{
    return getElement(map, key);
}


void put(LinkedMap* map, int key, int data)
{
    if (map->linkedMapSize == 0) {
        LinkedMapElement* newElement = makeNewLinkedMapElement(key, data);
        map->head = newElement;
        map->linkedMapSize++;
    } else {
        if (hasKey(map, key)) {
            LinkedMapElement* currentElement = getElement(map, key);
            currentElement->data = data;
        } else {
            LinkedMapElement* newElement = makeNewLinkedMapElement(key, data);
            newElement->nextElement = map->head;
            map->head = newElement;
            map->linkedMapSize++;
        }
    }
}


int get(LinkedMap* map, int key, int defaultValue)
{
    LinkedMapElement* currentElement = getElement(map, key);
    return currentElement ? currentElement->data : defaultValue;
}

int getSize(LinkedMap* map)
{
    return map->linkedMapSize;
}


int getKeyByIndex(LinkedMap* map, int index)
{
    LinkedMapElement* currentElement = map->head;
    for (int i = 0; i < index; i++)
        currentElement = currentElement->nextElement;
    return currentElement->key;
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
    map->linkedMapSize = 0;
    free(map);
}
