#include <stdio.h>
#include <stdlib.h>
#include "utn_validaciones.h"
#define MAX_CARACTERES 51
typedef struct
{
    int id;
    char name[MAX_CARACTERES];
    char lastName[MAX_CARACTERES];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;
typedef struct
{
    int id_sector;
    char descripcion_sector[MAX_CARACTERES];

}eSector;

int initEmployee(eEmployee myEmployee[],int sizeEmployee,int value);
int getFreePosition(eEmployee myEmployee[],int sizeEmployee,int* position);
int addEmployee(eEmployee myEmployee[],int sizeEmployee);
int myAuxEmployee(eEmployee myEmployee);
int findEmployeeByID(eEmployee myEmployee[],int sizeEmployee,int id);

