#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
Employee* employee_new()
{
    Employee* nuevo=(Employee*)malloc(sizeof(Employee));
    if(nuevo!=NULL)
    {
        nuevo->id=0;
        strcpy(nuevo->nombre," ");
        nuevo->horasTrabajadas=0;
        nuevo->sueldo=0;
    }
     return nuevo;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevo=employee_new();
    if(nuevo!=NULL)
    {
        if(employee_setId(nuevo,atoi(idStr)),
           employee_setNombre(nuevo,nombreStr),
           employee_setHorasTrabajadas(nuevo,atoi(horasTrabajadasStr)),
           employee_setSueldo(nuevo,atoi(sueldoStr)))
        {

        }

    }
    else
    {
        nuevo=NULL;
    }
    return nuevo;


}

int employee_setId(Employee* this,int id)
{
    int todoOK=0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id=id;
            todoOK=1;
        }
    }
    return todoOK;

}
int employee_getId(Employee* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOK=1;
    }

    return todoOK;

}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        todoOK=1;
    }
    return todoOK;

}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOK=1;
    }
    return todoOK;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOK=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOK=1;
    }

    return todoOK;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOK=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
    }
    return todoOK;

}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOK=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        todoOK=1;
    }

    return todoOK;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOK=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        todoOK=1;
    }
    return todoOK;

}
