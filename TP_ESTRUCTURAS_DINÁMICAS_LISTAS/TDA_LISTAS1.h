#ifndef TDA_LISTA_H
#define TDA_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

typedef struct Nodo Nodo;
typedef Nodo *PunteroNodo;

/* Operaciones del TDA */

void crearLista(PunteroNodo *Lista); //Crear una lista vacía

bool esVacia(PunteroNodo Lista);//Informa si la lista está vacía o no

void NuevoNodo(PunteroNodo *nuevoN);//Crea un nuevo nodo, reservando memoria para el mismo

void Insertar_Principio(PunteroNodo *Lista, int valorDato);//Inserta un nuevo nodo al principio de la lista, con el valor dado

void Insertar_Final(PunteroNodo *Lista, int valorDato);//Inserta un nuevo nodo al final de la lista, con el valor dado

bool existeEnLista(PunteroNodo Lista, int valor);//Consulta si un valor dado existe en la lista, devolviendo true si se encuentra y false en caso contrario

void eliminarElemento(PunteroNodo *Lista, int valorDato);//Elimina el primer nodo que contenga el valor dado, si existe en la lista,se pasa la lista como primero argumento y el valor a eliminar como segundo argumento

void sacarElemento(PunteroNodo *Lista, int *x);

void imprimirLista(PunteroNodo Lista);

#endif