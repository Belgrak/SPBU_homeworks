#include "linkedMap.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct LinkedMap {
    LinkedMapElement* head;
    LinkedMapElement* tail;
    int LinkedMapSize;
};

struct LinkedMapElement {
    int data;
    LinkedMapElement* nextElement;
    char key[128];
};

LinkedMap* makeNewLinkedMap()
{
    LinkedMap* lst = malloc(sizeof(LinkedMap));
    lst->head = NULL;
    lst->tail = NULL;
    lst->LinkedMapSize = 0;
    return lst;
}

LinkedMapElement* makeNewLinkedMapElement(const char key[128], int data)
{
    LinkedMapElement* newElement = malloc(sizeof(LinkedMapElement));
    strcpy(newElement->key, key);
    newElement->data = data;
    newElement->nextElement = NULL;
    return newElement;
}

bool hasKey(LinkedMap* map, const char key[128])
{
    int ind = 0;
    LinkedMapElement* currElement = map->head;
    while (ind < map->LinkedMapSize) {
        if (strcmp(currElement->key, key) == 0)
            return true;
        currElement = currElement->nextElement;
        ind++;
    }
    return false;
}

LinkedMapElement* getElement(LinkedMap* map, const char key[128])
{
    int ind = 0;
    LinkedMapElement* currElement = map->head;
    while (ind < map->LinkedMapSize) {
        if (strcmp(currElement->key, key) == 0)
            return currElement;
        currElement = currElement->nextElement;
        ind++;
    }
    return 0;
}

void put(LinkedMap* map, char key[128], int data)
{
    LinkedMapElement* newElement = makeNewLinkedMapElement(key, data);
    if (map->LinkedMapSize == 0) {
        map->head = newElement;
        map->tail = newElement;
        map->LinkedMapSize++;
    } else {
        if (hasKey(map, key)) {
            LinkedMapElement* currElement = getElement(map, key);
            currElement->data = data;
        } else {
            map->LinkedMapSize++;
            map->tail->nextElement = newElement;
            map->tail = newElement;
        }
    }
}

int get(LinkedMap* map, char key[128])
{
    if (hasKey(map, key)) {
        LinkedMapElement* currElement = getElement(map, key);
        return currElement->data;
    }
    return 0;
}

int getSize(LinkedMap* ls)
{
    return ls->LinkedMapSize;
}

char* getKeyByIndex(LinkedMap* map, int index)
{
    int ind = 0;
    LinkedMapElement* currElement = map->head;
    while (ind < index) {
        currElement = currElement->nextElement;
        ind++;
    }
    return currElement->key;
}
