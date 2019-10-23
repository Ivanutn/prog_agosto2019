#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fecha_nacimiento;
}eEmpleado;

empleado* new_empleado(void);
int main()
{
    eEmpleado* pEmp;

    return 0;
}

empleado* new_empleado(void)
{
    eEmpleado* aux;
    aux=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(aux!=NULL)
    {
        aux->legajo=0;
        strcpy(aux->nombre,"");
        aux->sexo='';
        aux->sueldo=0;
        aux->fecha_nacimiento.dia=0;
        aux->fecha_nacimiento.mes=0;
        aux->fecha_nacimiento.anio=0;

    }
    return aux;
}
