#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utn_array.h"
#define TOTAL 2
int main()
{
    int ok;
    int ok2;

    int legajo[TOTAL];
    int edad[TOTAL];
    int nota1[TOTAL];
    int nota2[TOTAL];
    float promedio[TOTAL];
    char sexo[TOTAL];

    ok=CargaVectorParalelo(legajo,edad,nota1,nota2,promedio,sexo,TOTAL);
    printf("deOK:%d",ok);
    ok2=mostrarArrayParalelo(legajo,edad,nota1,nota2,promedio,sexo,TOTAL);
     printf("deOK2:%d",ok2);
    return 0;
}
