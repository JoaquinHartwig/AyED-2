//Funcion q reciba una pila y lo imprima invertida
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PILAS.h"

void PilaInvertida(tipoPila *Pila)
{
 tipoPila Aux;
 int x;
 Aux=NULL;
 while(!esVacia(*Pila))
 {
 desapilar(Pila,&x);
 apilar(&Aux,x);
 
 }
 while(!esVacia(Aux))
{
    desapilar(&Aux,&x);
    printf("%d ",x);
}
}
void CopiadeUnaAOtra(tipoPila *Pila,tipoPila *Pila2)
{
 tipoPila Aux;
 Aux=NULL;
 int x;
 while(!esVacia(*Pila)) //Pila original -> Aux -> Pila copia
{
    desapilar(Pila,&x);
    apilar(&Aux,x);
}
while(!esVacia(Aux))
{
    desapilar(&Aux,&x);
    apilar(Pila2,x);
    apilar(Pila,x);
}
}
void sumarPilasCorrespondientes(tipoPila *Pila1, tipoPila *Pila2) //Si tenemos en cuenta q tienen los mismo elementos y no son NULL
{
    int x;
    int y;
    int suma;

    while(!esVacia(*Pila1) && !esVacia(*Pila2))
    {
        desapilar(Pila1,&x);
        desapilar(Pila2,&y);

        suma = x + y;

        printf("%d\n",suma);
    }
}

//Ahora voy a hacer teniendo en cuenta q una lista podria ser NULL,o no coincidir los elementos
//Procesar todos los elementos
void sumarPilas(tipoPila *Pila1,
                tipoPila *Pila2,
                tipoPila *PilaSuma)
{

int x;
int y;
int suma;
while(!esVacia(*Pila1) || !esVacia(*Pila2))
{
 if(!esVacia(*Pila1)&&!esVacia(*Pila2))
 {
     desapilar(Pila1,&x);
     desapilar(Pila2,&y  );
     suma=x+y;
     apilar(PilaSuma,suma);




  }
  else if (!esVacia(*Pila1))
  {
    desapilar(Pila1,&x);
    apilar(PilaSuma,x);

       
  }
  else{
   desapilar(Pila2,&y);
   apilar(PilaSuma,y);




  }
}
}
//Recorrer una pila y generar una nueva pila con los números pares.
void PilaPar(tipoPila *Pila1,tipoPila *Pila2)
{
tipoPila Aux;
Aux = NULL;
int x;
while(!esVacia(*Pila1))
{
    apilar(&Aux,x);//Aux debe apilar todos los elementos
  desapilar(Pila1,&x);
  if(x%2==0)
  {
    
    apilar(Pila2,x);
   

  }
}
while (!esVacia(Aux))
{
   desapilar(&Aux,&x);
   apilar(Pila1,x);

}




}





























