#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_array.h"
#include "utn.h"
#define MAX_CARACTERES 41
#define MAX_QTY 2
int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1.Alta\n2.Baja\n3.Modificar\n4.Listar\n5.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,5,3)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}
void menu(void)
{
    int numero;

    eAlumno vecAlumnos[MAX_QTY];
    inicializarArray(vecAlumnos,MAX_QTY);
    do
    {
            numero=opcion();
            switch (numero)
            {
            case 1:
                     cargaArray(vecAlumnos,MAX_QTY);

                     system("pause");
                     system("cls");
                break;
            case 2:
                    bajaLogica(vecAlumnos,MAX_QTY);
                    system("pause");
                    system("cls");

                break;
            case 3:
                modificarArray(vecAlumnos,MAX_QTY);
                break;
            case 4:
                printf("Nombre\t\tApellido\tLegajo\tFecha de nacimiento\tsexo\tEdad\tNota1\tnota2\tpromedio\n");
                mostrarArrayDeElementos(vecAlumnos,MAX_QTY);
                break;
            case 5:
                printf("Salir ok\n");
                break;
            default:
                break;
            }
    }while(numero!=5);

}

