#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PILAS.h"

/*Recibir una pila1 cargada de enteros pares y una pila2 vacía. 
Desapilar de a uno los elementos, aplicarle alguna operación matemática para transformarlo en un número impar, 
apilarlo en pila2 e informar la cantidad de números.*/
void transformarPila(tipoPila *Pila1, tipoPila *Pila2)
{
    int x;
    int cantidad = 0;

    while(!esVacia(*Pila1))
    {
        desapilar(Pila1,&x);

        x = x + 1;

        apilar(Pila2,x);

        cantidad++;
    }

    printf("Cantidad de numeros: %d",cantidad);
}