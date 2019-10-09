/*
    LAB 01 - Classificação e Pesquisa de Dados
    Autores: Wellington Espindula e Rafael Trevisan
    Prof. Dr.: João Comba

    No presente trabalho de laboratório de Classificação e Pesquisa de Dados, 
    objetivou-se a implementação do algoritmos de ordenação Shell Sort usando 
    o tamanho de pulos como:
    (i) a implementação original (Shell, 1959)
    (ii) a sequência proposta por Ciura em 2001
    
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