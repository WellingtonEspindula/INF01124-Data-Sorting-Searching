/*
    LAB 03 - Classificação e Pesquisa de Dados
    Autores: Wellington Espindula e Rafael Trevisan
    Prof. Dr.: João Comba

    No presente trabalho de laboratório de Classificação e Pesq
 */


#ifndef LIBS

#define LIBS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

#endif

#ifndef UTILS
#define UTILS
#include "../header/utils.h"
#endif

using namespace std;


void random_list(int list[], int size){
    for (int i = 0; i < size; i++){
        list[i] = rand() % (size+1);
    }
}

void show_list(int list[], int size){
    printf("[");
    for (int i = 0; i < (size - 1); i++){
        printf("%d, ", list[i]);
    }
    printf("%d]\n", list[size - 1]);
}

void show_list(string list[], int size){
    printf("[");
    for (int i = 0; i < (size - 1); i++){
        cout << list[i] << ", ";
    }
    cout << list[size - 1] << "]\n";
}

int is_sorted(int C[], int tam) {
  for (int i=1; i<tam; i++) {
    if ( C[i-1] > C[i])
      return false;
  }
  return true;
}

// Measures time of of function f_sort
int benchmark(void(*f_sort)(int[] , int ), int input[], int N , char* name){
    clock_t start, end;
    double time = 0;

    if ( N < 100){
       printf("input: ");
       show_list(input,N);
    }

    start = clock();
    f_sort(input,N) ;
    end = clock();

    time = (end - start)/(double)CLOCKS_PER_SEC;

    if (!is_sorted(input,N)){
       fprintf(stderr,"ERROR in %s\n",name);
    }
    else{
       printf("%s;%d;%f\n", name, N , time);
    }

    if ( N < 100){
       printf("output: ");
       show_list(input,N);
    }

    return false;
}