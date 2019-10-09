/** \brief Shell sort default implementation
 *
 * \param input - Input list
 * \param size - size of the list
 * \param verbose - show iterations
 * \param count_time - count execution time and show
 */
void shell_insertion_sort(int input[], int size, bool verbose, bool count_time);

/**
 * \brief Shell sort optimized using Ciura's Sequence. 
 * 
 *  Ciura's sequence was created by Marcin Ciura in
 *  Best Increments for the Average Case of Shellsort paper.
 * 
 * \param input - Input list
 * \param size - size of the list
 * \param verbose - show iterations
 * \param count_time - count execution time and show
 */
void ciura_sequence_shell_sort(int input[], int size, bool verbose, bool count_time);


// QuickSort
typedef struct  
{
    int swaps;
    int recursiveCalls;
    int executionTime;
} QuickSortStats;


enum QuickSortPartitionerType {
    MEDIAN, RANDOM
};


/**
 * \brief Shell sort optimized using Ciura's Sequence. 
 * 
 *  Ciura's sequence was created by Marcin Ciura in
 *  Best Increments for the Average Case of Shellsort paper.
 * 
 * \param input - Input list
//  * \param size - size of the list
 * \param verbose - show iterations
 * \param count_time - count execution time and show
 */
void quick_sort(std::vector<int> *input, QuickSortPartitionerType partitionerType, QuickSortStats *stats);
