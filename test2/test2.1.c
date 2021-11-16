#include "../library/commonUtils/ioInputInteger.h"
#include <stdio.h>

long long fib(int n)
{
    long long first = 0;
    long long second = 1;
    for (int i = 0; i < n - 1; i++) {
        second += first;
        first = second - first;
    }
    return second;
}

int main()
{
    int number = integerInput('n');
    if (number > 90) {
        printf("Error handled. Wrong number.");
        return 0;
    }
    printf("Your Fibonacci number is %lld", fib(number));
    return 0;
}