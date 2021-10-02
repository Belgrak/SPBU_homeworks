#include "../library/commonUtils/linkedMap.h"
#include <stdio.h>
#define WRONG_LINKED_MAP_KEY 0

void readElementsFromFile(LinkedMap* linkedMap, FILE* fileInput)
{
    char word[128] = "";
    while (fscanf(fileInput, "%s", word) != EOF)
        put(linkedMap, word, get(linkedMap, word, WRONG_LINKED_MAP_KEY) + 1);
}

int main(int argc, char* argv[])
{
    if (argc > 3) {
        printf("Error handled. Too much arguments.\n");
        return 0;
    }
    if (argc < 3) {
        printf("Error handled. You should enter <Program name> <Src file's path> <Dst file's path>\n");
        return 0;
    }
    FILE* fileInput = fopen(argv[1], "r");
    if (!fileInput) {
        printf("Error handled. Wrong src file path.");
        return 0;
    }

    FILE* fileOutput = fopen(argv[2], "w");

    LinkedMap* linkedMap = makeNewLinkedMap();
    readElementsFromFile(linkedMap, fileInput);

    for (int i = 0; i < getSize(linkedMap); i++) {
        fprintf(fileOutput, "%s,%d\n", getKeyByIndex(linkedMap, i), get(linkedMap, getKeyByIndex(linkedMap, i), WRONG_LINKED_MAP_KEY));
    }
    freeLinkedMap(linkedMap);
    fclose(fileInput);
    fclose(fileOutput);
    return 0;
}