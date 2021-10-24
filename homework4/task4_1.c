#include "../library/commonUtils/mergeSort.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arraySize = 0;
    printf("Please enter an array size: ");
    scanf("%d", &arraySize);
    int* array = calloc(arraySize, sizeof(int));
    printf("Please enter an array data( using Enter ):\n");
    for (int i = 0; i < arraySize; i++)
        scanf("%d", &array[i]);

    int* sorted = sort(array, arraySize);
    printf("Sorted Array: ");
    for (int i = 0; i < arraySize; i++)
        printf("%d ", sorted[i]);
    return 0;
}