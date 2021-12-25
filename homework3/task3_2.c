#include <stdbool.h>
#include <stdio.h>

typedef union Number {
    double value;
    char binaryForm[8];
} Number;

double getMantissa(const bool* binaryCode, int size)
{
    double number = 0;
    double temporary = 1;
    for (int i = 0; i < size; i++) {
        temporary /= 2;
        if (binaryCode[i])
            number += temporary;
    }
    return 1 + number;
}

void convertToBinaryCode64(Number number, bool* sign, bool shiftedExponent[11], bool mantissa[52])
{
    unsigned short bit = 0b10000000;

    int index = 0;
    for (int i = 7; i > -1; i--) {
        for (int j = 0; j < 8; j++) {
            if (index == 0)
                *sign = (number.binaryForm[i] & bit) ? 1 : 0;
            if (0 < index && index < 12)
                shiftedExponent[index - 1] = (number.binaryForm[i] & bit) ? 1 : 0;
            if (11 < index && index < 64)
                mantissa[index - 12] = (number.binaryForm[i] & bit) ? 1 : 0;
            bit >>= 1;
            index++;
        }
        bit = 0b10000000;
    }
}

int getExponent(const bool shiftedExponent[11])
{
    int number = 0;
    int temporary = 1;
    for (int i = 10; i >= 0; i--) {
        temporary *= i == 10 ? 1 : 2;
        if (shiftedExponent[i])
            number += temporary;
    }
    return number - 1024 + 1;
}

void convertToExponentialForm(Number number)
{
    bool sign = 0;
    bool shiftedExponent[11] = {};
    bool mantissa[52] = {};
    convertToBinaryCode64(number, &sign, shiftedExponent, mantissa);
    printf("%c%lf*2^%d", sign ? '-' : '+', getMantissa(mantissa, 52), getExponent(shiftedExponent));
}

int main()
{
    Number number = { 0 };
    printf("Please enter a double number: ");
    scanf("%lf", &number.value);
    convertToExponentialForm(number);
    return 0;
}