#include "../library/commonUtils/input_task_1.h"
#include <stdio.h>
#include <stdlib.h>

int gettingIncompleteQuotient(int dividend, int divisor)
{
    int quotient = 0;
    int dividend_abs = abs(dividend);
    int divisor_abs = abs(divisor);
    while (dividend_abs >= divisor_abs) {
        dividend_abs -= divisor_abs;
        ++quotient;
    }
    if (dividend < 0) {
        quotient = (-1) * quotient - 1;
    }
    if (divisor < 0) {
        quotient = (-1) * quotient;
    }
    return quotient;
}

int main()
{
    int integerA = integerInput('a');
    int integerB = integerInput('b');
    if (integerB == 0) {
        printf("Error was handed. Division by zero.\n");
        return 0;
    }
    printf("Неполное частное равно %d", gettingIncompleteQuotient(integerA, integerB));
    return 0;
}