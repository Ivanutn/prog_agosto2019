#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    char opcionSwitch = 'n';
    int cantidadEnLista = 0;

    do
    {
        cantidadEnLista = ll_len(listaEmpleados);
        switch(menu(listaEmpleados))
        {

        case 1:
            if(controller_loadFromText("data.csv", listaEmpleados))
            {
                printf("SE CARGO EXITOSAMENTE LA LISTA.\n");
                system("pause");
            }
            else
            {
                printf("NO SE PUDO CARGAR LA LISTA.\n");
                system("pause");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.bin", listaEmpleados))
            {
                printf("SE CARGO EXITOSAMENTE LA LISTA.\n");
                system("pause");
            }
            else
            {
                printf("NO SE PUDO CARGAR LA LISTA.\n");
                system("pause");
            }
            break;
        case 3:
            system("cls");
            if(controller_addEmployee(listaEmpleados))
            {
                printf("SE REALIZO EXITOSAMENTE EL ALTA.\n");
                system("pause");
            }
            else
            {
                printf("NO SE PUDO REALIZAR EL ALTA.\n");
                system("pause");
            }
            break;
        case 4:
            if(cantidadEnLista == 0)
            {
                printf("NO HAY EMPLEADOS PARA MODIFICAR.\n");
                system("pause");
            }
            else
            {
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("SE REALIZO EXITOSAMENTE LA MODIFICACION.\n");
                    system("pause");
                }

            }

            break;
        case 5:
            if(cantidadEnLista == 0)
            {
                printf("NO HAY EMPLEADOS PARA DAR DE BAJA.\n");
                system("pause");
            }
            else
            {
                if(controller_removeEmployee(listaEmpleados)==1)
                {
                    printf("SE REALIZO EXITOSAMENTE LA BAJA.\n");
                    system("pause");
                }
                else
                {
                    printf("NO SE HA PODIDO REALIZAR LA BAJA.\n");
                    system("pause");
                }
            }

            break;
        case 6:
            if(cantidadEnLista == 0)
            {
                printf("NO HAY EMPLEADOS PARA LISTAR.\n");
                system("pause");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
                system("pause");
                system("cls");
            }

            break;
        case 7:
            if(cantidadEnLista == 0)
            {
                printf("NO HAY EMPLEADOS PARA ORDENAR.\n");
                system("pause");
            }
            else
            {
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("SE REALIZO EXITOSAMENTE EL ORDENAMIENTO DE LA LISTA.\n");
                    system("pause");
                }
            }

            break;
        case 8:
            if(controller_saveAsText("data.csv", listaEmpleados))
            {
                printf("SE GUARDO EXITOSAMENTE LA LISTA EN TEXTO.\n");
                system("pause");
            }
            else
            {
                printf("NO SE PUDO GUARDAR LA LISTA EN TEXTO.\n");
                system("pause");
            }
            break;
        case 9:
            if(controller_saveAsBinary("data.bin", listaEmpleados))
            {
                printf("SE GUARDO EXITOSAMENTE LA LISTA EN BINARIO.\n");
                system("pause");
            }
            else
            {
                printf("NO SE PUDO GUARDAR LA LISTA EN BINARIO.\n");
                system("pause");
            }
            break;
        case 10:
            if(controller_Filter(listaEmpleados))
            {
                printf("SE HA FILTRADO CORRECTAMENTE.\n");
                system("pause");
            }
            else
            {
                printf("NO SE HA PODIDO FILTRAR CORRECTAMENTE.\n");
                system("pause");
            }
            break;
        case 11:
            opcionSwitch = getChar("DESEA SALIR 'S' o N : ");
            {
                if ( opcionSwitch == 's')
                {
                    break;
                }
            }
            break;
        }
    }
    while(opcionSwitch == 'n');
    return 0;
}
