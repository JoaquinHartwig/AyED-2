#include<stdio.h>
#include "TDA_LISTAS1.h"
/*
crearLista() //Funciones q voy a utilizar
esVacia()
sacarElemento()
Insertar_Final()
*/
/*  Dada una lista de números enteros, recorrer la lista e informar la cantidad de
números impares.
b) Dada una lista de números enteros, recorrer la lista e informar el mayor de los
números múltiplos de 6.
c) “Los números perfectos, son iguales a la suma de todos sus divisores menores
a él, por ejemplo, el número 6 es perfecto porque 6 = 1+2+3”. Dada una lista de
enteros determinar si existen números perfectos e insertarlos en una nueva lista.
d) Un banco mantiene un listado de “MontosPréstamos” con montos de
préstamos de clientes, el orden de las deudas se corresponde con otro listado
“DatosClientes” (al primer cliente del listado “DatosClientes” le corresponde
el primer préstamo del listado “MontoPréstamos” y así sucesivamente).
Se pide crear un módulo que reciba el listado “MontoPréstamos” y genere
UNIVERSIDAD NACIONAL DE MISIONES
Facultad de Ciencias Exactas, Químicas y Naturales
ALGORITMOS y ESTRUCTURAS DE DATOS II
2
dos nuevos listados “PrestamosActualizadosOpción1” y
“PrestamosActualizadosOpción2” respetando lo siguiente:
Para “PrestamosActualizadosOpción1”
Si el préstamo es menor a 50000 se aplica un descuento del 15%
Para “PrestamosActualizadosOpción2”
Si el préstamo es mayor o igual a 5000 se aplica descuento del 5%*/
 #include <stdio.h>
#include <stdbool.h>
#include "TDA_LISTAS1.h"

bool esPerfecto(int numero){ // Para q compile el programa gcc main.c TDA_LISTAS1.c -o programa

    int sumaDivisores = 0;

    for(int i = 1; i < numero; i++){

        if(numero % i == 0){
            sumaDivisores += i;
        }
    }

    return sumaDivisores == numero;
}

void generarListaPerfectos(PunteroNodo *Lista, PunteroNodo *Perfectos){

    PunteroNodo Aux;
    int x;

    crearLista(&Aux);
    crearLista(Perfectos);

    while(!esVacia(*Lista)){

        sacarElemento(Lista, &x);

        if(esPerfecto(x)){
            Insertar_Final(Perfectos, x);
        }

        Insertar_Final(&Aux, x);
    }

    while(!esVacia(Aux)){

        sacarElemento(&Aux, &x);

        Insertar_Final(Lista, x);
    }
}

void actualizarPrestamos(PunteroNodo *Lista,
                         PunteroNodo *Opcion1,
                         PunteroNodo *Opcion2){

    PunteroNodo Aux;
    int monto;

    crearLista(&Aux);
    crearLista(Opcion1);
    crearLista(Opcion2);

    while(!esVacia(*Lista)){

        sacarElemento(Lista, &monto);

        if(monto < 50000){
            Insertar_Final(Opcion1, monto - (monto * 15 / 100));
        }
        else{
            Insertar_Final(Opcion1, monto);
        }

        Insertar_Final(Opcion2, monto - (monto * 5 / 100));

        Insertar_Final(&Aux, monto);
    }

    while(!esVacia(Aux)){

        sacarElemento(&Aux, &monto);

        Insertar_Final(Lista, monto);
    }
}

int main(){

    PunteroNodo Lista;
    PunteroNodo Aux;
    PunteroNodo Perfectos;
    PunteroNodo Opcion1;
    PunteroNodo Opcion2;

    int contador = 0;
    int mayor = 0;
    int x;

    crearLista(&Lista);
    crearLista(&Aux);
    crearLista(&Perfectos);
    crearLista(&Opcion1);
    crearLista(&Opcion2);

    /* Carga de prueba */

    Insertar_Final(&Lista, 6);
    Insertar_Final(&Lista, 8);
    Insertar_Final(&Lista, 28);
    Insertar_Final(&Lista, 30);
    Insertar_Final(&Lista, 15);

    printf("Lista original:\n");
    imprimirLista(Lista);

    /* Punto A */

    while(!esVacia(Lista)){

        sacarElemento(&Lista, &x);

        if(x % 2 != 0){
            contador++;
        }

        Insertar_Final(&Aux, x);
    }

    while(!esVacia(Aux)){

        sacarElemento(&Aux, &x);

        Insertar_Final(&Lista, x);
    }

    printf("\nCantidad de impares: %d\n", contador);

    /* Punto B */

    while(!esVacia(Lista)){

        sacarElemento(&Lista, &x);

        if(x % 6 == 0){

            if(x > mayor){
                mayor = x;
            }
        }

        Insertar_Final(&Aux, x);
    }

    while(!esVacia(Aux)){

        sacarElemento(&Aux, &x);

        Insertar_Final(&Lista, x);
    }

    printf("Mayor multiplo de 6: %d\n", mayor);

    /* Punto C */

    generarListaPerfectos(&Lista, &Perfectos);

    printf("\nLista de numeros perfectos:\n");
    imprimirLista(Perfectos);

    /* Punto D */

    actualizarPrestamos(&Lista, &Opcion1, &Opcion2);

    printf("\nLista opcion 1:\n");
    imprimirLista(Opcion1);

    printf("\nLista opcion 2:\n");
    imprimirLista(Opcion2);

    return 0;
} //gcc main.c TDA_LISTAS1.c -o programa