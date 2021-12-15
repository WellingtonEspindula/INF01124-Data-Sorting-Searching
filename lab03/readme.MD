# Laboratório 3

## 1. Hybrid Sort
Even though the **Merge Sort** algorithm runs has a time complpexity of θ(n lg n) in the worst case scenario and the **Insertion Sort** has θ(n²), in real cases scenarios the Insertion Sort can be faster than Merge Sort to smaller chunks. Hence, the **Hybrid Sort** is an implementation of **Top Down Merge Sort** which applyes Insertion Sort to sort some sublists with *k* length.

### Usage:
* **Compile**:

```bash
make all 
```
* **How to run:** 
```bash
./lab3 [-f file] [-i size] [-m size] [-h size chunkSize]
```
-i means insertion sort
-m means merge sort
-h means hybrid sort

Examples:
```bash
./lab3 -i 100
./lab3 -m 100
./lab3 -h 100 64
./lab3 -f inputfile.txt
./lab3 -fh inputfile.txt 7
```
## 2. Radix Sort
