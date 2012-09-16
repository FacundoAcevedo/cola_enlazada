#include "cola.h"
#include "pila.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/* ******************************************************************
 *                        PRUEBAS UNITARIAS 
 * *****************************************************************/

/* Función auxiliar para imprimir si estuvo OK o no. */
void print_test(char* name, bool result) {
	printf("%s: %s\n", name, result? "OK" : "ERROR");
}

void prueba_cola(void){
// DATOS ESTATICOS    
int cero = 0;
int uno = 1;
int *val0 ;
val0 = &cero;
int *val1;
val1 = &uno; 
char *val2 = "Sexy Chambelan";

//DATOS DINAMICOS
// Pilas
pila_t* pila1 = pila_crear();
pila_apilar(pila1, val0);
pila_apilar(pila1, val1);
pila_apilar(pila1, val2);
pila_t* pila2 = pila_crear();
// Cola
cola_t* cola_aux = cola_crear();
cola_encolar(cola_aux, val1);
cola_encolar(cola_aux, val2);
cola_encolar(cola_aux, val1);
cola_encolar(cola_aux, val0);
cola_encolar(cola_aux, val2);

//Creo la cola
cola_t *cola = cola_crear();

// La cola debe estar vacia
print_test("1) Prueba cola_esta_vacia #0",cola_esta_vacia(cola)); //OK
print_test("2) Prueba cola_ver_primero", cola_ver_primero(cola)==NULL); //OK

// Encolo val0. La cola tiene un elemento.
print_test("3) Encolo val0 a la cola", cola_encolar(cola, val0)); //OK
// La cola no esta vacia
print_test("4) Prueba cola_esta_vacia #1",!cola_esta_vacia(cola)); //OK

//Encolo val1. La cola tiene dos elementos.
print_test("5) Encolo val1 a la cola", cola_encolar(cola, val1)); //OK

//Encolo val2. La cola tiene 3 elementos.
print_test("6) Encolo val2 a la cola", cola_encolar(cola, val2)); //OK
//Chequeo que el primero de la cola sea val0.
print_test("7) Prueba cola_ver_primero", cola_ver_primero(cola)==val0); //OK

//Desencolo el primer elemento de la cola: val0. La cola tiene 2 elementos.
print_test("8) Prueba cola_desencolar1",val0 == cola_desencolar(cola)); //OK

//Chequeo que el priemro de la cola sea val1.
print_test("9) Prueba cola_ver_primero", cola_ver_primero(cola)==val1);

//Desencolo el segundo elemento de la cola: val1. La cola tiene 1 elemento.
print_test("10) Prueba cola_desencolar2",val1 == cola_desencolar(cola)); //OK
print_test("11) Prueba cola_esta_vacia #2",!cola_esta_vacia(cola)); //OK
//Chequeo que el primero de la cola sea val2.
print_test("12) Prueba cola_desencolar2",cola_ver_primero(cola) == val2); //OK

//Desencolo el tercer elemento: val2. La cola quedo vacia.
print_test("13) Prueba cola_desencolar3",val2 == cola_desencolar(cola)); //OK
print_test("14) Prueba cola_esta_vacia#3", cola_esta_vacia(cola));

//Intento desencolar. Como esta vacia, retorna NULL.
print_test("15) Prueba cola_desencolar4", cola_desencolar(cola) == NULL); //OK

// Encolo pila1. La cola tiene un elemento.
print_test("16) Encolo pila1 a la cola", cola_encolar(cola, pila1)); //OK
// La cola no esta vacia
print_test("17) Prueba cola_esta_vacia #4",!cola_esta_vacia(cola)); //OK

// Encolo cola_aux. La cola tiene 2 elementos.
print_test("18) Encolo cola_aux a la cola", cola_encolar(cola, cola_aux)); //OK

// Encolo pila2. La cola tiene 3 elementos.
print_test("19) Encolo pila2 a la cola", cola_encolar(cola, pila2)); //OK

//Desencolo el primer elemento de la cola: pila1. La cola tiene 2 elementos.
print_test("20) Prueba cola_desencolar5",pila1 == cola_desencolar(cola)); //OK

//Desencolo el segundo elemento de la cola: cola_aux. La cola tiene 1 elementos.
print_test("21) Prueba cola_desencolar6", cola_aux == cola_desencolar(cola));

//Desencolo el tercer elemento de la cola: pila2. La cola queda vacia.
print_test("22) Prueba cola_desencolar7", pila2 == cola_desencolar(cola));
print_test("23) Prueba cola_esta_vacia #5", cola_esta_vacia(cola));






	return;
}
//~ /* ******************************************************************
 //~ *                        PROGRAMA PRINCIPAL
 //~ * *****************************************************************/

/* Programa principal. */
int main(void) {
	//~ /* Ejecuta todas las pruebas unitarias. */
	prueba_cola();
	return 0;
}
