#ifndef SPBU_C_HOMEWORKS_HASHMAP_H
#define SPBU_C_HOMEWORKS_HASHMAP_H
#include "values.h"

typedef struct HashMap HashMap;
typedef struct HashMapIterator HashMapIterator;
typedef uint32_t (*HashFunction)(Value);

HashMap* createHashMap(HashFunction hashFunction);
void destroyHashMap(HashMap* map);

Value get(HashMap* map, Value key);
void put(HashMap* map, Value key, Value value);
bool hasKey(HashMap* map, Value key);
MapEntry removeKey(HashMap* map, Value key);
int getSize(HashMap* map);

HashMapIterator* getIterator(HashMap* map);
Value getValue(HashMapIterator* iterator);
HashMapIterator* next(HashMapIterator* iterator);

#endif // SPBU_C_HOMEWORKS_HASHMAP_H
