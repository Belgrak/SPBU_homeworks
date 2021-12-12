#include "hashMap.h"
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

#define HASH_POLYNOMIAL_PARAMETER 239

struct Pair {
    Value key;
    Value value;
};

Pair* createPair()
{
    Pair* pair = malloc(sizeof(Pair));
    pair->key = wrapNone();
    pair->value = wrapNone();
    return pair;
}

struct HashMap {
    List** buckets;
    List** nextBuckets;
    int nextBucketsIndex;
    int mode;
    HashFunction function;
    int nBuckets;
    int elementsCount;
};

struct HashMapIterator{
    int nBuckets;
    List** buckets;
    int bucketIndex;
    int bucketElementIndex;
    bool isEnd;
};

uint32_t hashFunction(Value value, int nBuckets)
{
    char* targetString = getString(value);
    size_t length = strlen(targetString);
    int hashResult = 0;

    for (int i = 0; i < length - 1; i++) {
        hashResult = (hashResult + targetString[i]) % nBuckets;
        hashResult = (hashResult * HASH_POLYNOMIAL_PARAMETER) % nBuckets;
    }
    hashResult = (hashResult + targetString[length - 1]) % nBuckets;

    return hashResult;
}

HashMap* createHashMap(HashFunction hashFunction, int size)
{
    HashMap* table = malloc(sizeof(HashMap));
    table->nBuckets = size;
    table->nextBucketsIndex = 0;
    table->mode = 0;
    table->elementsCount = 0;
    table->function = hashFunction;
    table->buckets = malloc(sizeof(List*) * table->nBuckets);
    for (int i = 0; i < table->nBuckets; i++)
        table->buckets[i] = makeNewLinkedList();

    return table;
}

void destroyHashMap(HashMap* map)
{
    for (int i = 0; i < map->nBuckets; i++)
        freeLinkedList(map->buckets[i]);
    free(map->buckets);
    free(map);
}

float getLoadFactor(HashMap* map)
{
    return (float)map->elementsCount / (float)map->nBuckets;
}

void moveToBigBuckets(HashMap* table)
{
    if (table->mode == 0) {
        if (getLoadFactor(table) >= 1) {
            table->nextBuckets = malloc(sizeof(List*) * 3 * table->nBuckets);
            table->mode = 1;
        }
        return;
    }
    if (table->mode == 1) {
        for (int i = 0; i < 3 && table->nextBucketsIndex != table->nBuckets * 3; i++) {
            table->nextBuckets[table->nextBucketsIndex] = makeNewLinkedList();
            table->nextBucketsIndex++;
        }
        if (table->nextBucketsIndex == table->nBuckets * 3) {
            table->mode = 2;
            table->nextBucketsIndex = 0;
        }
        return;
    }
    if (table->mode == 2) {
        // do copy from bucket to newBucket
        bool doneCopy = false;
        for (int i = 0; i < 3 && table->nextBucketsIndex != table->nBuckets * 3; i++) {
            table->nextBuckets[table->nextBucketsIndex] = table->buckets[table->nextBucketsIndex];
            table->nextBucketsIndex++;
        }
        if (table->nextBucketsIndex == table->nBuckets) {
            doneCopy = true;
            table->nextBucketsIndex = 0;
        }
        if (doneCopy) {
            free(table->buckets);
            table->buckets = table->nextBuckets;
            table->mode = 0;
        }
    }
}

Value get(HashMap* map, Value key)
{
    moveToBigBuckets(map);
    uint32_t keyHash = map->function(key, map->nBuckets);
    return getElementDataByKey(map->buckets[keyHash], key);
}

bool hasKey(HashMap* map, Value key)
{
    return !isNone(get(map, key));
}

void put(HashMap* map, Value key, Value value)
{
    moveToBigBuckets(map);
    uint32_t keyHash = map->function(key, map->nBuckets);
    // Memory leak
    deleteFromList(map->buckets[keyHash], key);
    putElement(map->buckets[keyHash], key, value);
}

Pair* removeKey(HashMap* map, Value key)
{
    moveToBigBuckets(map);
    Pair* pair = createPair();
    pair->key = key;
    pair->value = get(map, key);
    uint32_t keyHash = map->function(key, map->nBuckets);
    deleteFromList(map->buckets[keyHash], key);
    return pair;
}

int getSize(HashMap* map)
{
    return map->nBuckets;
}

HashMapIterator* getIterator(HashMap* map){
    HashMapIterator* iterator = malloc(sizeof(HashMapIterator));
    iterator->nBuckets = map->nBuckets;
    iterator->buckets = map->buckets;
    iterator->isEnd = false;
    iterator->bucketIndex = 0;
    for (int i = 0; i < iterator->nBuckets; i++){
        if (getSizeList(iterator->buckets[i]) > 0){
            iterator->bucketIndex = i;
            break;
        }
    }
    iterator->bucketElementIndex = 0;
    return iterator;
}

Value getValue(HashMapIterator* iterator){
    if (iterator->isEnd)
        return wrapNone();
    if (iterator->bucketIndex < iterator->nBuckets){
        if (iterator->bucketElementIndex < getSizeList(iterator->buckets[iterator->bucketIndex]))
            return getElementValue(getElementByIndex(iterator->buckets[iterator->bucketIndex], iterator->bucketElementIndex));
    }
    return wrapNone();
}

Value getKey(HashMapIterator* iterator){
    if (iterator->isEnd)
        return wrapNone();
    if (iterator->bucketIndex < iterator->nBuckets){
        if (iterator->bucketElementIndex < getSizeList(iterator->buckets[iterator->bucketIndex]))
            return getElementKey(getElementByIndex(iterator->buckets[iterator->bucketIndex], iterator->bucketElementIndex));
    }
    return wrapNone();
}

HashMapIterator* next(HashMapIterator* iterator){
    if (iterator->bucketElementIndex < getSizeList(iterator->buckets[iterator->bucketIndex]) - 1)
        iterator->bucketElementIndex++;
    else {
        int previousIndex = iterator->bucketIndex;
        for (int i = iterator->bucketIndex + 1; i < iterator->nBuckets; i++){
            if (getSizeList(iterator->buckets[i]) > 0 ){
                iterator->bucketIndex = i;
                break;
            }
        }
        if (previousIndex == iterator->bucketIndex)
            iterator->isEnd = true;
        iterator->bucketElementIndex = 0;
    }
    return iterator;
}