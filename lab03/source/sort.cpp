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