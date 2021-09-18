#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool existenceOfRepetitiveElements(const int* array, int arrayLen)
{
    for (int i = 0; i < arrayLen; i++) {
        for (int j = i + 1; j < arrayLen; j++) {
            if (array[i] == array[j]) {
                return true;
            }
        }
    }
    return false;
}

int gettingMaxRepetitiveElement(const int* array, int arrayLen)
{
    int maxElement = 0;
    for (int i = 0; i < arrayLen; i++) {
        for (int j = i + 1; j < arrayLen; j++) {
            if (array[i] == array[j]) {
                if (array[i] > maxElement)
                    maxElement = array[i];
            }
        }
    }
    return maxElement;
}

int main()
{
    int arrSize = 0;
    printf("Введите кол-во элементов в массиве: ");
    scanf("%d", &arrSize);
    int* array = (int*)calloc(arrSize, sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        printf("Введите число в массив: ");
        scanf("%d", &array[i]);
    }
    if (!existenceOfRepetitiveElements(array, arrSize)) {
        printf("Error was handed. Array does not have any repetitive elements.\n");
        return 0;
    }
    printf("Max repetitive element: %d", gettingMaxRepetitiveElement(array, arrSize));
    free(array);
    return 0;
}