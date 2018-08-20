/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Version del programa: 1.2
Nombre del ingeniero: Juan Alberto Gutierrez Canto
Fecha de creación: 28/01/2016
Descripcion: Programa 1A de la materia proceso personal de software, programa que calcula 
                la media y desviacion estandar de N numeros con listas ligadas
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <cstdlib>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <iostream>
/*+++++++++++++Reutilizacion +++++++++++++++++++
Function: ISEMPTY()
Propósito: revisar si la lista esta vacia
In/out: no aplica/1 esta vacia-0 no esta vacia
Limitaciones: no aplica

+++++++++++++++++++++++++++++++++++++++++++
*/

using namespace std;
struct nodo                             
{                            /*-c estructura para guardar las listas ligadas*/
      double numero;
      struct nodo *sig;
};struct nodo *raiz=NULL, *last=NULL;

int ISEMPTY()                             
{                           /*-c funcion para saber si esta vacia las listas ligadas*/
     if(raiz == NULL)                        /*-c esta vacia la lista?? 1-si 0-no*/
           return 1;
     else
           return 0;
}

/*+++++++++++++Reutilizacion +++++++++++++++++++
Function: INSERT()
Propósito: insertar un dato en un nuevo nodo
In/out: dato a insertar/no aplica
Limitaciones: tipo de dato double

+++++++++++++++++++++++++++++++++++++++++++
*/

void INSERT(double dato)                    
{                                   /*-c insertar un dato en un nuevo nodo*/
     struct nodo *nuevo = NULL;                /*-c nuevo nodo*/
     if(ISEMPTY())
     {
           nuevo = (struct nodo *)malloc( sizeof (struct nodo));   /*-c inserta si no hay ninguna lista todavia*/
           nuevo->numero = dato;
           nuevo-> sig = NULL;
           raiz = last = nuevo;
     }
     else
     {
           nuevo = (struct nodo *)malloc( sizeof (struct nodo));    /*-c insertar cuando ya existe un nodo*/
           nuevo->numero = dato;
           nuevo-> sig = NULL;
           last->sig = nuevo;
           last = nuevo;
     }
}

/*+++++++++++++Reutilizacion +++++++++++++++++++
Function: REMUEVE()
Propósito: remueve un dato de la lista elimina el nodo
In/out: no aplica/dato
Limitaciones: tipo de dato double

+++++++++++++++++++++++++++++++++++++++++++
*/

double REMUEVE()                      
{                               /*-c regresar dato de la lista ligada*/
     struct nodo *elimina = NULL;
     double temp;
     if(!ISEMPTY())
     {
          elimina = raiz;
          raiz = raiz-> sig;      /*-c o raiz = elimina -> sig;*/
          temp = elimina -> numero;
          free(elimina);                    /*-c libera espacio de memoria*/
          return temp;
     }
     else
     return '\0';
}



int main()
{
      double media=0, desviacion=0,numero;
      int n;
      cin>>n;
      for(int i=0;i<n;i++)                       /*-c lee el ingreso de los datos de 0 a n*/
      {
          cin>>numero;
        INSERT(numero);                    /*-c guardamos en la lista ligadas*/
        media+=numero;                     /*-c calculamos la sumatoria para la media*/
      }
      media=media/n;                          /*-c calculamos la media*/
      for(int i=0;i<n;i++)                     /*-c ciclo para hacer sumatoria de desviacion estandar*/
      {
        desviacion+=pow((REMUEVE()-media),2);
      }
      desviacion= pow((desviacion/n-1),.5);                 /*-c terminamos de calcular la desviacion estandar*/
      cout<<"Media "<<media<<endl<<"Desviacion "<<desviacion<< endl;   /*-c imprime resultados*/
      system("PAUSE");
      return 0;
}
