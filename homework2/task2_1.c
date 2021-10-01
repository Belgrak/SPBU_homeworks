#include "../library/commonUtils/linkedMap.h"
#include <stdio.h>
#define WRONG_LINKED_MAP_KEY -1

void readElementsFromFile(LinkedMap* linkedMap, FILE* fileInput)
{
    char word[128] = "";
    while (fscanf(fileInput, "%s", word) != EOF) {
        if (hasKey(linkedMap, word)) {
            put(linkedMap, word, get(linkedMap, word, WRONG_LINKED_MAP_KEY) + 1);
        } else {
            put(linkedMap, word, 1);
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc > 3) {
        printf("Error handed. Too much arguments.\n");
        return 0;
    }
    if (argc < 3) {
        printf("Error handed. You should enter <Program name> <Src file's path> <Dst file's path>\n");
        return 0;
    }
    FILE* fileInput = fopen(argv[1], "r");
    if (fileInput == NULL) {
        printf("Error handed. Wrong src file path.");
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