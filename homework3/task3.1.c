#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int inputInteger()
{
    int number = 0;
    printf("Please enter a number: ");
    scanf("%d", &number);
    return number;
}

int binToDec(const int* binaryCode, int binarySize)
{
    int number = 0;
    for (int i = 1; i < binarySize; i++) {
        if (binaryCode[i])
            number += (int)pow(2, binarySize - i - 1);
    }
    return (int)pow((-1), binaryCode[0]) * number;
}

int* decToBin(int number, int* sizePointer)
{
    if (number == 0) {
        *sizePointer = 9;
        int* binaryCode = calloc(9, sizeof(int));
        return binaryCode;
    }
    int buffer[256], index = 0;
    buffer[255] = number < 0;
    number = abs(number);
    while (number > 0) {
        buffer[index] = number % 2;
        number /= 2;
        index++;
    }
    *sizePointer = 9;
    int* binaryCode = calloc(9, sizeof(int));
    binaryCode[0] = buffer[255];
    index--;
    for (int i = 8 - index; index >= 0; index--, i++)
        binaryCode[i] = buffer[index];
    return binaryCode;
}

int* binToTwosComplement(int* binaryCode, int binarySize)
{
    if (binaryCode[0] == 0 && binarySize == 1 || !binaryCode[0])
        return binaryCode;
    for (int i = 1; i < binarySize; i++)
        binaryCode[i] = 1 - binaryCode[i];
    for (int j = binarySize - 1; j >= 1; j--) {
        if (binaryCode[j] == 1 && j != 1) {
            binaryCode[j] = 0;
            continue;
        }
        binaryCode[j] = 1;
        break;
    }
    return binaryCode;
}

int* binSummation(const int* firstBin, int firstSize, const int* secondBin, int secondSize, int* summarySize)
{
    int* summary = calloc((int)fmax(firstSize, secondSize), sizeof(int));
    bool plusOneNext = false;
    *summarySize = (int)fmax(firstSize, secondSize);
    for (int i = firstSize - 1, j = secondSize - 1; i >= 0 || j >= 0; i--, j--) {
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

int* twosComplementToBin(int* binaryCode, int binarySize)
{
    if (!binaryCode[0])
        return binaryCode;
    int index = binarySize - 1;
    while (binaryCode[index] != 1)
        index--;
    binaryCode[index] = 0;
    for (int i = index + 1; i < binarySize; i++)
        binaryCode[i] = 1;
    for (int i = 1; i < binarySize; i++)
        binaryCode[i] = 1 - binaryCode[i];
    return binaryCode;
}

int* decToTwosComplement(int number, int* sizePointer)
{
    int* binaryCode = decToBin(number, sizePointer);
    return binToTwosComplement(binaryCode, *sizePointer);
}

void binaryPrint(int* binaryCode, int binarySize, char* comment)
{
    printf("%s", comment);
    for (int i = 0; i < binarySize; i++)
        printf("%d", binaryCode[i]);
    printf("\n");
}

int main()
{
    int firstNumber = inputInteger();
    int secondNumber = inputInteger();

    int firstSize = 0, secondSize = 0, summarySize = 0;
    int* firstBin = decToTwosComplement(firstNumber, &firstSize);
    int* secondBin = decToTwosComplement(secondNumber, &secondSize);
    int* summaryComplement = binSummation(firstBin, firstSize, secondBin, secondSize, &summarySize);
    int* summaryBin = twosComplementToBin(summaryComplement, summarySize);

    binaryPrint(firstBin, firstSize, "First two's complement binary code: ");
    binaryPrint(secondBin, secondSize, "Second two's complement binary code: ");
    binaryPrint(summaryComplement, summarySize, "Summary two's complement binary code: ");
    printf("Result of summation: %d\n", binToDec(summaryBin, summarySize));
    return 0;
}