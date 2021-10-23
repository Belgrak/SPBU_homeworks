#include "../library/commonUtils/binary.h"
#include "../library/commonUtils/ioInputInteger.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber = integerInput('a');
    int secondNumber = integerInput('b');

    int* firstBin = decToTwosComplement(firstNumber);
    int* secondBin = decToTwosComplement(secondNumber);
    int* summaryComplement = binSummation(firstBin, secondBin);
    int* summaryBin = twosComplementToBin(summaryComplement);

    binaryPrint(firstBin, "First two's complement binary code: ");
    binaryPrint(secondBin, "Second two's complement binary code: ");
    binaryPrint(summaryComplement, "Summary two's complement binary code: ");
    printf("Result of summation: %d\n", binToDec(summaryBin));

    free(firstBin);
    free(secondBin);
    free(summaryBin);
    return 0;
}