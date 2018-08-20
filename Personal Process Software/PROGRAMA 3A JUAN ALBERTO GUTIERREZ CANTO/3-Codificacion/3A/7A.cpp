/*+++++++++++++++++++++++Program++++++++++++++++++++++++
Version: 1.0
Nombre: Juan Alberto Gutierrez Canto
Fecha:  13/06/2016
Descripcion: Programa 7A de la materia proceso personal de software, programa que calcula
                la correlacion lineal de 2 series de numeros y su significancia y probabilidad
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*+++++++++++++++++++++Contenido++++++++++++++++++++++++
LOC reusadas: 105
LOC modificadas: 50
LOC compilación : 229
Librerias:
#include <cstdlib>
#include <iostream>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#define PI 3.1416
Clases: N/A
Funciones:
int ISEMPTY()
void INSERT(double datox,double datoy)
void REMUEVE()
void PEDIRDATOS()
float CALCULARCORRELACION()
float SIGNIFICANCIA()
void CALCULART1()
void CALCULART2()
void CALCULART3()
void CALCULARRANGO()
float XI()
float XI2()
float EXPX()
float FXI()
float TERM(int i)
float REGLASMP()
float PROBABILIDAD()
void RESULTADO()
int main()
source: C:\Users\equipo\Documents\proceso personal de software 2\PROGRAMA 7A JUAN ALBERTO GUTIERREZ CANTO\3-Codificacion
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include <iostream>
#include<stdlib.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#define PI 3.1416

using namespace std;
double xlow,xhigh,w,pasado,anterior,error,rt1,rt2,rt3,t,r,p;
int Nbloques,Nitems,n;
bool primera=false;

struct nodo
{                            /*-c estructura para guardar las listas ligadas*/
      double numerox,numeroy;
      struct nodo *sig;
};struct nodo *raiz=NULL, *last=NULL;

/*+++++++++++++seccion +++++++++++++++++++
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

/*+++++++++++++++++++seccion++++++++++++++++++++++++++
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

/*+++++++++++++++++++seccion++++++++++++++++++++++++++
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

/*++++++++++++++++++++ Reuso ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: PEDIRDATOS()
Propósito: pedir los datos que se van a utilizar para las formulas y asignar datos duros
In/out: tasa distribucion
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void PEDIRDATOS()
{
    double x,y;
    int i;
    xlow=0;
    Nbloques=20;
    error=0.000001;
    cout<<"Numero de datos n"<<endl<<"n - ";
    cin>>Nitems;
    cout<<"Ingresa los datos para la correlacion\n";
    for(i=0;i<Nitems;i++)
    {
        cin>>x>>y;
        INSERT(x,y);
    }
    pasado=0;
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: CALCULARCORRELACION()
Propósito: calcula la correlacion de dos series de datos
In/out: series de datos x, y/ r correlacion lineal
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double CALCULARCORRELACION()
{
    double x,y,val;
    double sumxcuadro=0,sumycuadro=0;
    double sumxy=0,sumx=0,sumy=0;
    int i,j;
    struct nodo *check=NULL;
    check=raiz;
    for(i=0;i<Nitems;i++)
    {
        x=check->numerox;
        y=check->numeroy;
        sumxy+=x*y;
        sumx+=x;
        sumy+=y;
        sumxcuadro+=x*x;
        sumycuadro+=y*y;
        check=check->sig;
        REMUEVE();
    }
    val=((n*sumxy)-(sumx*sumy))/(sqrt((((n*sumxcuadro)-(pow(sumx,2)))*((n*sumycuadro)-(pow(sumy,2))))));
    return (val);
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: SIGNIFICANCIA()
Propósito: calcula significancia de los valores de correlacion
In/out: r correlacion lineal/signifiacnia t
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double SIGNIFICANCIA()
{
    double absr=r;
    if(r<0)
        absr=r*(-1);
    return ((absr*sqrt(n-2))/(sqrt(1-pow(r,2))));
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: CALCULART1()
Propósito: calcula el valor gama 1 para la distribucion t de students
In/out: n grados de tolerancia / gama 1 rt1
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void CALCULART1()
{
    double val=1,a=2;
    int i;
    for(i=1;i<n;i+=2)
    {
        val*=i/a;
    }
    rt1=val*sqrt(PI);
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: CALCULART2()
Propósito: calcula el valor gama 2 para la distribucion t de students
In/out: n grados de tolerancia / gama 2 rt2
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void CALCULART2()
{
    double val=1;
    int i;
    for(i=2;i<((n+1)/2);i++)
    {
        val*=i;
    }
    rt2=val;
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: CALCULART3()
Propósito: calcula el valor gama 3 para la distribucion t de students
In/out: n grados de tolerancia / gama 3 rt3
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void CALCULART3()
{
    double val;
    val=PI*n;
    rt3=sqrt(val);
}

/*++++++++++++++++++++ Resuso ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: CALCULARRANGO()
Propósito: calcula el rango y los bloques
In/out: no aplica/no aplica
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void CALCULARRANGO()
{
    double xhigh_abs;
    xhigh_abs=xhigh;
    if(xhigh<0)
        xhigh_abs=xhigh*(-1);
    w=xhigh_abs/Nbloques;
    pasado=0;
    primera=true;
}

/*++++++++++++++++++++ Resuso ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: XI()
Propósito: calcula los valores de la formula xi
In/out: no aplica/xi
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double XI()
{
    double xi=0;
    if(!primera)
    {
        primera=true;
        return 0;
    }
    xi=pasado+w;            //-c incrementamso w al rango
    pasado=xi;
    return xi;
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: XI2()
Propósito: calcula los datos de la formula 1+xi^2/n
In/out: no aplica/xi2
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double XI2()
{
    double xi2;
    xi2=1+((pow(XI(),2))/n);              //-c se eleva al cuadrado xi
    return xi2;
}

/*++++++++++++++++++++ Reuso ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: EXPX()
Propósito: calcula el valor de XI2() elevado a -(n+1/2
In/out: no aplica/valor
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double EXPX()
{
    double valor;
    valor=pow(XI2(),(-((n+1)/2)));              //-c exponencial de xi
    return valor;
}

/*++++++++++++++++++++ Resuso ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function:FXI()
Propósito: calcula fx para la distribucion t students
In/out: no aplica/fx
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double FXI()
{
    double fx;
    fx= (rt2/(rt3*rt1))*EXPX();              //-c calculamos la raiz de un numero y sirve de divisro para un exponencial
    return fx;
}

/*++++++++++++++++++++ Reuso ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: TERM()
Propósito: calcula el termino de la distribucion
In/out: int i/ float term
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double TERM(int i)                       //-c recive la posicion del dato
{
    double term,a=2,b=3,c=4;
    if(i== 0 || i== Nbloques)           //-c calculamos term con las reglas de que si son la pocicion inicial y final se completa la siguiente formula
    {
        term=(FXI()*w)/b;
    }
    else if(i%2 == 0)                   //-c los datos no son iniciales, por lo tanto revisamos si son pares
    {
        term=a*FXI()*w/b;
    }
    else                                //-c los datos no son pares
    {
        term=c*FXI()*w/b;
    }
    return term;
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: REGLASMP()
Propósito: calcula el la regal de simpson para la distribucion t de students
In/out: no aplica/ float pasado
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double REGLASMP()
{
    double suma_term=0,nuevoerror,a=0.5;
    int i;
    anterior=0;
    Nbloques=10;
    do
    {
        Nbloques*=2;
        CALCULARRANGO();
        anterior=suma_term;
        suma_term=0;
        primera=false;
        for(i=0;i<=Nbloques;i++)     //-c calculamos la distribucion para los 20 datos
        {
            suma_term+=TERM(i);         //-c realizamos la sumatoria de todos los terminos de la distribucion
        }
        if(xhigh<0)
        {
            suma_term=a-suma_term;                //-c calculamos el resultado restando a 0.5 que es la distribucion normal, la suma de la suma de  los 20 terminos
        }
        else
        {
            suma_term=a+suma_term;                //-c calculamos el resultado sumando a 0.5 que es la distribucion normal, la suma de la suma de  los 20 terminos
        }
        nuevoerror=suma_term-anterior;
        if(nuevoerror<0)
            nuevoerror=nuevoerror*(-1.0);
    }while(nuevoerror > error);
    return anterior;
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: PROBABILIDAD()
Propósito: calcula la probabilidad de la distribucion t de students
In/out: no aplica/ float val
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double PROBABILIDAD()
{
    double val,a=2,b=1;
    val=a*(b-p);
    return val;
}
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: RESULTADO()
Propósito: cimprime los resultados, correlacion r, significancia t, probabilidad p
In/out: no aplica/ no aplica
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void RESULTADO()
{
    cout<<"r es: "<<r<<endl;              //-c imprimimos resultados
    cout<<"t es: "<<t<<endl;              //-c imprimimos resultados
    cout<<"2*(1-p) es: "<<p<<endl;              //-c imprimimos resultados

}

int main()
{
    freopen("prueba1.txt","r",stdin);
    PEDIRDATOS();
    n=Nitems;
    r=CALCULARCORRELACION();
    t=SIGNIFICANCIA();
    n=Nitems-1;
    CALCULART1();
    CALCULART2();
    CALCULART3();
    xhigh=t;
    p=REGLASMP();
    p=PROBABILIDAD();
    RESULTADO();
    return 0;
}
