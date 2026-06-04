

#include <stdio.h>
#include <stdlib.h>
#include "TDA_LISTA.h"

void crearLista(tipoLista *L){
    *L = NULL;
}

bool esVacia(tipoLista L){
    if(L == NULL){
        return true;
    }else{
        return false;
    }
}

void nuevoNodo(tipoLista *nuevoN){
    *nuevoN = (tipoLista) malloc(sizeof(Nodo));

    if(esVacia(*nuevoN)){
        printf("Error al reservar memoria\n");
        exit(1);
    }
}

void insertarPrincipio(tipoLista *L, int x){

    tipoLista nuevoN;

    nuevoNodo(&nuevoN);

    nuevoN->info = x;
    nuevoN->sig = *L;

    *L = nuevoN;
}

void insertarFinal(tipoLista *L, int x){

    tipoLista nuevoN;
    tipoLista auxiliar;

    nuevoNodo(&nuevoN);

    nuevoN->info = x;
    nuevoN->sig = NULL;

    if(esVacia(*L)){
        *L = nuevoN;
    }else{

        auxiliar = *L;

        while(auxiliar->sig != NULL){
            auxiliar = auxiliar->sig;
        }

        auxiliar->sig = nuevoN;
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