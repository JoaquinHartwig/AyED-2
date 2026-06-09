#include<stdio.h>
#include "TDA_LISTAS1.h"

int main(){//En este programa se utiliza mucho la funcion imprimirLista para mostrar el estado de la lista despues de cada operacion, lo que ayuda a visualizar como se va modificando la lista con cada insercion, eliminacion o busqueda.

    PunteroNodo Lista; //  gcc main.c TDA_LISTAS.c -o programa
    int x;//.\programa.exe

    crearLista(&Lista);

    

    

    printf("Verificando si la lista esta vacia...\n");
    if(esVacia(Lista)){
        printf("La lista esta vacia\n");
    }else{
        printf("La lista NO esta vacia\n");
    }   

    printf("\nInsertando al principio...\n"); // hago una lista q contenga 3 elementos, insertando al principio cada uno de ellos, el resultado es una lista con los elementos en orden inverso al que se insertaron, ya que cada nuevo elemento se convierte en el nuevo primer nodo de la lista
    Insertar_Principio(&Lista, 10); //2,5,10
    Insertar_Principio(&Lista, 5);
    Insertar_Principio(&Lista, 2);

    imprimirLista(Lista); //La función imprimirLista recorre la lista desde el primer nodo hasta el último nodo, imprimiendo el valor de cada nodo seguido de " | ". En este caso, se imprimirá "2 | 5 | 10 | ", ya que el primer nodo contiene el valor 2, el segundo nodo contiene el valor 5 y el tercer nodo contiene el valor 10. Después de imprimir todos los nodos, se imprime un salto de línea para finalizar la salida.

    printf("\nInsertando al final...\n");//recibe la lista (q ya esta cargada con los elementos 2,5,10) y el valor a insertar (20), la función Insertar_Final crea un nuevo nodo con el valor 20 y lo agrega al final de la lista. Luego se inserta el valor 30 al final de la lista, resultando en una lista con los elementos 2,5,10,20,30
    Insertar_Final(&Lista, 20);
    Insertar_Final(&Lista, 30);

    imprimirLista(Lista);

    

    

    printf("\nBuscando elementos...\n");

    if(existeEnLista(Lista, 20)){
        printf("20 existe en la lista\n");
    }else{
        printf("20 NO existe en la lista\n");
    }

    if(existeEnLista(Lista, 99)){
        printf("99 existe en la lista\n");
    }else{
        printf("99 NO existe en la lista\n");
    }

    printf("\nEliminando elemento 15...\n"); //Borrar elemento 15, que no existe en la lista, por lo que se mostrará un mensaje indicando que el valor no está en la lista. Luego se imprimirá la lista para mostrar que no ha habido cambios, ya que el elemento 15 no se eliminó porque no estaba presente en la lista.

    eliminarElemento(&Lista, 15);

    imprimirLista(Lista);

    printf("\nSacando primer elemento...\n");

    sacarElemento(&Lista, &x);

    printf("Elemento extraido: %d\n", x);

    imprimirLista(Lista);

    return 0;
}