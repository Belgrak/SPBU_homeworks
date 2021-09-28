#include "../library/commonUtils/linkedMap.h"
#include <stdio.h>
#include <stdlib.h>

void addingLinkedMapElements(LinkedMap* linkedMap)
{
    char* word = calloc(128, sizeof(char));
    while (fscanf(fileInput, "%s", word) != EOF) {
        if (hasKey(linkedMap, word)) {
            put(linkedMap, word, get(linkedMap, word) + 1);
        } else {
            put(linkedMap, word, 1);
        }
    }
    free(word);
}

int main()
{
    char* srcName = calloc(255, sizeof(char));
    printf("Введите расположение входного файла формата [src].txt:");
    scanf("%s", srcName);
    FILE* fileInput = fopen(srcName, "r");
    if (fileInput == NULL) {
        printf("Error handed. Wrong src file path.");
        return 0;
    }

    char* dstName = calloc(255, sizeof(char));
    printf("Введите расположение файла для вывода формата [dst].csv:");
    scanf("%s", dstName);
    FILE* fileOutput = fopen(dstName, "w");

    LinkedMap* linkedMap = makeNewLinkedMap();
    addingLinkedMapElements(linkedMap);

    for (int i = 0; i < getSize(linkedMap); i++) {
        fprintf(fileOutput, "%s,%d\n", getKeyByIndex(linkedMap, i), get(linkedMap, getKeyByIndex(linkedMap, i)));
    }
    free(srcName);
    free(dstName);
    return 0;
}