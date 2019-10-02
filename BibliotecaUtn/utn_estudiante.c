#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BibliotecaUtn/utn.h"
#include "utn_estudiante.h"

int inicializarArray(eEstudiante pArray[],int cantidad)
{
    int retorno=-1;
    if(pArray!=NULL && cantidad>0)
    {
        for(int i=0; i<cantidad; i++)
        {
            pArray[i].estado=0;
        }
        retorno=0;
    }
    return retorno;
}

int buscarEspacioLibre(eEstudiante pArray[],int cantidad)
{
    int retorno=-1; // es que NO esta vacio el  array
    if(pArray!=NULL && cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            if(pArray[i].estado == 0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int buscarLegajo(eEstudiante pArray[],int cantidad,int legajo,int* posicionLegajo)
{
    int retorno=1;//no existe. cero, existe
    if(pArray!=NULL && cantidad>0)
    {
         for(int i=0;i<cantidad;i++)
        {
            if(pArray[i].estado==1)
            {
                if(pArray[i].id_estudiante==legajo)
                {
                    retorno=0;
                    *posicionLegajo=i;
                    break;
                }

            }

        }
    }

    return retorno;
}
int cargaArray(eEstudiante pArray[],int cantidad,eMateria materias[], int sizeMateria)
{
    int pos;
    int retorno=0;
    int auxLegajo;
    int auxID_materia;
    int posicionLegajo;
    char auxNombre[MAX];

     pos=buscarEspacioLibre(pArray,cantidad);
     if(pArray[pos].estado==0)
     {
         if(getInt(&auxLegajo,"Ingrese ID estudiante, debe estar entre 1 y 100:","Error. El ID debe estar entre 1 y 100\n",1,100,3)==0)
            {
                if(buscarLegajo(pArray,cantidad,auxLegajo,&posicionLegajo)==0)
                {
                    printf("Ese ID ya existe.\n");
                    return 1;
                }

            }
            else
            {
                return 1;
            }

            if(!getString(auxNombre,"Ingrese su nombre:","Error. El nombre debe contener minimo 2 y maximo 40 caracteres.\n",2,MAX-1,3)==0)
            {
                return 1;
            }
            strcpy(pArray[pos].nombre,auxNombre);
            pArray[pos].id_estudiante=auxLegajo;

            pArray[pos].estado=1;
            materias[pos].estado=1;

     }
     else
     {
         printf("ya no hay mas espacio\n");
         retorno=-1;
     }
    return retorno;
}

void mostrarUnElemento(eEstudiante pArray,eMateria pCarrera)
{


    printf("%d\n%s\n%s\n",pArray.id_estudiante,pArray.nombre,pCarrera.descripcion);
  // printf("%d\n%s\%sn",pArray.id_estudiante,pArray.nombre);
    //printf("%s  %s\n",pArray.nombre,pArray.apellido);

}
int obtenerDescripcion(eMateria materias[],int cantCarrera,int id_encontrar,char* descripcion)
{
    int retorno=0;
    if(materias!=NULL && cantCarrera>0)
    {
        for(int i=0;i<cantCarrera;i++)
        {
            if(materias[i].id_materia==id_encontrar)
            {
                strcpy(descripcion,materias[i].descripcion);
            }
        }
    }
    return retorno;
}

int mostrarArrayDeElementos(eEstudiante pArray[],int cantidad,eMateria materias[],int cantCarrera)
{
    int retorno=1;
    if(pArray!=NULL && cantidad>0)
    {

        for(int i=0; i<cantidad; i++)
        {
            if(pArray[i].estado!=0)
            {

                printf("\n");
                mostrarUnElemento(pArray[i],materias[i]);
                retorno=0;
            }
        }
    }
    else
    {
        retorno=1;
    }



    return retorno;
}

int bajaLogica(eEstudiante array[],int cantidad,eMateria materias[],int cantCarrera)
{
    int retorno=1;
    int auxLegajo;
    int posicionLegajo;
    char seguir[2];
    if(array!=NULL && cantidad>0)
    {
        if(!getInt(&auxLegajo,"Ingrese ID de estudiante:","Error. El ID debe ser de 1 a 100.\n",1,100,3)==0)
        {
            return 1;
        }
        for(int i=0;i<cantidad;i++)
        {
            if(array[i].estado==1)
            {

                if(buscarLegajo(array,cantidad,auxLegajo,&posicionLegajo)==0)
                {

                   mostrarUnElemento(array[posicionLegajo],materias[posicionLegajo]);
                    printf("posicion de ese elemento:%d\n",posicionLegajo);
                    if(botonSeguir(seguir,"Para dar de baja pulse [S], caso contrario pulse cualquier tecla:","Ingrese solo una letra.\n",2)==0)
                    {
                        printf("Baja dada con exito. Adios !\n");
                        array[posicionLegajo].estado=0;
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    printf("No existe el legajo.\n");
                    break;
                }
            }
        }

    }
    return retorno;
}

int informe_UNO(eEstudiante arrayEstudiante[],int sizeEstudiante,eMateria arrayMaterias[],int sizeMaterias,eCurso arrayCurso[],int sizeCurso)
{
    int retorno=0;
    int aux_id_estudiante;
    int aux_id_materia;
    char auxNombre[MAX];

    if(!getString(auxNombre,"Ingrese nombre a buscar:","error.\n",1,MAX-1,3)==0)
    {
        return 1;
    }

    for(int i=0;i<sizeEstudiante;i++)
    {
        if(stricmp(auxNombre,arrayEstudiante[i].nombre)==0)
        {

            printf("Nombre:%s\nMateria:%s\n",arrayEstudiante[i].nombre,arrayMaterias[i].descripcion);
        }

    }


    return retorno;

}

int altaCurso(eCurso cursos[],int sizeCurso,eEstudiante estudiantes[],int sizeEstudiante,eMateria materias[],int sizeMateria)
{
    int retorno=0;
    int auxID;

    if(cursos!=NULL && sizeCurso >0 && estudiantes !=NULL && sizeEstudiante >0 && materias!=NULL && sizeMateria >0)
    {
        for(int i=0; i<sizeEstudiante;i++)
        {
            if(estudiantes[i].estado==1)
            {
                printf("Nombre:%s\nID:%d\n",estudiantes[i].nombre,estudiantes[i].id_estudiante);
                printf("\n");
                if(!getInt(&auxID,"Ingrese el ID a buscar:","Error. ID debe ser entre 1 y 100.\n",1,100,3)==0)
                {
                    return 1;
                }
                else
                {
                    getString(,"","",1,MAX-1,3);
                }
            }
        }
    }
    return retorno;
}
