/*
LAB 04: Tabelas Hash

AUTORES: Rafael Trevisan (rafael.trevisan@inf.ufrgs.br) e Wellington Espindula (wmespindula@inf.ufrgs.br)

DESCRIÇÃO: A atividade desenvolvida baseia-se na implementação de tabelas hash para armazenar
nomes em uma lista de contatos. Para essa atividade foram implementadas duas funções de hash
distintas e também dois métodos de resolução de conflitos. Foi implementada, também, uma função
de pesquisa para encontrar nomes nessa tabela ,que retorna “-1” ao não encontrar o nome ou um
número “N” > 0, que corresponde ao número de acessos necessário para encontrar o nome na tabela.
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
#include <iomanip>
#include <list>
#include <map> 
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

void show_list(string list[], int l, int h){
    printf("[");
    for (int i = l; i < (h); i++){
        cout << list[i] << ", ";
    }
    cout << list[h] << "]\n";
}

int is_sorted(int C[], int tam) {
  for (int i=1; i<tam; i++) {
    if ( C[i-1] > C[i])
      return false;
  }
  return true;
}

bool is_sorted(string C[], int tam) {
  for (int i=1; i<tam; i++) {
    if ( C[i-1].compare(C[i]) < 0)
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


// Measures time of of function f_sort
double benchmark(void(*f_sort)(string[] , int), string input[], int N , char* name){
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

/*     if (!is_sorted(input,N)){
       fprintf(stderr,"ERROR in %s\n",name);
       return -1;
    } */
/*     else{
       printf("%s;%d;%f\n", name, N, time);
    } */

    if ( N < 100){
       printf("output: ");
       show_list(input,N);
    }

    return time;
}

int fibonacci_sequence(int n) { 
    if (n <= 1) 
        return n; 
    return fibonacci_sequence(n-1) + fibonacci_sequence(n-2); 
} 
