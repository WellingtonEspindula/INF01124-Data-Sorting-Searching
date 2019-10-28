# Laboratório 3

## 1. Hybrid Sort
Although the **Merge Sort** algorithm runs on time θ(n lg n) in the worst case and the **Insertion Sort** runs on θ(n²) in the worst case, in reallity the constants involved can make Insertion Sort faster than Merge Sort to smaller problems. Hence, the **Hybrid Sort** is a implementation of **Top Down Merge Sort** that applyes Insertion Sort to sort some sublists with *k* length.

### Usage:
* **Compile**:

```bash
make all 
```
* **How to run:** 
```bash
./lab3 -[f/i/m/g] 
```
Examples:
```bash
./lab3 -i 100
./lab3 -m 100
./lab3 -h 100 64
./lab3 -f inputfile.txt
./lab3 -fh inputfile.txt 7
```
## 2. Radix Sort