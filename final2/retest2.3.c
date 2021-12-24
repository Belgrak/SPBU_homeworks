#include "../library/commonUtils/list.h"
#include <stdio.h>
#define DEFAULT_VALUE 0

void readElementsFromFile(List* list, FILE* fileInput)
{
    int number = 0;
    while (fscanf(fileInput, "%d", &number) != EOF)
        putElement(list, number);
}

bool isSymmetric(List* list)
{
    for (int i = 0, j = getListSize(list) - 1; i != j && i - j != 1; i++, j--) {
        if (getByIndex(list, i, DEFAULT_VALUE) != getByIndex(list, j, DEFAULT_VALUE))
            return false;
    }
    return true;
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

    List* list = makeNewList();
    readElementsFromFile(list, fileInput);
    printf("This list is ");
    printf(isSymmetric(list) ? "symmetric" : "not symmetric");
    freeList(list);
    fclose(fileInput);
    return 0;
}