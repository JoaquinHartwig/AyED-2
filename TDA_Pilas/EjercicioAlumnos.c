/*Paso 2: ¿Qué pide?

almacenar en una pila los alumnos con nota superior a 7*/
/*Se tienen almacenados en una lista enlazada los nombres de una serie de alumnos y
alumnas y las notas obtenidas en el examen de la asignatura de Fundamentos de
Programación I. La lista enlazada está ordenada por el nombre del alumno.
Se pide:
 Diseñar una solución (realizar un esquema, planteo etc.)
 Realizar el TDA correspondiente.
 Codificar un módulo que permita almacenar en una pila los alumnos con una
nota superior a 7.*/
/*Lista
 ↓
Analizar cada alumno
 ↓
Si nota > 7
 ↓
Pila*/


/*Lista Original
      ↓
 Analizo
      ↓
Lista Auxiliar
      ↓
Reconstruyo*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PILAS.h"
#include "TDA_PARCIAL.h"//Libreria q contiene sacar 


void ListaaPilaalumnos(tipoLista *Lista1,tipoPila *Pila1)
{
 tipoLista Aux;
 int num=0;
 char nombre[30]=NULL;
 crearLista(&Aux);
   
while (!esVacia(*Lista1))
{
   sacarElemento(Lista1,&num);
   if(num>7)
   {
    insertarFinal(&Aux,num);
    apilar(Pila1,num);


   }
   
}
while (!esVacia(Aux))
{
sacarElemento(&Aux,&num);
insertarFinal(Lista1,num);



}








}
