#ifndef LIBS

#define LIBS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

#endif

#include "../header/utils.h"
#include "../header/sort.h"


void shell_insertion_sort(int input[], int size, bool verbose){
    int changes;
    
    int h = size/2;

    if (verbose){
        showArray(input, size);
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
            showArray(input, size);
        }
        
        h /= 2;
    }
}


int[] find_ciura_sequence(int size){
    int ciura_sequence[8] = {1, 4, 10, 23, 57, 132, 301, 701};    
    
    // find the maximum h of the sequence given the list size
    // init vars
    int i = 0;
    int h_max = ciura_sequence[i];
    int aux = size/h_max;
    while (aux >= 1){
        i++;
        if (i < 8){
            h_max = ciura_sequence[i];
            aux = size/h_max;
        } else {
            h_max *= 2.25;
            aux = size/h_max;
        }
    }

    // create the ciura sequence using the maximum value
    int ciura_sequence_local[i];
    int j = i;
    i = 0;
    h_max = 0;
    while (j > 0){
        if (i < 8){
            h_max = ciura_sequence[i];
        } else {
            h_max *= 2.25;
        }
        ciura_sequence_local[j] = h_max;
        i++;
        j--;
    }

    return ciura_sequence_local;
}

/* void ciura_sequence_shell_sort(int input[], int size, bool verbose){



    int changes;

    if (verbose)
    {
        showArray(input, size);
    }

    while (gap >= 0) // reduz tamanho h
    { 
        for (int i = h; i < size; i++) { // ordena segmentos
            int chave = input[i];
            int j = i - h;
            while ((j >= 0) && (input[j] > chave))
            {
                input[j + h] = input[j];
                j -= h;
                changes++;
            }
            input[j + h] = chave;
        }
        
        if (verbose){
            printf("After increments of size %d the list is ", h);
            showArray(input, size);
        }
        
        h /= 2;
    }
} */