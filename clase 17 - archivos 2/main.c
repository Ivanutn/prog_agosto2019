#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
}eEmpleado;

int mostrarEmpleado(eEmpleado* e);
int main()
{
    eEmpleado unEmpleado={1,"ana",15000};
    FILE* f=fopen("data.bin","wb"); //modo escritura binaria
    if(f==NULL)
    {
        printf("no se pudo crear un archivo.\n");
    }
    else
    {

    }

    mostrarEmpleado(&unEmpleado);
    return 0;
}
int mostrarEmpleado(eEmpleado* e)
{
    int todoOK=0;
    if(e!=NULL)
    {
        printf("%d  %s  %.2f\n",e->id,e->nombre,e->sueldo);
    }
    return todoOK;
}
