#include "hashMap.h"
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_START_SIZE 256
#define HASH_POLYNOMIAL_PARAMETER 239

struct HashMap
{
    List** bucket;
    int mode;
    HashFunction function;
    int nBuckets;
};

uint32_t hashFunction(Value value){
    targetString = getString(value);
    size_t length = strlen(targetString);
    int hashResult = 0;

    for (int i = 0; i < length - 1; i++) {
        hashResult = (hashResult + targetString[i]) % nBuckets;
        hashResult = (hashResult * HASH_POLYNOMIAL_PARAMETER) % nBuckets;
    }
    hashResult = (hashResult + targetString[length - 1]) % nBuckets;

    return hashResult;
}

HashMap* createHashMap(HashFunction hashFunction)
{
    HashMap* table = malloc(sizeof(HashMap));
    table->nBuckets = HASH_TABLE_START_SIZE;
    table->mode = 0;
    table->function = hashFunction;
    table->bucket = malloc(sizeof(List*) * table->nBuckets);
    for (int i = 0; i < table->nBuckets; i++)
        table->bucket[i] = makeNewLinkedList();

    return table;
}

void destroyHashMap(HashMap* map)
{
    for (int i = 0; i < map->nBuckets; i++)
        freeLinkedList(map->bucket[i]);
    free(map->bucket);
    free(map);
}

Value get(HashMap* map, Value key)
{
    int keyHash = hashFunction(key);
    deleteFromList(table->bucket[keyHash], key);
    bool result = insert(key, value, getListSize(table->bucket[keyHash]), table->bucket[keyHash]);

    if (getLoadFactor(table) > HASH_TABLE_LOAD_BORDER) {
        table->nextBuckets = malloc(...);
        table->mode = 1;
    }
}

//
//void moveToBigBuckets(HashMap* table)
//{
//    if (table->mode == 0)
//        return;
//    if (table->mode == 1) {
//        table->nextBuckets[table->nextBucketsIndex] = makeNewLinkedList();
//        table->nextBucketIndex++;
//        if (table->nextBucketIndex == table->nBuckets * 2)
//            table->mode = 2;
//        return;
//    }
//    if (table->mode == 2) {
//        // do copy from bucket to newBucket
//
//        if (doneCopy) {
//            free(table->bucket);
//            table->bucket = table->nextBuckets;
//            table->mode = 0;
//        }
//    }
//}


bool hashTableInsert(HashTable* table, char* key, char* value) {
    moveToBigBuckets(table);
    int keyHash = calculateHash(key, HASH_POLYNOMIAL_PARAMETER, table->nBuckets);
    deleteFromList(table->bucket[keyHash], key);
    bool result = insert(key, value, getListSize(table->bucket[keyHash]), table->bucket[keyHash]);

    if (getLoadFactor(table) > HASH_TABLE_LOAD_BORDER) {
        table->nextBuckets = malloc(...);
        table->mode = 1;
    }
}

char* getValueFromHashTable(HashTable* table, char* key) {
    moveToBigBuckets(table);
}