#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "utn_validaciones.h"


int initCar(eAutos myCar[],int sizeAutos,int value)
{
    int retorno=-1;
    if(myCar!=NULL && sizeAutos>0)
    {
        for(int i=0; i<sizeAutos; i++)
        {
            myCar[i].isEmpty=value; //value 0 = vacio.
        }
        retorno=0;
    }
    return retorno;

}
int getFreePosition(eAutos myCar[],int sizeAutos,int* position)
{
    int retorno=-1; // es que NO esta vacio el  array
    if(myCar!=NULL && sizeAutos > 0)
    {
        for(int i=0; i<sizeAutos; i++)
        {
            if(myCar[i].isEmpty == 0)
            {
                *position=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;

}

int add_Car(eAutos myCar[],int sizeAutos)
{
    int retorno=1;
    int pos;
    if(myCar!=NULL && sizeAutos>0)
    {

        if(getFreePosition(myCar,sizeAutos,&pos)==0)
        {
            newCar(myCar,sizeAutos,pos);
            retorno=0;
        }
        else
        {
            printf("Ya no hay mas espacio libre.\n");
            retorno=1;
        }

    }

    return retorno;

}

int newCar(eAutos myCar[],int sizeAutos,int posicion)
{
    int retorno=0;
    int id_incremental=1;
    int aux_id_marca;
    int aux_id_color;
    int aux_dia;
    int aux_mes;
    int aux_anio;

    char auxPatente[MAX_CARACTERES];

    if(myCar!=NULL && sizeAutos>0)
    {

        if(!getString(auxPatente,"ingrese patente:","Error. min de caracteres 1 y maximo 6.\n",1,MAX_PATENTES-1,3)==0)
        {
            return 1;

        }
        pause_and_clearScreen();
        if(!getInt(&aux_id_marca,"Elija Marca.\n1.renault\n2.fiat\n3.ford\n4.chevrolet\n5.peugeot.\nElija una opcion:","Error, ingrese una de las opciones dadas.\n",1,5,3)==0)
        {
            return 1;

        }
        pause_and_clearScreen();
        if(!getInt(&aux_id_color,"Elija Color.\n1.negro\n2.blanco\n3.gris\n4.rojo\n5.azul.\nElija una opcion:","Error, ingrese una de las opciones dadas.\n",1,5,3)==0)
        {
            return 1;
            pause_and_clearScreen();
        }
        pause_and_clearScreen();
        if(!getInt(&aux_anio,"ingrese anio:","Error. ingrese anio desde 1900 a 2019",1900,2019,3)==0)
        {
            return 1;
            pause_and_clearScreen();
        }
        pause_and_clearScreen();
        if(!getInt(&aux_mes,"ingrese mes:","Error. ingrese mes desde 1 a 12",1,12,3)==0)
        {
            return 1;
        }
        pause_and_clearScreen();
        if(!getInt(&aux_dia,"ingrese dia:","Error. ingrese dia desde 1 a 31",1,31,3)==0)
        {
            return 1;
        }
        pause_and_clearScreen();

        strcpy(myCar[posicion].patente,auxPatente);
        myCar[posicion].idMarca=aux_id_marca;
        myCar[posicion].idColor=aux_id_color;
        myCar[posicion].modelo.anio=aux_anio;
        myCar[posicion].modelo.mes=aux_mes;
        myCar[posicion].modelo.dia=aux_dia;
        myCar[posicion].id=id_incremental+posicion;
        myCar[posicion].isEmpty=1;//ocupado
    }

    return retorno;
}

int findCarPatente(eAutos myCar[],int sizeAutos,char* patente)
{
    int retorno=-1;
    if(myCar!=NULL && sizeAutos >0)
    {
        for(int i=0;i<sizeAutos;i++)
        {
            if(myCar[i].isEmpty==1)
            {
                if(stricmp(myCar[i].patente,patente)==0)
                {
                    retorno=i;
                    break;
                }
            }

        }

    }
    return retorno;
}


int getDescripcionMarca(eMarcas miMarca[],int sizeMarca,int id,char* descripcion)
{
    int retorno=0;
    if(miMarca!=NULL && sizeMarca>0 )
    {
        for(int i=0;i<sizeMarca;i++)
        {
            if(miMarca[i].estado==1)
            {
                if(miMarca[i].id==id)
                {

                    strcpy(descripcion,miMarca[i].descripcion);
                }
            }


        }

    }
    else
    {
        retorno=1;
    }
    return retorno;

}
void printOneAutos(eAutos myCar,eMarcas miMarca[],int sizeMarca)
{
    char descripcion[30];
    getDescripcionMarca(miMarca,sizeMarca,myCar.idMarca,descripcion);
    printf("desc:%s \n",descripcion);
    printf("%d %s %d %s %d\n",myCar.id,myCar.patente,myCar.idMarca,descripcion,myCar.idColor);
}

int printAllCars(eAutos myCar[],int sizeCar,eMarcas misMarcas[],int sizeMarcas)
{
    if(myCar!=NULL && sizeCar>0 &&misMarcas!=NULL &&sizeMarcas>0)
    {
        for(int i=0;i<sizeCar;i++)
        {
            if(myCar[i].isEmpty==1)
            {
                printOneAutos(myCar[i],misMarcas,sizeMarcas);

            }
        }

    }
    return 0;
}

int removeCar(eAutos myCar[],int sizeCar,eMarcas misMarcas[],int sizeMarca)
{
    int retorno=0;
    char patente[MAX_PATENTES];
    int index_id;
    char seguir[2];
    if(myCar!=NULL && sizeCar>0 && misMarcas!=NULL && sizeMarca>0)
    {
        for(int i=0; i<sizeCar; i++)
        {
            if(myCar[i].isEmpty==1)
            {
                printOneAutos(myCar[i],misMarcas,sizeMarca);
            }
        }
        if(!getString(patente,"\nIngrese patente para dar de baja:","Error. Ingrese una patente de 1 a 6 caracteres.\n",1,MAX_PATENTES-1,3)==0)
        {
            return 1;
        }
        else
        {
            for(int i=0; i<sizeCar; i++)
            {
                if(myCar[i].isEmpty==1)
                {
                    index_id=findCarPatente(myCar,sizeCar,patente);
                    if(index_id!=-1)
                    {
                        printOneAutos(myCar[index_id],misMarcas,sizeMarca);
                        if(botonSeguir(seguir,"para dar de baja pulse [s], caso contrario pulse cualquier tecla:","Error, Ingrese un solo caracter.\n")==0)
                        {

                            myCar[index_id].isEmpty=0;
                            myCar[index_id].id-=1;
                            printf("auto dado de baja con exito.\nAdios.\n");
                            retorno=0;
                            pause_and_clearScreen();
                        }
                        else
                        {
                            printf("No se dio de baja.\nAdios.\n");
                            retorno=1;
                            break;
                        }
                    }


                }
            }

        }
    }
    return retorno;
}

eAutos forzarAutos(int id, char* patente, int marca, int color,int dia,int mes,int anio, int estado)
{
    eAutos aux;
    aux.id=id;
    strcpy(aux.patente,patente);
    aux.idMarca=marca;
    aux.idColor=color;
    aux.modelo.dia=dia;
    aux.modelo.mes=mes;
    aux.modelo.anio=anio;
    aux.isEmpty=estado;

    return aux;
}
