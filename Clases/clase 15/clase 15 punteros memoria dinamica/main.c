#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pVector;
    int* auxiliarPvector;// utilizado a la hora de redimensionar dinamicamente el vector. puede devolver null.
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

     //REDIMENSIONAR EL VECTOR PARA GUARDAR 10 ELEMENTOS.
    auxiliarPvector=(int*)realloc(pVector,sizeof(int)*10);//agrando el vector con realloc,
                                                         // uso un auxiliar para no perder los datos ya cargados
    if(auxiliarPvector!=NULL)
    {
        pVector=auxiliarPvector;//asigno a pVector la direccion de memoria de auxiliar, que ahora esta redimensionada
                                //para poder guardar 10 elementos, manteniendo los 5 elementos ya cargados.

        //CARGAR LOS SIGUIENTES 5 NUMEROS
         for(int i=5;i<10;i++)
        {
            printf("Ingrese un numero:");
            scanf("%d",pVector+i);
        }

        //MUESTRO LOS 10 NUMEROS CARGADOS
         for(int i=0;i<10;i++)
        {
            printf("%d\n",*(pVector+i));
        }
        //REDIMENSIONO EL VECTOR A 4 ELEMENTOS Y LOS MUESTRO.
        pVector=(int*)realloc(pVector,sizeof(int)*4);
         for(int i=0;i<4;i++)
        {
            printf("%d\n",*(pVector+i));
        }
        //LIBERAR ESPACIO EN MEMORIA USANDO UN FREE.
        free(pVector);

    }
    return 0;
}
