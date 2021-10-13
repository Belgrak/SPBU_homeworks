#include <math.h>
#include <stdio.h>

double inputDouble()
{
    double number = 0;
    printf("Please enter a double number: ");
    scanf("%lf", &number);
    return number;
}

void getAndPrintMantissaAndExponent(double number)
{
    number = fabs(number);
    int exponent = 0;
    if (number >= 1) {
        while (number > pow(2, exponent))
            ++(exponent);
        if (number < pow(2, exponent))
            --(exponent);
        printf("%lf*2^%i", number / pow(2, exponent), exponent);
    } else {
        while (number < pow(2, (-1) * exponent))
            ++(exponent);
        printf("%lf*2^-%i", number * pow(2, exponent), exponent);
    }
}

int main()
{
    double number = inputDouble();
    printf("%c", number > 0 ? '+' : '-');
    getAndPrintMantissaAndExponent(number);
    return 0;
}