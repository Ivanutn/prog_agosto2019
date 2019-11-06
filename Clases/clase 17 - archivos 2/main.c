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
    int cant;
    eEmpleado unEmpleado={1,"julia",15000};
    eEmpleado clonEmpleado;
    eEmpleado otroClonardo;
   /* FILE* f=fopen("data.bin","wb"); //modo escritura binaria
    if(f==NULL)
    {
        printf("no se pudo crear un archivo.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
       cant=fwrite(&unEmpleado,sizeof(eEmpleado),1,f); //devuelve la cantidad de elementos que pudo escribir
       if(cant<1)
       {
           printf("problemas para guardar en el archivo.\n");

       }
       else
       {
           printf("se guardo de manera exitosa.\n");
           fclose(f);
       }


    }*/

    FILE* f=fopen("data.bin","rb");
    if(f==NULL)
    {
        printf("no se pudo crear un archivo.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
       cant=fread(&otroClonardo,sizeof(eEmpleado),1,f); //devuelve la cantidad de elementos que pudo escribir
       if(cant<1)
       {
           printf("problemas para leer en el archivo.\n");

       }
       else
       {
           printf("se leyo el archivo de manera exitosa.\n");
           fclose(f);
       }


    }

    mostrarEmpleado(&otroClonardo);
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
