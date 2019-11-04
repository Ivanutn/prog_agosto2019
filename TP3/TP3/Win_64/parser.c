#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOK=0;//1 esta bien, 0 todo mal.
    int cant;
    char buffer[4][30];

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.csv","r");
        if(pFile==NULL)
        {
            todoOK;
        }
        else
        {
            fscanf(f,"%[^,],%[^,],%[^,],%[^\n],\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            while(!feof(f))
            {
                cant=fscanf(f,"%[^,],%[^,],%[^,],%[^\n],\n",buffer[0],buffer[1],buffer[2],buffer[3]);
                if(cant==4)
                {


                }
                else
                {
                    break;
                }

            }


        }


        todoOK=1;
    }
    else
    {
        printf("Error al parsear empleado en modo texto.\n");
        todoOK;
    }


    return todoOK;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
