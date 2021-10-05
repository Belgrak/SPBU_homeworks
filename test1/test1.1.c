#include "../library/commonUtils/vector.h"
#include <stdio.h>
#include <stdlib.h>
#define WRONG_LINKED_MAP_KEY 0

int main()
{
    int firstVectorSize = 0;
    printf("Введите кол-во элементов в первом векторе: ");
    scanf("%d", &firstVectorSize);
    int* firstData = (int*)calloc(firstVectorSize, sizeof(int));
    for (int i = 0; i < firstVectorSize; i++) {
        printf("Введите число в вектор ");
        scanf("%d", &firstData[i]);
    }
    Vector* firstVector = makeNewVector(firstData);

    int secondVectorSize = 0;
    printf("Введите кол-во элементов во втором векторе: ");
    scanf("%d", &secondVectorSize);
    int* secondData = (int*)calloc(secondVectorSize, sizeof(int));
    for (int i = 0; i < secondVectorSize; i++) {
        printf("Введите число в вектор ");
        scanf("%d", &secondData[i]);
    }
//    Vector* secondVector = makeNewVector(secondData);

//    printf("Скалярное произведение: %d", getScalarProduct(firstVector, secondVector, 0));
//    printf("Длина ветора 1: %d", getVectorLength(firstVector));
//    printf("Длина суммы векторов: %d", getVectorLength(vectorSummation(firstVector, secondVector)));
//    printf("Длина разности векторов: %d", getVectorLength(vectorSubtraction(firstVector, secondVector)));

    return 0;
}