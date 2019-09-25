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
                if(pArray[i].legajo==legajo)
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
int cargaArray(eEstudiante pArray[],int cantidad,eCarrera carreras[], int cantCarrera)
{
    int pos;
    int retorno=0;
    int auxLegajo;
    int auxID_carrera;
    int posicionLegajo;
    char auxNombre[MAX];

     pos=buscarEspacioLibre(pArray,cantidad);
     if(pArray[pos].estado==0)
     {
         if(getInt(&auxLegajo,"Ingrese legajo, debe estar entre 1 y 100:","Error. El legajo debe estar entre 1 y 100\n",1,100,3)==0)
            {
                if(buscarLegajo(pArray,cantidad,auxLegajo,&posicionLegajo)==0)
                {
                    printf("Ese legajo ya existe.\n");
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
            if(!getInt(&auxID_carrera,"Ingrese id de carrera.\n1-Programacion\n2-SPD\nOpcion:","Error. El la opcion debe estar entre 1 o 2\n",1,2,3)==0)
            {
                return 1;
            }
            strcpy(pArray[pos].nombre,auxNombre);
            pArray[pos].legajo=auxLegajo;
            pArray[pos].id_carrera=auxID_carrera;

            pArray[pos].estado=1;
            carreras[pos].estado=1;

     }
     else
     {
         printf("ya no hay mas espacio\n");
         retorno=-1;
     }
    return retorno;
}

void mostrarUnElemento(eEstudiante pArray,eCarrera pCarrera)
{


    printf("%d\n%s\n%s\n",pArray.legajo,pArray.nombre,pCarrera.descripcion);
   //printf("%d\n%s\%sn",pArray.legajo,pArray.nombre);
    //printf("%s  %s\n",pArray.nombre,pArray.apellido);

}
int obtenerDescripcion(eCarrera carrera[],int cantCarrera,int id_encontrar,char* descripcion)
{
    int retorno=0;
    if(carrera!=NULL && cantCarrera>0)
    {
        for(int i=0;i<cantCarrera;i++)
        {
            if(carrera[i].id_carrera==id_encontrar)
            {
                strcpy(descripcion,carrera[i].descripcion);
            }
        }
    }
    return retorno;
}

int mostrarArrayDeElementos(eEstudiante pArray[],int cantidad,eCarrera pCarrera[],int cantCarrera)
{
    int retorno=1;
    if(pArray!=NULL && cantidad>0)
    {

        for(int i=0; i<cantidad; i++)
        {
            if(pArray[i].estado!=0)
            {
                obtenerDescripcion(pCarrera,cantCarrera,pArray[i].id_carrera,pCarrera[i].descripcion);
                printf("\n");
                mostrarUnElemento(pArray[i],pCarrera[i]);
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

int bajaLogica(eEstudiante array[],int cantidad,eCarrera carrera[],int cantCarrera)
{
    int retorno=1;
    int auxLegajo;
    int posicionLegajo;
    char seguir[2];
    if(array!=NULL && cantidad>0)
    {
        if(!getInt(&auxLegajo,"Ingrese legajo:","Error. El legajo debe ser de 1 a 100.\n",1,100,3)==0)
        {
            return 1;
        }
        for(int i=0;i<cantidad;i++)
        {
            if(array[i].estado==1)
            {

                if(buscarLegajo(array,cantidad,auxLegajo,&posicionLegajo)==0)
                {

                   mostrarUnElemento(array[posicionLegajo],carrera[posicionLegajo]);

                    if(botonSeguir(seguir,"Para dar de baja pulse [S], caso contrario pulse cualquier tecla:","Ingrese solo una letra.\n",2)==0)
                    {
                        printf("Baja dada con exito. Adios !\n");
                        array[i].estado=0;
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

