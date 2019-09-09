#include <stdio.h>
#include <stdlib.h>

int vectorMaximo(int* array,int cantidad);
int vectorMinimo(int* array,int cantidad);

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
    int retorno=-1; // es que NO esta vacio el  array
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
    printf("%d\n",array);
    return 0;
}

int mostrarArrayElemento(int array[],int cantidad)
{
    for(int i=0; i<cantidad; i++)
    {

        if(array[i]!=0)
        {
            mostrarUnElemento(array[i]);
        }
    }


    return 0;
}

int cargaArray(int* pArray,int cantidad)
{
    int pos;
    int auxiliar;
    int retorno=0;
    char seguir='s';
    inicializarArray(pArray,cantidad,0);

    do{
        pos=buscarEspacioLibre(pArray,cantidad);
        if(buscarEspacioLibre(pArray,cantidad)!=-1)
        {
            if(getInt(&auxiliar,"Num:","Error\n",0,100)==0)
            {

                pArray[pos]=auxiliar;
                printf("para seguir pulse S: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }

        }

        else
        {
           printf("ya no hay mas espacio\n");
           break;
        }


    }while(seguir=='s' || seguir=='S');


    return retorno;

}

