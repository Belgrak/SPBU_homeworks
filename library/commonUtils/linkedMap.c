#include "linkedMap.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct LinkedMap {
    LinkedMapElement* head;
    int linkedMapSize;
};

struct LinkedMapElement {
    int data;
    LinkedMapElement* nextElement;
    char* key;
};

LinkedMap* makeNewLinkedMap()
{
    LinkedMap* map = malloc(sizeof(LinkedMap));
    map->head = NULL;
    map->linkedMapSize = 0;
    return map;
}

LinkedMapElement* makeNewLinkedMapElement(const char* key, int data)
{
    LinkedMapElement* newElement = malloc(sizeof(LinkedMapElement));
    newElement->key = strdup(key);
    newElement->data = data;
    newElement->nextElement = NULL;
    return newElement;
}

LinkedMapElement* getElement(LinkedMap* map, const char* key)
{
    for (LinkedMapElement* currentElement = map->head; currentElement; currentElement = currentElement->nextElement) {
        if (strcmp(currentElement->key, key) == 0)
            return currentElement;
    }
    return NULL;
}

bool hasKey(LinkedMap* map, const char* key)
{
    return getElement(map, key);
}

void put(LinkedMap* map, const char* key, int data)
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

int get(LinkedMap* map, const char* key, int defaultValue)
{
    LinkedMapElement* currentElement = getElement(map, key);
    return currentElement ? currentElement->data : defaultValue;
}

int getSize(LinkedMap* map)
{
    return map->linkedMapSize;
}

char* getKeyByIndex(LinkedMap* map, int index)
{
    LinkedMapElement* currentElement = map->head;
    for (int i = 0; i < index; i++)
        currentElement = currentElement->nextElement;
    return currentElement->key;
}

void freeLinkedMap(LinkedMap* map)
{
    LinkedMapElement* currentElement = map->head->nextElement;
    for (int i = 0; i < map->linkedMapSize - 1; i++) {
        free(map->head->key);
        free(map->head);
        map->head = currentElement;
        currentElement = currentElement->nextElement;
    }
    map->linkedMapSize = 0;
    free(map);
}
