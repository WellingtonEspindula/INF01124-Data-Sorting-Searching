using namespace std;

/** \brief Given some array, create a list using random values
 * 
 * \param input - Input list
 * \param size - size of the list
 */
void random_list(int list[], int size);

/** \brief Show list elements
 * 
 * \param input - Input list
 * \param size - size of the list
 */
void show_list(int list[], int size);

void show_list(string list[], int size);

/** \brief Measures time of sort function
 *
 * \param *f_sort - Sort function that will be used 
 * \param input - Input list
 * \param N - size of the list
 * \param name - Function name
*/
int benchmark(void(*f_sort)(int[] , int ), int input[], int N , char* name);

/** \brief Measures time of sort function
 *
 * \param *f_sort - Sort function that will be used 
 * \param input - Input list
 * \param N - size of the list
 * \param name - Function name
*/
double benchmark(void(*f_sort)(string[] , int ), string input[], int N , char* name);

void show_list(string list[], int size);

void show_list(string list[], int l, int h);

int fibonacci_sequence(int n);