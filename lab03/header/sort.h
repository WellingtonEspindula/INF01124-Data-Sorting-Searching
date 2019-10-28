/** TODO COMMENTS
 */
extern int LEAF_SIZE;

enum SORT_TYPE { INSERTION, MERGE, HYBRID };

/** \brief Insertion Sort using binary search
 *
 *  \param vector - Input vector to be sorted
 *  \param size - Size of the vector
 */
void binary_insertion_sort(int vector[], int size);

/** \brief Default Insertion Sort
 *
 *  \param vector - Input vector to be sorted
 *  \param size - Size of the vector
 */
void insertion_sort(int vector[], int size);

/** \brief Default Top Down Merge Sort
 *
 *  \param vector - Input vector to be sorted
 *  \param size - Size of the vector
 */
void merge_sort(int vector[], int size);

/** \brief Hybrid Sort is an Top Down Merge sort using, as optimization,
 * Insertion Sort in some sublits
 *
 *  \param vector - Input vector to be sorted
 *  \param size - Size of the vector
 */
void hybrid_sort(int vector[], int size);
