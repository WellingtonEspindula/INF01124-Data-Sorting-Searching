using namespace std;

enum HASH_FUNCTION_TYPE { HORNER, POLYNOMIAL };
enum HASH_COLLISION_TREATMENT { CHAINING, EABQ };

typedef struct Entry {
    string value;
    vector<string> aux;     // In the chaining mode, we can have a list of strings
    bool used;
    bool occupied;
};

typedef struct HashTable {
    int m;                  // Table size
    int n;                  // Elements count
    int collision_count;    // Numbers of collisions 
    HASH_FUNCTION_TYPE function_type;
    HASH_COLLISION_TREATMENT collision_tratment;
    Entry* entries;
};

HashTable create(int m, HASH_FUNCTION_TYPE function_type, HASH_COLLISION_TREATMENT collision_tratment);

void insert(HashTable* table, string element);

int search(HashTable table, string element);

void remove(HashTable* table, string element);

long occupation_rate(HashTable table);

int string_hash(string s);

void show(HashTable table);