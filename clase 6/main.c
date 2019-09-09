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
    float resProm;
    cargaArray(numeros,TOTAL);
    mostrarArrayElemento(numeros,TOTAL);

    resSuma=sumaVector(numeros,TOTAL);
    resProm=promedioVector(numeros,TOTAL);
    printf("\nres:%d",resSuma);
    printf("\nresProm:%.2f",resProm);
    return 0;
}

