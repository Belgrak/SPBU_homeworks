#include "complexNumber.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ComplexNumber {
    float realPart;
    float imaginaryPart;
};

ComplexNumber* createComplexNumber(float realPart, float imaginaryPart)
{
    ComplexNumber* number = malloc(sizeof(ComplexNumber));
    number->realPart = realPart;
    number->imaginaryPart = imaginaryPart;
    return number;
}

ComplexNumber* sumComplexNumbers(ComplexNumber* first, ComplexNumber* second)
{
    return createComplexNumber(first->realPart + second->realPart, first->imaginaryPart + second->imaginaryPart);
}

ComplexNumber* subtractComplexNumbers(ComplexNumber* first, ComplexNumber* second)
{
    return createComplexNumber(first->realPart - second->realPart, first->imaginaryPart - second->imaginaryPart);
}

ComplexNumber* multiplyComplexNumbers(ComplexNumber* first, ComplexNumber* second)
{
    float realPart = first->realPart * second->realPart - first->imaginaryPart * second->imaginaryPart;
    float imaginaryPart = first->realPart * second->imaginaryPart + first->imaginaryPart * second->realPart;
    return createComplexNumber(realPart, imaginaryPart);
}

ComplexNumber* divideComplexNumbers(ComplexNumber* first, ComplexNumber* second, int* error)
{
    float denominator = second->realPart * second->realPart + second->imaginaryPart * second->imaginaryPart;
    if (denominator == 0) {
        *error = ZERO_DENOMINATOR;
        return NULL;
    }
    float realPartNumerator = first->realPart * second->realPart + first->imaginaryPart * second->imaginaryPart;
    float imaginaryPartNumerator = first->imaginaryPart * second->realPart - first->realPart * second->imaginaryPart;
    return createComplexNumber(realPartNumerator / denominator, imaginaryPartNumerator / denominator);
}

float getAbs(ComplexNumber* number)
{
    return sqrtf(number->realPart * number->realPart + number->imaginaryPart * number->imaginaryPart);
}

void printComplexNumber(ComplexNumber* number)
{
    printf("%f + (%f)i\n", number->realPart, number->imaginaryPart);
}