#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_validaciones.h"

int initEmployee(eEmployee myEmployee[],int sizeEmployee,int value)
{
    int retorno=-1;
    if(myEmployee!=NULL && sizeEmployee>0)
    {
        for(int i=0; i<sizeEmployee; i++)
        {
            myEmployee[i].isEmpty=value; //value 0 = vacio.
        }
        retorno=0;
    }
    return retorno;

}
int getFreePosition(eEmployee myEmployee[],int sizeEmployee,int* position)
{
    int retorno=-1; // es que NO esta vacio el  array
    if(myEmployee!=NULL && sizeEmployee > 0)
    {
        for(int i=0; i<sizeEmployee; i++)
        {
            if(myEmployee[i].isEmpty == 0)
            {
                *position=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;

}

int addEmployee(eEmployee myEmployee[],int sizeEmployee)
{
    eEmployee auxEmployee;
    int retorno=0;
    int id=0;
    int pos;
    if(getFreePosition(myEmployee,sizeEmployee,&pos)==0)
    {
        if(myAuxEmployee(auxEmployee)==0)
        {
            myEmployee[pos]=auxEmployee;
            myEmployee[pos].id=id;
            myEmployee[pos].isEmpty=1;//ocupado
            id++;
            printf("Alta dada con exito.\n");
        }

    }
    else
    {
        printf("No hay mas espacio.\n");
        retorno=1;
    }
    return retorno;

}

int myAuxEmployee(eEmployee myEmployee)
{
    char auxNombre[MAX_CARACTERES];
    char auxApellido[MAX_CARACTERES];
    float auxSalary;
    int auxSector;

    if(!getString(auxNombre,"ingrese nombre:","Error. min de caracteres 1 y maximo 50.\n",1,MAX_CARACTERES-1,3)==0)
    {
         return 1;
    }
    if(!getString(auxApellido,"ingrese apellido:","Error. min de caracteres 1 y maximo 50.\n",1,MAX_CARACTERES-1,3)==0)
    {
       return 1;
    }
    if(!getFloat(&auxSalary,"Ingrese salario:","Error, salario debe ser mayor a 1000",1000,999999)==0)
    {
        return 1;
    }
    if(!getInt(&auxSector,"Sector\n1.Sistemas\n2.RRHH\n3.Contabilidad\nIngrese su opcion:","Error. elija las opciones del menu.\n",1,3,3)==0)
    {
        return 1;
    }
    strcpy(myEmployee.name,auxNombre);
    strcpy(myEmployee.lastName,auxApellido);
    myEmployee.salary=auxSalary;
    myEmployee.sector=auxSector;

    return 0;
}

int findEmployeeByID(eEmployee myEmployee[],int sizeEmployee,int id)
{
    int retorno=-1;
    if(myEmployee!=NULL && sizeEmployee >0 && id >0)
    {

        for(int i=0;i<sizeEmployee;i++)
        {
            if(myEmployee[i].isEmpty==1)
            {
                if(myEmployee[i].id==id)
                {
                    retorno=i;
                    break;
                }
                else
                {
                    printf("No existe ese ID.\n");
                    break;
                }

            }

        }

    }
    return retorno;
}

int getSectorDescription(eSector mySector[],int sizeSector,int id,char* descripcion)
{
    int retorno=0;
    if(mySector!=NULL && sizeSector>0 )
    {
        for(int i=0;i<sizeSector;i++)
        {
            if(mySector[i].id_sector==id)
            {
                strcpy(descripcion,mySector[i].descripcion_sector);
            }

        }

    }
    return retorno;

}
void listOneEmployee(eEmployee myEmployee,eSector mySector)
{
    printf("%s %s %s %.2f\n",myEmployee.name,myEmployee.lastName,mySector.descripcion_sector,myEmployee.salary);
}

void listAllEmployees(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector)
{
    if(myEmployee!=NULL && sizeEmployee>0 &&mySector!=NULL &&sizeSector>0)
    {
        for(int i=0;i<sizeEmployee;i++)
        {
            if(myEmployee[i].isEmpty==1)
            {

            }
        }

    }
}
