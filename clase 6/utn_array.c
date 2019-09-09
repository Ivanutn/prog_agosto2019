#include <stdio.h>
#include <stdlib.h>
int inicializarArray(int* pArray,int cantidad,int valor)
{
    int retorno=-1;
    if(pArray!=NULL && cantidad>0)
    {
        for(int i=0; i<cantidad; i++)
        {
            pArray[i]=valor;
        }
        retorno=0;
    }
    return retorno;
}

int buscarEspacioLibre(int* pArray,int cantidad)
{
    int retorno=1; // es que NO esta vacio el  array
    if(pArray!=NULL && cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            if(pArray[i] == 0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int isEmptyArray(int* pArray,int cantidad,int valor)
{
    int retorno=1;//si retorno 1 NO esta vacio
    for(int i=0; i<cantidad; i++)
    {
        if(pArray[i]==valor)
        {
            retorno=0;
        }
    }
    return retorno;
}

int mostrarUnElemento(int array)
{
    printf("%d",array);
    return 0;
}

int mostrarArrayElemento(int array[],int cantidad)
{
    for(int i=0; i<cantidad; i++)
    {

        mostrarUnElemento(array[i]);
    }

    return 0;
}

