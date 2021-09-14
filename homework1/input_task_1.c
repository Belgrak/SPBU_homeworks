#include "input_task_1.h"
#include <stdio.h>

int input(char* name_of_var)
{
    int digit;
    printf("Ввелите целое число %s: ", name_of_var);
    scanf("%d", &digit);
    return digit;
}
