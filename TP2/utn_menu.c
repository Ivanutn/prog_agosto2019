
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_validaciones.h"
#define MAX_QTY 5
int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1.Alta\n2.Baja\n3.Modificar\n4.Listar\n5.Informe\n6.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,6,3)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}
void menu(void)
{
    int numero;
    eEmployee myEmployee[MAX_QTY];
    initEmployee(myEmployee,MAX_QTY,0);
    eSector mySector[MAX_QTY]={ {1,"sistemas"}, {2,"RRHH"},{3,"Contabilidad"} };
    do
    {
            numero=opcion();
        switch (numero)
        {
        case 1:
            addEmployee(myEmployee,MAX_QTY);
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

            system("pause");
            system("cls");
            break;
        case 5:

            break;
        case 6:
            break;
        default:
            break;
        }
    }while(numero!=6);

}
