#ifndef TDA_ALUMNOS_H
#define TDA_ALUMNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char nombre[30];
    int nota;
} alumno;

struct nodo
{
    alumno info;
    struct nodo *sig;
};

typedef struct nodo *tipoLista;

/* Operaciones */

void crearLista(tipoLista *L);

bool esVacia(tipoLista L);

void nuevo_nodo(tipoLista *nuevoN);

void insertarFinal(tipoLista *L, alumno x);

void sacarElemento(tipoLista *L, alumno *x);

#endif