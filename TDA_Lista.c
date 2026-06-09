

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_LISTA.h"

void crearLista(tipoLista *L){
    *L = NULL;
}

bool esVacia(tipoLista L){// Si el puntero es NULL, la lista está vacía
    if(L == NULL){
        return true;
    }else{
        return false;
    }
}

void nuevoNodo(tipoLista *nuevoN){
    *nuevoN = (tipoLista) malloc(sizeof(Nodo));// Reservamos memoria para un nuevo nodo con malloc,y sizeof se pregunta cuando espacio va ocupar el nodo

    if(esVacia(*nuevoN)){//Utilizamos la función esVacia para verificar si el nodo se creó correctamente, si el puntero es NULL, significa que no se pudo reservar memoria
        printf("Error al reservar memoria\n");
        exit(1);
    }
}

void insertarPrincipio(tipoLista *L, int x){

    tipoLista nuevoN;

    nuevoNodo(&nuevoN);//Creamos un nuevo nodo utilizando la función nuevoNodo, que reserva memoria para el nodo y verifica si se creó correctamente

    nuevoN->info = x;//El nuevo nodo se inicializa con el valor x, asignando x al campo info del nodo
    nuevoN->sig = *L;//Ahora el campo sig del nuevo nodo apunta al nodo que actualmente es el primer nodo de la lista, es decir, el nodo al que apunta *L

    *L = nuevoN;//Hacemos q *L apunte al nuevo nodo, convirtiéndolo en el nuevo primer nodo de la lista. Ahora el nuevo nodo es el primer nodo de la lista y su campo sig apunta al nodo que era el primer nodo antes de la inserción
}

void insertarFinal(tipoLista *L, int x){

    tipoLista nuevoN;
    tipoLista aux;

    nuevoNodo(&nuevoN);

    nuevoN->info = x;
    nuevoN->sig = NULL;

    if(esVacia(*L)){ // Si la lista está vacía, el nuevo nodo se convierte en el primer nodo de la lista
        *L = nuevoN;
    }else{

        aux= *L;//guardamos el primer nodo de la lista en aux para recorrer la lista y encontrar el último nodo

        while(aux->sig != NULL){//recorremos la lista hasta encontrar el último nodo, que es el nodo cuyo campo sig es NULL. Mientras aux->sig no sea NULL, significa que aún no hemos llegado al último nodo, por lo que avanzamos al siguiente nodo asignando aux = aux->sig
            aux = aux->sig;//Esto funciona como el cursor que recorre la lista, avanzando de nodo en nodo hasta llegar al último nodo. Cuando aux->sig es NULL, significa que hemos llegado al último nodo de la lista
        }

        aux->sig = nuevoN;//Aqui se hace la union entre el último nodo de la lista y el nuevo nodo, asignando el nuevo nodo al campo sig del último nodo. Esto agrega el nuevo nodo al final de la lista, ya que ahora el último nodo apunta al nuevo nodo, y el nuevo nodo se convierte en el nuevo último nodo de la lista.
    }
}

void eliminarElemento(tipoLista *L, int x){

    tipoLista actual = *L;
    tipoLista anterior = NULL;

    while(actual != NULL && actual->info != x){

        anterior = actual;
        actual = actual->sig;
    }

    if(actual != NULL){

        if(anterior == NULL){
            *L = actual->sig;
        }else{
            anterior->sig = actual->sig;
        }

        free(actual);
    }else{
        printf("Elemento no encontrado\n");
    }
}

bool buscarElemento(tipoLista L, int x){

    while(L != NULL){

        if(L->info == x){
            return true;
        }

        L = L->sig;
    }

    return false;
}

void imprimirLista(tipoLista L){

    printf("\nLista: ");

    while(L != NULL){

        printf("%d -> ", L->info);

        L = L->sig;
    }

    printf("NULL\n");
}