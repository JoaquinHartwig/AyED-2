#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PARCIAL.h"

void crearLista(tipoLista *punteroLista ){
    *punteroLista = NULL;}

bool esVacia(tipoLista L){//La lista ¿apunta a nada? Si el puntero es NULL, la lista está vacía
    if (L == NULL){//Se utiliza en mientras para recorrer la lista, si el puntero es NULL, significa que hemos llegado al final de la lista, lo que indica que la lista está vacía o que hemos recorrido toda la lista.
        return (true);//Mientras exista un nodo en la lista, el puntero no será NULL, por lo que la función devolverá false. Solo cuando el puntero sea NULL, lo que indica que no hay nodos en la lista, la función devolverá true.
    }
    else {
        return (false);
    }
}

void nuevo_nodo(tipoLista *nuevoN){ //Sirve para crear un nuevo nodo en la lista, se utiliza en las funciones de inserción para agregar nuevos nodos a la lista. La función recibe un puntero a un tipoLista, que es un puntero al primer nodo de la lista, y asigna memoria para un nuevo nodo utilizando malloc. Si la asignación de memoria falla, la función imprime un mensaje de error y termina el programa.
   *nuevoN = malloc(sizeof(struct nodo));
    if (esVacia(*nuevoN)) {//Verifica q el nuevonodo apunte a algo (nuevonodo), si el puntero es NULL, significa que no se pudo asignar memoria para el nuevo nodo, lo que indica un error en la asignación de memoria.
        printf("Error: no se pudo asignar memoria\n"); //Verifica que se haya asignado correctamente la memoria antes de utilizarla.
        exit(1);
   }
}

/*1) Reserva memoria para un nodo.
2) Guarda la dirección en el puntero recibido.
3) Verifica que malloc no haya fallado.
}*/

void insertarPrincipio(tipoLista *L, int x) {
    tipoLista nuevoNodo;//Se crea una variable de tipo puntero (todavia no apunta a nada)
    nuevo_nodo(&nuevoNodo);//Reserva memoria,Se crea el nodo vacio y nuevonodo lo apunta q es la variable de tipo puntero q lo creamos anteriormente
    nuevoNodo->info = x;//Pone el dato enviado como argumento en el nodo 
    nuevoNodo->sig = *L;//Aca se hace la conexion
    *L = nuevoNodo;//La lista vuelve a apuntar al
}


void insertarFinal(tipoLista *L, int x) {
    tipoLista nuevoNodo;//nodo q voy a crear 
    tipoLista PI;//puntero auxilair para no perder el inicio de la lista
    nuevo_nodo(&nuevoNodo);//Se crea un nodo vacio
    nuevoNodo->info = x;//Se carga el valor
    nuevoNodo->sig = NULL;//Se carga la direccion NULL,como va ser la ultima tiene q ser NULL

    if (esVacia(*L)) {//Si la lista es vacia entra en este caso,y simplemente y hace q lista apunte al nuevo nodo
        *L = nuevoNodo;//Aca se hace la magia
    } else {//Caso lista NO Vacia 
        PI = *L;//Guardamos el inicio 
        while (!esVacia((*L)->sig)) { //¿el siguiente es NULL?  
            *L = (*L)->sig;//Aqui se hace el recorrido
        }
        (*L)->sig = nuevoNodo;//Esto conecta el ultimo nodo con el nodo q queremos insertar al final
        *L = PI;//Vuelve la lista al comienzo,gracias al puntero auxiliar
    }

}

void eliminarElem(tipoLista *L, int x){
    tipoLista PI, PA = NULL; //PI guarda el comienzo de la lista,PA va a apuntar al nodo anterior que estamos analizando
    PI = *L;//Guardamos el comienzo de la lista en PI

    while ((!esVacia(*L)) && ((*L)->info != x)){ // Mientras no llegue al final y no encuentre el valor

        PA = *L;//Guarda la posicion antes de  movernos en la lista
        *L = (*L)->sig;//Recorrido de lista
    }
    if (!esVacia(*L)){
        if (!esVacia(PA)){//Como PA no es vacia entra
            PA->sig = (*L)->sig;//Hace el salto para conectar los extremos,donde estaba el nodo eliminado
        }
        else{
            PI = PI->sig;
        }
        free(*L);//Elimina en memoria el nodo
    }
    *L = PI;//Apunta al comienzo la lista
}
/*  1) Guarda el inicio en PI.
2) Busca el valor.
3) PA guarda el nodo anterior.
4) Cuando encuentra el nodo:
      anterior -> siguiente
5) Borra el nodo.
6) Recupera el inicio con *L = PI.*/

void imprimir_lista(tipoLista L) { //Como no modifica solo lee recibe nodo*TipoLista 
    printf("[");//Recibe solamente una copia
    while (!esVacia(L)) {//Mientras exista un nodo
        printf("%d", L->info);//Imprime el dato
        if (L->sig != NULL) {//¿Hay siguiente?
            printf(", ");
        }
        L = L->sig;//Recorre la lista
    }
    printf("]\n");
}
/*1) Imprime "["
2) Recorre nodo por nodo.
3) Imprime cada dato.
4) Si hay otro nodo, imprime ", ".
5) Avanza al siguiente nodo.
6) Imprime "]". */

void sacarElemento(tipoLista *L, int *x){
    if(*L == NULL){//¿La lista está vacía?
        exit(1);// si es q si,No hay nada q sacar
    }
    tipoLista primerNodo = *L; //Ambos punteros apuntan al primer nodo.¿Para qué quiere otro puntero?Porque después va a mover la lista:
    *L = primerNodo->sig; //¿Qué vale primerNodo->sig? Aca se hace q los dos punteros apunten a partes distintas de la lista
    *x = primerNodo->info;//Como el primer nodo apunta al primer nodo agarra el dato y lo almacena en una variable,aca se hace la extraccion del elemento
    free(primerNodo);//Se elimina el primer nodo
}
/*1) Guarda el dato del primer nodo en x.
2) Elimina el primer nodo de la lista.
3) Hace que la lista empiece en el segundo nodo.   */

/*  Crear otro puntero que apunte a algún nodo
para no perder referencias importantes.*/

/*while(!esVacia(Lista)){
    sacarElemento(&Lista, &x);

    // trabajar con x
}

Cada vuelta saca el primer elemento.*/
/*  Saco un elemento.
Lo analizo.
Decido qué hacer con él.
Lo guardo donde corresponda.*/