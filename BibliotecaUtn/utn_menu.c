#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_array.h"
#include "utn.h"
#define MAX_CARACTERES 41
#define MAX_QTY 3
int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1.Alta\n2.Baja\n3.Modificar\n4.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,4,3)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}
void menu(void)
{
    int numero;
    eAlumno vecAlumnos[MAX_QTY];
    do
    {
            numero=opcion();
            switch (numero)
            {
            case 1:
                printf("Alta ok\n");
                cargaArray(vecAlumnos,MAX_QTY);
                break;
            case 2:
                printf("Baja ok\n");
                break;
            case 3:
                printf("Modificar ok\n");
                break;
            case 4:
                printf("Salir ok\n");
                break;
            default:
                break;
            }
    }while(numero!=4);

}

