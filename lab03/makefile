############################# Makefile ##########################
all: lab3
lab3: sort.o utils.o main.o 
		# O compilador faz a ligação entre os dois objetos
		g++ -o lab3 Debug/sort.o Debug/utils.o Debug/main.o -g -O3
utils.o: 
		g++ -o Debug/utils.o -c source/utils.cpp -W -Wall -pedantic -g -O3
sort.o: 
		g++ -o Debug/sort.o -c source/sort.cpp -W -Wall -pedantic -g -O3
main.o:
		g++ -o Debug/main.o -c source/main.cpp -W -Wall -pedantic -g -O3
clean:
		rm Debug/*.o
run:	lab3 clean
		./lab3