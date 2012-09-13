#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

typedef struct nodo nodo_t;

struct nodo
{
    void* valor;
    nodo_t* ref;
};

struct cola
{
    nodo_t* prim;
    size_t tamanio;
};


cola_t* cola_crear()
{
    cola_t* cola = malloc(sizeof(cola_t));
    if (cola == NULL) return NULL;
    cola->prim = NULL;
    cola->tamanio = 0;
    return cola;
}

//FUNCION AUXILIAR: creacion de un nodo
//Recibe un valor. Devuelve el nodo.
nodo_t* nodo_crear(void* valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return NULL;
    nodo->valor = valor;
    nodo_t* ref = NULL;
    return nodo;
}

// Destruye la cola. Si se recibe la funciÃ³n destruir_dato por parÃ¡metro,
// para cada uno de los elementos de la cola llama a destruir_dato.
// Pre: la cola fue creada. destruir_dato es una funciÃ³n capaz de destruir
// los datos de la cola, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la cola.
void cola_destruir(cola_t *cola, void destruir_dato(void*))
{
   if (destruir_dato == NULL) free(cola);
    //le paso los nodos a destruir
    void *array[cola->tamanio];
    //Obtengo todas las direcciones de memoria 
    for (int indice = 1; indice < (cola->tamanio)-1; indice++)
    {
        // ESTA INCPLETA!!! RE NCOMPLETA!!
        if (indice == 0)
        {
            array[0] = cola->prim;

        }
        /*array[indice] = *((array[indice]));*/
        cola_desencolar(cola);
        destruir_dato(array[indice]);
    }
}

// Devuelve verdadero o falso, segÃºn si la cola tiene o no elementos encolados.
// Pre: la cola fue creada.
bool cola_esta_vacia(const cola_t *cola)
{
    if(cola->tamanio == 0) return true;
    return false;
}



// Agrega un nuevo elemento a la cola. Devuelve falso en caso de error.
// Pre: la cola fue creada.
// Post: se agregÃ³ un nuevo elemento a la cola, valor se encuentra al final
// de la cola.
bool cola_encolar(cola_t *cola, void* valor)
{
    //Construyo el nuevo nodo que quiero encolar. nuevo_nodo->valor = valor
    // y nuevo_nodo->referencia = NULL porque esta al final de la cola
    nodo_t* nuevo_nodo = nodo_crear(valor);
    nuevo_nodo->referencia = NULL;
    
    //Ubico nuevo_nodo:
    
    //Si la cola está vacía, nuevo_nodo es el primer nodo de la cola
    if (cola->tamanio == 0) cola->prim = nuevo_nodo;
    
    //Sino, debo moverme hasta el final de la cola
    else{
        nodo_t* iterador = nodo_crear(valor); 

        // El ciclo recorre la cola desde el primer nodo hasta el ultimo,
        // cuya referencia es NULL
        while (iterador->ref != NULL){
                iterador->valor = iterador->ref;
                iterador->ref = (iterador->ref)->valor;
            }
    // Se cambia la referencia del ultimo elemento de la cola por la del nuevo_nodo
    iterador->ref = nuevo_nodo;
    
    // Incremento el tamanio
    cola->tamanio += 1;
    }
}


// Obtiene el valor del primer elemento de la cola. Si la cola tiene
// elementos, se devuelve el valor del primero, si estÃ¡ vacÃ­a devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolviÃ³ el primer elemento de la cola, cuando no estÃ¡ vacÃ­a.
void* cola_ver_primero(const cola_t *cola){

    if (cola_esta_vacia(cola)==true) return NULL;

    void* primero = (cola->prim)->valor;

    return primero;
}

// Saca el primer elemento de la cola. Si la cola tiene elementos, se quita el
// primero de la cola, y se devuelve su valor, si estÃ¡ vacÃ­a, devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolviÃ³ el valor del primer elemento anterior, la cola
// contiene un elemento menos, si la cola no estaba vacÃ­a.
void* cola_desencolar(cola_t *cola);
    
    if (cola_esta_vacia(cola) == true) return NULL;
    
    //Guardo el valor a desencolar
    void* desencolado = (cola->prim)->valor;
    // Cambio la referencia de prim. Ahora vale la referencia al segundo nodo.
    cola->prim = (cola->prim)->ref;

    // Destruyo el nodo desencolado? ¿¿??

    // Disminuyo el tamanio
    cola->tamanio -= 1;
    // Devuelvo el valor del desencolado
    return desencolado;
}    



