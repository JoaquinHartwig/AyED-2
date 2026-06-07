/*  Una tienda mantiene un listado “Deudas” con montos de deudas de clientes, el orden de las deudas se
corresponde con otro listado “DatosClientes” (al primer cliente del listado “DatosClientes” le corresponde
la primera deuda del listado “Deudas” y así sucesivamente).
Se pide crear un módulo que reciba el listado “Deudas” y genere un nuevo listado “DeudasActualizadas”
respetando lo siguiente:
Si la deuda es menor a 10000 se aplica un recargo del 10%
Si la deuda es menor a 50000 se aplica un recargo del 25%
Si la deuda es menor a 100000 se aplica un recargo del 35%
Si la deuda es mayor o igual a 100000 se aplica un recargo del 50% más un monto fijo de 20000.
TDA Listas
#include <stdio.h>
#include <stdlib.h>
struct nodo
{
int info;
struct nodo *sig;
};
typedef struct nodo *tipoLista;
/operaciones/
void crearLista(lista); /Crea la lista/
void NuevoNodo(lista);/Crea un nuevo nodo/
bool esVacia_L(lista);
/controla si la lista está vacía o no, se pasa como parámetro la lista/
void insertarPrincipio(lista, valorDato);
/inserta al principio de a uno los elementos en la lista, se pasa como
parámetro la lista y el elemento a insertar/
void insertarFinal(lista, valorDato);
/inserta al final de a uno los elementos en la lista, se pasa como parámetro
la lista y el elemento a insertar/
void insertarOrdenado(lista, valorDato);
/inserta ordenado de a uno los elementos en la lista, se pasa como parámetro
la lista y el elemento a insertar/
bool existeElemento(lista, valorDato);
/Verifica si un elemento está en la lista, devuelve verdadero o falso/
void BorrarElemento(lista, valorDato);
/elimina un elemento de la lista, se pasa como parámetros la lista y el
elemento a ser eliminado de la misma/
void imprimirLista(lista);
/imprime los elementos de una lista/
void sacarElemento(lista, valorDato);/Saca siempre el primer elemento, el
mismo se elimina de la lista y pasa a ser primero el segundo elemento, sirve
para recorrer la lista y obtener cada uno de sus elementos/*/

//Funciones de Listas de la Catedra, se pueden usar para resolver los ejercicios planteados en el parcial, como por ejemplo, la función esPerfecto para determinar si un número es perfecto o no, y la función generarListaPerfectos para generar una nueva lista con los números perfectos encontrados en la lista original. Además, la función actualizarPrestamos se puede utilizar para actualizar los montos de los préstamos según las condiciones establecidas en el ejercicio d).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PARCIAL.h"


//tipoLista= struct nodo* 
void generarDeudasActualizadas(tipoLista *Deudas,
                               tipoLista *DeudasActualizadas)
{
    
    //Recibe lista con las deudas a la q vamos a hacer el recargo,y otra vacia donde vamos a depositar esas actualizaciones
    //DeudasActualizadas lista vacia donde vamos a guardar las recargas
    //Por qué *? Porque vamos a modificar ambas listas.


    tipoLista Aux;//Va a guardar temporalmente las deudas originales (Todavia apunta a basura)
    int monto;//Guarda lo q sacamos
    int nuevoMonto;//Guarda la deuda actualizada

    crearLista(&Aux);//Creamos una lista auxiliar (Apunta a NULL)
    crearLista(DeudasActualizadas);//Creamos la lista donde vamos a insertar las deudas actualizadas

    while(!esVacia(*Deudas))//recorre la lista Deudas mientras no se vacia
    {
        sacarElemento(Deudas, &monto);//Saca el primer elemento 

        if(monto < 10000)
        {
            nuevoMonto = monto + monto * 10 / 100;
        }
        else if(monto < 50000)
        {
            nuevoMonto = monto + monto * 25 / 100;
        }
        else if(monto < 100000)
        {
            nuevoMonto = monto + monto * 35 / 100;
        }
        else
        {
            nuevoMonto = monto + monto * 50 / 100 + 20000;
        }

        insertarFinal(DeudasActualizadas, nuevoMonto);//Guarda la actuakizacion en la nueva lista

        insertarFinal(&Aux, monto);
    }
    //¿Para qué sirve el segundo while? Porque la lista original quedó destruida.



    while(!esVacia(Aux))//Recompone la lista deudas.Ya que sacar elemento destruye la lista original,y por eso necesitamos un lista  auxiliar
    {
        sacarElemento(&Aux, &monto);

        insertarFinal(Deudas, monto);
    }
}
int main (){






}