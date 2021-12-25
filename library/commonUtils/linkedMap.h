#ifndef SPBU_C_HOMEWORKS_LinkedMap_H
#define SPBU_C_HOMEWORKS_LinkedMap_H
#include <stdbool.h>

typedef struct LinkedMap LinkedMap;
typedef struct LinkedMapElement LinkedMapElement;

LinkedMap* makeNewLinkedMap();

bool hasKey(LinkedMap* map, int key);
void put(LinkedMap* map, int key, int value);
int get(LinkedMap* map, int key, int defaultValue);

int getSize(LinkedMap* map);
int getKeyByIndex(LinkedMap* map, int index);
void freeLinkedMap(LinkedMap* map);

#endif // SPBU_C_HOMEWORKS_LinkedMap_H