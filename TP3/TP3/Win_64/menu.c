#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_validaciones.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3.Alta de empleado\n4.Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7.Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,10,3)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}
void menu(void)
{
    int numero;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL)
    {

        do
        {
            numero=opcion();
            switch (numero)
            {
            case 1:
                 controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                system("pause");
                system("cls");

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                break;
            case 7:
                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            default:
                break;
            }
        }while(numero!=10);
    }
    else
    {
        printf("Hubo un problema al asignar memoria.\n");
    }

}
