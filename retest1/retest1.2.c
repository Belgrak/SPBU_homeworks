#include "../library/commonUtils/linkedMap.h"
#include <ctype.h>
#include <stdio.h>

void countAlphas(FILE* fileInput, LinkedMap* map)
{
    while (feof(fileInput)) {
        char symbol = getc(fileInput);
        if (isalpha(symbol) && symbol >= 97)
            put(map, symbol, get(map, symbol, 0));
    }
}

void outputResult(FILE* fileOutput, LinkedMap* map)
{
    for (char i = 'a'; i <= 'z'; i++) {
        if (get(map, i, 0) != 0)
            fprintf(fileOutput, "%c: %d", i, get(map, i, 0));
    }
}

int main(int argc, char* argv[])
{
//    if (argc > 2) {
//        printf("Error handled. Too much arguments.\n");
//        return 0;
//    }
//    if (argc < 2) {
//        printf("Error handled. You should enter <Program name> <Src file's path>\n");
//        return 0;
//    }
    FILE* fileInput = fopen("../r.txt", "r");
    if (!fileInput) {
        printf("Error handled. Wrong src file path.");
        return 0;
    }
    LinkedMap* map = makeNewLinkedMap();
    countAlphas(fileInput, map);
    FILE* fileOutput = fopen("../resultRetest1.2.txt", "w");
    outputResult(fileOutput, map);
    freeLinkedMap(map);
    fclose(fileInput);
    fclose(fileOutput);
    return 0;
}