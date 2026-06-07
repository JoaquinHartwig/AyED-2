#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PARCIAL.h"

/*Recibe una lista lis cargada.
Agrega 25 y 50 a la misma lista.
Elimina 60.
Analiza cada elemento:
Si es múltiplo de 8 y menor a 500 → va a lista1.
Si no → va a lista2.*/

void ListadeNumeros(tipoLista *LISTA,tipoLista *LISTA1,tipoLista *LISTA2)
{
tipoLista Aux;
int num=0;    
crearLista(&Aux);
crearLista(LISTA1);
crearLista(LISTA2);
insertarFinal(LISTA,25);
insertarFinal(LISTA,50);
eliminarElem(LISTA,60);
while(!esvacia(*LISTA))
{
   sacarElemento(LISTA,&num);//esta funcion ademas de sacar el elemento hace el recorrido con L = L->sig;
   if (num%8==0 && num<500)
   {
        insertarFinal(LISTA1,num);
   }
   else
   {

       insertarFinal(LISTA2,num);

   }
 insertarFinal(&Aux,num);






}
while(!esVacia(Aux))//PARA RECONSTRUIR LA LISTA ORIGINAL
{
    sacarElemento(&Aux,&num);

    insertarFinal(LISTA,num);
}   





}