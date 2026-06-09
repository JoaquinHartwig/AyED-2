#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PARCIAL.h"
//
/*"Hacer un proceso que reciba una lista cargada con las notas de los alumnos de algoritmos 2,
 y genere 2 listas nuevas. Una que se llame "Aprobados", otra que se llame "Desaprobados" 
 y al final del proceso se informe por pantalla qué porcentaje representan los aprobados 
 sobre el total de alumnos de la cátedra."*/

void ListaNotas(tipoLista *listaNotas,tipoLista*Aprobados,tipoLista *Desaprobados)
{
tipoLista Aux;
crearLista(&Aux);
crearLista(Aprobados);
crearLista(Desaprobados);
int num;
int aprobados = 0;
int total = 0;
while (!esVacia(*listaNotas))
{
    sacarElemento(listaNotas,&num);
    if(num>=6)
    {
    insertarFinal(Aprobados,num);
    insertarFinal(&Aux,num);
    aprobados++;
    total++;

    }
    else{

        insertarFinal(Desaprobados,num);
        insertarFinal(&Aux,num);
        total++;
    }
}
printf("El porcentaje que representan los aprobados sobre el total de alumnos es %d",(float)aprobados*100/total);
while(!esVacia(Aux))
{
 sacarElemento(&Aux,&num);
 insertarFinal(listaNotas,num);

}



}