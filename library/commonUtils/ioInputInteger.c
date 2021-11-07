#include "ioInputInteger.h"
#include <stdio.h>

int integerInput(char nameOfVar)
{
    int digit = 0;
    printf("Please enter a number %c: ", nameOfVar);
    scanf("%d", &digit);
    return digit;
}
