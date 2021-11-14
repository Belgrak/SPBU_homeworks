#include "binary.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIGNED_BINARY_SIZE 33

int binToDec(bin binaryCode)
{
    int number = 0;
    int temporary = 1;
    for (int i = SIGNED_BINARY_SIZE - 1; i > 0; i--) {
        temporary *= i == SIGNED_BINARY_SIZE - 1 ? 1 : 2;
        if (binaryCode[i])
            number += temporary;
    }
    return (binaryCode[0] == 1 ? -1 : 1) * number;
}

bin decToBin(int number)
{
    bin binaryCode = calloc(SIGNED_BINARY_SIZE, sizeof(int));
    binaryCode[0] = number < 0;
    number = abs(number);
    for (int index = SIGNED_BINARY_SIZE - 1; number > 0; index--) {
        binaryCode[index] = number % 2;
        number /= 2;
    }
    return binaryCode;
}

bin binToBinsComplement(bin binaryCode)
{
    if (!binaryCode[0])
        return binaryCode;
    for (int i = 1; i < SIGNED_BINARY_SIZE; i++)
        binaryCode[i] = 1 - binaryCode[i];
    for (int j = SIGNED_BINARY_SIZE - 1; j >= 1; j--) {
        if (binaryCode[j] == 1 && j != 1) {
            binaryCode[j] = 0;
            continue;
        }
        binaryCode[j] = 1;
        break;
    }
    return binaryCode;
}

bin binSummation(bin firstBin, bin secondBin)
{
    bin summary = calloc(SIGNED_BINARY_SIZE, sizeof(int));
    bool plusOneNext = false;
    for (int i = SIGNED_BINARY_SIZE - 1; i >= 0; i--) {
        summary[i] = firstBin[i] + secondBin[i] + 1 * plusOneNext;
        plusOneNext = summary[i] / 2 == 1;
        summary[i] %= 2;
    }
    return summary;
}

bin binsComplementToBin(bin binaryCode)
{
    if (!binaryCode[0])
        return binaryCode;
    int index = SIGNED_BINARY_SIZE - 1;
    while (binaryCode[index] != 1)
        index--;
    binaryCode[index] = 0;
    for (int i = index + 1; i < SIGNED_BINARY_SIZE; i++)
        binaryCode[i] = 1;
    for (int i = 1; i < SIGNED_BINARY_SIZE; i++)
        binaryCode[i] = 1 - binaryCode[i];
    return binaryCode;
}

bin decToBinsComplement(int number)
{
    return binToBinsComplement(decToBin(number));
}

bin leftShift(bin binaryCode, int count)
{
    for (int i = 0, j = count; i < SIGNED_BINARY_SIZE; i++, j++) {
        if (j >= SIGNED_BINARY_SIZE)
            binaryCode[i] = 0;
        else
            binaryCode[i] = binaryCode[j];
    }
    return binaryCode;
}

int multiply(bin firstBin, bin secondBin)
{
    binaryPrint(firstBin, "First binary complement code: ");
    binaryPrint(secondBin, "Second binary complement code: ");
    firstBin[0] = 0;
    secondBin[0] = 0;
    bin multiplicationBinary = calloc(SIGNED_BINARY_SIZE, sizeof(int));
    bin temporary = NULL;
    int shiftCount = 0;
    for (int i = SIGNED_BINARY_SIZE - 1; i >= 0; i--) {
        if (secondBin[i] == 1) {
            temporary = multiplicationBinary;
            multiplicationBinary = binSummation(temporary, leftShift(firstBin, shiftCount));
            free(temporary);
            shiftCount = 0;
        }
        shiftCount++;
    }
    binaryPrint(multiplicationBinary, "Multiplication binary complement code: ");
    int multiplication = binToDec(binsComplementToBin(multiplicationBinary));
    free(multiplicationBinary);
    return multiplication;
}

void binaryPrint(bin binaryCode, char* comment)
{
    printf("%s", comment);
    for (int i = 0; i < SIGNED_BINARY_SIZE; i++)
        printf("%d", binaryCode[i]);
    printf("\n");
}