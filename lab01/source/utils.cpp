#ifndef LIBS

#define LIBS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

#endif

#include "../header/utils.h"

void random_list(int list[], int size){
    for (int i = 0; i < size; i++){
        list[i] = rand();
    }
}

void showArray(int list[], int size){
    printf("[");
    for (int i = 0; i < (size - 1); i++)
    {
        printf("%d, ", list[i]);
    }
    printf("%d]\n", list[size - 1]);
}