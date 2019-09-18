#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BibliotecaUtn/utn.h"
#include "../BibliotecaUtn/utn_array.h"
#include "../BibliotecaUtn/utn_menu.h"
#include "../BibliotecaUtn/utn_menu.h"
#define MAX_CARACTERES 41
#define MAX_QTY 3


int bubbleSort(eAlumno pArray[],int cantidad);
int main()
{

    /** fgets(cant,sizeof,stdin) cant de elementos del array, si se trabaja con arrays, sizeof(del tipo de dato),origne o ingreso de la informacion, si no se trabaja con
    archivos se usa el stdin (standar input)
    fgets coloca un '\n' al final de la cadena. se debe pisar con un '\0' */
    eAlumno vecAlumnos[MAX_QTY];
    eAlumno vecAux[3]={{"juan alberto","samid",1,{1,5,1990},'m',65,7,7,14,1},{"acero","massa",2,{1,5,1985},'m',55,8,7,15,1},{"juan carlos","cepacuercia",3,{31,4,1945},'m',15,10,10,10,1}};
    printf("Nombre\t\tApellido\tLegajo\tFecha de nacimiento\tsexo\tEdad\tNota1\tnota2\tpromedio\n");
    mostrarArrayDeElementos(vecAux,3);
    //cargaArray(vecAlumnos,MAX_QTY);
    //printf("Nombre  Apellido Legajo Fecha de nacimiento sexo Edad Nota1 nota2 promedio\n");
    //mostrarArrayDeElementos(vecAlumnos,MAX_QTY);*/

    bubbleSort(vecAux,3);
    printf("\nDespues del ordenamiento\n");
    mostrarArrayDeElementos(vecAux,3);

    return 0;
}
/**
ingresar el legajo
verificar si existe ese legajo ¿como lo verifico?
recorres el array, buscando el estado en 1.

*/
int bubbleSort(eAlumno pArray[],int cantidad)
{

    int flag=-1;
    eAlumno auxAlumno;
    eAlumno copiaAlumno[cantidad];
    //int* pAux=array;
    for(int i=0;i<cantidad;i++)
    {
        copiaAlumno[i]=pArray[i];
    }
    while(flag==-1)
    {
        flag=0;
        for(int i=0; i<cantidad-1; i++)
        {
            if( stricmp(copiaAlumno[i].nombre,copiaAlumno[i+1].nombre)>0)
            {
                auxAlumno=copiaAlumno[i];
                copiaAlumno[i]=copiaAlumno[i+1];
                copiaAlumno[i+1]=auxAlumno;

                flag=-1;
            }
        }
    }
     for(int i=0;i<cantidad;i++)
    {
        pArray[i]=copiaAlumno[i];
    }
    //array=pAux;
    return 0;
}
