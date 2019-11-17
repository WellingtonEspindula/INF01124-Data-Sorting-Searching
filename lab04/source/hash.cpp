#ifndef LIBS
#define LIBS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <iomanip>
#include <list>
#include <map> 
#endif

#ifndef HASH
#define HASH
#include "../header/hash.h"
#endif

#ifndef UTILS
#define UTILS
#include "../header/utils.h"
#endif

#define P 127   // 127 is the minor prime number after 122 (max ascii code value).

#define C1 1
#define C2 3


int horner_hash(HashTable table, string s){
    int hash = 0;
    for (int i = 0; i < s.length(); i++){
        hash = ((P * hash + s.at(i)) % table.m);
    }

    return hash;
}

int fibonacci_hash(HashTable table, string s){
    int hash = 0;
    for (int i = 0; i < s.length(); i++){
        hash = ((fibonacci_sequence(i+8) * s.at(i) + hash) % table.m);
    }

    return hash;
}

int string_hash(HashTable table, string s){
    if (table.function_type == HORNER){
        return horner_hash(table, s);
    } else if (table.function_type == FIBONACCI) {
        return fibonacci_hash(table, s);
    } else {
        return -1;
    }
}

HashTable create(int m, HASH_FUNCTION_TYPE function_type, HASH_COLLISION_TREATMENT collision_tratment){
    HashTable new_HashTable;
    new_HashTable.m = m;
    new_HashTable.n = 0;
    new_HashTable.collision_count = 0;
    new_HashTable.function_type = function_type;
    new_HashTable.collision_tratment = collision_tratment;
    new_HashTable.entries = new Entry[m];

    return new_HashTable;
}

bool insert(HashTable* table, string element){
    int hash_code = string_hash(*table, element);

    Entry entry = table->entries[hash_code];
    
    // verify if has some element in the position
    if  (!entry.occupied){
        entry.value = element;
        entry.occupied = true;
    } else {        // If already has element in the position, threat the collision
        
        // Verify if was not a collision, but the name was already occupying the value pos 
        if (entry.value.compare(element) == 0)
            return true;
        

        // CHAINING
        if (table->collision_tratment == CHAINING){
            
            // Verify if the value is already there
            for (string s : entry.aux){
                if (s.compare(element) == 0)
                    return true;
            }

            // if isn't, put it on the vector
            entry.aux.push_back(element);

        // EABQ (Enderecamento aberto com busca quadratica)
        } else if (table->collision_tratment == EABQ){
            for (int i = 1; i < table->m; i++){
                hash_code = (hash_code + (C1*i + C2*i*i)) % (table->m);
                entry = table->entries[hash_code];

                if (!entry.occupied){
                    entry.value = element;
                    entry.occupied = true;
                    break;
                }
                table->collision_count++;   // add one collision to count
            }
        } else {
            return false;
        }
        // count the collision
        table->collision_count++;
    }
    table->entries[hash_code] = entry;
    table->n++;
    return true;
}

int search(HashTable table, string element){
    int hash_code = string_hash(table, element);

    int access_num = 0;

    if (table.entries[hash_code].value.compare(element) == 0){
        return access_num;
    } else {
        // Chaining case
        if (table.collision_tratment == CHAINING){

            // Firstly, we verify if the first value is on the hash table
            access_num++;
            if (table.entries[hash_code].value.compare(element) == 0){
                return access_num;
            }

            // Search throught the aux vector
            list<string> vector = table.entries[hash_code].aux;

            for (string vector_element : vector){
                access_num++;
                if (vector_element.compare(element) == 0){
                    return access_num;
                }
            }
            
            // if it has not found the element in the vector, he will return -1 code
            return -1;
        } else if (table.collision_tratment == EABQ){
            for (int i = 0; i < table.m; i++){
                hash_code = (hash_code + (C1*i + C2*i*i)) % (table.m);
                Entry entry = table.entries[hash_code];

                access_num++;
                if ((entry.occupied) && (entry.value.compare(element) == 0)){
                    return access_num;
                }
            }

            // if it has not found the element in the hashtable, return -1
            return -1;
        } else {
            return -1;
        }
    }
}

bool remove(HashTable* table, string element){
    // TODO
}

float occupation_rate(HashTable table){
    int occupation = 0;
    int table_size = table.m;
    Entry* entries = table.entries;

    for (int i = 0; i < table_size; i++){
        if (entries[i].occupied){
            occupation++;
        }
    }
    return ((float) occupation)/((float) table_size);
}

long occupation(HashTable table){
    int occupation = 0;
    int table_size = table.m;
    Entry* entries = table.entries;

    for (int i = 0; i < table_size; i++){
        if (entries[i].occupied){
            occupation++;
        }
    }

    return occupation;
}

void show(HashTable table){
    printf("-----------HEADER--------\n");
    printf("| m = %d, n = %d, occupation = %d, ccount = %d, occuprate = %.3f |\n", table.m, table.n, occupation(table), table.collision_count, occupation_rate(table));
    printf("-------------------------\n");

    
    Entry* entries = table.entries;

    for (int i = 0; i < table.m; i++){
        list<string> values = entries[i].aux;

        cout << "| " << entries[i].value << ";";
        for (string name : values){
            cout << name << ";";
        }
        cout << " |\n";
    }
    cout << "-------------------------\n";
}