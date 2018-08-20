/*+++++++++++++++++++++++Program++++++++++++++++++++++++
Version: 1.0
Nombre: Juan Alberto Gutierrez Canto
Fecha:  26/06/2016
Descripcion: Programa 8A de la materia proceso personal de software, programa que ordena una lista de x,y numeros
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*+++++++++++++++++++++Contenido++++++++++++++++++++++++
LOC reusadas:55
LOC modificadas:10
LOC compilación :215
Librerias:
#include <cstdlib>
#include <iostream>
#include<stdlib.h>
#include <stdio.h>
#include <malloc.h>
Clases: N/A
Funciones:
int ISEMPTY()
void INSERT(double datox,double datoy)
void REMUEVE()
void PEDIRDATOS()
void BURBUJALTST()
int main()
source: C:\Users\equipo\Documents\proceso personal de software 2\PROGRAMA 8A JUAN ALBERTO GUTIERREZ CANTO\3-Codificacion
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include <iostream>
#include<stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

bool ambas=false;
long long n;

struct nodo
{                            /*-c estructura para guardar las listas ligadas*/
      double datox,datoy;
      struct nodo *sig;
};struct nodo *raiz=NULL, *last=NULL;

/*+++++++++++++reutilizado +++++++++++++++++++
Function: ISEMPTY()
Propósito: revisar si la lista esta vacia
In/out: no aplica/1 esta vacia-0 no esta vacia
Limitaciones: no aplica

+++++++++++++++++++++++++++++++++++++++++++
*/

int ISEMPTY()
{                           /*-c funcion para saber si esta vacia las listas ligadas*/
     if(raiz == NULL)                        /*-c esta vacia la lista?? 1-si 0-no*/
           return 1;
     else
           return 0;
}

/*+++++++++++++++++++reutilizado++++++++++++++++++++++++++
void INSERT(double dato)
Descripcion: insertar un dato en un nuevo nodo
Limitaciones: tipo de dato double
Input: double datox,datoy;
Output: no aplica;
++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void INSERT(double datox,double datoy)
{                                   /*-c insertar un dato en un nuevo nodo*/
     struct nodo *nuevo = NULL;                /*-c nuevo nodo*/
     if(ISEMPTY())
     {
           nuevo = (struct nodo *)malloc( sizeof (struct nodo));   /*-c inserta si no hay ninguna lista todavia*/
           nuevo->datox = datox;
           nuevo->datoy=datoy;
           nuevo-> sig = NULL;
           raiz = last = nuevo;
     }
     else
     {
           nuevo = (struct nodo *)malloc( sizeof (struct nodo));    /*-c insertar cuando ya existe un nodo*/
           nuevo->datox = datox;
           nuevo->datoy=datoy;
           nuevo-> sig = NULL;
           last->sig = nuevo;
           last = nuevo;
     }
}

/*+++++++++++++++++++reutilizado++++++++++++++++++++++++++
double REMUEVE()
Descripcion: emueve datos de la lista elimina el nodo
Limitaciones: tipo de dato double
Input: no aplica
Output: datos
++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void REMUEVE()
{                               /*-c regresar dato de la lista ligada*/
     struct nodo *elimina = NULL;
     if(!ISEMPTY())
     {
          elimina = raiz;
          raiz = raiz-> sig;      /*-c o raiz = elimina -> sig;*/
          free(elimina);                    /*-c libera espacio de memoria*/
     }
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: PEDIRDATOS()
Propósito: pedir los datos que se van a utilizar para las formulas y asignar datos duros
In/out: tasa distribucion
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void PEDIRDATOS()
{
    double datox,datoy;
    long long i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>datox>>datoy;
        INSERT(datox,datoy);
    }
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: BURBUJALTST()
Propósito: ordenar una serie de x, y datos
In/out: lista de datos desordenada / lista de datos ordenada
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void BURBUJALTST()
{
    double datox;
    double datoy;
    long long i;
    long long y;
    struct nodo *inicio=NULL;
    struct nodo *auxiliar=NULL;
    i=0;
    y=0;
    inicio=raiz;
    while(i<n)
    {
        y=i+1;
        auxiliar=inicio->sig;
        while(y<n)
        {
            if(ambas == false)
            {
                if(inicio->datox>auxiliar->datox)
                {
                    datox=auxiliar->datox;
                    datoy=auxiliar->datoy;
                    auxiliar->datox=inicio->datox;
                    auxiliar->datoy=inicio->datoy;
                    inicio->datox=datox;
                    inicio->datoy=datoy;
                }
            }
            else
            {
                if(inicio->datoy>auxiliar->datoy)
                {
                    datox=auxiliar->datox;
                    datoy=auxiliar->datoy;
                    auxiliar->datox=inicio->datox;
                    auxiliar->datoy=inicio->datoy;
                    inicio->datox=datox;
                    inicio->datoy=datoy;
                }
            }
            y++;
            auxiliar=auxiliar->sig;
        }
        i++;
        inicio=inicio->sig;

    }
    i=0;
    inicio=raiz;
    while(i<n)
    {
        printf("%.2f %.2f\n",inicio->datox,inicio->datoy);
        inicio=inicio->sig;
        i++;
    }
    if(ambas==false)
    {
        ambas=true;
        BURBUJALTST();
    }
}


int main()
{
    freopen("prueba1.txt","r",stdin);
    PEDIRDATOS();
    BURBUJALTST();
    return 0;
}
