#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
}eEmpleado
eEmpleado* newEmpleado(void);

int main()
{
    //array de punteros a empleados
    //puntero auxiliar estatico que lo guarda en el array de dir de memorias que es dinamica.
    //
    eEmpleado* aux;


    return 0;
}
eEmpleado* newEmpleado(void)
{
    eEmpleado* nuevo=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(nuevo!=NULL)
    {
        nuevo->id=0;
        strcpy(nuevo->nombre," ");
        nuevo->sueldo=0;
        return nuevo;
    }
}
