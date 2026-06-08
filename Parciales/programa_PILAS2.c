#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PILAS.h"

void AnalizarMultiplosPilas(tipoPila *PILA, tipoPila *PILA1,tipoPila *PILA2,tipoPila *PILA3)
{
int x;
int suma = 0;
int cantidad = 0;
float promedio;
tipoPila Aux;
Aux=NULL;

while (!esVacia(*PILA))
{
    desapilar(PILA,&x);
    if(x%9==0 && x<600)
    {
       apilar(PILA1,x);
       apilar(&Aux,x);

            
    }
    else if(x%4==0)
    {
       
       apilar(PILA2,x);
       apilar(&Aux,x);



    }
    else 
    {

      apilar(PILA3,x);
       apilar(&Aux,x);

    }
}
while(!esVacia(*PILA2))
{    desapilar(PILA2,&x);
     suma=suma+x;
     cantidad++;

        
}
promedio= (float)suma/cantidad;
printf("El promedio de los multiplos de 4 es : %f",promedio);
while (!esVacia(Aux))
{
    desapilar(&Aux,&x);
    apilar(PILA,x);
    if(x%4==0)
    {
        apilar(PILA2,x);
    }
}


}