

#ifndef TDA_LISTA_H
#define TDA_LISTA_H

#include <stdbool.h>

struct nodo{
    int info;
    struct nodo *sig;
};

typedef struct nodo Nodo;
typedef Nodo *tipoLista;

/* Prototipos */

void crearLista(tipoLista *L);

bool esVacia(tipoLista L);

void nuevoNodo(tipoLista *nuevoN);

void insertarPrincipio(tipoLista *L, int x);

void insertarFinal(tipoLista *L, int x);

void eliminarElemento(tipoLista *L, int x);

bool buscarElemento(tipoLista L, int x);

void imprimirLista(tipoLista L);

#endif