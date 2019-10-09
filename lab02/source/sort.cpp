/*
    LAB 02 - Classificação e Pesquisa de Dados
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
#include <vector>

#endif

#include "../header/utils.h"
#include "../header/sort.h"

using namespace std;



// Shell Sort
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

stack<int> find_ciura_sequence(int size){
    int ciura_sequence[8] = {1, 4, 10, 23, 57, 132, 301, 701};
    stack<int> final_sequence;

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
    stack<int> ciura_sequence = find_ciura_sequence(size);

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


// QuickSort
int partitioner_median_key(vector<int> input, int left, int right){
    int firstValue = input.at(left);
    int medValue = input.at( (left+right)/2 );
    int lastValue = input.at(right);

    int pivot;
    if ( ((firstValue >= medValue) && (firstValue <= lastValue)) ||
            ((firstValue <= medValue) && (firstValue >= lastValue)) ) {
        pivot = left;
    } else if ( ((medValue >= firstValue) && (medValue <= lastValue)) ||
            ((medValue <= firstValue) && (medValue >= lastValue)) ) {
        pivot = (left+right)/2;
    } else {
        pivot = right;
    }
    return pivot;
}

int partitioner_random_key(int left, int right){
    int range = right - left + 1;
    int random_num = rand() % range;

    int pivot = left + random_num;

    return pivot;
}

int partition(vector<int> *input, int left, int right, QuickSortPartitionerType partitionerType, int *swaps) {
    vector<int> v = *input;
    int chave_pos, chave, i, j;

    if (partitionerType == MEDIAN){
        chave_pos = partitioner_median_key(v, left, right);

    } else if (partitionerType == RANDOM){
        chave_pos = partitioner_random_key(left, right);
    }

    swap(v[chave_pos], v[right]);
    (*swaps)++;
    chave = v.at(right);

    i=left;

    for (j = left; j <= (right - 1); j++){
        if (v.at(j) <= chave){
            swap(v[i], v[j]);
            (*swaps)++;
            i++;
        }
    }

    swap(v[i], v[right]);
    (*swaps)++;

    *input = v;
    return i;
}

void quick_sort_recursive(vector<int> *input, int left, int right, QuickSortPartitionerType partitionerType, int *recCalls, int *nSwaps){
    static int recursive_calls = 0;
    static int swaps = 0;

    recursive_calls++;
    int pivot; // índice do pivô
	if (right > left) {
        int swaps_partition = 0;
        pivot = partition(input, left, right, partitionerType, &swaps_partition);
        swaps += swaps_partition;

		quick_sort_recursive(input, left, pivot-1, partitionerType, recCalls, nSwaps);
		quick_sort_recursive(input, pivot+1, right, partitionerType, recCalls, nSwaps);
	}

    *recCalls = recursive_calls;
    *nSwaps = swaps;
}

void quick_sort(vector<int> *input, QuickSortPartitionerType partitionerType, QuickSortStats *stats){
    clock_t begin, end;
    int swaps, recursiveCalls;

    begin = clock();
    quick_sort_recursive(input, 0, (input->size()-1), partitionerType, &recursiveCalls, &swaps);
    end = clock();

    stats->swaps = swaps;
    stats->recursiveCalls = recursiveCalls;
    stats->executionTime = (double(end - begin)) / CLOCKS_PER_SEC;
}
