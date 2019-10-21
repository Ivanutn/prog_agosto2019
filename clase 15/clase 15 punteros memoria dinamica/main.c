#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pVector;
    int* auxiliarPvector;
    pVector=(int*)malloc(sizeof(int)*5);//reservo memoria de manera dinamica para un vector de entero de 5 elementos
                                        //sizeof(int)*5, 4 bytes * 5 elementos.
    if(pVector!=NULL)//verifico que malloc no haya devuelvto NULL al pedir memoria dinamica
    {
        for(int i=0;i<5;i++)
        {
            printf("Ingrese un numero:");
            scanf("%d",pVector+i);//guardo los numeros utilizando aritmetica de punteros.
        }
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\n",*(pVector+i));//los muestro usando aritmetica de punteros.
    }

    auxiliarPvector=(int*)realloc(pVector,sizeof(int)*10);//agrando el vector con realloc, uso un auxiliar para no perder los datos ya cargados
    if(pVector!=NULL)
    {
        pVector=auxiliarPvector;
        //cargar los siguientes 5 numeros.
        //luego reduricr a 4 elementos y mostrarlos.
    }
    return 0;
}
