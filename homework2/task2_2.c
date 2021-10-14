#include "../library/commonUtils/linkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOG_COMMAND_ERROR 1

bool sliceArray(const char* array, int indexStart, int indexEnd, char** newArray)
{
    if (indexEnd < indexStart || indexStart < 0 || indexEnd < 0)
        return false;
    *newArray = calloc((indexEnd - indexStart + 1), sizeof(char));
    for (int i = 0; i < indexEnd - indexStart; i++)
        (*newArray)[i] = array[indexStart + i];
    return true;
}

void delete (LinkedList* list, char start[128], char end[128], char* array, int* error)
{
    int indexStart = strstr(array, start) - array;
    int indexEndPlusOne = strstr(strstr(array, start) + strlen(start), end) - array + strlen(end);
    char* result = NULL;
    if (sliceArray(array, 0, indexStart, &result)) {
        char* endPart = NULL;
        if (sliceArray(array, indexEndPlusOne, strlen(array), &endPart)) {
            result = realloc(result, (strlen(result) + strlen(endPart) + 1) * sizeof(char));
            strcat(result, endPart);
            putElement(list, result);
            free(endPart);
        } else
            *error = LOG_COMMAND_ERROR;
        free(result);
    } else
        *error = LOG_COMMAND_ERROR;
}

void insert(LinkedList* list, char* start, char* fragment, char* array, int* error)
{
    int indexStartEnd = strstr(array, start) - array + strlen(start);
    char* result = NULL;
    if (sliceArray(array, 0, indexStartEnd, &result)) {
        result = realloc(result, (strlen(result) + strlen(fragment) + 1) * sizeof(char));
        strcat(result, fragment);
        char* endPart = NULL;
        if (sliceArray(array, indexStartEnd, strlen(array), &endPart)) {
            result = realloc(result, (strlen(result) + strlen(endPart) + 1) * sizeof(char));
            strcat(result, endPart);
            putElement(list, result);
            free(endPart);
        } else
            *error = LOG_COMMAND_ERROR;
        free(result);
    } else
        *error = LOG_COMMAND_ERROR;
}

void replace(LinkedList* list, char* template, char* fragment, char* array, int* error)
{
    int indexStart = strstr(array, template) - array;
    int indexEndPlusOne = indexStart + strlen(template);
    char* result = NULL;
    if (sliceArray(array, 0, indexStart, &result)) {
        result = realloc(result, (strlen(result) + strlen(fragment) + 1) * sizeof(char));
        strcat(result, fragment);
        char* endPart = NULL;
        if (sliceArray(array, indexEndPlusOne, strlen(array), &endPart)) {
            result = realloc(result, (strlen(result) + strlen(endPart) + 1) * sizeof(char));
            strcat(result, endPart);
            putElement(list, result);
            free(endPart);
        } else
            *error = LOG_COMMAND_ERROR;
        free(result);
    } else
        *error = LOG_COMMAND_ERROR;
}

void readElementsFromFile(LinkedList* list, FILE* fileInput, int* error)
{
    int lengthOriginalArray = 0;
    int logsCount = 0;
    fscanf(fileInput, "%d", &lengthOriginalArray);
    char* originalArray = calloc(lengthOriginalArray + 1, sizeof(char));
    fscanf(fileInput, "%s", originalArray);
    fscanf(fileInput, "%d", &logsCount);
    putElement(list, originalArray);
    free(originalArray);
    char command[128] = "", firstArgument[128] = "", secondArgument[128] = "";
    char* array = getElementDataByIndex(list, getSizeList(list) - 1);
    for (int i = 0; i < logsCount; i++) {
        if (*error)
            break;
        fscanf(fileInput, "%s %s %s", command, firstArgument, secondArgument);
        if (strcmp(command, "DELETE") == 0)
            delete (list, firstArgument, secondArgument, array, error);
        if (strcmp(command, "INSERT") == 0)
            insert(list, firstArgument, secondArgument, array, error);
        if (strcmp(command, "REPLACE") == 0)
            replace(list, firstArgument, secondArgument, array, error);
        array = getElementDataByIndex(list, getSizeList(list) - 1);
    }
    free(array);
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

    LinkedList* list = makeNewLinkedList();
    int error = 0;
    readElementsFromFile(list, fileInput, &error);
    if (error) {
        printf("Error handled. Error in a log command.");
        return 0;
    }

    for (int i = 1; i < getSizeList(list); i++) {
        fprintf(fileOutput, "%s\n", getElementDataByIndex(list, i));
    }
    freeLinkedList(list);
    fclose(fileInput);
    fclose(fileOutput);
    return 0;
}