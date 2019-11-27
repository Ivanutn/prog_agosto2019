#include <stdio.h>
#include <stdlib.h>
#include "estructuras_genericas.h"

eGenerico* generico_new()
{
    eGenerico* nuevo=(eGenerico*)malloc(sizeof(eGenerico));
    if(nuevo!=NULL)
    {
      /*  nuevo->id=0;
        strcpy(nuevo->nombre," ");
        nuevo->horasTrabajadas=0;
        nuevo->sueldo=0;*/
    }
     return nuevo;

}

eGenerico* generico_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    eGenerico* nuevo=generico_new();
    if(nuevo!=NULL)
    {
        if( generico_setId(nuevo,atoi(idStr)),
           generico_setNombre(nuevo,nombreStr),
           generico_setHorasTrabajadas(nuevo,atoi(horasTrabajadasStr)),
           generico_setSueldo(nuevo,atoi(sueldoStr)))
        {

        }

    }
    else
    {
        nuevo=NULL;
    }
    return nuevo;


}
int generico_setId(eGenerico* this,int id)
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
int generico_getId(eGenerico* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOK=1;
    }

    return todoOK;

}

int generico_setNombre(eGenerico* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        todoOK=1;
    }
    return todoOK;

}
int generico_getNombre(eGenerico* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOK=1;
    }
    return todoOK;

}

int generico_setHorasTrabajadas(eGenerico* this,int horasTrabajadas)
{
    int todoOK=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOK=1;
    }

    return todoOK;

}
int generico_getHorasTrabajadas(eGenerico* this,int* horasTrabajadas)
{
    int todoOK=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
    }
    return todoOK;

}

int generico_setSueldo(eGenerico* this,int sueldo)
{
    int todoOK=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        todoOK=1;
    }

    return todoOK;

}
int generico_getSueldo(eGenerico* this,int* sueldo)
{
    int todoOK=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        todoOK=1;
    }
    return todoOK;

}
