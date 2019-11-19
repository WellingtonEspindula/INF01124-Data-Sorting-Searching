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

#ifndef UTILS
#define UTILS
#include "../header/utils.h"
#endif

#ifndef HASH
#define HASH
#include "../header/hash.h"
#endif

#define M_CHAINING 2477
#define M_EABQ 20123

using namespace std;

// prototypes
vector<vector<int>> readFileToVectors(string fileName);
vector<string> readFileToStringVector(string fileName);
void writeList(string fileName, vector<vector<int>> list);
void writeList(string fileName, vector<string> list);
void writeStats(string fileName, vector<string> strings, double time);


int main(int argc, char ** argv){
    if (argc < 3){
        printf("Missing arguments.\n Ex.: ./lab4 insert_list.txt search_list.txt\n");
        return EXIT_FAILURE;
    }

    vector<string> names = readFileToStringVector(argv[1]);
    vector<string> search_names = readFileToStringVector(argv[2]);

    // 1.1
    // 1.1.1 - Chaning and Horner
    HashTable table1 = create(M_CHAINING, HORNER, CHAINING);
    // reading name files
    for (string name : names){
        insert(&table1, name);
    }
    printf("TABLE 1:\n");
    show_info(table1);
    printf("\n");

    // 1.1.2 - Chaning and Fibonacci
    HashTable table2 = create(M_CHAINING, FIBONACCI, CHAINING);
    for (string name : names){
        insert(&table2, name);
    }
    printf("TABLE 2:\n");
    show_info(table2);
    printf("\n");

    // 1.1.3 - Quadratic probing and Horner
    HashTable table3 = create(M_EABQ, HORNER, EABQ);
    for (string name : names){
        insert(&table3, name);
    }
    printf("TABLE 3:\n");
    show_info(table3);
    printf("\n");

    // 1.1.4 - Quadratic probing and Fibonacci
    HashTable table4 = create(M_EABQ, FIBONACCI, EABQ);
    for (string name : names){
        insert(&table4, name);
    }
    printf("TABLE 4:\n");
    show_info(table4);
    printf("\n");


    // 1.2
    // for (int i = 0; i < search_names.size(); i++){
    //     string name = search_names.at(i);
    //     cout << i << ". " << name << ": " << search(table2, name) << endl;
    // }
    // show_list(&names[0], names.size());

    return 0;
}


vector<string> readFileToStringVector(string fileName){
    vector<string> string_vector = vector<string>();

    ifstream file (fileName);
    if (file.is_open()){
        string word;

        while(!file.eof()) { 
            getline(file, word);
            string_vector.push_back(word);
        }

        file.close();
    }
    return string_vector;
} 

void writeList(string fileName, vector<vector<int>> list){
    ofstream file (fileName);
    if (file.is_open())
    {
        file << list.size() << "\n";
        for (int i = 0; i < list.size(); i++){
            file << list.at(i).size() << " ";
            for (int j = 0; j < (list.at(i).size() - 1); j++){
                file << list.at(i).at(j) << " ";
            }
            file << list.at(i).back() << "\n";
        }      
        file.close();
    }
}

void writeList(string fileName, vector<string> list){
    ofstream file (fileName);
    if (file.is_open())
    {
        for (int i = 0; i < (list.size() - 1); i++){
            file << list.at(i) << " ";
        }      
        file << list.back() << "\n";
        file.close();
    }
}

void writeStats(string fileName, vector<string> strings, double time){
    ofstream file (fileName);
    if (file.is_open())
    {
        file << "Foram ordenadas " << strings.size() << " palavras em " << time << " segundos\n";
        
        string stringAtual = "";
        int countStringAtual = 0;
        for (string element : strings){
            if (element != stringAtual){
                if (!stringAtual.empty()){
                    file << countStringAtual << "\n";
                }
                stringAtual = element;
                file << "ocorrencias de " << stringAtual << ": ";
                countStringAtual = 1;
            } else {
                countStringAtual++;
            }
        }
        file << countStringAtual << "\n";
        file.close();
    }
}
