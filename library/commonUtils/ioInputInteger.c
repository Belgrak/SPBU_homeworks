#include "ioInputInteger.h"
#include <stdio.h>

int integerInput(char nameOfVar)
{
    int digit = 0;
    printf("Ввелите число %c: ", nameOfVar);
    scanf("%d", &digit);
    return digit;
}
