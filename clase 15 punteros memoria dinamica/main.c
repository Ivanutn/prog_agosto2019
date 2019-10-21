#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pVector;
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
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\n",*(pVector+i));//los muestro usando aritmetica de punteros.
    }
    return 0;
}
