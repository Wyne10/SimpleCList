#include <stdio.h>
#include "list.h"

int main()
{
    int testValue = 42;
    int testValue2 = 50;
    int testValue3 = 60;
    int testValue4 = 70;
    List list = createList(sizeof(int));
    appendList(&list, &testValue);
    appendList(&list, &testValue2);
    appendList(&list, &testValue3);
    appendList(&list, &testValue4);
    printf("Value 1 = %i \n", ((int*)list.list)[0]);
    printf("Value 2 = %i \n", ((int*)list.list)[1]);
    printf("Value 3 = %i \n", ((int*)list.list)[2]);
    printf("Value 4 = %i \n", ((int*)list.list)[3]);
    insertElementList(&list, 1, &testValue, false);
    printf("Value 1 = %i \n", ((int*)list.list)[0]);
    printf("Value 2 = %i \n", ((int*)list.list)[1]);
    printf("Value 3 = %i \n", ((int*)list.list)[2]);
    printf("Value 4 = %i \n", ((int*)list.list)[3]);
    printf("Value 5 = %i \n", ((int*)list.list)[4]);
    free(list.list);
    return 0;
}