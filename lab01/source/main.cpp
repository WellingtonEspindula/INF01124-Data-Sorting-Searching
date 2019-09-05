#ifndef LIBS

#define LIBS
#include <cstdio>
#include <cstdlib>

#endif

#include <ctime>
#include <iostream>
#include "../header/sort.h"


int main(){
    int test1_shellsort_size = 9;
    int test1_shellsort[test1_shellsort_size] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    shell_insertion_sort(test1_shellsort, test1_shellsort_size, true);

    int test2_shellsort_size = 15;
    int test2_shellsort[test2_shellsort_size] = {733, 77, 611, 51, 496, 990, 61, 175, 127, 794, 794, 76, 197, 141, 863};
    shell_insertion_sort(test2_shellsort, test2_shellsort_size, true);

    int test3_shellsort_size = 20;
    int test3_shellsort[test3_shellsort_size] = {872, 424, 729, 573, 877, 696, 321, 758, 949, 217, 767, 238, 562, 175, 999, 12, 380, 406, 225, 995};
    shell_insertion_sort(test3_shellsort, test3_shellsort_size, true);


    return 0;
}
