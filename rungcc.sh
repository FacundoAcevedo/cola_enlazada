#!/bin/bash
#genero los .o

gcc -Wall -g -pedantic -std=c99 -c pila.c
gcc -Wall -g -pedantic -std=c99 -c cola.c


#genero el ejecutable prueba_pila.bin
gcc -Wall -g -pedantic -std=c99 cola.o pila.o prueba_cola.c -o prueba_cola.bin

