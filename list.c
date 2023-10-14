#include "list.h"
#include <stdio.h>
#include "string.h"

List createList(size_t elementSize)
{
    List list = { elementSize, 0, malloc(elementSize) };
    return list;
}

void appendList(List *list, void* element)
{
    list->numOfElements++;
    list->list = realloc(list->list, list->elementSize * list->numOfElements);
    char* lastElement = (char*)list->list + list->elementSize * (list->numOfElements - 1);
    memcpy_s(lastElement, list->elementSize, element, list->elementSize);
}

void popList(List *list)
{
    if (list->numOfElements == 0)
    {
        fprintf(stderr, "Pop list with 0 elements");
        exit(EXIT_FAILURE);
    }

    list->numOfElements--;
    list->list = realloc(list->list, list->elementSize * list->numOfElements);
}

void removeElementList(List *list, size_t index)
{
    if (list->numOfElements < index + 1)
    {
        fprintf(stderr, "List index is out of bound");
        exit(EXIT_FAILURE);
    }

    list->numOfElements--;
    char* removedElement = (char*)list->list + list->elementSize * index;
    memmove(removedElement, removedElement + list->elementSize, list->elementSize * list->numOfElements);
    list->list = realloc(list->list, list->elementSize * list->numOfElements);
}

void insertElementList(List *list, size_t index, void* element, bool override)
{
    char* insertElement = (char*)list->list + list->elementSize * index;

    if (override == true)
    {
        memcpy_s(insertElement, list->elementSize, element, list->elementSize);
    }
    else
    {
        list->numOfElements++;
        list->list = realloc(list->list, list->elementSize * list->numOfElements);
        memmove(insertElement + list->elementSize, insertElement, list->elementSize * (list->numOfElements - 1));
        memcpy_s(insertElement, list->elementSize, element, list->elementSize);
    }
}