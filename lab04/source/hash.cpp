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
#include <map> 
#endif

#ifndef HASH
#define HASH
#include "../header/hash.h"
#endif

#define P 127   // 127 is the minor prime number after 122 (max ascii code value).


int horner_hash(HashTable table, string s){
    int hash = 0;
    for (int i = 0; i < s.length(); i++){
        hash = ((P * hash + s.at(i)) % table.m);
    }

    return hash;
}

int polynomial_hash(HashTable table, string s){
    
}


int string_hash(HashTable table, string s){
    if (table.function_type == HORNER){
        return horner_hash(table, s);
    } else if (table.function_type == POLYNOMIAL) {
        return polynomial_hash(table, s);
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

void insert(HashTable* table, string element){
    int hash_code = string_hash(*table, element);

    Entry entry = table->entries[hash_code];
    
    // verify if has some element in the position
    if  (entry.value.empty()){
        entry.value = element;
        entry.occupied = true;
        entry.used = true;
    } else {        // If already has element in the position, threat the collision
        
        // Verify if was not a collision, but the name was already occupying the value pos 
        if (entry.value.compare(element) == 0)
            return;
        
        if (table->collision_tratment == CHAINING){
            
            // Verify if the value is already there
            for (string s : entry.aux){
                if (s.compare(element) == 0)
                    return;
            }

            // if isn't, put it on the vector
            entry.aux.push_back(element);

        } else if (table->collision_tratment == EABQ){
            // TODO
        } else {
            return;
        }
        // count the collision
        table->collision_count++;
    }
    table->entries[hash_code] = entry;
    table->n++;
}

int search(HashTable table, string element){
    int hash_code = string_hash(table, element);

    int access_num = 0;

    if (table.entries[hash_code].value.compare(element) == 0){
        return access_num;
    } else {
        // Chaining case
        if (table.collision_tratment == CHAINING){
            // Search throught the aux vector
            vector<string> vector = table.entries[hash_code].aux;

            for (string vector_element : vector){
                access_num++;
                if (vector_element.compare(element) == 0){
                    return access_num;
                }
            }
            
            // if it has not found the element in the vector, he will return -1 code
            return -1;
        } else if (table.collision_tratment == EABQ){
            // TODO
            return -1;
        } else {
            return -1;
        }

    }

}

void remove(HashTable* table, string element){

}

long occupation_rate(HashTable table){
    int occupation = 0;
    int table_size = table.m;
    Entry* entries = table.entries;

    for (int i = 0; i < table_size; i++){
        if (entries[i].occupied){
            occupation++;
        }
    }

    return table_size/occupation;
}

void show(HashTable table){
    cout << "-----------HEADER--------\n";
    cout << "| m = " << table.m << "; n = " << table.n << "; occupation rate = " << occupation_rate(table) 
    << " ccount = " << table.collision_count << " |\n";
    cout << "-------------------------\n";
    
    Entry* entries = table.entries;

    for (int i = 0; i < table.m; i++){
        vector<string> values = entries[i].aux;

        cout << "| " << entries[i].value << ";";
        for (string name : values){
            cout << name << ";";
        }
        cout << " |\n";
    }

}