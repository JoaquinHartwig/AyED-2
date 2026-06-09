
#include <stdbool.h>

#ifndef TDA_listas
#define TDA_listas

// TIPOS
struct nodo { //Esto crea un tipo de dato llamado nodo, que es una estructura que contiene un campo info de tipo entero para almacenar el valor del nodo y un campo sig que es un puntero a otro nodo, lo que permite enlazar los nodos entre sí para formar la lista.
    int info;
    struct nodo *sig;
};
//A partir de ahora,tipoLista significa "struct nodo *", lo que hace que el código sea más legible y fácil de entender, ya que se puede referir a la lista simplemente como tipoLista en lugar de tener que escribir struct nodo * cada vez que se quiera manipular la lista.

//tipoLista Lista; (lista apunta al primer nodo de la lista) lo que permite acceder a todos los nodos de la lista a través de los punteros sig de cada nodo. Al manipular la lista, se puede modificar el puntero Lista para agregar, eliminar o buscar nodos en la lista, lo que facilita la gestión de la estructura de datos.)
//tipoLista *Lista; (Puedo modificar la variable Lista desde la función)
//tipoLista *Lista(recibe la dirección de la variable Lista) (Puedo modificar la variable Lista desde la función)
//tipoLista *L puntero a la variable Lista, lo que permite modificar el puntero a la lista en la función crearLista, ya que se pasa la dirección del puntero a la lista. Esto es necesario para que la función pueda asignar el valor NULL al puntero de la lista y así indicar que la lista está vacía.)
typedef struct nodo *tipoLista; //Apodo para el puntero al primer nodo de la lista, lo que facilita la manipulación de la lista sin tener que lidiar directamente con punteros a nodos en el código principal. Al usar tipoLista, se puede trabajar con la lista de manera más abstracta y legible, sin preocuparse por los detalles de la implementación de los nodos.
//La variable lista no contiene todos los nodos de la lista, sino que es un puntero que apunta al primer nodo de la lista. Cada nodo a su vez contiene un campo info que almacena el valor del nodo y un campo sig que es un puntero al siguiente nodo en la lista. De esta manera, se puede recorrer la lista siguiendo los punteros sig desde el primer nodo hasta el último nodo, que es aquel cuyo campo sig es NULL.
// PROTOTIPOS
void crearLista(tipoLista *punteroLista);//Crea la lista y apunta a NULL, lo que indica que la lista está vacía al inicio
//Puntero a un puntero nodo, lo que permite modificar el puntero a la lista en la función crearLista, ya que se pasa la dirección del puntero a la lista. Esto es necesario para que la función pueda asignar el valor NULL al puntero de la lista y así indicar que la lista está vacía.
bool esVacia(tipoLista L);

void nuevo_nodo(tipoLista *nuevoN);

void insertarPrincipio(tipoLista *L, int x);

void insertarFinal(tipoLista *L, int x);

void eliminarElem(tipoLista *L, int x);

void imprimir_lista(tipoLista L);

void sacarElemento(tipoLista *L, int *x);

#endif
