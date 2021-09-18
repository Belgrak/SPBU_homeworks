#include "input_task_1.h"
#include <stdio.h>

int integerInput(char nameOfVar)
{
    int digit = 0;
    printf("Ввелите целое число %c: ", nameOfVar);
    scanf("%d", &digit);
    return digit;
}
