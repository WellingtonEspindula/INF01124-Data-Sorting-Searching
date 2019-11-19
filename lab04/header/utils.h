/*
LAB 04: Tabelas Hash

AUTORES: Rafael Trevisan (rafael.trevisan@inf.ufrgs.br) e Wellington Espindula (wmespindula@inf.ufrgs.br)

DESCRIÇÃO: A atividade desenvolvida baseia-se na implementação de tabelas hash para armazenar
nomes em uma lista de contatos. Para essa atividade foram implementadas duas funções de hash
distintas e também dois métodos de resolução de conflitos. Foi implementada, também, uma função
de pesquisa para encontrar nomes nessa tabela ,que retorna “-1” ao não encontrar o nome ou um
número “N” > 0, que corresponde ao número de acessos necessário para encontrar o nome na tabela.
*/

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

/** \brief Show list of strings
 * 
 * \param input - Input list
 * \param size - size of the list
 */
void show_list(string list[], int size);

/** \brief Show list of strings between some interval (low - high)
 * 
 * \param input - Input list
 * \param l - lower element in the list
 * \param h - higger element in the list
 */
void show_list(string list[], int l, int h);

/** \brief Measures time of sort function
 *
 * \param f_sort - Sort function that will be used 
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

/** \brief Calculate the Fibonacci number given a entry
 *
 * \param n - The nth element in the Fibonacci Sequence
 * \return The Fibonnacci number to n
*/
int fibonacci_sequence(int n);