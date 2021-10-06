#include "../library/commonUtils/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sliceArray(const char* array, int indexStart, int indexEnd)
{
    if (indexEnd <= indexStart)
        return "";
    char* newArray = calloc((indexEnd - indexStart + 1), sizeof(char));
    int index = -1;
    for (int i = indexStart; i <= indexEnd; i++) {
        newArray[++index] = array[i];
    }
    return newArray;
}

void delete (LinkedList* list, char start[128], char end[128], char* array)
{
    int indexStartMinusOne = strstr(array, start) - array - 1;
    int indexEndPlusOne = strstr(sliceArray(array, (int)(indexStartMinusOne + strlen(start) + 1), (int)strlen(array) - 1), end) - array + strlen(end) + 1;
    char* result = sliceArray(array, 0, indexStartMinusOne);
    strcat(result, sliceArray(array, indexEndPlusOne, (int)strlen(array) - 1));
    printf("%s\n", result);
    putDna(list, result);
    free(result);
}

void insert(LinkedList* list, char start[128], char fragment[128], char* array)
{
    int indexStart = strstr(array, start) - array + strlen(start) - 1;
    int indexEndPlusOne = indexStart + 1;
    char* result = sliceArray(array, 0, indexStart);
    strcat(result, strcat(fragment, sliceArray(array, indexEndPlusOne, (int)strlen(array) - 1)));
    printf("%s\n", result);
    putDna(list, result);
    free(result);
}

void replace(LinkedList* list, char template[128], char fragment[128], char* array)
{
    int indexStartMinusOne = strstr(array, template) - array - 1;
    int indexEndPlusOne = indexStartMinusOne + strlen(template) + 1;
    char* result = sliceArray(array, 0, indexStartMinusOne);
    strcat(result, strcat(fragment, sliceArray(array, indexEndPlusOne, (int)strlen(array) - 1)));
    printf("Res: %s\n", result);
    putDna(list, result);
    free(result);
}

void readElementsFromFile(LinkedList* list, FILE* fileInput)
{
    int lengthOriginalArray = 0, logsCount = 0;
    fscanf(fileInput, "%d", &lengthOriginalArray);
    char* originalArray = calloc(lengthOriginalArray, sizeof(char));
    fscanf(fileInput, "%s", originalArray);
    fscanf(fileInput, "%d", &logsCount);
    putDna(list, originalArray);
    free(originalArray);
    char command[128] = "", firstArgument[128] = "", secondArgument[128] = "";
    char* array = getDataByIndex(list, getSizeList(list) - 1);
    for (int i = 0; i < logsCount; i++) {
        fscanf(fileInput, "%s %s %s", command, firstArgument, secondArgument);
        printf("%s\n", command);
        if (strcmp(command, "DELETE") == 0)
            delete (list, firstArgument, secondArgument, array);
        if (strcmp(command, "INSERT") == 0)
            insert(list, firstArgument, secondArgument, array);
        if (strcmp(command, "REPLACE") == 0)
            replace(list, firstArgument, secondArgument, array);
        array = getDataByIndex(list, getSizeList(list) - 1);
    }
    free(array);
}

int main()
{
    //    if (argc > 3) {
    //        printf("Error handled. Too much arguments.\n");
    //        return 0;
    //    }
    //    if (argc < 3) {
    //        printf("Error handled. You should enter <Program name> <Src file's path> <Dst file's path>\n");
    //        return 0;
    //    }
    FILE* fileInput = fopen("../dna_logs.txt", "r");
    if (!fileInput) {
        printf("Error handled. Wrong src file path.");
        return 0;
    }

    //    FILE* fileOutput = fopen(argv[2], "w");

    LinkedList* list = makeNewLinkedList();
    readElementsFromFile(list, fileInput);
    //    char* current = getDataByIndex(list, 1);
    //    for (int i = 1; i < getSizeList(list); i++) {
    //        fprintf(fileOutput, "%s\n", current);
    //        current = getDataByIndex(list, i + 1);
    //    }
    freeLinkedList(list);
    fclose(fileInput);
    //    fclose(fileOutput);
    return 0;
}