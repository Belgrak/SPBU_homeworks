#include "input_task_1.h"
#include <stdio.h>

int integerInput(char name_of_var)
{
    int digit = 0;
    printf("Ввелите целое число %c: ", name_of_var);
    scanf("%d", &digit);
    return digit;
}
