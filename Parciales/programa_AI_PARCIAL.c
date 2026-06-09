/*

# 📄 Parcial de práctica

## 1) Usando el TDA de Listas de enteros

Una empresa posee un listado llamado **Sueldos** con los salarios de sus empleados.

Se pide crear un módulo que reciba el listado **Sueldos** y genere un nuevo listado **SueldosActualizados** respetando las siguientes condiciones:

* Si el sueldo es menor a $500.000 se incrementa un 10%.
* Si el sueldo es menor a $1.000.000 se incrementa un 20%.
* Si el sueldo es menor a $2.000.000 se incrementa un 30%.
* Si el sueldo es mayor o igual a $2.000.000 se incrementa un 40% más un bono fijo de $100.000.

**Observación:** La lista original debe quedar igual que al inicio.

---

## 2) Usando el TDA de Pilas de enteros

Una fábrica clasifica cajas mediante códigos:

```text
1001 = Electrónica
1002 = Juguetes
1003 = Herramientas
1004 = Ropa
```

Se recibe una pila cargada con dichos códigos.

Realizar un módulo que informe:

* Cantidad de cajas de cada tipo.
* Código con mayor cantidad.
* Código con menor cantidad.

---

## 3) Usando el TDA de Pilas

Se recibe:

```text
Pila1 (cargada)
Pila2 (vacía)
Pila3 (vacía)
```

Procesar los elementos de Pila1 de la siguiente manera:

* Si el número es múltiplo de 5 y menor que 100, apilarlo en Pila2.
* En caso contrario, apilarlo en Pila3.

Además:

* Informar la cantidad de elementos que fueron a Pila2.
* Informar el promedio de dichos elementos.

---

## 4) Prueba de escritorio

Realizar la prueba de escritorio completa de:

```c
void insertarPrincipio(tipoLista *L, int x)
{
    tipoLista nuevoNodo;

    nuevo_nodo(&nuevoNodo);

    nuevoNodo->info = x;

    nuevoNodo->sig = *L;

    *L = nuevoNodo;
}
```

Utilizando los elementos:

```text
12
25
81
```

y considerando que la lista comienza vacía.

---

# ⭐ Nivel "profesora mala"

Si terminás ese parcial rápido, hacé este:

## 5) Usando el TDA de Listas

Recibir una lista de enteros llamada **Numeros**.

Generar una nueva lista llamada **Pares** que contenga únicamente los números pares.

La lista original debe quedar exactamente igual que al inicio.

---

Ese último es MUY de tu cátedra porque te obliga a pensar:

```text
sacarElemento()
↓
procesar
↓
insertarFinal()
↓
lista auxiliar
↓
reconstruir
```

que es justamente el patrón que aparece en casi todos los ejercicios que me mostraste. 🔥
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_PARCIAL.h"
#include "TDA_PILAS.h"

void ListaDeSueldos(tipoLista *Sueldo,tipoLista SueldosActualizados)
{
  tipoLista Aux;
  int num;
  int numActualizado;
  crearLista(&Aux);
  crearLista(SueldosActualizados);
  while(!esVacia(*Sueldo))
  {
    sacarElemento(Sueldo,&num);
    insertarFinal(&Aux,num);
    if(num<500000)
    {
      numActualizado=num+num*10/100;

    }
    else if(num>500000 )
    {

        numActualizado=num+num*20/100;

    }
    else if(num>1000000)
    {
      numActualizado=num+num*30/100;

    }
    else
    {
        numActualizado=(num+num*40/100)+100000;

    }
    insertarFinal(SueldosActualizados,numActualizado);
  }
  while (!esVacia(Aux))
  {
    sacarElemento(&Aux,&num);
    insertarFinal(Sueldo,num);
  }
  



}
void Clasificacion_de_codigos(tipoPila *Codigos)
{
   
   int codigo = 0;
   tipoPila Aux;
   crear(&Aux);
   int cantElectrónica=0;
   int  cantJuguetes=0;
    int cantHerramientas=0;
    int cantRopa=0;   
   while(!esVacia(*Codigos))
   {
      
    apilar(&Aux,codigo);
    desapilar(Codigos,&codigo);

      if(codigo== 1001)
      {
       cantElectrónica++;

      }
      else if(codigo==1002)
      {
        cantJuguetes++;
      }
      else if(codigo==1003)
      {

        cantHerramientas++;
      }
      else{
        cantRopa++;
      }




   }
   printf("La cantidad de Electronica es %d",cantElectrónica);
      printf("La cantidad de Jueguetes es %d",cantJuguetes);
         printf("La cantidad de Herramientas es %d",cantHerramientas);
            printf("La cantidad de Ropa es %d",cantRopa);
    int mayor=0;
    int menor=0;
    mayor=cantElectrónica;
    menor=cantElectrónica;
    while(!esVacia(Aux))
    {

        desapilar(&Aux,&codigo);
        apilar(Codigos,codigo);
    }
    if(cantJuguetes > mayor)
    {
        mayor = cantJuguetes;
    }

    if(cantHerramientas > mayor)
    {
        mayor = cantHerramientas;
    }

    if(cantRopa > mayor)
    {
        mayor = cantRopa;
    }

    if(cantJuguetes < menor)
    {
        menor = cantJuguetes;
    }

    if(cantHerramientas < menor)
    {
        menor = cantHerramientas;
    }

    if(cantRopa < menor)
    {
        menor = cantRopa;
    }

    if(mayor == cantElectrónica)
    {
        printf("Mayor cantidad: codigo 1001\n");
    }
    else if(mayor == cantJuguetes)
    {
        printf("Mayor cantidad: codigo 1002\n");
    }
    else if(mayor == cantHerramientas)
    {
        printf("Mayor cantidad: codigo 1003\n");
    }
    else
    {
        printf("Mayor cantidad: codigo 1004\n");
    }

    if(menor == cantElectrónica)
    {
        printf("Menor cantidad: codigo 0001\n");
    }
    else if(menor == cantJuguetes)
    {
        printf("Menor cantidad: codigo 0002\n");
    }
    else if(menor == cantHerramientas)

    {
      printf("Menor cantidad: codigo 1003\n");
}
    else{
        printf("Menor cantidad:codigo 1004\n");
    }

}

void Pilas_Multiplos(tipoPila*Pila1,tipoPila*Pila2,tipoPila*Pila3)
{
/*Si el número es múltiplo de 5 y menor que 100, apilarlo en Pila2.
En caso contrario, apilarlo en Pila3.*/
/*Informar la cantidad de elementos que fueron a Pila2.
Informar el promedio de dichos elementos.*/
tipoPila Aux;
crear(&Aux);
crear(Pila2);
crear(Pila3);
float promedio=0;
int total=0; //para hacer la division
int cantPila2=0;
int num;
while(!esVacia(*Pila1))
{
   desapilar(Pila1,&num);
   apilar(&Aux,num);
   if(num%5==0 && num < 100)
   {
    apilar(Pila2,num);
    cantPila2++;
    total=total+num;      
     
   }
   else{
    apilar(Pila3,num);
   }

}

if(cantPila2 > 0)
{
    promedio = (float)total/cantPila2;
}
printf("El promedio de Pila2 es: %f y la cantidad de la misma es: %d",promedio,cantPila2);

while ((!esVacia(Aux)))
{
    desapilar(&Aux,&num);
    apilar(Pila1,num);
}


}