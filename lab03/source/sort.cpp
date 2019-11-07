/*
    LAB 03 - Classificação e Pesquisa de Dados
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
#include <fstream>
#include <stack>
#include <vector>

#endif

#ifndef SORT
#define SORT
#include "../header/sort.h"
#endif

#ifndef UTILS
#define UTILS
#include "../header/utils.h"
#endif

#define N_LETTERS 27
#define ASCII_A_CODE 65
#define MAX_ARRAY_SIZE 1000000

using namespace std;

int binary_search(int vector[], int low, int high, int key) {
    int mid;
    if (low == high)
            return low;
    mid = low + ((high-low)/2);
    if (key > vector[mid])
            return binary_search(vector, mid+1, high, key);
    else if (key < vector[mid])
            return binary_search(vector, low, mid, key);
    return mid;
}

void binary_insertion_sort(int vector[], int size) {
    int i, j, key;
    int ins;
    for (j = 1; j < size; j++) {
        ins = binary_search(vector, 0, j, vector[j]);
        key = vector[j];
        for (int k = (j-1); k >= ins; k--) {
                vector[k+1] = vector[k];
        }
        vector[ins] = key;
    }
}

void insertion_sort(int vector[], int size) {
    int i, j, key;
    for (j=1; j < size; j++) {
            key = vector[j];
            i = j-1;
            while ( (i >= 0) && (vector[i] > key)) {
                    vector[i+1] = vector[i];
                    i--;
            }
            vector[i+1] = key;
    }
}

void insertion_sort(int vector[], int lo, int hi) {
    int i, j, key;
    for (j = lo; j <= hi; j++) {
            key = vector[j];
            i = j-1;
            while ( (i >= lo) && (vector[i] > key)) {
                    vector[i+1] = vector[i];
                    i--;
            }
            vector[i+1] = key;
    }
}
/* void insertion_sort(string vector[], int lo, int hi, int d) {
    int i, j, key;
    for (j = lo; j <= hi; j++) {
            key = vector[j].at(d);
            i = j-1;
            while ( (i >= lo) && (vector[i].at(d) > key)) {
                    vector[i+1] = vector[i];
                    i--;
            }
            vector[i+1] = key;
    }
} */

void merge(int vector[], int aux[], int lo, int mid, int hi) {
    // copy to aux[]
    for (int k = lo; k <= hi; k++) {
        aux[k] = vector[k]; 
    }

    // merge back to a[]
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            vector[k] = aux[j++];
        }
        else if (j > hi) {              
            vector[k] = aux[i++];
        }
        else if (aux[j] < aux[i]) {
            vector[k] = aux[j++];
        }
        else {
            vector[k] = aux[i++];
        }
    }
}

void merge_sort(int vector[], int aux[], int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    merge_sort(vector, aux, lo, mid);
    merge_sort(vector, aux, mid + 1, hi);
    merge(vector, aux, lo, mid, hi);
}

void merge_sort(int vector[], int size) {
    int aux[size];
    merge_sort(vector, aux, 0, size-1);
}

int LEAF_SIZE;
void hybrid_sort(int vector[], int aux[], int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    merge_sort(vector, aux, lo, mid);
    merge_sort(vector, aux, mid + 1, hi);
    
    if ((hi - lo) <= LEAF_SIZE){
        insertion_sort(vector, lo, hi);
    } else {
        merge(vector, aux, lo, mid, hi);
    }
}

void hybrid_sort(int vector[], int size) {
    int aux[size];
    merge_sort(vector, aux, 0, size-1);
}

   
int letters_to_int(string word, int d) {
    if ((d < 0) || (d > word.length())){
        printf("Letters to int exception: Digit out of the bound\n");
    }
    if (d == word.length()) return -1;
    return word.at(d) - (int) 'A';
}

void radix_sort(string vector[], int lo, int hi, int d, string aux[]) {

    // if gets in the last subarray, returns to previous recursion call
    if (hi <= lo) {
        return;
    }

    // calculate frequency count
    int count[N_LETTERS+2] = {0};
    for (int i = lo; i <= hi; i++) {
        int c = letters_to_int(vector[i], d);
        count[c+2]++;
    }

    // summarise
    for (int r = 0; r < N_LETTERS+1; r++){
        count[r+1] += count[r];
    }


    for (int i = lo; i <= hi; i++) {
        int c = letters_to_int(vector[i], d);
        aux[count[c+1]++] = vector[i];
    }

    // copy from auxiliar to main vector
    for (int i = lo; i <= hi; i++){
        vector[i] = aux[i - lo];
    }

    // recursion to each caractere (digit)
    for (int r = 0; r < N_LETTERS; r++)
        radix_sort(vector, lo + count[r], lo + count[r+1] - 1, d+1, aux);
}

string aux[MAX_ARRAY_SIZE];
void radix_sort(string vector[], int size) {
    // string aux[size] = {""};
    if (size > MAX_ARRAY_SIZE){
        printf("Vector out of limit size");
    } else {
        radix_sort(vector, 0, size-1, 0, aux);
    }
}