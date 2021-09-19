#include "../library/commonUtils/input_task_1.h"
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int number)
{
    int d = 2;
    while (d * d <= number && number % d != 0)
        d++;
    return d * d > number;
}

int main()
{
    printf("Данная программа выводит все простые числа не превосходящие числа a\n");
    int integerA = integerInput('a');
    bool firstTimeAndSimple = true;
    for (int i = 2; i <= integerA; i++) {
        if (isPrime(i)) {
            if (firstTimeAndSimple) {
                printf("Простые числа: ");
                firstTimeAndSimple = false;
            }
            printf("%d ", i);
        }
    }
    if (firstTimeAndSimple)
        printf("К сожалению, простых чисел не превосходящих числа %d нет", integerA);
    return 0;
}