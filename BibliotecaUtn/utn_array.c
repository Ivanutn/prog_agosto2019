#include <stdio.h>
#include <stdlib.h>
#include "utn_array.h"
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

float promedioVector(int* array,int cantidad)
{
    float resultado;
    int suma;
    float retorno=1;//1 es error.
    if(cantidad>0)
    {
        for(int i=0;i<cantidad;i++)
        {
           suma=sumaVector(array,cantidad);
           resultado=(float)suma/cantidad;
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
    printf("%s %s %d %d - %d - %d %c %d %d %d %.2f",pArray.nombre,pArray.apellido,pArray.legajo,pArray.fecha_de_ingreso.dia,pArray.fecha_de_ingreso.mes,pArray.fecha_de_ingreso.anio,pArray.sexo,pArray.edad,pArray.nota1,pArray.nota2,pArray.promedio);

}

int mostrarArrayDeElementos(eAlumno pArray[],int cantidad)
{

    if(pArray!=NULL && cantidad>0)
    {

        for(int i=0; i<cantidad; i++)
        {
            if(pArray[i].estado!=0)
            {
                mostrarUnElemento(pArray[i]);
            }
        }
    }



    return 0;
}

int cargaArray(eAlumno pArray[],int cantidad)
{
    int pos;
    int retorno=0;
    char seguir='s';
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

    inicializarArray(pArray,cantidad);

    do{
        pos=buscarEspacioLibre(pArray,cantidad);
        if(buscarEspacioLibre(pArray,cantidad)!=1)
        {
            if(getInt(&auxLegajo,"Ingrese legajo, debe estar entre 1 y 100:","Error. El legajo debe estar entre 1 y 100\n",1,100,3)==0)
            {
                pArray[pos].legajo=auxLegajo;

            }
            if(getString(auxNombre,"Ingrese su nombre:","Error. El nombre debe contener minimo 2 y maximo 40 caracteres.\n",2,MAX_CARACTERES-1,3)==0)
            {
                strcpy(pArray[pos].nombre,auxNombre);
            }
            if(getString(auxApellido,"Ingrese su apellido:","Error. El apellido debe contener minimo 2 y maximo 40 caracteres.\n",2,MAX_CARACTERES-1,3)==0)
            {
                 strcpy(pArray[pos].apellido,auxApellido);
            }
            if(getSex(&auxSexo,"Ingrese sexo, [F] o [M]:","Error. Debe ingresar [F] o [M]\n",3)==0)
            {
                pArray[pos].sexo=auxSexo;
            }

                printf("para seguir pulse S: ");
                fflush(stdin);
                scanf("%c",&seguir);
        }

        else
        {
           printf("ya no hay mas espacio\n");
           break;
        }


    }while(seguir=='s' || seguir=='S');


    return retorno;

}

