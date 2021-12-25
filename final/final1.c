#include "../library/commonUtils/linkedMap.h"
#include "../library/commonUtils/mergeSort.h"
#include <stdio.h>
#include <stdlib.h>

bool isInArray(int* array, int arraySize, int n)
{
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == n)
            return true;
    }
    return false;
}

void countNums(LinkedMap* map, int* arraySize, int** array)
{
    int number = 0;
    scanf("%d", &number);
    while (number != 0) {
        if (!isInArray(*array, *arraySize, number)) {
            (*array)[*arraySize] = number;
            *array = realloc(*array, (*arraySize + 2) * sizeof(int));
            (*arraySize)++;
        }
        put(map, number, get(map, number, 0) + 1);
        scanf("%d", &number);
    }
    int* tempArray = *array;
    *array = sort(*array, *arraySize);
    free(tempArray);
}

void outputResult(LinkedMap* map, int arraySize, int* array)
{
    for (int i = 0; i < arraySize; i++)
        printf("%d: %d\n", array[i], get(map, array[i], 0));
}

int main(int argc, char* argv[])
{
    printf("Please enter numbers: ");
    LinkedMap* map = makeNewLinkedMap();
    int arraySize = 0;
    int* array = calloc(1, sizeof(int));
    countNums(map, &arraySize, &array);
    outputResult(map, arraySize, array);
    free(array);
    freeLinkedMap(map);
    return 0;
}