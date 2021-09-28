#ifndef SPBU_C_HOMEWORKS_LinkedMap_H
#define SPBU_C_HOMEWORKS_LinkedMap_H

#include <stdbool.h>

typedef struct LinkedMap LinkedMap;
typedef struct LinkedMapElement LinkedMapElement;

LinkedMap* makeNewLinkedMap();

bool hasKey(LinkedMap* map, const char key[128]);
void put(LinkedMap* map, char key[128], int value);
int get(LinkedMap* map, char key[128]);

int getSize(LinkedMap* ls);
char* getKeyByIndex(LinkedMap* map, int index);

#endif // SPBU_C_HOMEWORKS_LinkedMap_H
