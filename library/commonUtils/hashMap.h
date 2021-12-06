#ifndef SPBU_C_HOMEWORKS_HASHMAP_H
#define SPBU_C_HOMEWORKS_HASHMAP_H
#include "values.h"
#include <stdint.h>

typedef struct Pair Pair;

typedef struct HashMap HashMap;
typedef struct HashMapIterator HashMapIterator;
typedef uint32_t (*HashFunction)(Value, int);

HashMap* createHashMap(HashFunction hashFunction, int size);
void destroyHashMap(HashMap* map);

uint32_t hashFunction(Value value, int nBuckets);

Value get(HashMap* map, Value key);
void put(HashMap* map, Value key, Value value);
bool hasKey(HashMap* map, Value key);
Pair removeKey(HashMap* map, Value key);
int getSize(HashMap* map);

HashMapIterator* getIterator(HashMap* map);
Value getValue(HashMapIterator* iterator);
HashMapIterator* next(HashMapIterator* iterator);

#endif // SPBU_C_HOMEWORKS_HASHMAP_H
