/*+++++++++++++++++++++++Program++++++++++++++++++++++++
Version: 1.2
Nombre: Juan Alberto Gutierrez Canto
Fecha:  09/03/2016
Descripcion: Programa 6A de la materia proceso personal de software, programa que calcula
                rangos upi y lpi conjunto de n datos utilizando listas ligadas
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*+++++++++++++++++++++Contenido++++++++++++++++++++++++
LOC reusadas: 78
LOC modificadas: 15
LOC compilación : 165
Librerias:
#include <cstdlib>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <iostream>
Clases: N/A
Funciones:
INSERT()
ISEMPTY()
REMOVE()
LEERDATOS()
CALCULAB1()
CALCULAB0()
IMPRIMEDATOS()
Surce code in c:/documentos/psp/ejemplo.cpp
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <cstdlib>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <iostream>

using namespace std;

double arrmain[2],temSuma[2];
double sumyibs=0,sumxiavg=0;

struct nodo
{                            /*-c estructura para guardar las listas ligadas*/
      double numerox,numeroy;
      struct nodo *sig;
};struct nodo *raiz=NULL, *last=NULL;

/*+++++++++++++Reutilizacion +++++++++++++++++++
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

/*+++++++++++++++++++Reuse++++++++++++++++++++++++++
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
           nuevo->numerox = datox;
           nuevo->numeroy=datoy;
           nuevo-> sig = NULL;
           raiz = last = nuevo;
     }
     else
     {
           nuevo = (struct nodo *)malloc( sizeof (struct nodo));    /*-c insertar cuando ya existe un nodo*/
           nuevo->numerox = datox;
           nuevo->numeroy=datoy;
           nuevo-> sig = NULL;
           last->sig = nuevo;
           last = nuevo;
     }
}

/*+++++++++++++++++++Reuse++++++++++++++++++++++++++
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


void LEERDATOS(int nDatos)
{
    double numerox, numeroy,mediax=0,mediay=0;
    cout<<"Introduce los "<<nDatos<<" valores de x un espacio y"<<endl;
    for(int i=0;i<nDatos;i++)                       /*-c lee el ingreso de los datos de 0 a n*/
      {
          cin>>numerox>>numeroy;
        INSERT(numerox,numeroy);                    /*-c guardamos en la lista ligadas*/
        mediax+=numerox;
        mediay+=numeroy;                     /*-c calculamos la sumatoria para la media*/
      }
      arrmain[0]=mediax/nDatos;
      arrmain[1]=mediay/nDatos;
}

double CALCULAB1(int nDatos)
{
    double sumaXY=0,sumaXX=0,nxyavg,nxxavg;
    struct nodo *check=NULL;
    check=raiz;
    do{
        temSuma[0]=check->numerox;
        temSuma[1]=check->numeroy;
        sumaXY+=temSuma[0]*temSuma[1];
        sumaXX+=temSuma[0]*temSuma[0];
        check=check->sig;
    }while(check->sig != NULL);
    temSuma[0]=check->numerox;
    temSuma[1]=check->numeroy;
    sumaXY+=temSuma[0]*temSuma[1];
    sumaXX+=temSuma[0]*temSuma[0];
    nxyavg=arrmain[0]*arrmain[1]*nDatos;
    nxxavg=arrmain[0]*arrmain[0]*nDatos;
    return ((sumaXY -nxyavg)/(sumaXX -nxxavg));
}

double CALCULAB0(double B1)
{
    return (arrmain[1]-(B1*arrmain[0]));
}

double CALCULASTD(double b1,double b0,int n)
{
    double bss,yibs,xiavg;
    sumyibs=0;
    sumxiavg=0;
    struct nodo *check=NULL;
    check=raiz;
    do{
        temSuma[0]=check->numerox;
        temSuma[1]=check->numeroy;
        bss=b0+b1*temSuma[0];
        yibs=pow((temSuma[1]-b0-b1*temSuma[0]),2);
        sumyibs+=yibs;
        xiavg=pow((temSuma[0]-arrmain[0]),2);
        sumxiavg+=xiavg;
        check=check->sig;
    }while(check->sig != NULL);
    temSuma[0]=check->numerox;
    temSuma[1]=check->numeroy;
    bss=b0+b1*temSuma[0];
    yibs=pow((temSuma[1]-b0-b1*temSuma[0]),2);
    sumyibs+=yibs;
    xiavg=pow((temSuma[0]-arrmain[0]),2);
    sumxiavg+=xiavg;

    return sqrt(sumyibs/(n-2));
}

double CALCULARANGO(double t, double b0, double b1, int n,double xk)
{

    double primera=t*CALCULASTD(b1,b0,n);
    double segunda=sqrt(1+ (1/n)+ (pow((xk-arrmain[0]),2)/sumxiavg));
    return primera*segunda;
}

double CALCULAUPI(double rango,double xk)
{
    return xk+rango;
}

double CALCULALPI(double rango,double xk)
{
    return xk-rango;
}


int main()
{

      double B1,B0,rango,upi9,lpi9,xk,upi7,lpi7,yk;
      int nDatos;
      freopen("input6A.txt","r",stdin);
      cout<<"Introduce el numero de programas que tienes que registrar espacio y la cantidad de loc que se predicen"<<endl;
      cin>>nDatos>>xk;
      LEERDATOS(nDatos);
      B1=CALCULAB1(nDatos);
      B0=CALCULAB0(B1);
      rango=CALCULARANGO(1.860, B0,B1,nDatos,xk);
      yk=B0+B1*xk;
      upi9=CALCULAUPI(rango,yk);
      lpi9=CALCULALPI(rango,yk);
      rango=CALCULARANGO(1.108, B0,B1,nDatos,xk);
      upi7=CALCULAUPI(rango,yk);
      lpi7=CALCULALPI(rango,yk);
      cout<<"B1 = "<<B1<<endl<<"B0 = "<<B0<<endl<<"UPI(70%) = "<<upi7<<endl;
      cout<<"LPI(70%) = "<<lpi7<<endl<<"UPI(90%) = "<<upi9<<endl<<"LPI(90%) = "<<lpi9<<endl;
      system("PAUSE");
      return 0;
}
