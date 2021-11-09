#include "../library/commonUtils/treeMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pair {
    Value key;
    Value value;
};

void add(TreeMap* map, char firstOption[20], char secondOption[20])
{
    put(map, wrapInt(atoi(firstOption)), wrapInt(get(map, wrapInt(atoi(firstOption))).intValue + atoi(secondOption)));
}

void getSizeCount(TreeMap* map, char firstOption[20], FILE* fileOutput)
{
    fprintf(fileOutput, "%d", get(map, wrapInt(atoi(firstOption))).intValue);
    printf("%d\n", get(map, wrapInt(atoi(firstOption))).intValue);
}

void select(TreeMap* map, char firstOption[20], FILE* fileOutput)
{
    Value size = getLowerBound(map, wrapInt(atoi(firstOption)));
    Pair* pair = NULL;
    printf(isNone(size) ? "SORRY\n" : "%d\n", isNone(size) ?: size.intValue);
    if (!isNone(size)) {
        if (get(map, size).intValue - 1 == 0)
            pair = removeKey(map, size);
        else
            put(map, size, wrapInt(get(map, size).intValue - 1));
    }
}

void readElementsFromFile(TreeMap* map, FILE* fileInput, FILE* fileOutput)
{
    int logsCount = 0;
    fscanf(fileInput, "%d", &logsCount);
    char command[20] = "";
    char firstOption[20] = "";
    char secondOption[20] = "";
    for (int i = 0; i < logsCount; i++) {
        fscanf(fileInput, "%s %s", command, firstOption);
        if (strcmp(command, "ADD") == 0) {
            fscanf(fileInput, "%s", secondOption);
            add(map, firstOption, secondOption);
        }
        if (strcmp(command, "GET") == 0)
            getSizeCount(map, firstOption, fileOutput);
        if (strcmp(command, "SELECT") == 0)
            select(map, firstOption, fileOutput);
    }
}

int main()
{
    FILE* fileInput = fopen("../shop_logs.txt", "r");
    if (!fileInput) {
        printf("Error handled. Wrong src file path.");
        return 0;
    }
    FILE* fileOutput = fopen("../shop_res.txt", "w");
    TreeMap* map = createTreeMap(&compare);
    readElementsFromFile(map, fileInput, fileOutput);
    deleteTreeMap(map);
    return 0;
}