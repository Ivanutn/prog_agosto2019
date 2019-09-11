#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utn_array.h"
#define TOTAL 2
#include <string.h>

int main()
{

    int legajo[TOTAL];
    int edad[TOTAL];
    int nota1[TOTAL];
    int nota2[TOTAL];
    float promedio[TOTAL];
    char sexo[TOTAL];

    CargaVectorParalelo(legajo,edad,nota1,nota2,promedio,sexo,TOTAL);
    mostrarArrayParalelo(legajo,edad,nota1,nota2,promedio,sexo,TOTAL);

    return 0;
}
