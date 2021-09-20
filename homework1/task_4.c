#include "../library/commonUtils/ioInputInteger.h"
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int number)
{
    int d = 2;
    while (number > d) {
        if (number % d == 0)
            return false;
        else
            d++;
    }
    return true;
}

int main()
{
    printf("Данная программа выводит все простые числа не превосходящие числа a\n");
    int integerA = integerInput('a');
    bool isPrimeFound = true;
    for (int i = 2; i <= integerA; i++) {
        if (isPrime(i)) {
            if (isPrimeFound) {
                printf("Простые числа: ");
                isPrimeFound = false;
            }
            printf("%d ", i);
        }
    }
    if (isPrimeFound)
        printf("К сожалению, простых чисел не превосходящих числа %d нет", integerA);
    return 0;
}