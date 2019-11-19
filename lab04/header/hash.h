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

/**
 * \brief Enum that identifies the hash function that will be used
 * */
enum HASH_FUNCTION_TYPE { HORNER, FIBONACCI };

/**
 * \brief Enum that identifies the treatment politics
 * */
enum HASH_COLLISION_TREATMENT { CHAINING, EABQ };

/**
 * \brief HashTable entry
 * */
typedef struct Entry {
    string value;         // Entry value
    list<string> aux;     // In the chaining mode, we can have a list of strings
    bool occupied = false; // is occupied
};

/**
 * \brief HashTable
 * */
typedef struct HashTable {
    int m;                  // Table size
    int n;                  // Elements count
    int collision_count;    // Numbers of collisions 
    HASH_FUNCTION_TYPE function_type;
    HASH_COLLISION_TREATMENT collision_treatment;
    Entry* entries;
};

/**
 * \brief Create a new hash table
 * \param m - HashTable's size
 * \param function_type - Hash function that will be used on strings on the HashTable
 * \param collision_tratment - HashTable's collision treatment policy
 * \return Return the new HashTable
 * */
HashTable create(int m, HASH_FUNCTION_TYPE function_type, HASH_COLLISION_TREATMENT collision_tratment);

/**
 * \brief Insert an element into the HashTable
 * \param table - HashTable memory address to be inserted the element
 * \param element - The element (string) to be inserted
 * \return Returns if the insertion was sucessfull
 * */
bool insert(HashTable* table, string element);

/**
 * \brief Search an element through the HashTable
 * \param table - HashTable to be searched through
 * \param element - The element (string) to be searched
 * \return Returns the number of access neccesssary to find the element. 
 * If it was not found, returns -1
 * */
int search(HashTable table, string element);

/**
 * \brief Remove an element from the HashTable
 * \param table - HashTable memory address to remove the element
 * \param element - The element (string) to be removed
 * \return Returns if the deletation was sucessfull
 * */
bool remove(HashTable* table, string element);

/**
 * \brief Calculate the occupation rate on a HashTable 
 * \param table - HashTable to be analyesed
 * \return Returns a number between 0 and 1 that says how much occupied is the HashTable
 * */
float occupancy_rate(HashTable table);

/**
 * \brief Calculate the respective hash code to a string given its HashTable
 * \param table - HashTable
 * \param s - The string to be hashed
 * \return Returns the hash code
 * */
int string_hash(HashTable table, string s);

/**
 * \brief Show a table and its properties
 * \param table - HashTable to be showed
 * */
void show(HashTable table);

/**
 * \brief Show a table's properties
 * \param table - HashTable to be showed
 * */
void show_info(HashTable table);