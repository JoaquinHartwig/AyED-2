#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PARCIAL.h"
#include "TDA_PILAS.h"

void generarListaEspecial(tipoLista *ListaOriginal,
                          tipoLista *ListaEspecial)
                          

{
tipoLista Aux;
crearLista(&Aux);
int num=0;
int numActualizado=0;
crearLista(ListaEspecial);
while(!esVacia(*ListaOriginal))
{
numActualizado=0;//reinicia el contador    
sacarElemento(ListaOriginal,&num);
insertarFinal(&Aux,num);
if(num%2==0)
{
    numActualizado=num*2;  
    insertarFinal(ListaEspecial,numActualizado);


}
else{
    numActualizado=num*3;
    insertarFinal(ListaEspecial,numActualizado);
}

}
while(!esVacia(Aux))
{
   sacarElemento(&Aux,&num);
   insertarFinal(ListaOriginal,num);

}



} 

void analizarTemperaturas(tipoPila *Pila)
{
tipoPila Aux;
crear(&Aux);
int temperatura=0;
int cantmenoresde0=0;
int cantentre0y30=0;
int cantmayoresde30=0;
while (!esVacia(*Pila))
{
    desapilar(Pila,&temperatura);
    apilar(&Aux,temperatura);
    if (temperatura<0)
    {
        cantmenoresde0++;
    }
    else if (temperatura>=0 && temperatura <= 30)
    {
        cantentre0y30++;
    }
    else
    {
        cantmayoresde30++;
    }
}
while (!esVacia(Aux))
{
    desapilar(&Aux,&temperatura);
    apilar(Pila,temperatura);
}
printf("La cantidad de menores q 0 es %d, de entre 0 y 30 es %d y mayores de 30 son %d",cantmenoresde0,cantentre0y30,cantmayoresde30);
}
void separarNumeros(tipoPila *PilaOriginal,
                    tipoPila *PilaPares,
                    tipoPila *PilaImpares)

{
 tipoPila Aux;
 int num;
 crear(&Aux);
 crear(PilaPares);
 crear(PilaImpares);
 while(!esVacia(*PilaOriginal))
 {
    desailar(PilaOriginal,&num);
    apilar(&Aux,num);
    if(num%2==0)
    {
        insertarFinal(PilaPares,num);
    }
    else

    {
        insertarFinal(PilaImpares,num);
    }


 }
while(!esVacia(Aux))
{
    desapilar(&Aux,&num);
    apilar(PilaOriginal,num);
}



}          

void contarMayores(tipoLista *Lista)
{
  tipoLista Aux;
  crearLista(&Aux);
  int num;
  int cantnumMayores=0;
  int cantnumMenores=0;
  while(!esVacia(*Lista))
  {
   sacarElemento(Lista,&num);
   insertarFinal(&Aux,num);
   if(num>100)
   {
    cantnumMayores++;
   }
   else
   {
    cantnumMenores++;
   }

  }
  printf("La cantidad de números mayores de 100 es %d y menores o iguales a 100 es %d",cantnumMayores,cantnumMenores);
  while(!esVacia(Aux))
  {
    sacarElemento(&Aux,&num);
    insertarFinal(Lista,num);
  }
  

}





