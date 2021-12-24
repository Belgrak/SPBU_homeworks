#ifndef SPBU_C_HOMEWORKS_LinkedMap_H
#define SPBU_C_HOMEWORKS_LinkedMap_H
#include <stdbool.h>

typedef struct LinkedMap LinkedMap;
typedef struct LinkedMapElement LinkedMapElement;

LinkedMap* makeNewLinkedMap();

void put(LinkedMap* map, int value);
int getSize(LinkedMap* map);
int getByIndex(LinkedMap* map, int index, int defaultValue);
void freeLinkedMap(LinkedMap* map);

#endif // SPBU_C_HOMEWORKS_LinkedMap_H
