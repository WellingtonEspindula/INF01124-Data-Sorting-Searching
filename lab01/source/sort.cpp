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
#include "../header/sort.h"


void shell_insertion_sort(int input[], int size, bool verbose, bool count_time){
    clock_t begin, end;
    if (count_time){
        begin = clock();
    }
    
    int changes;
    int h = size/2;

    if (verbose){
        show_list(input, size);
    }

    while (h >= 1) {                                        // Reduce gap size
        for (int i = h; i < size; i++) {                    // Initialize index i with the gap value
                                                            // and runs looking for the actual key position
            int chave = input[i];                           // Get key value
            int j = i - h;                      
            while ((j >= 0) && (input[j] > chave)) {
                input[j + h] = input[j];
                j -= h;
                changes++;
            }
            input[j + h] = chave;
        }
        
        if (verbose){
            printf("After increments of size %d the list is ", h);
            show_list(input, size);
        }
        
        h /= 2;
    }

    if (count_time){
        end = clock();
        double delta_t = (double(end - begin)) / CLOCKS_PER_SEC;
        printf("Time elapsed: %f\n", delta_t);
    }        
}

std::stack<int> find_ciura_sequence(int size){
    int ciura_sequence[8] = {1, 4, 10, 23, 57, 132, 301, 701};
    std::stack<int> final_sequence;
    
    // find the maximum h of the sequence given the list size
    // init vars
    int i = 0;
    int h = ciura_sequence[i];
    while ((size/h) > 1){
        if (i < 8){
            h = ciura_sequence[i];
        } else {
            h *= 2.25;
        }
        i++;
        // printf("[i = %d] [h = %d]\n", i, h);
        final_sequence.push(h);
    }

    return final_sequence;
}


void ciura_sequence_shell_sort(int input[], int size, bool verbose, bool count_time){
    clock_t begin, end;
    if (count_time){
        begin = clock();
    }

    // Find gap values from Ciura's sequence for this array size
    std::stack<int> ciura_sequence = find_ciura_sequence(size);
    
    int changes;
    int h;

    if (verbose){
        show_list(input, size);
    }

    while (!ciura_sequence.empty()) {
        h = ciura_sequence.top();                           // gets the actual gap
        ciura_sequence.pop();                               // removes it from stack

        for (int i = h; i < size; i++) {

            int chave = input[i];
            int j = i - h;
            while ((j >= 0) && (input[j] > chave)) {
                input[j + h] = input[j];
                j -= h;
                changes++;
            }
            input[j + h] = chave;
        }
        
        if (verbose){
            printf("After increments of size %d the list is ", h);
            show_list(input, size);
        }
        
    }
    
    if (count_time){
        end = clock();
        double delta_t = (double(end - begin)) / CLOCKS_PER_SEC;
        printf("Time elapsed: %f\n", delta_t);
    }
}