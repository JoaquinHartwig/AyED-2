
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_ALUMNOS.H"
#include "TDA_PILAS1.H"




void ListaAPilaAlumnos(tipoLista *Lista1,
                       tipoPila *Pila1)
{
    tipoLista Aux;
    alumno dato;

    crearLista(&Aux);

    while(!esVacia(*Lista1))
    {
        sacarElemento(Lista1,&dato);

        if(dato.nota > 7)
        {
            apilar(Pila1,dato);
        }

        insertarFinal(&Aux,dato);
    }

    while(!esVacia(Aux))
    {
        sacarElemento(&Aux,&dato);

        insertarFinal(Lista1,dato);
    }
}