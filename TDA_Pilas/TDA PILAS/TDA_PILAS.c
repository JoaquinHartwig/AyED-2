#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PILAS.h"

/*  Lista:
podés recorrer
podés insertar al principio
podés insertar al final
podés borrar en cualquier lugar

Pila:
solo trabajás con el TOPE
*/
struct nodo { // Lo mismo q una lista 
    int info;
    struct nodo *sig;
};

typedef struct nodo *tipoPila;

bool esVacia(tipoPila Pila){ //Verifica si la pila es vacia 
    if (Pila == NULL){
        return (true);
    }
    else {
        return (false);
    }
}
void crear (tipoPila *nuevoN){
    *nuevoN = (tipoPila)malloc(sizeof(struct nodo));
    if (esVacia(*nuevoN)) {
        printf("Error: no se pudo asignar memoria\n"); 
        exit(1);
    }
}
void apilar(tipoPila *Pila, int x) { //Es exactamente igual a InsertaralPrincipio
    tipoPila nuevoNodo;
    crear(&nuevoNodo);
    nuevoNodo->info = x;
    nuevoNodo->sig = *Pila;
    *Pila = nuevoNodo;
}
void desapilar(tipoPila *Pila, int *x)  //Es practicamente Sacar Elemento de Listas (con esta funcion se analiza los elementos de la pila )
{
    tipoPila Aux;

    Aux = *Pila;

    *x = Aux->info;

    *Pila = Aux->sig;

    free(Aux);
}
