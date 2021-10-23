#include "binary.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIGNED_BINARY_SIZE 33

int binToDec(const int* binaryCode)
{
    int number = 0;
    for (int i = 1; i < SIGNED_BINARY_SIZE; i++) {
        if (binaryCode[i])
            number += (int)pow(2, SIGNED_BINARY_SIZE - i - 1);
    }
    return (int)pow((-1), binaryCode[0]) * number;
}

int* decToBin(int number)
{
    if (abs(number) == 0) {
        int* binaryCode = calloc(SIGNED_BINARY_SIZE, sizeof(int));
        return binaryCode;
    }
    int buffer[256] = {};
    int index = 0;
    buffer[255] = number < 0;
    number = abs(number);
    while (number > 0) {
        buffer[index] = number % 2;
        number /= 2;
        index++;
    }
    int* binaryCode = calloc(SIGNED_BINARY_SIZE, sizeof(int));
    binaryCode[0] = buffer[255];
    index--;
    for (int i = SIGNED_BINARY_SIZE - 1 - index; index >= 0; index--, i++)
        binaryCode[i] = buffer[index];
    return binaryCode;
}

int* binToTwosComplement(int* binaryCode)
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

int* binSummation(const int* firstBin, const int* secondBin)
{
    int* summary = calloc(SIGNED_BINARY_SIZE, sizeof(int));
    bool plusOneNext = false;
    for (int i = SIGNED_BINARY_SIZE - 1, j = SIGNED_BINARY_SIZE - 1; i >= 0 || j >= 0; i--, j--) {
        int index = (int)fmax(i, j);
        if (plusOneNext) {
            if (i < 0)
                summary[index] = 1 + secondBin[j];
            else if (j < 0)
                summary[index] = 1 + firstBin[i];
            else if (i >= 0 && j >= 0)
                summary[index] = firstBin[i] + secondBin[j] + 1;
            plusOneNext = false;
        } else if (i < 0)
            summary[index] = secondBin[j];
        else if (j < 0)
            summary[index] = firstBin[i];
        else if (i >= 0 && j >= 0)
            summary[index] = firstBin[i] + secondBin[j];
        if (summary[index] >= 2)
            plusOneNext = true;
        summary[index] = summary[index] % 2;
    }
    return summary;
}

int* twosComplementToBin(int* binaryCode)
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

int* decToTwosComplement(int number)
{
    return binToTwosComplement(decToBin(number));
}

int* leftShift(int* binaryCode, int count)
{
    return decToTwosComplement(binToDec(twosComplementToBin(binaryCode)) << count);
}

int* rightShift(int* binaryCode, int count)
{
    return decToTwosComplement(binToDec(twosComplementToBin(binaryCode)) >> count);
}

void binaryPrint(int* binaryCode, char* comment)
{
    printf("%s", comment);
    for (int i = 0; i < SIGNED_BINARY_SIZE; i++)
        printf("%d", binaryCode[i]);
    printf("\n");
}