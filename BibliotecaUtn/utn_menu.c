#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_estudiante.h"
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

    eEstudiante misEstudiantes[MAX_QTY];
    eCarrera misCarreras[MAX_QTY]={ {1,0,"Programacion"},{2,0,"SPD"}};
    inicializarArray(misEstudiantes,MAX_QTY);
    do
    {
            numero=opcion();
            switch (numero)
            {
            case 1:
            cargaArray(misEstudiantes,MAX_QTY,misCarreras,MAX_QTY);
                     system("pause");
                     system("cls");
                break;
            case 2:

                    system("pause");
                    system("cls");

                break;
            case 3:

                break;
            case 4:
                mostrarArrayDeElementos(misEstudiantes,MAX_QTY,misCarreras,MAX_QTY);

                break;
            case 5:
                printf("Salir ok\n");
                break;
            default:
                break;
            }
    }while(numero!=5);

}

