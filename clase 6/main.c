#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utn_array.h"
#define TOTAL 5
#define VALOR 0

int cargaArray(int* pArray,int cantidad);
int main()

{
    int numeros[TOTAL];
    inicializarArray(numeros,TOTAL,VALOR);

    if(isEmptyArray(numeros,TOTAL,0)==0)
    {
        for(int i=0; i<TOTAL; i++)
        {
            getInt(&numeros[i],"Ingrese un numero:","Error debe ingresar un numero entre 0 y 100.\n",0,100);
        }

    }
    printf("\n");
    mostrarUnElemento(numeros[2]);
    printf("\n");
    mostrarArrayElemento(numeros,TOTAL);


    return 0;
}

int cargaArray(int* pArray,int cantidad)
{

}
