/*+++++++++++++++++++++++Program++++++++++++++++++++++++
Version: 1.0
Nombre: Juan Alberto Gutierrez Canto
Fecha:  04/04/2016
Descripcion: Programa 5A de la materia proceso personal de software, programa que calcula
                la distribucion normal con la formula de simpson
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*+++++++++++++++++++++Contenido++++++++++++++++++++++++
LOC reusadas: 78
LOC modificadas: 15
LOC compilación : 165
Librerias:
#include <iostream>
#include <math.h>
#include <stdio.h>
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
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1416

using namespace std;
float xlow,xhigh, w,pasado;
int Nbloques;
bool primera=false;
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: PEDIRDATOS()
Propósito: pedir los datos que se van a utilizar para las formulas y asignar datos duros
In/out: tasa distribucion
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
void PEDIRDATOS()
{
    xlow=0;
    Nbloques=20;
    cout<<"Introduce el valor de x"<<endl<<"x - ";
    cin>>xhigh;
    pasado=0;
}
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: CALCULARRANGO()
Propósito: calcula el rango y los bloques
In/out: no aplica/no aplica
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
void CALCULARRANGO()
{
    float xhigh_abs;
    xhigh_abs=xhigh;
    if(xhigh<0)
        xhigh_abs=xhigh*-1;
    w=xhigh_abs/Nbloques;
}
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: XI()
Propósito: calcula los valores de la formula xi
In/out: no aplica/xi
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
float XI()
{
    float xi=0;
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
Function: CXI2()
Propósito: calcula los datos de la formula xi^2
In/out: no aplica/xi2
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
float XI2()
{
    float xi2;
    xi2=pow(XI(),2)/2;              //-c se eleva al cuadrado xi
    return xi2;
}
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: EXPX()
Propósito: calcula el exponencial de un numero dado por la funcionXI2()
In/out: no aplica/valor
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
float EXPX()
{
    float valor;
    valor=exp(-XI2());              //-c exponencial de xi
    return valor;
}
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function:FXI()
Propósito: calcula fx para la distribucion
In/out: no aplica/fx
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

float FXI()
{
    float fx;
    fx= EXPX()/sqrt(2*PI);              //-c calculamos la raiz de un numero y sirve de divisro para un exponencial
    return fx;
}
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: TERM()
Propósito: calcula el termino de la distribucion
In/out: int i/ float term
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

float TERM(int i)                       //-c recive la posicion del dato
{
    float term;
    if(i== 0 || i== Nbloques)           //-c calculamos term con las reglas de que si son la pocicion inicial y final se completa la siguiente formula
    {
        term=(FXI()*w)/3;
    }
    else if(i%2 == 0)                   //-c los datos no son iniciales, por lo tanto revisamos si son pares
    {
        term=2*FXI()*w/3;
    }
    else                                //-c los datos no son pares
    {
        term=4*FXI()*w/3;
    }
    cout<<term<<endl;
    return term;
}
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: RESULTADO()
Propósito: imprime el resultado
In/out: total/no aplica
Limitaciones: ninguna
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
void RESULTADO(float total)
{
    float resultado;
    if(xhigh<0)
    {
        resultado=0.5-total;                //-c calculamos el resultado restando a 0.5 que es la distribucion normal, la suma de la suma de  los 20 terminos
    }
    else
    {
        resultado=0.5+total;                //-c calculamos el resultado sumando a 0.5 que es la distribucion normal, la suma de la suma de  los 20 terminos
    }
    cout<<resultado<<endl;              //-c imprimimos resultados
}


int main()
{
    float suma_term=0;
    PEDIRDATOS();                   //-f llamamos a pedir datos para recolectar datos
    CALCULARRANGO();
    for(int i=0;i<=Nbloques;i++)     //-c calculamos la distribucion para los 20 datos
    {
        suma_term+=TERM(i);         //-c realizamos la sumatoria de todos los terminos de la distribucion
    }
    cout<<"suma "<<suma_term<<endl;
    RESULTADO(suma_term);                    //-f mandamos a llamara a la funcion para imprimir resultado
    return 0;
}
