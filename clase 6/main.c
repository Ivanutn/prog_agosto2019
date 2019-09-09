#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utn_array.h"
#define TOTAL 2
#define VALOR 0


int main()

{
    int numeros[TOTAL];
    int resSuma;
    int min;
    int max;
    float resProm;
    cargaArray(numeros,TOTAL);
    mostrarArrayElemento(numeros,TOTAL);

    resSuma=sumaVector(numeros,TOTAL);
    resProm=promedioVector(numeros,TOTAL);
    printf("\nSumres:%d",resSuma);
    printf("\nPromres:%.2f",resProm);
    max=
    printf("\nmax:%d\n",vectorMaximo(numeros,TOTAL,&max));
    printf("\nmin:%d\n",vectorMinimo(numeros,TOTAL,&min));

    return 0;
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
