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

#ifndef SORT
#define SORT
#include "../header/sort.h"
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
    HashTable table1 = create(M_EABQ, FIBONACCI, EABQ);
    
    // reading name files
    vector<string> names = readFileToStringVector(argv[1]);
    for (string name : names){
        insert(&table1, name);
    }
    // show(table1);

    vector<string> search_names = readFileToStringVector(argv[2]);
    for (string name : search_names){
        cout << "1. " << name << ": " << search(table1, name) << endl;
    }
    // show_list(&names[0], names.size());


// DEPRECATED CODE FROM LAB3
//     // Init rand
//     srand(time(0));


//     // Get arguments from input
//     if (argc < 3){
//         printf("Missing parameters\n");
//         return EXIT_FAILURE;
//     }

//     // Parameters from the input
//     bool isFileSort = false;
//     SORT_TYPE sort_type = HYBRID;
//     int sequence_length;

//     // it will be used only if entry is from a file
//     vector<vector<int>> lists = vector<vector<int>>();

//     int program_number = 0;

//     // verifies if has a flag'
//     if (argv[1][0] == '-'){

//         // checks if the selected program is 1 or 2
//         program_number = argv[1][1] - '0';
//         if ((program_number != 1) && (program_number != 2)){
//             printf("Wrong parameters\n");
//             return EXIT_FAILURE;
//         }
//     } else {
//         printf("Missing parameters\n");
//         return EXIT_FAILURE;
//     }

//     if (program_number == 1){
//         // verifies if has a flag
//         if (argv[2][0] == '-'){
//             string flag = argv[2];

//             // verifies the flag f that means it will sort a file
//             isFileSort = (flag.find("f") != string::npos);
            
//             // Verifies if has the sort_type flags 
//             if (flag.find("i") != string::npos){
//                 sort_type = INSERTION;
//             } else if (flag.find("m") != string::npos){
//                 sort_type = MERGE;
//             } else if (flag.find("h") != string::npos){
//                 sort_type = HYBRID;
//             }

//             if (isFileSort){
//                 lists = readFileToVectors(argv[3]);
//             } else {
//                 sequence_length = atoi(argv[3]);
//             }
            
//             // If has a flag and the sort_type is HYBRID, 
//             // the LEAF_SIZE has to be the 3º argument
//             if (sort_type == HYBRID){
//                 if (argc < 5){
//                     printf("Missing parameters\n");
//                     return EXIT_FAILURE;
//                 } else {
//                     LEAF_SIZE = atoi(argv[4]);
//                 }
//             }

//         // If hasn't a flag, use default value for sort_type
//         } else {
//             sequence_length = atoi(argv[1]);
//             LEAF_SIZE = atoi(argv[2]);
//         }

//         if (isFileSort){
//             vector<vector<int>> ordered_lists = vector<vector<int>>();
//             for (int i = 0; i < lists.size(); i++){
//                 vector<int> vector = lists.at(i);
//                 switch (sort_type){
//                     case INSERTION:
//                         benchmark(insertion_sort, &vector[0], vector.size(), "InsertionSort");
//                         break;
//                     case MERGE:
//                         benchmark(merge_sort, &vector[0], vector.size(), "MergeSort");
//                         break;
//                     case HYBRID:
//                         benchmark(hybrid_sort, &vector[0], vector.size(), "HybridSort");
//                         break;
//                     default:
//                         printf("A problem ocurred in sort type selction\n");
//                         break;
//                 }
//                 ordered_lists.push_back(vector);
//             }
//             writeList("saida.txt", ordered_lists);

//         } else {
//             int vector[sequence_length];
//             random_list(vector, sequence_length);

//             switch (sort_type){
//                 case INSERTION:
//                     benchmark(insertion_sort, vector, sequence_length, "InsertionSort");
//                     break;
//                 case MERGE:
//                     benchmark(merge_sort, vector, sequence_length, "MergeSort");
//                     break;
//                 case HYBRID:
//                     benchmark(hybrid_sort, vector, sequence_length, "HybridSort");
//                     break;
//                 default:
//                     printf("A problem ocurred in sort type selction\n");
//                     break;
//             }
//         }
//     } else if (program_number == 2){
//         if (argc < 3){
//             printf("Missing parameters\n");
//             return EXIT_FAILURE;
//         } else {
//             string filename = argv[2];

//             // generate output name
//             int position_of_point = filename.find('.');
//             string outputname = filename.substr(0, filename.find('.'));
//             outputname.append("_ordered.txt");
//             string outputstats = filename.substr(0, filename.find('.'));
//             outputstats.append("_stats.txt");

//             vector<string> strings = readFileToStringVector(filename);
            
// /*             map<string, int> ocurrences = map<string, int>();
//             for (string element: strings){
//                 if (ocurrences.find(element) == ocurrences.end()){
//                     ocurrences.insert({element, 0});
//                 } else {
//                     ocurrences.({element, 0});
//                 }
//             } */

//             double time = benchmark(radix_sort, &strings[0], strings.size(), "radix_sort");
//             if (time > 0){
//                 writeList(outputname, strings);
//                 writeStats(outputstats, strings, time);
//             }
//         }
//     }


//         // TEST LIMITS
// /*     for (int i = 1; i <= 100; i++){
//         vector<int> list = vector<int>();

//         for (int j = (i-1); j >= 0; j--){
//             list.push_back(j);
//         }

//         // show_list(&list[0], list.size());
//         clock_t start = clock();
//         merge_sort(&list[0], list.size());
//         clock_t end = clock();

//         double time = (end - start)/(double)CLOCKS_PER_SEC;
//         printf("%d;%d;%f\n", i+1, list.size(), time);
//     } */

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

vector<string> readFileToStringVector(string fileName){
    vector<string> string_vector = vector<string>();

    ifstream file (fileName);
    if (file.is_open()){
        string word, word2;
        string whole_word;

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
