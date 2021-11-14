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
    fprintf(fileOutput, "%d\n", get(map, wrapInt(atoi(firstOption))).intValue);
}

void selectElement(TreeMap* map, char firstOption[20], FILE* fileOutput)
{
    Value size = getLowerBound(map, wrapInt(atoi(firstOption)));
    Pair* pair = NULL;
    fprintf(fileOutput, isNone(size) ? "SORRY\n" : "%d\n", isNone(size) ?: size.intValue);
    if (!isNone(size)) {
        if (get(map, size).intValue - 1 == 0)
            pair = removeKey(map, size);
        else
            put(map, size, wrapInt(get(map, size).intValue - 1));
    }
    if (pair)
        free(pair);
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
            selectElement(map, firstOption, fileOutput);
    }
}

void fprintBalance(TreeMap* map, FILE* fileOutput)
{
    TreeMapIterator* iterator = getIterator(map);
    while (hasElement(iterator)) {
        fprintf(fileOutput, "%d %d\n", getKey(iterator).intValue, getValue(iterator).intValue);
        next(iterator);
    }
    free(iterator);
}

int main()
{
    FILE* fileInput = fopen("../shop_logs.txt", "r");
    if (!fileInput) {
        printf("Error handled. Wrong src file path.");
        return 0;
    }
    FILE* resultFileOutput = fopen("../shop_res.txt", "w");
    FILE* balanceFileOutput = fopen("../shop_balance.txt", "w");
    TreeMap* map = createTreeMap(&compare);
    readElementsFromFile(map, fileInput, resultFileOutput);
    fprintBalance(map, balanceFileOutput);
    deleteTreeMap(map);
    fclose(fileInput);
    fclose(resultFileOutput);
    fclose(balanceFileOutput);
    return 0;
}