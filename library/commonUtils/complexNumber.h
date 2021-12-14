#ifndef SPBU_C_HOMEWORKS_COMPLEXNUMBER_H
#define SPBU_C_HOMEWORKS_COMPLEXNUMBER_H

#define ZERO_DENOMINATOR -1

typedef struct ComplexNumber ComplexNumber;

ComplexNumber* createComplexNumber(float realPart, float imaginaryPart);

ComplexNumber* sumComplexNumbers(ComplexNumber* first, ComplexNumber* second);
ComplexNumber* subtractComplexNumbers(ComplexNumber* first, ComplexNumber* second);
ComplexNumber* multiplyComplexNumbers(ComplexNumber* first, ComplexNumber* second);
ComplexNumber* divideComplexNumbers(ComplexNumber* first, ComplexNumber* second, int* error);

float getAbs(ComplexNumber* number);
void printComplexNumber(ComplexNumber* number);

#endif // SPBU_C_HOMEWORKS_COMPLEXNUMBER_H
