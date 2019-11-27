#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "AxelUTN.h"
#include "parser.h"

///SE ENCARGA DE IR DICIENDO LO QUE HAY QUE HACER..

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* newArchivo;
    newArchivo = fopen(path, "r");
    if(newArchivo == NULL && pArrayListEmployee == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO.\n");
        system("pause");
        retorno = 0;
    }
    else
    {
        parser_EmployeeFromText(newArchivo, pArrayListEmployee);
        retorno = 1;
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* newArchivo;
    newArchivo = fopen(path, "rb");
    if(newArchivo == NULL && pArrayListEmployee == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO.\n");
        system("pause");
        retorno = 0;
    }
    else
    {
        parser_EmployeeFromBinary(newArchivo, pArrayListEmployee);
        retorno = 1;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int flag = 0;
    Employee* newEmpleado;
    char auxIdChar[20];
    char auxNombre[20], auxHoras[20], auxSueldo[20];
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        do
        {
            flag = 0;
            printf("INGRESE ID: ");
            fflush(stdin);
            gets(auxIdChar);
            for(int i = 0; i< ll_len(pArrayListEmployee);i++)
            {
                newEmpleado = ll_get(pArrayListEmployee, i);
                if(newEmpleado->id == atoi(auxIdChar))
                {
                    printf("YA EXISTE UN USUARIO CON ESE ID.\n");
                    system("pause");
                    system("cls");
                    printf("RE ");
                    flag = 1;
                    break;
                }
            }
        }while(flag==1);
        if(flag == 0)
        {
            if(esDato(auxNombre, "NOMBRE")==1)
            {
                if(esNumerico(auxHoras, "HORAS TRABAJADAS")==1)
                {
                    if(esNumerico(auxSueldo,"SUELDO")== 1)
                    {
                        newEmpleado = employee_new();
                        if(newEmpleado != NULL)
                        {
                            newEmpleado = employee_newParametros(auxIdChar, auxNombre, auxHoras, auxSueldo);
                            if(newEmpleado != NULL)
                            {
                                ll_add(pArrayListEmployee, newEmpleado);
                                retorno = 1;
                            }
                            else
                            {
                                printf("EMPLOYEE_NEWPARAMETROS ES NULL\n");
                                system("pause");
                            }
                        }
                        else
                        {
                            printf("EMPLOYEE_NEW ES NULL\n");
                            system("pause");
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("LA LISTA RETORNO: %d\n", pArrayListEmployee);
        system("pause");
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int auxID;
    char auxNombre[20], auxHoras[20], auxSueldo[20];
    int flag = 2;
    int opcion = 0;
    int modificar;

    do
    {
        system("cls");
        printf("MODIFICAR EMPLEADO.\n");
        auxID = getInt("INGRESE ID: ");

        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            if(empleado->id == auxID)
            {
                printf("ESTE, ES EL EMPLEADO QUE DESEA MODIFICAR??\n");
                printf("%5d %10s %10d %20d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
                modificar = getChar("'S' o 'N'\n");
                if(modificar == 's')
                {
                    flag = 1;
                    do
                    {
                        system("cls");
                        opcion = getInt("QUE DESEA MODIFICAR.\n\n0.- SALIR.\n1.- NOMBRE.\n2.- HORAS TRABAJADAS.\n3.- SUELDO.\n");
                        switch(opcion)
                        {
                        case 0:
                            opcion = getInt("SEGURO QUE DESEA SALIR INGRESE '0': \n");
                            break;
                        case 1:
                            if(getNombre(auxNombre, "INGRESE NOMBRE: "))
                            {
                                employee_setNombre(empleado, auxNombre);
                                printf("SE CAMBIO EL DATO EXOTOSAMENTE.\n");
                                system("pause");
                                break;
                            }
                        case 2:
                            if(esNumerico(auxHoras, "HORAS TRABAJADAS"))
                            {
                                employee_setHorasTrabajadas(empleado, atoi(auxHoras));
                                printf("SE CAMBIO EL DATO EXOTOSAMENTE.\n");
                                system("pause");
                                break;
                            }
                        case 3:
                            if(esNumerico(auxSueldo, "SUELDO"))
                            {
                                employee_setSueldo(empleado, atoi(auxSueldo));
                                printf("SE CAMBIO EL DATO EXOTOSAMENTE.\n");
                                system("pause");
                                break;
                            }
                        }
                    }while(opcion != 0);
                    //ll_set(pArrayListEmployee, i, empleado);
                    printf("SE GUARDO EL CAMBIO EXITOSAMENTE.\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else if(modificar == 'n')
                {
                    system("cls");
                    printf("ADIOS.\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("OPCION INCORRECTA.\n");
                    system("pause");
                }
            }
            flag = 0;
        }
        if(flag == 0)
        {
            //INFORMAR QUE NO EXISTE EMPLEADO.
            printf("ERROR. NO SE ENCONTRO EL EMPLEADO.\n");
            system("pause");
            system("cls");
            flag = 2;
        }
    }while(flag == 2);
    return flag;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int auxID;
    int flag = 0;
    char eliminar = 'n';

    system("cls");
    printf("BAJA DE EMPLEADO.\n");
    auxID = getInt("INGRESE ID: ");

    for(int i = 0; i<ll_len(pArrayListEmployee); i++)
    {
        empleado = ll_get(pArrayListEmployee, i);
        if(empleado->id == auxID)
        {
            flag = 1;
            printf("ESTE, ES EL EMPLEADO QUE DESEA DAR DE BAJA??\n");
            printf("%5d %10s %10d %20d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
            eliminar = getChar("'S' o 'N'\n");
            if(eliminar == 's')
            {
                ll_remove(pArrayListEmployee, i);
                flag = 1;
                break;
            }
            else{
                flag = 2;
                break;
            }
        }
    }
    if(flag == 0)
    {
        //INFORMAR QUE NO EXISTE EMPLEADO.
        printf("NO SE HA ENCONTRADO EL EMPLEADO.\n");
        system("pause");
        system("cls");
    }
    if(flag == 2)
    {
        printf("SE HA CANCELADO LA BAJA.\n");
        system("pause");
        system("cls");
    }
    return flag;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmp = employee_new();
    int len=ll_len(pArrayListEmployee);
    int contador = 0;
    int auxId, auxHoras, auxSueldo;
    char auxNombre[50];

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<len;i++ )
        {
            auxEmp = ll_get(pArrayListEmployee, i);
            if(auxEmp != NULL)
            {
                employee_getId(auxEmp, &auxId);
                employee_getNombre(auxEmp, auxNombre);
                employee_getHorasTrabajadas(auxEmp, &auxHoras);
                employee_getSueldo(auxEmp, &auxSueldo);
                printf("%5d %10s %10d %20d\n", auxId, auxNombre, auxHoras, auxSueldo);
                contador++;
                if(contador == 150)
                {
                    contador = 0;
                    system("pause");
                }
            }
            else
            {
                retorno = -1;
                break;
            }
        }
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno;
    LinkedList* auxLl = ll_clone(pArrayListEmployee);

    system("cls");
    opcion = getInt("METODOS DE ORDENAMIENTO.\n0.- Salir.\n1.- ORDENAR POR ID ASCENDENTE.\n2.- ORDENAR POR ID DESCENDENTE.\n3.- ORDENAR POR NOMBRE ASCENDENTE.\n4.- ORDENAR POR NOMBRE DESCENDENTE.\n5.- ORDENAR POR HORAS TRABAJADAS ASCENDENTE.\n6.- ORDENAR POR HORAS TRABAJADAS DESCENDENTE.\n7.- ORDENAR POR SUELDO ASCENDENTE.\n8.- ORDENAR POR SUELDO DESCENDENTE.\n\nOPCION: ");

    switch(opcion)
    {
        case 1:
            puts("ORDENANDO LISTA...");
            retorno = ll_sort(auxLl, comparar_id, 0);
            controller_ListEmployee(auxLl);
            system("pause");
            break;
        case 2:
            puts("ORDENANDO LISTA...");
            retorno = ll_sort(auxLl, comparar_id, 1);
            controller_ListEmployee(auxLl);
            system("pause");
            break;
        case 3:
            puts("ORDENANDO LISTA...");
            retorno = ll_sort(auxLl, comparar_nombre, 1);
            controller_ListEmployee(auxLl);
            system("pause");
            break;
        case 4:
            puts("ORDENANDO LISTA...");
            retorno = ll_sort(auxLl, comparar_nombre, 0);
            controller_ListEmployee(auxLl);
            system("pause");
            break;
        case 5:
            puts("ORDENANDO LISTA...");
            retorno = ll_sort(auxLl, comparar_horariosTrabajados, 0);
            controller_ListEmployee(auxLl);
            system("pause");
            break;
        case 6:
            puts("ORDENANDO LISTA...");
            retorno = ll_sort(auxLl, comparar_horariosTrabajados, 1);
            controller_ListEmployee(auxLl);
            system("pause");
            break;
        case 7:
            puts("ORDENANDO LISTA...");
            retorno = ll_sort(auxLl, comparar_sueldo, 0);
            controller_ListEmployee(auxLl);
            system("pause");
            break;
        case 8:
            puts("ORDENANDO LISTA...");
            retorno = ll_sort(auxLl, comparar_sueldo, 1);
            controller_ListEmployee(auxLl);
            system("pause");
            break;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* auxEmp;
    int auxId, auxHoras, auxSueldo;
    char nombre[20];
    int len = ll_len(pArrayListEmployee);
    FILE* newArchivo = fopen(path, "w");

    if(newArchivo != NULL && pArrayListEmployee != NULL)
    {
        fprintf(newArchivo, "id,first_name,last_name,sueldo\n");
        for(int i = 0; i<len; i++)
        {
            auxEmp = ll_get(pArrayListEmployee,i);
            employee_getId(auxEmp, &auxId);
            employee_getNombre(auxEmp, nombre);
            employee_getHorasTrabajadas(auxEmp, &auxHoras);
            employee_getSueldo(auxEmp, &auxSueldo);
            fprintf(newArchivo, "%d, %s, %d, %d\n", auxId, nombre, auxHoras, auxSueldo);
        }
        fclose(newArchivo);
        retorno = 1;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* auxEmp;
    int len = ll_len(pArrayListEmployee);
    FILE* newArchivo = fopen(path, "wb");

    if(newArchivo != NULL && pArrayListEmployee != NULL)
    {
        for(int i = 0; i<len; i++)
        {
            auxEmp = ll_get(pArrayListEmployee,i);
            fwrite(auxEmp, sizeof(Employee), 1, newArchivo);
        }
        fclose(newArchivo);
    }
    return retorno;
}


/** \brief FILTRAR POR CRITERIO Y GUARDARLO EN UNA NUEVA LISTA.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_Filter(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    LinkedList* auxll;

    if(pArrayListEmployee != NULL)
    {
        auxll = ll_filter(pArrayListEmployee, filtrar);
        if( auxll != NULL)
        {
            controller_saveAsText("listaFiltrada.csv", auxll);
            retorno = 1;
        }
    }
    return retorno;
}
