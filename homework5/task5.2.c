#include "../library/commonUtils/treeMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Pair {
    Value key;
    Value value;
};

void create(TreeMap* map, char street[20], char house[20], char building[20], char index[20])
{
    Value houseValue = get(map, wrapString(street));
    TreeMap* houseMap = houseValue.pointerValue;
    if (!houseMap){
        houseMap = createTreeMap(&compare);
        TreeMap* buildingMap = createTreeMap(&compare);
        put(buildingMap, wrapInt(atoi(building)), wrapInt(atoi(index)));
        put(houseMap, wrapInt(atoi(house)), wrapPointer(buildingMap));
    } else {
        Value buildingValue = get(houseMap, wrapInt(atoi(house)));
        TreeMap* buildingMap = buildingValue.pointerValue;
        if (!buildingMap)
            buildingMap = createTreeMap(&compare);
        put(buildingMap, wrapInt(atoi(building)), wrapInt(atoi(index)));
        put(houseMap, wrapInt(atoi(house)), wrapPointer(buildingMap));
    }
    put(map, wrapString(street), wrapPointer(houseMap));

}

void getIndex(TreeMap* map, char street[20], char house[20], char building[20])
{
    Value houseValue = get(map, wrapString(street));
    if (isNone(houseValue)) {
        printf("None\n");
        return;
    }
    Value buildingValue = get(houseValue.pointerValue, wrapInt(atoi(house)));
    if (isNone(buildingValue)) {
        printf("None\n");
        return;
    }
    Value indexValue = get(buildingValue.pointerValue, wrapInt(atoi(building)));
    if (isNone(buildingValue)) {
        printf("None\n");
        return;
    }
    printf("%d\n", indexValue.intValue);
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
    char thirdOption[20] = "";
    char fourthOption[20] = "";
    char fifthOption[20] = "";
    char sixthOption[20] = "";
    for (int i = 0; i < logsCount; i++) {
        fscanf(fileInput, "%s %s %s", command, firstOption, secondOption);
        if (strcmp(command, "CREATE") == 0) {
            fscanf(fileInput, "%s %s", thirdOption, fourthOption);
//            printf("%s %s %s %s %s\n", command, firstOption, secondOption, thirdOption, fourthOption);
            create(map, firstOption, secondOption, thirdOption, fourthOption);
        }
        if (strcmp(command, "GET") == 0) {
            fscanf(fileInput, "%s", thirdOption);
//            printf("%s %s %s %s\n", command, firstOption, secondOption, thirdOption);
            getIndex(map, firstOption, secondOption, thirdOption);
        }
//        if (strcmp(command, "RENAME") == 0)
//            printf("%s %s %s\n", command, firstOption, secondOption);
        if (strcmp(command, "DELETE_BLOCK") == 0) {
            fscanf(fileInput, "%s", thirdOption);
//            printf("%s %s %s %s\n", command, firstOption, secondOption, thirdOption);
        }
//        if (strcmp(command, "DELETE_HOUSE") == 0)
//            printf("%s %s %s\n", command, firstOption, secondOption);
        if (strcmp(command, "LIST") == 0) {
            fscanf(fileInput, "%s %s %s %s", thirdOption, fourthOption, fifthOption, sixthOption);
//            printf("%s %s %s %s %s %s %s\n", command, firstOption, secondOption, thirdOption, fourthOption, fifthOption, sixthOption);
        }
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
    SetConsoleOutputCP(CP_UTF8);
    FILE* fileInput = fopen("../streets_logs.txt", "r");
    if (!fileInput) {
        printf("Error handled. Wrong src file path.");
        return 0;
    }
    FILE* resultFileOutput = fopen("../street_res.txt", "w");
    TreeMap* map = createTreeMap(&compare);
    readElementsFromFile(map, fileInput, resultFileOutput);
    deleteTreeMap(map);
    fclose(fileInput);
    fclose(resultFileOutput);
    return 0;
}