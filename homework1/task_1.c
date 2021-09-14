#include "input_task_1.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = input((char*)"a");
    int b = input((char*)"b");
    int r = 0;
    int a_abs = abs(a);
    int b_abs = abs(b);
    while (a_abs >= b_abs) {
        a_abs = a_abs - b_abs;
        ++r;
    }
    if (a < 0) {
        r = (-1) * r - 1;
    }
    if (b < 0) {
        r = (-1) * r;
    }
    printf("Неполное частное равно %d", r);
    return 0;
}