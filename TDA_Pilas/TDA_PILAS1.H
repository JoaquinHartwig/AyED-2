#ifndef TDA_PILA_ALUMNOS_H
#define TDA_PILA_ALUMNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char nombre[30];
    int nota;
} alumno;

struct nodoPila
{
    alumno info;
    struct nodoPila *sig;
};

typedef struct nodoPila *tipoPila;

/* Operaciones */

bool esVaciaPila(tipoPila P);

void crearNodoPila(tipoPila *nuevoN);

void apilar(tipoPila *P, alumno x);

void desapilar(tipoPila *P, alumno *x);

#endif