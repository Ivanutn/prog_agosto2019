#include <stdio.h>
#include <stdlib.h>

int pedirEntero(char[]);
int calMaximo(int,int);
int calMinimo(int,int);
int main()
{
    calcularMinMax(4,1,1);

    return 0;
}

int pedirEntero(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    return numero;
}
int calMaximo(int numero,int maximo)
{
    int flag=0;
    int retorno;
    if(numero>maximo|| flag==0){
        maximo=numero;
        flag=1;
        retorno=maximo;
    }
    return retorno;
}
int calMinimo(int numero,int minimo)
{
    int flag=0;
    int retorno;
    if(numero<minimo|| flag==0){
        minimo=numero;
        flag=1;
        retorno=minimo;
    }
    return retorno;
}
