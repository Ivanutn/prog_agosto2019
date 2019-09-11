#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "utn_array.h"
#define TOTAL 2

int mostrarMatriz(char matriz[][50],int cantidad);
int main()
{

 /*   int legajo[TOTAL];
    int edad[TOTAL];
    int nota1[TOTAL];
    int nota2[TOTAL];
    float promedio[TOTAL];
    char sexo[TOTAL];

    CargaVectorParalelo(legajo,edad,nota1,nota2,promedio,sexo,TOTAL);
    mostrarArrayParalelo(legajo,edad,nota1,nota2,promedio,sexo,TOTAL);*/

    /**
    matrices de cadena de caracteres
    char nombre[cantidad de elementos que corresponden a las posiciones] [cantidad de caracteres de la cadena]
    ejemplo:
    char nombre[2][20];
    */
    char nombre[TOTAL][51];
    char apellidos[TOTAL][51];
    char auxNombre[51];
    char auxApellido[51];


    for(int i=0;i<TOTAL;i++)
    {
       if(getString(auxNombre,"Ingrese nombre:","Error. El minino de caracteres es 2 y maximo 50",2,51)==0)
       {
           strcpy(nombre[i],auxNombre);
       }
       if(getString(auxApellido,"Ingrese apellido:","El minino de caracteres es 2 y maximo 50",2,51)==0)
       {
           strcpy(apellidos[i],auxApellido);
       }
    }




    return 0;
}
int mostrarMatriz(char matriz[][50],int cantidad)
{
    int retorno=-1;
    if(matriz!=NULL && cantidad>0)
    {
        for(int i=0;i<cantidad;i++)
        {
            printf("%s\n",matriz[i]);
        }
        retorno=0;

    }
    return retorno;
}
