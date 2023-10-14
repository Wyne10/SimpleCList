#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    size_t elementSize;
    size_t numOfElements;
    void* list;
} List;

List createList(size_t elementSize);

void appendList(List *list, void* element);

void popList(List *list);

void removeElementList(List *list, size_t index);

void insertElementList(List *list, size_t index, void* element, bool override);

#endif