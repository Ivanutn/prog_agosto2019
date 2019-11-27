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
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* newEmployee;
    int retorno = 0;
    char buffer[4][20];
    int cant;

    fscanf(pFile, "%[^,], %[^,], %[^,], %[^,\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    //printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(pFile)&& pArrayListEmployee != NULL)
    {
        cant = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant == 4)
        {
            newEmployee = employee_new();
            newEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            ll_add(pArrayListEmployee, newEmployee);
            retorno = 0;
        }
        else
        {
            printf("NO SE HA LEIDO CORRECTAMENTE.\n");
            system("pause");
            retorno = 1;
        }
    }
    fclose(pFile);
    free(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* newEmployee;
    int retorno = 0;
    char buffer[4][20];
    int cant;

    while(!feof(pFile)&& pArrayListEmployee != NULL)
    {
        newEmployee = employee_new();
        newEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

        if(newEmployee == NULL)
        {
            retorno = 0;
        }
        else
        {
            cant = fread(newEmployee, sizeof(Employee), 1, pFile);
            if(cant == 1)
            {
                ll_add(pArrayListEmployee, newEmployee);
                retorno = 1;
            }
        }
    }
    fclose(pFile);
    free(pFile);
    return retorno;
}
