#include "../library/commonUtils/binary.h"
#include "../library/commonUtils/ioInputInteger.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber = integerInput('a');
    int secondNumber = integerInput('b');

    int* firstBin = decToBinsComplement(firstNumber);
    int* secondBin = decToBinsComplement(secondNumber);

    printf("Multiplication result: %d", multiply(firstBin, secondBin));

    free(firstBin);
    free(secondBin);
    return 0;
}