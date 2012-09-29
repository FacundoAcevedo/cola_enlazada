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

void (destruir)(void* dato) {
	pila_destruir((pila_t*)dato);

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
//Vectores dinamicos


printf("\n\n ########### COMIENZO DE PRUEBAS ########### \n\n");

//Creo las colas
cola_t *cola_est = cola_crear();
cola_t *cola_pilas = cola_crear();
cola_t *cola_colas = cola_crear();
//~ cola_t *cola_VectDim = cola_crear();



printf("######## Cola con datos estáticos ########\n");
// La cola_est debe estar vacia
print_test("1) Prueba cola_esta_vacia",cola_esta_vacia(cola_est)); //OK
print_test("2) Prueba cola_ver_primero", cola_ver_primero(cola_est)==NULL); //OK

// Encolo val0. La cola_est tiene un elemento.
print_test("3) Encolo val0 a la cola_est", cola_encolar(cola_est, val0)); //OK
// La cola_est no esta vacia
print_test("4) Prueba cola_esta_vacia",!cola_esta_vacia(cola_est)); //OK

//Encolo val1. La cola_est tiene dos elementos.
print_test("5) Encolo val1 a la cola_est", cola_encolar(cola_est, val1)); //OK

//Encolo val2. La cola_est tiene 3 elementos.
print_test("6) Encolo val2 a la cola_est", cola_encolar(cola_est, val2)); //OK
//Chequeo que el primero de la cola_est sea val0.
print_test("7) Prueba cola_ver_primero", cola_ver_primero(cola_est)==val0); //OK

//Desencolo el primer elemento de la cola_est: val0. La cola_est tiene 2 elementos.
print_test("8) Prueba cola_desencolar",val0 == cola_desencolar(cola_est)); //OK

//Chequeo que el priemro de la cola_est sea val1.
print_test("9) Prueba cola_ver_primero", cola_ver_primero(cola_est)==val1);

//Desencolo el segundo elemento de la cola_est: val1. La cola_est tiene 1 elemento.
print_test("10) Prueba cola_desencolar",val1 == cola_desencolar(cola_est)); //OK
print_test("11) Prueba cola_esta_vacia",!cola_esta_vacia(cola_est)); //OK
//Chequeo que el primero de la cola_est sea val2.
print_test("12) Prueba cola_desencolar",cola_ver_primero(cola_est) == val2); //OK

//Desencolo el tercer elemento: val2. La cola_est quedo vacia.
print_test("13) Prueba cola_desencolar",val2 == cola_desencolar(cola_est)); //OK
print_test("14) Prueba cola_esta_vacia", cola_esta_vacia(cola_est));

//Intento desencolar. Como esta vacia, retorna NULL.
print_test("15) Prueba cola_desencolar", cola_desencolar(cola_est) == NULL); //OK

printf("\n\n");



printf("######## Cola con pilas como datos ########\n");
// Encolo pila1 a cola_pilas. La cola_pilas tiene un elemento.
print_test("16) Encolo pila1 a la cola_pilas", cola_encolar(cola_pilas, pila1)); //OK
// La cola_pilas no esta vacia
print_test("17) Prueba cola_esta_vacia",!cola_esta_vacia(cola_pilas)); //OK

// Encolo pila1 de nuevo. La cola_pilas tiene 2 elementos.
print_test("18) Encolo pila1 a la cola_pilas", cola_encolar(cola_pilas, pila1)); //OK

// Encolo pila2. La cola_pilas tiene 3 elementos.
print_test("19) Encolo pila2 a la cola_pilas", cola_encolar(cola_pilas, pila2)); //OK

//Desencolo el primer elemento de la cola_pilas: pila1. La cola_pilas tiene 2 elementos.
print_test("20) Prueba cola_desencolar",pila1 == cola_desencolar(cola_pilas)); //OK

//Desencolo el segundo elemento de la cola_pilas: pila1. La cola_pilas tiene 1 elementos.
print_test("21) Prueba cola_desencolar", pila1 == cola_desencolar(cola_pilas));

//Desencolo el tercer elemento de la cola_pilas: pila2. La cola_pilas queda vacia.
print_test("22) Prueba cola_desencolar", pila2 == cola_desencolar(cola_pilas));
print_test("23) Prueba cola_esta_vacia", cola_esta_vacia(cola_pilas));
// Encolo pila1 de nuevo. La cola_pilas tiene 2 elementos.
print_test("BIS) Encolo pila1 a la cola_pilas", cola_encolar(cola_pilas, pila1)); //OK
print_test("BIS) Encolo pila2 a la cola_pilas", cola_encolar(cola_pilas, pila2)); //OK

printf("\n\n");



printf("######## Cola con colas como datos ########\n");
// Encolo cola_aux a cola_colas. La cola_colas tiene un elemento.
print_test("24) Encolo cola_aux a la cola_colas", cola_encolar(cola_colas, cola_aux)); //OK
// La cola_aux no esta vacia
print_test("25) Prueba cola_esta_vacia",!cola_esta_vacia(cola_colas)); //OK

//Desencolo el primer elemento de la cola_colas: cola_aux. La cola_colas tiene 0 elementos.
print_test("26) Prueba cola_desencolar",cola_aux == cola_desencolar(cola_colas)); //OK
print_test("27) Prueba cola_esta_vacia", cola_esta_vacia(cola_colas));

printf("\n\n");

// Destruyo cola_est
cola_destruir(cola_est, NULL);

// Destruyo cola_aux
cola_destruir(cola_aux, NULL);

// Destruyo cola_colas
cola_destruir(cola_colas, NULL);

// Destruyo cola_pilas
cola_destruir(cola_pilas, (*destruir));


printf("\n\n ########### FIN DE PRUEBAS ########### \n\n");





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
