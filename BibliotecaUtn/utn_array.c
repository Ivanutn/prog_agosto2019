#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_array.h"
#include "utn.h"
int vectorMaximo(int* array,int cantidad,int* max)
{
    int flag=0;
    int maximo=0;

         for(int i=0;i<cantidad;i++)
        {
            if(flag==0 || array[i]>maximo)
            {
                maximo=array[i];
                flag=1;
            }
        }
        *max=maximo;
    return *max;
}

int vectorMinimo(int* array,int cantidad,int* min)
{
    int flag=0;
    int minimo=0;
    for(int i=0; i<cantidad; i++)
    {
        if(flag==0 || array[i]<minimo)
        {
            minimo=array[i];
            flag=1;
        }
    }

    *min=minimo;
    return *min;
}

int sumaVector(int* array,int cantidad)
{
    int resultado=0;
    int retorno=1;
    for(int i=0;i<cantidad;i++)
    {
        resultado=resultado+array[i];
        retorno=resultado;
    }
    return retorno;
}

float promedioVector(eAlumno array[],int cantidad)
{
    float resultado;
    int suma;
    float retorno=1;//1 es error.
    if(cantidad>0 && array!=NULL)
    {
        for(int i=0;i<cantidad;i++)
        {
           suma=array[i].nota1+array[i].nota2;
           resultado=(float)suma/2;
           retorno=resultado;

        }
    }
    return retorno;

}

int inicializarArray(eAlumno pArray[],int cantidad)
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

int buscarEspacioLibre(eAlumno pArray[],int cantidad)
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

void mostrarUnElemento(eAlumno pArray)
{

   // printf("%-10s\t%-10s\t%-12d\t%d/%d/%d%10c %8d %7d %6d %10.2f\n",pArray.nombre,pArray.apellido,pArray.legajo,pArray.fecha_de_ingreso.dia,pArray.fecha_de_ingreso.mes,pArray.fecha_de_ingreso.anio,pArray.sexo,pArray.edad,pArray.nota1,pArray.nota2,pArray.promedio);
    printf("%s  %s\n",pArray.nombre,pArray.apellido);

}

int mostrarArrayDeElementos(eAlumno pArray[],int cantidad)
{
    int retorno=1;
    if(pArray!=NULL && cantidad>0)
    {

        for(int i=0; i<cantidad; i++)
        {
            if(pArray[i].estado!=0)
            {
                mostrarUnElemento(pArray[i]);
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

int cargaArray(eAlumno pArray[],int cantidad)
{
    int pos;
    int retorno=0;
    char auxNombre[MAX_CARACTERES];
    char auxApellido[MAX_CARACTERES];
    int auxLegajo;
    int auxDia;
    int auxMes;
    int auxAnio;
    char auxSexo;
    int auxEdad;
    int auxNota1;
    int auxNota2;
    float promedio;
    int flagNota1=0;
    int flagNota2=0;

        inicializarArray(pArray,cantidad);
        pos=buscarEspacioLibre(pArray,cantidad);

        if(pArray[pos].estado==0)
        {
           if(getInt(&auxLegajo,"Ingrese legajo, debe estar entre 1 y 100:","Error. El legajo debe estar entre 1 y 100\n",1,100,3)==0)
            {
                if(buscarLegajo(pArray,cantidad,auxLegajo)==0)
                {
                    printf("Ese legajo ya existe.\n");

                }
                else
                {
                    pArray[pos].legajo=auxLegajo;
                }


            }
            else
            {
                return 1;
            }

            if(getString(auxNombre,"Ingrese su nombre:","Error. El nombre debe contener minimo 2 y maximo 40 caracteres.\n",2,MAX_CARACTERES-1,3)==0)
            {
                strcpy(pArray[pos].nombre,auxNombre);
            }
            else
            {
                return 1;
            }

            if(getString(auxApellido,"Ingrese su apellido:","Error. El apellido debe contener minimo 2 y maximo 40 caracteres.\n",2,MAX_CARACTERES-1,3)==0)
            {
                strcpy(pArray[pos].apellido,auxApellido);
            }
            else
            {
                return 1;
            }

            if(getSex(&auxSexo,"Ingrese sexo, [F] o [M]:","Error. Debe ingresar [F] o [M]\n",3)==0)
            {
                pArray[pos].sexo=auxSexo;
            }
            else
            {
                return 1;
            }

            if(getInt(&auxDia,"Ingrese dia de la fecha de ingreso:","Error. Dias entre 1 y 31\n",1,31,3)==0)
            {
                pArray[pos].fecha_de_ingreso.dia=auxDia;
            }
            else
            {
                return 1;
            }

            if(getInt(&auxMes,"Ingrese mes de la fecha de ingreso:","Error. Mes entre 1 y 12\n",1,12,3)==0)
            {
                pArray[pos].fecha_de_ingreso.mes=auxMes;
            }
            else
            {
                return 1;
            }

            if(getInt(&auxAnio,"Ingrese anio de la fecha de ingreso:","Error. Anio entre 1 y 2010\n",1,2010,3)==0)
            {
                pArray[pos].fecha_de_ingreso.anio=auxAnio;
            }
            else
            {
                return 1;
            }

            if(getInt(&auxEdad,"Ingrese edad:","Error. Edad entre 1 y 100\n",1,100,3)==0)
            {
                pArray[pos].edad=auxEdad;
            }
            else
            {
                return 1;
            }

            if(getInt(&auxNota1,"Ingrese nota primer examen:","Error. nota entre 1 y 10\n",1,10,3)==0)
            {
                pArray[pos].nota1=auxNota1;
                flagNota1=1;
            }
            else
            {
                return 1;
            }

            if(getInt(&auxNota2,"Ingrese nota segudno examen:","Error. nota entre 1 y 10\n",1,10,3)==0)
            {
                pArray[pos].nota2=auxNota2;
                flagNota2=1;
            }
            else
            {
                return 1;
            }
            if(flagNota1==1 && flagNota2==1)
            {
                promedio=promedioVector(pArray,cantidad);
                pArray[pos].promedio=promedio;
            }
            pArray[pos].estado=1;//estado en 1 implica que esa posicion ya se cargo con datos

        }

        else
        {
           printf("ya no hay mas espacio\n");
           retorno=1;
        }




     return retorno;
}
int buscarLegajo(eAlumno pArray[],int cantidad,int legajo)
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
                    break;
                }

            }

        }
    }

    return retorno;
}

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
            if(stricmp(copiaAlumno[i].nombre,copiaAlumno[i+1].nombre)>0)
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

