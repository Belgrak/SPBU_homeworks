#include "../library/commonUtils/linkedMap.h"
#include <stdio.h>
#define DEFAULT_VALUE 0

void readElementsFromFile(LinkedMap* linkedMap, FILE* fileInput)
{
    int number = 0;
    while (fscanf(fileInput, "%d", &number) != EOF)
        put(linkedMap, number);
}

bool isSymmetric(LinkedMap* map)
{
    for (int i = 0, j = getSize(map) - 1; i != j && i - j != 1; i++, j--) {
        if (getByIndex(map, i, DEFAULT_VALUE) != getByIndex(map, j, DEFAULT_VALUE))
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

    LinkedMap* linkedMap = makeNewLinkedMap();
    readElementsFromFile(linkedMap, fileInput);
    printf("This list is ");
    printf(isSymmetric(linkedMap) ? "symmetric" : "not symmetric");
    freeLinkedMap(linkedMap);
    fclose(fileInput);
    return 0;
}