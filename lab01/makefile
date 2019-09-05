############################# Makefile ##########################
all: lab1
lab1: sort.o main.o 
		# O compilador faz a ligação entre os dois objetos
		g++ -o lab1 Debug/sort.o Debug/main.o -g
sort.o: 
		g++ -o Debug/sort.o -c source/sort.cpp -W -Wall -pedantic -g
main.o:
		g++ -o Debug/main.o -c source/main.cpp -W -Wall -pedantic -g
clean:
		rm -rf *.o
run:	lab1 clean
		./lab1