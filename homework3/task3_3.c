#include "../library/commonUtils/binary.h"
#include "../library/commonUtils/ioInputInteger.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber = integerInput('a');
    int secondNumber = integerInput('b');

    int* firstBin = decToTwosComplement(abs(firstNumber));
    int* secondBin = decToTwosComplement(abs(secondNumber));

    printf("Multiplication result: %d", multiply(firstBin, secondBin, ((firstNumber < 0) + (secondNumber < 0)) % 2));
    return 0;
}