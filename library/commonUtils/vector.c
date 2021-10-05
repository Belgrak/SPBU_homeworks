#include "vector.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Vector {
    int size;
    int* data;
};

Vector* makeNewVector(const int* data)
{
    Vector* newVector = malloc(sizeof(Vector));
    int index = 0;
    for (int i = data[index]; i; i = data[++index]) {
        newVector->data[index] = i;
    }
    newVector->size = ++index;
    return newVector;
}

int getScalarProduct(Vector* firstVector, Vector* secondVector, int defaultValue)
{
    if (firstVector->size == secondVector->size) {
        int scalarProduct = 0;
        for (int i = 0; i < firstVector->size; i++) {
            scalarProduct += firstVector->data[i] + secondVector->data[i];
        }
        return scalarProduct;
    }
    return defaultValue;
}

int getVectorLength(Vector* vector)
{
    int vectorLength = 0;
    for (int i = 0; i < vector->size; i++) {
        vectorLength += vector->data[i] * vector->data[i];
    }
    return (int)sqrt(vectorLength);
}

Vector* vectorSummation(Vector* firstVector, Vector* secondVector)
{
    if (firstVector->size == secondVector->size) {
        int* data = calloc(firstVector->size, sizeof(int));
        for (int i = 0; i < firstVector->size; i++) {
            data[i] = firstVector->data[i] + secondVector->data[i];
        }
        Vector* newVector = makeNewVector(data);
        free(data);
        return newVector;
    }
    return NULL;
}

Vector* vectorSubtraction(Vector* firstVector, Vector* secondVector)
{
    if (firstVector->size == secondVector->size) {
        int* data = calloc(firstVector->size, sizeof(int));
        for (int i = 0; i < firstVector->size; i++) {
            data[i] = firstVector->data[i] - secondVector->data[i];
        }
        Vector* newVector = makeNewVector(data);
        free(data);
        return newVector;
    }
    return NULL;
}