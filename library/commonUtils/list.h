#ifndef SPBU_C_HOMEWORKS_LIST_H
#define SPBU_C_HOMEWORKS_LIST_H
#include <stdbool.h>

typedef struct List List;
typedef struct ListElement ListElement;

List* makeNewList();

void putElement(List* list, int value);
int getListSize(List* list);
int getByIndex(List* list, int index, int defaultValue);
void freeList(List* list);

#endif // SPBU_C_HOMEWORKS_LIST_H
