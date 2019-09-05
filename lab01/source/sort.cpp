#ifndef LIBS

#define LIBS
#include <cstdio>
#include <cstdlib>

#endif

#include "../header/sort.h"

// AUXILIAR METHODS
void showArray(int list[], int size)
{
    printf("[");
    for (int i = 0; i < (size - 1); i++)
    {
        printf("%d, ", list[i]);
    }
    printf("%d]\n", list[size - 1]);
}


// Sort methods
void shell_insertion_sort(int input[], int size, bool verbose){
    int changes;
    int i, j, chave;
    
    int h = size/2;

    if (verbose)
    {
        showArray(input, size);
    }

    while (h >= 1) // reduz tamanho h
    { 
        for (i = h; i < size; i++) { // ordena segmentos
            chave = input[i];
            j = i - h;
            while ((j >= 0) && input[j] > chave)
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
}

