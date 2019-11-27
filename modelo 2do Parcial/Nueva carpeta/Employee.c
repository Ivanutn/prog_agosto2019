#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* newEmpleado = (Employee*) malloc(sizeof(Employee));
    if(newEmpleado != NULL)
    {
        newEmpleado->id = 0;
        strcpy(newEmpleado->nombre, "");
        newEmpleado->horasTrabajadas = 0;
        newEmpleado->sueldo = 0;
    }
    return newEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmpleado = employee_new();
    int ok = 0;
    if(newEmpleado != NULL)
    {
        if(employee_setId(newEmpleado, atoi(idStr)))
        {
            if(employee_setNombre(newEmpleado, nombreStr))
            {
                if(employee_setHorasTrabajadas(newEmpleado, atoi(horasTrabajadasStr)))
                {
                    if(employee_setSueldo(newEmpleado, atoi(sueldoStr)))
                    {
                        ok = 1;
                    }
                }
            }
        }
        if(ok == 0)
        {
            free(newEmpleado);
            newEmpleado = NULL;
        }
    }
    return newEmpleado;
}

int employee_setId(Employee* this, int id)
{
    int ok = 0;

    if(this!= NULL)
    {
        this->id = id;
        ok = 1;
    }
    return ok;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int ok = 0;

    if(this!= NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        ok = 1;
    }
    return ok;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int ok = 0;

    if(this!= NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        ok = 1;
    }
    return ok;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int ok;

    if(this!= NULL)
    {
        this->sueldo = sueldo;
        ok = 1;
    }
    return ok;
}
int employee_getId(Employee* this, int* id)
{
     int ok = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id ;
        ok = 1;
    }
    return ok;
}
int employee_getNombre(Employee* this, char* nombre)
{
     int ok = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        ok = 1;
    }
    return ok;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
     int ok = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ok = 1;
    }
    return ok;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
         int ok = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        ok = 1;
    }
    return ok;
}

int comparar_id(void* pElementoA, void* pElementoB)
{
    Employee* auxiliarA = (Employee*)pElementoA;
    Employee* auxiliarB = (Employee*)pElementoB;

    int aux = 0;

    if(auxiliarA->id > auxiliarB->id)
    {
        aux = -1;
    }
    else if(auxiliarA->id < auxiliarB->id)
    {
        aux = 1;
    }
    else
    {
        aux = 0;
    }

    return aux;
}

int comparar_nombre(void* pElementoA, void* pElementoB)
{
    Employee* auxiliarA = (Employee*)pElementoA;
    Employee* auxiliarB = (Employee*)pElementoB;

    int aux = strcmp(auxiliarA->nombre, auxiliarB->nombre);

    return aux;
}

int comparar_horariosTrabajados(void* pElementoA, void* pElementoB)
{
    Employee* auxiliarA = (Employee*)pElementoA;
    Employee* auxiliarB = (Employee*)pElementoB;

    int aux = 0;

    if(auxiliarA->horasTrabajadas > auxiliarB->horasTrabajadas)
    {
        aux = -1;
    }
    else if(auxiliarA->horasTrabajadas < auxiliarB->horasTrabajadas)
    {
        aux = 1;
    }
    else
    {
        aux = 0;
    }

    return aux;
}

int comparar_sueldo(void* pElementoA, void* pElementoB)
{
    Employee* auxiliarA = (Employee*)pElementoA;
    Employee* auxiliarB = (Employee*)pElementoB;

    int aux = 0;

    if(auxiliarA->sueldo > auxiliarB->sueldo)
    {
        aux = -1;
    }
    else if(auxiliarA->sueldo < auxiliarB->sueldo)
    {
        aux = 1;
    }
    else
    {
        aux = 0;
    }

    return aux;
}

int filtrar(void* pElement)
{
    int retorno = 0;
    if(pElement != NULL)
    {
        Employee* auxElement = (Employee*)pElement;
        if(auxElement->sueldo > 30000)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int mapSueldo(void* pElement)
{
    int retorno = 0;
    int auxHora;
    if(pElement != NULL)
    {
        Employee* auxElement = (Employee*)pElement;
        employee_getHorasTrabajadas(auxElement, auxHora);
        employee_setSueldo(auxElement, (auxHora * 300));
        retorno = 1;
    }
    return retorno;
}
