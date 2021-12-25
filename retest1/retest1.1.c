#include "../library/commonUtils/complexNumber.h"
#include <stdio.h>
#include <stdlib.h>

ComplexNumber* complexNumberInput()
{
    float realPart = 0;
    float imaginaryPart = 0;
    printf("Please enter a real part of a complex number: ");
    scanf("%f", &realPart);
    printf("Please enter a imaginary part of a complex number: ");
    scanf("%f", &imaginaryPart);
    return createComplexNumber(realPart, imaginaryPart);
}

int main()
{
    ComplexNumber* first = complexNumberInput();
    ComplexNumber* second = complexNumberInput();

    printf("First complex number\n");
    printComplexNumber(first);

    printf("Second complex number\n");
    printComplexNumber(second);

    printf("\n");

    int error = 0;

    ComplexNumber* additionResult = sumComplexNumbers(first, second);
    printComplexNumber(additionResult);
    free(additionResult);

    ComplexNumber* subtractionResult = subtractComplexNumbers(first, second);
    printComplexNumber(subtractionResult);
    free(subtractionResult);

    ComplexNumber* multiplyResult = multiplyComplexNumbers(first, second);
    printComplexNumber(multiplyResult);
    free(multiplyResult);

    ComplexNumber* divisionResult = divideComplexNumbers(first, second, &error);
    if (error == ZERO_DENOMINATOR)
        printf("In division denominator equals zero");
    else {
        printComplexNumber(divisionResult);
        free(divisionResult);
    }

    printf("First complex number's abs: %f", getAbs(first));
    free(first);
    free(second);
    return 0;
}