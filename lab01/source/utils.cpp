/*
    LAB 01 - Classificação e Pesquisa de Dados
    Autores: Wellington Espindula e Rafael Trevisan
    Prof. Dr.: João Comba


 */


#ifndef LIBS

#define LIBS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stack>

#endif

#include "../header/utils.h"

void random_list(int list[], int size){
    for (int i = 0; i < size; i++){
        list[i] = rand();
    }
}

void show_list(int list[], int size){
    printf("[");
    for (int i = 0; i < (size - 1); i++)
    {
        printf("%d, ", list[i]);
    }
    printf("%d]\n", list[size - 1]);
}