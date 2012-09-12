#include "cola.h"
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
//Valores    
int *val0 = 0;
int *val1 = 1;
char *val2 = "Soy una cadena :D";


//Creo la cola
cola_t *cola = cola_crear();

//preubas
print_test("Prueba cola_esta_vacia #0",!cola_esta_vacia(cola);
print_test("Encolo val0 a la cola", cola_encolar(cola, val0);
print_test("Prueba cola_esta_vacia #1",cola_esta_vacia(cola);
print_test("Encolo val1 a la cola", cola_encolar(cola, val1);
print_test("Encolo val2 a la cola", cola_encolar(cola, val2);

int *primero = NULL;
primero = cola_ver_primero(cola);
print_test("Prueba cola_ver_primero", val0 == primero);

//uso la variable "primero" para desencolar tambien
primero = cola_desencolar(cola);
print_test("Prueba cola_desencolar",val0 == primero);
}
/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/
//~ 
//~ /* Programa principal. */
int main(void) {
	//~ /* Ejecuta todas las pruebas unitarias. */
	prueba_cola();
	return 0;
}
