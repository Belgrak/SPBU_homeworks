#include <stdio.h>
#include <stdlib.h>

void readElementsFromFile(FILE* fileInput)
{
    int minDay = 99;
    int minMonth = 99;
    int minYear = 9999;
    char day[3] = "";
    char month[3] = "";
    char year[5] = "";
    while (fscanf(fileInput, " %s.%s.%s ", day, month, year) != EOF) {
        if (atoi(year) < minYear) {
            minYear = atoi(year);
            minMonth = atoi(month);
            minDay = atoi(day);
        }
        if (atoi(year) == minYear) {
            if (atoi(month) < minMonth) {
                minYear = atoi(year);
                minMonth = atoi(month);
                minDay = atoi(day);
            }
            if (atoi(month) == minMonth) {
                if (atoi(day) < minDay) {
                    minYear = atoi(year);
                    minMonth = atoi(month);
                    minDay = atoi(day);
                }
            }
        }
    }
    printf("Minimum Date: %d.%d.%d", minDay, minMonth, minYear);
}

int main(int argc, char* argv[])
{
    if (argc > 2) {
        printf("Error handled. Too much arguments.\n");
        return 0;
    }
    if (argc < 2) {
        printf("Error handled. You should enter <Program name> <Src file's path>\n");
        return 0;
    }
    FILE* fileInput = fopen(argv[1], "r");
    if (!fileInput) {
        printf("Error handled. Wrong src file path.");
        return 0;
    }

    readElementsFromFile(fileInput);

    fclose(fileInput);
    return 0;
}
