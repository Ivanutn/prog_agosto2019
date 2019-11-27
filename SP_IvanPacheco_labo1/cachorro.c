#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cachorro.h"

eCachorro* cachorro_new()
{
    eCachorro* nuevo=(eCachorro*)malloc(sizeof(eCachorro));
    if(nuevo!=NULL)
    {
        nuevo->id_cachorro=0;
        strcpy(nuevo->nombre," ");
        nuevo->dias=0;
        strcpy(nuevo->raza," ");
        strcpy(nuevo->reservado," ");
        nuevo->genero='N';
    }
     return nuevo;

}

eCachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* reservadoStr,char* genero)
{
    eCachorro* nuevo=cachorro_new();
    if(nuevo!=NULL)
    {
        if(cachorro_setId(nuevo,atoi(idStr)),
           cachorro_setNombre(nuevo,nombreStr),
           cachorro_setDias(nuevo,atoi(diasStr)),
           cachorro_setRaza(nuevo,(razaStr)),
           cachorro_setReservado(nuevo,reservadoStr),
           cachorro_setGenero(nuevo,genero))
        {

        }

    }
    else
    {
        nuevo=NULL;
    }
    return nuevo;


}

int cachorro_setId(eCachorro* this,int id)
{
    int todoOK=0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id_cachorro=id;
            todoOK=1;
        }
    }
    return todoOK;

}
int cachorro_getId(eCachorro* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id_cachorro;
        todoOK=1;
    }

    return todoOK;

}

int cachorro_setNombre(eCachorro* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        todoOK=1;
    }
    return todoOK;

}
int cachorro_getNombre(eCachorro* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOK=1;
    }
    return todoOK;

}

int cachorro_setDias(eCachorro* this,int dias)
{
    int todoOK=0;
    if(this!=NULL && dias>0)
    {
        this->dias=dias;
        todoOK=1;
    }

    return todoOK;

}
int cachorro_getDias(eCachorro* this,int* dias)
{
    int todoOK=0;
    if(this!=NULL && dias!=NULL)
    {
        *dias=this->dias;
    }
    return todoOK;

}

int cachorro_setRaza(eCachorro* this,char* raza)
{
    int todoOK=0;
    if(this!=NULL && raza!=NULL && strlen(raza)<30)
    {
        strcpy(this->raza,raza);
        todoOK=1;
    }

    return todoOK;

}
int cachorro_getRaza(eCachorro* this,char* raza)
{
    int todoOK=0;
    if(this!=NULL && raza!=NULL && strlen(raza)<128)
    {
        strcpy(raza,this->raza);
        todoOK=1;
    }
    return todoOK;

}

int cachorro_setReservado(eCachorro* this,char* reservado)
{
    int todoOK=0;
    if(this!=NULL && reservado!=NULL && strlen(reservado)<3)
    {
        strcpy(this->reservado,reservado);
        todoOK=1;
    }

    return todoOK;

}

int cachorro_getReservado(eCachorro* this,char* reservado)
{
    int todoOK=0;
    if(this!=NULL && reservado!=NULL && strlen(reservado)<3)
    {
        strcpy(reservado,this->reservado);
        todoOK=1;
    }
    return todoOK;

}

int cachorro_setGenero(eCachorro* this,char* genero)
{
    int todoOK=0;
    if(this!=NULL && genero!=NULL && strlen(genero)<2)
    {
        for(int i=0;i<strlen(genero);i++)
        {
            if(genero[i]=='m' || genero[i]=='M')
            {
                this->genero=genero[i];
                todoOK=1;
            }
            else if(genero[i]=='h' || genero[i]=='H')
            {
                this->genero=genero[i];
                todoOK=1;
            }
        }

    }

    return todoOK;

}

int cachorro_getGenero(eCachorro* this,char* genero)
{
    int todoOK=0;
    if(this!=NULL && genero!=NULL)
    {
        if(genero[0]=='m' || genero[0]=='M')
        {
            genero[0]=this->genero;
            todoOK=1;
        }
        else if(genero[0]=='h' || genero[0]=='H')
        {
            genero[0]=this->genero;
            todoOK=1;
        }



    }
    return todoOK;

}

