#include "mergeSort.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int* merge(int* firstArray, int firstSize, int* secondArray, int secondSize)
{
    if (!secondArray) {
        int* mergedArray = calloc(firstSize, sizeof(int));
        memcpy(mergedArray, firstArray, firstSize * sizeof(int));
        return mergedArray;
    }
    int* mergedArray = calloc(firstSize + secondSize, sizeof(int));
    int i = 0;
    int j = 0;
    while (i < firstSize && j < secondSize) {
        if (firstArray[i] <= secondArray[j]) {
            mergedArray[i + j] = firstArray[i];
            i++;
        } else {
            mergedArray[i + j] = secondArray[j];
            j++;
        }
        if (i == firstSize)
            memcpy(mergedArray + i + j, secondArray + j, (secondSize - j) * sizeof(int));
        if (j == secondSize)
            memcpy(mergedArray + i + j, firstArray + i, (firstSize - i) * sizeof(int));
    }
    return mergedArray;
}

int* sort(int* array, int size)
{
    int* sortedArray = calloc(size, sizeof(int));
    memcpy(sortedArray, array, size * sizeof(int));
    int firstArraySize = 1;
    int* tempArray = NULL;
    while (firstArraySize <= size) {
        for (int i = 0, j = firstArraySize; i < size; i += 2 * firstArraySize, j += 2 * firstArraySize) {
            int* secondArray = NULL;
            int secondArraySize = 0;
            if (j < size) {
                secondArray = sortedArray + j;
                secondArraySize = fmin(firstArraySize, size - j);
            }
            tempArray = merge(sortedArray + i, firstArraySize, secondArray, secondArraySize);
            memcpy(sortedArray + i, tempArray, (firstArraySize + secondArraySize) * sizeof(int));
            if (tempArray)
                free(tempArray);
        }
        firstArraySize *= 2;
    }
    return sortedArray;
}