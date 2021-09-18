#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int gettingMaxRepetitiveElement(const int *array, int array_len) {
    int maxElement = 0;
    bool HasRepetitiveElements = false;
    for (int i = 0; i < array_len; i++) {
        for (int j = i + 1; j < array_len; j++) {
            if (array[i] == array[j]) {
                HasRepetitiveElements = true;
                if (array[i] > maxElement) maxElement = array[i];
            }
        }
    }
    if (!HasRepetitiveElements) {
        printf("Error was handed. Array does not have any repetitive elements.\n");
    }
    return maxElement;
}

int main() {
    int size = 0;
    printf("Введите кол-во элементов в массиве: ");
    scanf("%d", &size);
    int *array = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("Введите число в массив: ");
        scanf("%d", &array[i]);
    }
    printf("Max repetitive element: %d", gettingMaxRepetitiveElement(array, size));
    free(array);
    return 0;
}