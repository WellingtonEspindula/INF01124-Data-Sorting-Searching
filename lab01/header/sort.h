/** \brief Shell sort default implementation
 * \param input - 
 * \param size - size of vector
 * \param verbose - 
 */
void shell_insertion_sort(int input[], int size, bool verbose);

/**
 * \brief Shell sort optimized using Ciura's Sequence. 
 * \description Ciura's sequence was created by Marcin Ciura in
 *  Best Increments for the Average Case of Shellsort paper.
 * 
 * \param
 * \param
 * \param
 */
void ciura_sequence_shell_sort(int input[], int size, bool verbose);

int[] find_ciura_sequence(int size);