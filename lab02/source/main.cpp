/*
    LAB 01 - Classificação e Pesquisa de Dados
    Autores: Wellington Espindula e Rafael Trevisan
    Prof. Dr.: João Comba


 */


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

#endif

#include "../header/utils.h"
#include "../header/sort.h"

using namespace std;

// prototypes
vector<vector<int>> readFileToVectors(string fileName);
void writeList(string fileName, vector<vector<int>> list);
void writeStats(string fileName, vector<QuickSortStats> stats);

int main(int argc, char ** argv){
    srand(time(0));
    
    vector<vector<int>> lists;
    
    if (argc >= 1){
        lists = readFileToVectors(argv[1]);
    } else {
        lists = readFileToVectors("entrada.txt");
    }

    vector<vector<int>> ordered_med_lists = vector<vector<int>>();
    vector<vector<int>> ordered_rand_lists = vector<vector<int>>();

    vector<QuickSortStats> med_stats_list;
    vector<QuickSortStats> rand_stats_list;

    for (int i = 0; i < lists.size(); i++){
        vector<int> v_med = lists.at(i);
        QuickSortStats v_med_stats;
        
        vector<int> v_rand = v_med;
        QuickSortStats v_rand_stats;
        
        quick_sort(&v_med, MEDIAN, &v_med_stats);
        quick_sort(&v_rand, RANDOM, &v_rand_stats);

        ordered_med_lists.push_back(v_med);
        med_stats_list.push_back(v_med_stats);

        ordered_rand_lists.push_back(v_rand);
        rand_stats_list.push_back(v_rand_stats);

        printf("Terminou o %dº;\n", (i+1));

    }

    writeList("saida-primeiro.txt", ordered_med_lists);
    writeStats("stats-primeiro.txt", med_stats_list);
    
    writeList("saida-aleatorio.txt", ordered_rand_lists);
    writeStats("stats-aleatorio.txt", rand_stats_list);

    return 0;
}

vector<vector<int>> readFileToVectors(string fileName){
    vector<vector<int>> vectors = vector<vector<int>>();

    ifstream file (fileName);
    if (file.is_open()){
        string nlists;
        getline (file, nlists);

        int numberOfLists = stoi(nlists);

        for (int i = 0; i < numberOfLists; i++){
            string nNum;
            getline(file, nNum, ' ');
            int numberOfNumers = stoi(nNum);

            if (numberOfNumers !=  0){
                vector<int> list = vector<int>();

                string str_number;
                for (int j = 0; j < numberOfNumers - 1; j++){
                    getline(file, str_number, ' ');
                    int number = stoi(str_number);
                    list.push_back(number);
                }
                getline(file, str_number, '\n');
                int number = stoi(str_number);
                list.push_back(number);

                vectors.push_back(list);
            }
        }
        file.close();
    }
    return vectors;
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


void writeStats(string fileName, vector<QuickSortStats> stats){
    ofstream file(fileName);
    if (file.is_open())
    {
        for (int i = 0; i < stats.size(); i++){
            file << "[swaps: " << stats.at(i).swaps << "; recursive calls: " << stats.at(i).recursiveCalls 
                    << "; execution time: " << stats.at(i).executionTime << " s]"<< "\n";
        }
        file.close();
    }
}
