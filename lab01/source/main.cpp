#ifndef LIBS

#define LIBS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

#endif

#include "../header/utils.h"
#include "../header/sort.h"

int main(){
    srand(time(0));

    int test1_shellsort_size = 9;
    int test1_shellsort[test1_shellsort_size] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    shell_insertion_sort(test1_shellsort, test1_shellsort_size, true);
    printf("\n");

    int test2_shellsort_size = 15;
    int test2_shellsort[test2_shellsort_size] = {733, 77, 611, 51, 496, 990, 61, 175, 127, 794, 794, 76, 197, 141, 863};
    shell_insertion_sort(test2_shellsort, test2_shellsort_size, true);
    printf("\n");


    int test3_shellsort_size = 20;
    int test3_shellsort[test3_shellsort_size] = {872, 424, 729, 573, 877, 696, 321, 758, 949, 217, 767, 238, 562, 175, 999, 12, 380, 406, 225, 995};
    shell_insertion_sort(test3_shellsort, test3_shellsort_size, true);
    printf("\n");

    int size1 = 20;
    int random_list1[size1];
    random_list(random_list1, size1);
    // showArray(random_list1, size1);

    int size2 = 30;
    int random_list2[size2];
    random_list(random_list2, size2);
    // showArray(random_list2, size2);

    int size = 1000;
    int *ciura_sequence = find_ciura_sequence(size);
    // printf("\n\n%d\n", ciura_sequence[0]);
    // printf("%d\n", ciura_sequence[1]);
    // showArray(ciura_sequence, 8);

    return 0;
}