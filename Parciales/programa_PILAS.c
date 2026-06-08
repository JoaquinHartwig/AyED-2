/*Usando el TDA de Pilas de enteros
La biblioteca “Juan Pérez” tiene una pila de libros de novelas y a cada una le corresponde un código (el
código 0001 corresponde a novelas policiacas, el 0002 a novelas románticas, el 0003 a novelas de ciencia
ficción y el 0004 a novelas fantásticas).
El director de dicha biblioteca necesita saber la cantidad de novelas por código y cuál es el código que
tiene mayor cantidad y cual menor cantidad.
Teniendo en cuenta lo anterior realizar un módulo que resuelva lo planteado.
*/
//0001=policiacas
//0002//romanticas
//0003 ciencia ficcion
//0004 fantasticas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PILAS.h"

void BibliotecadeLibrosPilas(tipoPila *Pila1)
{
    tipoPila Aux;
    Aux=NULL;
    int codigo=0;
    int cantPoliciacas=0;
    int cantRomanticas=0;
    int cantCienciaficcion=0;
    int cantfantasticas=0;
    while(!esVacia(*Pila1))
    {
      desapilar(Pila1,&codigo);
      apilar(&Aux,codigo);
      if(codigo==0001)
      {
      cantPoliciacas++;

      }
      else if(codigo==0002)
      {

       cantRomanticas++; 

      }
      else if(codigo==0003)
      {
       cantCienciaficcion++;
       

      }
      else 
      {

      cantfantasticas++;

      }




    }
    printf("La cantidad de policiacas es %d, de Romanticas es: %d, de CienciaFiccion es %d, de Fantasticas es %d",cantPoliciacas,cantRomanticas,cantCienciaficcion,cantfantasticas);
    while(!esVacia(Aux))//para reconstruir la Pila original
{
    desapilar(&Aux,&codigo);
    apilar(Pila1,codigo);
}

    int mayor = cantPoliciacas;
    int menor = cantPoliciacas;

    if(cantRomanticas > mayor)
    {
        mayor = cantRomanticas;
    }

    if(cantCienciaficcion > mayor)
    {
        mayor = cantCienciaficcion;
    }

    if(cantfantasticas > mayor)
    {
        mayor = cantfantasticas;
    }

    if(cantRomanticas < menor)
    {
        menor = cantRomanticas;
    }

    if(cantCienciaficcion < menor)
    {
        menor = cantCienciaficcion;
    }

    if(cantfantasticas < menor)
    {
        menor = cantfantasticas;
    }

    if(mayor == cantPoliciacas)
    {
        printf("Mayor cantidad: codigo 0001\n");
    }
    else if(mayor == cantRomanticas)
    {
        printf("Mayor cantidad: codigo 0002\n");
    }
    else if(mayor == cantCienciaficcion)
    {
        printf("Mayor cantidad: codigo 0003\n");
    }
    else
    {
        printf("Mayor cantidad: codigo 0004\n");
    }

    if(menor == cantPoliciacas)
    {
        printf("Menor cantidad: codigo 0001\n");
    }
    else if(menor == cantRomanticas)
    {
        printf("Menor cantidad: codigo 0002\n");
    }
    else if(menor == cantCienciaficcion)
    {

}