objetos = dados.o KMP.o forcaBruta.o main.o

main: $(objetos)
	gcc $(objetos) -o main

dados.o: dados.c dados.h
	gcc -c dados.c
	
forcaBruta.o: forcaBruta.c dados.h
	gcc -c forcaBruta.c

KMP.o: KMP.c KMP.h
	gcc -c KMP.c

main.o: main.c dados.h
	gcc -c main.c

run1: 
	./main entrada.txt 1

run2: 
	./main entrada.txt 2

run3: 
	./main entrada.txt 3

run4: 
	./main entrada.txt 4

clean:
	rm -rf dados.o forcaBruta.o KMP.o main.o main
