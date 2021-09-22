#include <stdio.h>
#include <stdlib.h>

void replacingBeginAndEndOfArray(int* array, int arrayLength, int firstArrLen)
{
    for (int i = 0; i < firstArrLen; i++) {
        int tempValue = array[0];
        for (int j = 1; j < arrayLength; j++) {
            array[j - 1] = array[j];
        }
        array[arrayLength - 1] = tempValue;
    }
}

int main()
{
    int summaryArraySize = 0, firstArrayLength = 0;
    printf("Введите кол-во элементов в массиве и длину первого подмассива: ");
    scanf("%d  %d", &summaryArraySize, &firstArrayLength);
    if (summaryArraySize <= 0) {
        printf("Error handed. Wrong array size.");
        return 0;
    }
    if (firstArrayLength > summaryArraySize || firstArrayLength < 0) {
        printf("Error handed. You have a mistake in a first array length");
        return 0;
    }
    int* summaryArray = (int*)calloc(summaryArraySize, sizeof(int));
    for (int i = 0; i < summaryArraySize; i++) {
        printf("Введите число в массив: ");
        scanf("%d", &summaryArray[i]);
    }
    replacingBeginAndEndOfArray(summaryArray, summaryArraySize, firstArrayLength);
    printf("Измененный массив: ");
    for (int i = 0; i < summaryArraySize; i++) {
        printf("%d ", summaryArray[i]);
    }
    free(summaryArray);
    return 0;
}
