#!/bin/sh

# Remove residual files
rm -f out.csv output.pdf Rplots.pdf

# Roda os experimentos e cria um arquivo .csv
echo "Algo;N;time;k" > out.csv
for i in $(seq 100 50 1000) ; do 
./lab3 -i $i;
./lab3 -m $i;
./lab3 -h $i 64;
done >> out.csv

# ./lab3 -fi entradas/entrada.txt >> out.csv
# ./lab3 -fm entradas/entrada.txt >> out.csv
# ./lab3 -fh entradas/entrada.txt 7 >> out.csv

# Plota os graficos usando o script R
Rscript plot.R
