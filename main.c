

#include <stdio.h>
#include "TDA_LISTA.h"

int main(){

    tipoLista lista;

    crearLista(&lista);

    int opcion;
    int valor;

    do{

        printf("\n--- MENU ---\n");
        printf("1. Insertar al principio\n");
        printf("2. Insertar al final\n");
        printf("3. Eliminar elemento\n");
        printf("4. Buscar elemento\n");
        printf("5. Mostrar lista\n");
        printf("0. Salir\n");

        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

            case 1:

                printf("Ingrese valor: ");
                scanf("%d", &valor);

                insertarPrincipio(&lista, valor);

                break;

            case 2:

                printf("Ingrese valor: ");
                scanf("%d", &valor);

                insertarFinal(&lista, valor);

                break;

            case 3:

                printf("Ingrese valor a eliminar: ");
                scanf("%d", &valor);

                eliminarElemento(&lista, valor);

                break;

            case 4:

                printf("Ingrese valor a buscar: ");
                scanf("%d", &valor);

                if(buscarElemento(lista, valor)){
                    printf("El elemento SI existe\n");
                }else{
                    printf("El elemento NO existe\n");
                }

                break;

            case 5:

                imprimirLista(lista);

                break;

            case 0:

                printf("Fin del programa\n");

                break;

            default:

                printf("Opcion invalida\n");
        }

    }while(opcion != 0);

    return 0;
}