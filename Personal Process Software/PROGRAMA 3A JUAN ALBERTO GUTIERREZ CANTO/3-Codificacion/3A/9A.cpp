/*Version: 1.2
Nombre: Juan Alberto Gutierrez Canto
Fecha:  14/07/2016
Descripcion: Programa 9A de la materia proceso personal de software, programa que calcula
                normalizacion de datos de x^2
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*+++++++++++++++++++++Contenido++++++++++++++++++++++++
LOC reusadas: 78
LOC modificadas: 15
LOC compilación : 165
Librerias:
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <malloc.h>
#include <math.h>
#define PI 3.1416
Clases: N/A
Funciones:
PEDIRDATOS()
CALCULARRANGO()
XI()
XI2()
EXPX()
FXI()
TERM()
RESULTADOS()
Surce code in C:\Users\equipo\Documents\Personal Process Software\5A\main.cpp
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <malloc.h>
#include <math.h>
#define PI 3.1416

using namespace std;
double tablavaloresnor[10][10];

/*++++++++++++++++++++ REUTILIZACION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: struct nodo()
Propósito: estructura para guardar dos datos doubles, con una liga
In/out: N/A
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

struct nodo{
    double numerox;
    double numeroy;
    struct nodo *sig;
}; struct nodo *raiz=NULL, *last=NULL;

/*+++++++++++++reutilizado +++++++++++++++++++
Function: ISEMPTY()
Propósito: revisar si la lista esta vacia
In/out: no aplica/1 esta vacia-0 no esta vacia
Limitaciones: no aplica

+++++++++++++++++++++++++++++++++++++++++++
*/

int ISEMPTY()
{
    if(raiz== NULL)
        return 1;
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

void INSERT(double datox)
{
    struct nodo *nuevo=NULL;
    if(ISEMPTY())
    {
        nuevo=(struct nodo *)malloc(sizeof(struct nodo));
        nuevo->numerox=datox;
        nuevo->sig=NULL;
        raiz=last=nuevo;
    }
    else
    {
        nuevo=(struct nodo *)malloc(sizeof(struct nodo));
        nuevo->numerox=datox;
        nuevo->sig=NULL;
        last->sig=nuevo;
        last=nuevo;
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
{
    struct nodo *elimina=NULL;
    if(!ISEMPTY())
    {
        elimina=raiz;
        raiz=raiz->sig;
        free(elimina);
    }
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: PEDIRDATOS()
Propósito: pedir los datos que se van a utilizar para las formulas y asignar datos duros
In/out: N/A
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

int PEDIRDATOS()
{
    double datox;
    double datoy;
    long long n;
    long long i;
    printf("Introduce el numero de datos n\n");
    cin>>n;
    for(i=0;i<n;i++)
    {
        printf("dame el numero %d\n",i+1);
        cin>>datox;
        INSERT(datox);
    }
    return n;
}

/*++++++++++++++++++++ REUTILIZACION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: BURBUJALTST()
Propósito: ordena los datos de una lista ligada
In/out: n de datos
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void BURBUJALTST(int n)
{
    struct nodo *inicio;
    struct nodo *auxiliar;
    double datox;
    long i;
    long y;
    double datoy;
    i=0;
    y=0;
    inicio=raiz;
    while(i<n)
    {
        y=i+1;
        auxiliar=inicio->sig;
        while(y<n)
        {
            if(true)
            {
                if(inicio->numerox>auxiliar->numerox)
                {
                    datox=auxiliar->numerox;
                    datoy=auxiliar->numeroy;
                    auxiliar->numerox=inicio->numerox;
                    auxiliar->numeroy=inicio->numeroy;
                    inicio->numerox=datox;
                    inicio->numeroy=datoy;
                }
            }
            else
            {
                if(inicio->numeroy>auxiliar->numeroy)
                {
                    datox=auxiliar->numerox;
                    datoy=auxiliar->numeroy;
                    auxiliar->numerox=inicio->numerox;
                    auxiliar->numeroy=inicio->numeroy;
                    inicio->numerox=datox;
                    inicio->numeroy=datoy;
                }
            }
            y++;
            auxiliar=auxiliar->sig;
        }
        i++;
        inicio=inicio->sig;

    }
}

/*++++++++++++++++++++ REUTILIZACION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: AVG()
Propósito: calcula el average de una serie de numeros
In/out: n numeros/average
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double AVG(int n)
{
    struct nodo *inicio=NULL;
    double avgdata;
    long i;
    inicio=raiz;
    avgdata=0;
    for(i=0;i<n;i++)
    {
        avgdata+=inicio->numerox;
        inicio=inicio->sig;
    }
    avgdata=avgdata/n;
    return avgdata;
}

/*++++++++++++++++++++ REUTILIZACION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: VARIANZA()
Propósito: calcula la varianza de n datos
In/out: n datos, average /varianza
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double VARIANZA(int n,double avgdata)
{
    struct nodo *inicio=NULL;
    double varianza;
    long i;
    inicio=raiz;
    varianza=0;
    for(i=0;i<n;i++)
    {
        varianza+=pow((inicio->numerox - avgdata),2);
        inicio=inicio->sig;
    }
    varianza=varianza/(n-1);
    return varianza;
}

/*++++++++++++++++++++ REUTILIZACION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: CALRANGOS()
Propósito: calcula los segmentos que se pueden usar para la normalizacion
In/out: n numero de datos/numero de segmentos
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

int CALRANGOS(int n)
{
    int s;
    int i;
    if(n%5==0)
    {
        for(i=0;i<(n/5);i++)
        {
            tablavaloresnor[3][i]=5;
        }
        return n/5;
    }
    else if(n%5==4)
    {
        for(i=0;i<(n/5);i++)
        {
            tablavaloresnor[3][i]=5;
        }
        tablavaloresnor[3][i]=4;
        return (n/5)+1;
    }
    else if(n%5<4)
    {
        for(i=0;i<((n/5)-1);i++)
        {
            tablavaloresnor[3][i]=5;
        }
        for(i=0;i<((n%5)+5);i++)
        {
            tablavaloresnor[3][i+1]++;
        }
        return (n/5)-1;
    }

}

/*++++++++++++++++++++ REUTILIZAR ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: REGLASMPNOR()
Propósito: calcula la regla de simpson de la forma normal
In/out: valor de xlow, xhigh, numero de bloques/resultados
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double REGLASMPNOR(double xlow,double xhigh,double N)
{
    double w;
    double fija;
    double x2;
    double ex;
    double fx;
    double term;
    double sumterm;
    bool negative;
    int i;
    sumterm=0;
    negative=false;
    fija=1.0/sqrt(2*PI);
    if(xhigh<0)
    {
        xhigh=xhigh*(-1);
        negative=true;
    }
    w=xhigh/N;
    for(i=0;i<=20;i++)
    {
        x2=pow(xlow,2)/2.0;
        ex=exp(-x2);
        fx=ex*fija;
        if(i==0||i==20)
        {
            term=fx*(w/3.0);
        }
        else if(i%2==0)
        {
            term=2.0*fx*(w/3.0);
        }
        else
        {
            term=4.0*fx*(w/3.0);
        }
        sumterm+=term;
        xlow+=w;
    }
    if(negative)
    {
        sumterm-=.5;
        sumterm*=-1;
    }
    else
    {
        sumterm+=.5;
    }
    return sumterm;
}

/*++++++++++++++++++++ REUTILIZABLE ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: SECNORMAL()
Propósito: calcula las secciones de la formula para la normalizacion.
In/out: no de datos/calidad q
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double SECNORMAL(int n)
{
    struct nodo *inicio=NULL;
    double sumterm;
    double rglsmps;
    long segmentos;
    double pk;
    double contsegment;
    double pabove;
    double pbelow;
    double xbelow;
    double xabove;
    double busqueda;
    double contador;
    int i;
    segmentos=CALRANGOS(n);
    rglsmps=-4;
    sumterm=0;
    contsegment=0;
    pabove=0;
    inicio=raiz;
    busqueda=inicio->numeroy;
    tablavaloresnor[1][0]=-100000;
    for(i=0;i<segmentos;i++)
    {
        contsegment+=tablavaloresnor[3][i];
        pk=(1.0/n)*contsegment;
        do
        {
            pbelow=pabove;
            xbelow=xabove;
            pabove=REGLASMPNOR(0,rglsmps,20);
            xabove=rglsmps;
            rglsmps+=.1;
        }while(pabove<pk);
        tablavaloresnor[2][i]=xbelow+((pk-pbelow)/(pabove-pbelow))*(xabove-xbelow);
        tablavaloresnor[1][i+1]=tablavaloresnor[2][i];
        contador=0;
        while(busqueda<tablavaloresnor[2][i])
        {
            contador++;
            if(inicio->sig==NULL)
                break;
            inicio=inicio->sig;
            busqueda=inicio->numeroy;
        }
        tablavaloresnor[4][i]=contador;
        tablavaloresnor[5][i]=pow(tablavaloresnor[3][i]-tablavaloresnor[4][i],2);
        tablavaloresnor[6][i]=tablavaloresnor[5][i]/tablavaloresnor[3][i];
        sumterm+=tablavaloresnor[6][i];

    }
    return sumterm;
}

/*++++++++++++++++++++ REUTILIZABLE ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: REGLASPMX2()
Propósito: calcula la regla de simpson para la forma x^2
In/out: valor de xlow, xhigh, numero de bloques, grados de libertad/ resultado de la grafica
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double REGLASPMX2(double xlow,double xhigh,double N,double n)
{
    double w;
    double tfija;
    double fija;
    double xan;
    double exa;
    double fx;
    double term;
    bool negative;
    int i;
    double sumterm;
    negative=false;
    tfija=1;
    sumterm=0;
    for(i=1;i<n;i+=2)
    {
        tfija=tfija*(i/2.0);
    }
    tfija=tfija*sqrt(PI);
    fija=pow(2,(n/2));
    if(xhigh<0)
    {
        xhigh=xhigh*-1;
        negative=false;
    }
    w=xhigh/N;
    for(i=0;i<=N;i++)
    {
        xan=pow(xlow,(n/2)-1);
        exa=exp(-(xlow/2));
        fx=(xan*exa)/(fija*tfija);
        if(i==0||i==20)
        {
            term=fx*(w/3);
        }
        else if(i%2==0)
        {
            term=2*fx*(w/3);
        }
        else
        {
            term=4*fx*(w/3);
        }
        sumterm+=term;
        xlow+=w;
    }
    if(negative)
    {
        sumterm-=.5;
    }
    else
    {
        sumterm+=.5;
    }
    return sumterm;
}

/*++++++++++++++++++++ REUTILIZABLE ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: PROBABILIDAD()
Propósito: calcula la probabilidad 1-p
In/out: prob numero a calcular
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double PROBABILIDAD(double prob)
{
    prob=1-prob;
    return prob;
}

/*++++++++++++++++++++ REUTILIZABLE ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: NORMALIZACION()
Propósito: calcula la calidad de los datos normalizando
In/out: n numero de datos/ probabilidad
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

double NORMALIZACION(int n)
{
    double xavg;
    double varianza;
    double dest;
    double q;
    double simx2;
    double p;
    struct nodo *inicio=NULL;
    int i;
    double aux;
    inicio=raiz;
    xavg=AVG(n);
    varianza=VARIANZA(n,xavg);
    varianza=sqrt(varianza);
    for(i=0;i<n-1;i++)
    {
        aux=(inicio->numerox -xavg)/varianza;
        inicio->numeroy=aux;
        inicio=inicio->sig;
    }
    q=SECNORMAL(n);
    cout<<"q "<<q<<endl;
    p=REGLASPMX2(0,q,20,9);
    p=p-REGLASPMX2(0,q,40,9);
    p=1-p;
    p=PROBABILIDAD(p);
    return p;
}

/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: main()
Propósito: funcion principal
In/out: N/A
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

int main()
{
    int n;
    freopen("prueba2.txt","r",stdin);
    n=PEDIRDATOS();
    BURBUJALTST(n);
    cout<<"resultado "<<NORMALIZACION(n);
    return 0;
}
