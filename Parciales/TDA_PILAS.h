#ifndef TDA_PILAS_H
#define TDA_PILAS_H
#include <stdio.h>  
#include <stdbool.h>

struct nodo {
int info;
struct  nodo *sig;

};
typedef struct nodo *tipoPila;

bool esVacia(tipoPila Pila);
void crear (tipoPila *nuevoN);
void apilar(tipoPila *Pila, int x);
void desapilar(tipoPila *Pila, int *x); 



#endif