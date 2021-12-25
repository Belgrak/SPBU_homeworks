#include "../library/commonUtils/mergeSort.h"
#include <stdio.h>
#include <stdlib.h>

void findSaddlePoints(int** array, int rowsSize, int columnsSize)
{
    for (int i = 0; i < rowsSize; i++) {
        for (int j = 0; j < columnsSize; j++) {
            int* tempRowArray = sort(array[i], columnsSize);
            if (tempRowArray[0] != array[i][j]) {
                free(tempRowArray);
                continue;
            }

            int* tempColumnArray = calloc(rowsSize, sizeof(int));
            for (int h = 0; h < rowsSize; h++)
                tempColumnArray[h] = array[h][j];
            int* sortedTempColumnArray = sort(tempColumnArray, rowsSize);
            if (sortedTempColumnArray[rowsSize - 1] == array[i][j])
                printf("%d\n", array[i][j]);
            free(tempRowArray);
            free(tempColumnArray);
            free(sortedTempColumnArray);
        }
    }
}

int main()
{
    int rowsSize = 0;
    int columnsSize = 0;
    printf("Please enter nRows: ");
    scanf("%d", &rowsSize);
    printf("Please enter nColumns: ");
    scanf("%d", &columnsSize);
    int** array = calloc(rowsSize, sizeof(int*));
    printf("Please enter a data( using Enter ):\n");
    for (int i = 0; i < rowsSize; i++) {
        array[i] = calloc(columnsSize, sizeof(int));
        for (int j = 0; j < columnsSize; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    findSaddlePoints(array, rowsSize, columnsSize);

    for (int i = 0; i < rowsSize; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}