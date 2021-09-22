#include <stdio.h>
#include <stdlib.h>

void makingOddSpiral(int** matrix, int length)
{
    matrix[length / 2][length / 2] = 1;
    int row = length / 2, column = length / 2, count = 1, prev_number = 1;
    while (prev_number < length * length) {
        for (int j = 0; j < count; j++) {
            if (prev_number == length * length)
                break;
            if (count % 2 != 0)
                column++;
            else
                column--;
            matrix[row][column] = ++prev_number;
        }
        for (int h = 0; h < count; h++) {
            if (prev_number == length * length)
                break;
            if (count % 2 != 0)
                row++;
            else
                row--;
            matrix[row][column] = ++prev_number;
        }
        count++;
    }
}

int main()
{
    int nOdd = 0;
    printf("Введите целое нечетное число: ");
    scanf("%d", &nOdd);
    if (nOdd % 2 == 0) {
        printf("Error handed. You entered an even number.");
        return 0;
    }
    int** matrix = calloc(nOdd, sizeof(int*));
    for (int i = 0; i < nOdd; i++)
        matrix[i] = calloc(nOdd, sizeof(int));
    makingOddSpiral(matrix, nOdd);
    for (int t = 0; t < nOdd; t++) {
        for (int g = 0; g < nOdd; g++) {
            printf("%d\t", matrix[t][g]);
        }
        printf("\n");
        free(matrix[t]);
    }
    free(matrix);
    return 0;
}
