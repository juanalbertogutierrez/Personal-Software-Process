/*+++++++++++++++++++++++Program++++++++++++++++++++++++
Version: 1.3
Nombre: Juan Alberto Gutierrez Canto
Fecha:  11/02/2016
Descripcion: Programa 2A de la materia proceso personal de software, programa que cuenta las loc´s del codigo
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*+++++++++++++++++++++Contenido++++++++++++++++++++++++
LOC reusadas: 0
LOC modificadas: 15
LOC compilación : 146
Librerias:
    <iostream>
    <stdio.h>
    <string>
Clases: N/A
Funciones:
    void FUNCION();
Surce code in C:\Users\equipo\Documents\Personal Process Software\2A\main.cpp
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/



#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int contador_comentario,contador_globallocs=0;
/*++++++++++++++++++++ seccion ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Function: FUNCION()
Propósito: cuanta las loc's logicas y los comentarios
In/out: direccion del archivo/no aplica
Limitaciones: ninguna

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void FUNCION(FILE *archivo_lectura)
{
    char caracter[200];
    int contador_funcion=0,i;
    fgets(caracter,200,archivo_lectura);
    if(caracter[0] == '{')
    {
        while(caracter[0] != '}')
        {
            fgets(caracter,200,archivo_lectura);
            i=200;
            while(i--)
            {
                if(caracter[i] == '/' && caracter[i-1] == '*')
                {
                    caracter[i]='2';
                    contador_comentario++;
                    break;
                }
            }
            contador_funcion++;
        }
    }
    contador_funcion++;
    cout<<contador_funcion<<" Locs\n\n";
    contador_globallocs+=contador_funcion;

}

int main()
{
    int numero_archivo=1;
    char archivo[30],caracter[205];
    FILE *archivo_lectura;
    while(numero_archivo){
        cout<<"Primero copia el archivo que desea contar \na la carpeta del programa \n";
        cout<<"una vez echo esto:\n\nIntroduce el nombre del codigo fuente a analizar"<<endl;
        cin>>archivo;
        archivo_lectura=fopen(archivo,"r");/*-c se habre el codigo a revisar*/
        contador_comentario=0;/*-I la variable es contador de loc comentario*/
        contador_globallocs=0;/*-Ila variable es contador de loc general*/
        if(archivo_lectura == NULL)/*-c verifica si existe el archivo*/
            cout<<"No se encontro el archivo";
        else
        {
             while (feof(archivo_lectura) == 0)/*-c recorrer el archivo hasta que se acabe*/
            {
                fgets(caracter,200,archivo_lectura);/*-c funcion para cachar lineas del archivo*/
                if(caracter[0] == '/' &&  caracter[1] == '*')/*-c encontrar comentarios de caja*/
                {
                    while(caracter[0] != '*' && caracter[1] != '/')/*-c saltar lineas de comentarios de caja*/
                    {
                        fgets(caracter,200,archivo_lectura);
                    }
                    contador_comentario++;
                }
                if(caracter[0] == 'i' && caracter[1] == 'n' && caracter[2] == 't')/*-c cuenta loc's logicas y comentario funcion int*/
                {
                        cout<<"Funcion .- "<<caracter;
                        FUNCION(archivo_lectura);
                        fgets(caracter,200,archivo_lectura);
                }
                if(caracter[0] == 'v' && caracter[1] == 'o' && caracter[2] == 'i')/*-c cuenta loc's logicas y comentario funcion void*/
                {
                        cout<<"Funcion .- "<<caracter;
                        FUNCION(archivo_lectura);
                }
                if(caracter[0] == 'f' && caracter[1] == 'l' && caracter[2] == '0')/*-c cuenta loc's logicas y comentario funcion float*/
                {
                        cout<<"Funcion .- "<<caracter;
                        FUNCION(archivo_lectura);
                }
                if(caracter[0] == 'c' && caracter[1] == 'h' && caracter[2] == 'a')/*-c cuenta loc's logicas y comentario funcion char*/
                {
                       cout<<"Funcion .- "<<caracter;
                       FUNCION(archivo_lectura);
                }
                if(caracter[0] == 's' && caracter[1] == 't' && caracter[2] == 'r')/*-c cuenta loc's logicas y comentario funcion string*/
                {
                       cout<<"Funcion .- "<<caracter;
                       FUNCION(archivo_lectura);
                }
                if(caracter[0] == 'd' && caracter[1] == 'o' && caracter[2] == 'u')/*-c cuenta loc's logicas y comentario funcion double*/
                {
                       cout<<"Funcion .- "<<caracter;
                       FUNCION(archivo_lectura);
                }
                if(caracter[0] == 'c' && caracter[1] == 'l' && caracter[2] == 'a')/*-c cuenta loc's logicas y comentario clases*/
                {
                       cout<<"Clase .- "<<caracter;
                       FUNCION(archivo_lectura);
                }
                if(caracter[0] == '#')/*-c cuenta loc's define y librerias*/
                {
                      contador_globallocs++;
                }

            }
            contador_globallocs+=contador_comentario;
            cout<<"Comentarios "<<contador_comentario<<" Loc's\n\n";
            cout<<"Lineas totales de codigo(loc's) --"<<contador_globallocs<<"--\n";
        }
        cout<<"\nDesea leer otro archivo?\n1=si 0=no\n";
        cin>>numero_archivo;
    }
    return 0;
}
