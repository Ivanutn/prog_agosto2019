#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utn_array.h"
#define TOTAL 3
#define VALOR 0


int main()

{
    int numeros[TOTAL];
    int min;
    int max;

    cargaArray(numeros,TOTAL);
    mostrarArrayElemento(numeros,TOTAL);

    printf("\nmax:%d\n",vectorMaximo(numeros,TOTAL,&max));
    printf("\nmin:%d\n",vectorMinimo(numeros,TOTAL,&min));

    return 0;
}


/**

int flag=-1
while(flag==-1)
{
    flag=0;
    for(i=0;i<cant-1;i++)
    {
        if(array[i]>array[i+1])
        {
            swap
            flag==-1
        }
    }
}


*/
