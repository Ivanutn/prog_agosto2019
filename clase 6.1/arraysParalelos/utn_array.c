#include <stdio.h>
#include <stdlib.h>

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
{/*
    int pos;
    int retorno=0;
    char seguir='s';
    inicializarArray(pArray,cantidad,0);
    do{
        pos=buscarEspacioLibre(pArray,cantidad);
        if(buscarEspacioLibre(pArray,cantidad)!=-1)
        {
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
*/
return 0;
}

int CargaVectorParalelo(int* legajo,int* edad,int* nota1,int* nota2,float* promedio,char* sexo,int cantidad)
{
    int legajoAux;
    int edadAux;
    int nota1Aux;
    int nota2Aux;
    int sumaAux;
    float promedioAux;
    char sexoAux;
    int pos;
    int retorno=0;
    char seguir='s';
    inicializarArray(legajo,cantidad,0);
    inicializarArray(edad,cantidad,0);
    inicializarArray(nota1,cantidad,0);
    inicializarArray(nota2,cantidad,0);
    for(int i=0;i<cantidad;i++)
    {
        promedio[i]=0;
    }
    for(int i=0;i<cantidad;i++)
    {
        sexo[i]='a';
    }
    do{
        pos=buscarEspacioLibre(legajo,cantidad);
        if(buscarEspacioLibre(legajo,cantidad)!=-1)
        {
            if(getInt(&legajoAux,"Ingrese su legajo. Debe estar entre 1 y 100:","Error. El legajo debe estar entre 1 y 100",1,100)==0)
            {
                legajo[pos]=legajoAux;
            }
            if(getInt(&edadAux,"Ingrese su edad:","Error. edad entre 0 y 100",0,100)==0)
            {
                edad[pos]=edadAux;
            }
            if(getInt(&nota1Aux,"Ingrese su nota de primer parcial:","Error. nota entre 1 y 10",1,10)==0)
            {
                nota1[pos]=nota1Aux;
            }
            if(getInt(&nota2Aux,"Ingrese su nota de segundo parcial:","Error. nota entre 1 y 10",1,10)==0)
            {
                nota2[pos]=nota2Aux;
            }
            if(nota1Aux !=0 && nota2Aux !=0)
            {
               sumaAux=nota1[pos]+nota2[pos];
               promedioAux=(float)sumaAux/2;
               promedio[pos]=promedioAux;
            }
            if(getSex(&sexoAux,"Ingrese su sexo, debe ser la letra [F] o [M]:","Error. debe ser la letra [F] o [M]")==0)
            {
                sexo[pos]=sexoAux;
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
int mostrarArrayParalelo(int* legajo,int* edad,int* nota1,int* nota2,float* promedio,char* sexo,int cantidad)
{
    int retorno=0;
    for(int i=0;i<cantidad;i++)
    {
      printf("Legajo:%d\nEdad:%d\nNota1:%d\nNota2:%d\nPromedio:%.2f\nSexo:%c\n",legajo[i],edad[i],nota1[i],nota2[i],promedio[i],sexo[i]);

    }
    return retorno;

}
