#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* mergeAndSortArrays(int firstSize, int* firstArray, int secondSize, int* secondArray)
{
    int* mergedArray = calloc(firstSize + secondSize, sizeof(int));
    int i = 0;
    int j = 0;
    while (i < firstSize && j < secondSize) {
        if (firstArray[i] >= secondArray[j]) {
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

int main()
{
    int firstArraySize = 0;
    int secondArraySize = 0;
    printf("Please enter first array size: ");
    scanf("%d", &firstArraySize);
    int* firstArray = calloc(firstArraySize, sizeof(int));
    for (int i = 0; i < firstArraySize; i++) {
        printf("Please enter a number: ");
        scanf("%d", &firstArray[i]);
    }

    printf("Please enter first array size: ");
    scanf("%d", &secondArraySize);
    int* secondArray = calloc(secondArraySize, sizeof(int));
    for (int i = 0; i < secondArraySize; i++) {
        printf("Please enter a number: ");
        scanf("%d", &secondArray[i]);
    }
    int* mergedArray = mergeAndSortArrays(firstArraySize, firstArray, secondArraySize, secondArray);
    printf("Merged and Sorted Array: ");
    for (int i = 0; i < firstArraySize + secondArraySize; i++) {
        printf("%d ", mergedArray[i]);
    }
    free(firstArray);
    free(secondArray);
    free(mergedArray);
    return 0;
}
