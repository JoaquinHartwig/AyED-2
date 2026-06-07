//Programa Pares e Impares
//Recorrer lista1 y contar pares e impares
//Si pares > impares eliminar todos los impares
//Si pares < impares eliminar todos los pares
//Informar el promedio de los numeros q los q hay mayor cantidad 
//No perder la lista original (lista1)
//Usar Auxiliar + sacarElemento()
//En la lista2 poner lo q cumple la condicion
//Y con el el auxiliar guardar la lista original






#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PARCIAL.h"


void numerosPareseImpares(tipoLista *lista1, tipoLista *lista2)
{
    tipoLista Aux;

    int num;
    int cantPares = 0;
    int cantImpares = 0;

    int suma = 0;
    int cantidad = 0;

    crearLista(&Aux);
    crearLista(lista2);

    // PRIMER RECORRIDO:
    // Cuenta pares e impares y guarda todo en Aux

    while(!esVacia(*lista1))
    {
        sacarElemento(lista1, &num);

        if(num % 2 == 0)
        {
            cantPares++;
        }
        else
        {
            cantImpares++;
        }

        insertarFinal(&Aux, num);
    }

    printf("Cantidad de pares: %d\n", cantPares);
    printf("Cantidad de impares: %d\n", cantImpares);

    // SEGUNDO RECORRIDO:
    // Genera Lista2 y reconstruye Lista1

    while(!esVacia(Aux))
    {
        sacarElemento(&Aux, &num);

        if(cantPares > cantImpares)
        {
            // Conservar solamente los pares

            if(num % 2 == 0)
            {
                insertarFinal(lista2, num);

                suma += num;
                cantidad++;
            }
        }
        else
        {
            // Conservar solamente los impares

            if(num % 2 != 0)
            {
                insertarFinal(lista2, num);

                suma += num;
                cantidad++;
            }
        }

        // Reconstruye la lista original
        insertarFinal(lista1, num);
    }

    if(cantidad > 0)
    {
        printf("Promedio: %.2f\n", (float)suma / cantidad);
    }
}










