#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Nodo{
    int dato;
    struct Nodo *siguiente;
} typedef Nodo;

typedef Nodo *PunteroNodo;

void crearLista(PunteroNodo *Lista){
    *Lista = NULL;
}

bool esVacia(PunteroNodo Lista){
    if(Lista == NULL){
        return true;
    }else{
        return false;
    }
}

void NuevoNodo(PunteroNodo *Lista){
    *Lista = (PunteroNodo)malloc(sizeof(Nodo));

    if(esVacia(*Lista)){
        printf("Error al reservar memoria");
        exit(1);
    }
}

bool existeEnLista(PunteroNodo Lista, int valor){

    while(!esVacia(Lista)){

        if(Lista->dato == valor){
            return true;
        }else{
            Lista = Lista->siguiente;
        }
    }

    return false;
}

void Insertar_Principio(PunteroNodo *Lista, int valorDato){

    PunteroNodo nuevoN;

    NuevoNodo(&nuevoN);

    nuevoN->dato = valorDato;
    nuevoN->siguiente = *Lista;

    *Lista = nuevoN;
}

void Insertar_Final(PunteroNodo *Lista, int valorDato){

    PunteroNodo nuevoN;

    NuevoNodo(&nuevoN);

    nuevoN->dato = valorDato;
    nuevoN->siguiente = NULL;

    if(esVacia(*Lista)){

        *Lista = nuevoN;

    }else{

        PunteroNodo auxiliar = *Lista;

        while(!esVacia(auxiliar->siguiente)){
            auxiliar = auxiliar->siguiente;
        }

        auxiliar->siguiente = nuevoN;
    }
}



void eliminarElemento(PunteroNodo *Lista, int valorDato){

    if(existeEnLista(*Lista, valorDato)){

        PunteroNodo auxiliar = *Lista;
        PunteroNodo nodoEliminado;

        if(auxiliar->dato == valorDato){

            nodoEliminado = auxiliar;
            *Lista = nodoEliminado->siguiente;

        }else{

            PunteroNodo anterior = auxiliar;
            auxiliar = auxiliar->siguiente;

            while(auxiliar != NULL &&
                  auxiliar->dato != valorDato){

                anterior = auxiliar;
                auxiliar = auxiliar->siguiente;
            }

            if(auxiliar != NULL){

                nodoEliminado = auxiliar;
                anterior->siguiente = auxiliar->siguiente;
            }
        }

        free(nodoEliminado);

    }else{

        printf("El valor no esta en la lista");
    }
}

void sacarElemento(PunteroNodo *Lista, int *x){

    if(esVacia(*Lista)){
        return;
    }

    PunteroNodo primerNodo = *Lista;

    *Lista = primerNodo->siguiente;

    *x = primerNodo->dato;

    free(primerNodo);
}

void imprimirLista(PunteroNodo Lista){

    while(!esVacia(Lista)){

        printf("%d | ", Lista->dato);

        Lista = Lista->siguiente;
    }

    printf("\n");
}