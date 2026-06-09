#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PILAS.h"
#include "TDA_PARCIAL.h"



void ListaAPilas(tipoLista *Lista,
                 tipoPila *Menores,
                 tipoPila *Mayores)
{
    tipoLista Aux;
    int x;

    int cantMenores = 0;
    int cantMayores = 0;

    crearLista(&Aux);

    while(!esVacia(*Lista))
    {
        sacarElemento(Lista,&x);

        if(x <= 5)
        {
            apilar(Menores,x);
            cantMenores++;
        }
        else
        {
            apilar(Mayores,x);
            cantMayores++;
        }

        insertarFinal(&Aux,x);
    }

    while(!esVacia(Aux))
    {
        sacarElemento(&Aux,&x);

        insertarFinal(Lista,x);
    }

    if(cantMenores > cantMayores)
    {
        printf("La pila Menores tiene mas elementos\n");
    }
    else if(cantMayores > cantMenores)
    {
        printf("La pila Mayores tiene mas elementos\n");
    }
    else
    {
        printf("Ambas pilas tienen la misma cantidad de elementos\n");
    }
}