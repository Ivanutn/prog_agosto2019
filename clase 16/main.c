#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


eEmpleado* new_empleado(void);
int mostrarEmpleado(eEmpleado* emp);
eEmpleado* new_empParametrizado(int legajo,char* nombre,char sexo,float sueldo,int dia,int mes,int anio);
int agregarEmpleado(eEmpleado* vec,int tam,eEmpleado* emp);
int main()
{
    eEmpleado* pEmp;
    eEmpleado* lista;
    lista=(eEmpleado*)malloc((sizeof(eEmpleado)));
    int tam=0;//cumple 2 funciones . 1ero me inidica el tamanio de la lista, 2do me da el indice de la lista.
    if(lista==NULL)
    {
        printf("No se pudo conseguir memoria.\n");
        exit(EXIT_FAILURE);
    }
     pEmp=new_empParametrizado(1234,"jorge",'m',30000,1,2,1985);
     if(agregarEmpleado(lista,tam,pEmp)==1)
     {
         printf("se pudo agregar.\n");
         mostrarEmpleado(lista+tam);


     }
    // *(lista+tam)=*pEmp;//copio el contenido de una estructura a la primera posicion de la estructura lista.

   // mostrarEmpleado(lista+tam);

   /* pEmp=new_empleado();
    mostrarEmpleado(pEmp);
    printf("\n");
    pEmp=new_empParametrizado(1234,"jorge",'m',30000,1,2,1985);
    mostrarEmpleado(pEmp);*/

   // free(pEmp);
    return 0;
}

eEmpleado* new_empleado(void)
{
    eEmpleado* aux;
    aux=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(aux!=NULL)
    {
        aux->legajo=0;
        strcpy(aux->nombre,"sin definir");//especificar que no esta definido
        aux->sexo='m';
        aux->sueldo=0;
        aux->fecha_nacimiento=(eFecha){1,1,1990};// se castea al tipo de dato efecha para que reconozca los campos hardcodeados.
       /*aux->fecha_nacimiento.dia=0;
        aux->fecha_nacimiento.mes=0;
        aux->fecha_nacimiento.anio=0;*/

    }
    return aux;
}

 int mostrarEmpleado(eEmpleado* emp)
 {
     int todoOK=0;
     if(emp!=NULL)
     {
         printf("%d  %s  %c  %.2f  %d %d %d",emp->legajo,emp->nombre,emp->sexo,emp->sueldo,emp->fecha_nacimiento.dia,emp->fecha_nacimiento.mes,emp->fecha_nacimiento.anio);
         todoOK=1;

     }
    return todoOK;
 }

eEmpleado* new_empParametrizado(int legajo,char* nombre,char sexo,float sueldo,int dia,int mes,int anio)
{

    eEmpleado* nuevoEmpleado;
    nuevoEmpleado=new_empleado();
    if(nuevoEmpleado!=NULL)
    {
       nuevoEmpleado->legajo=legajo;//colocar dentro de funciones que validan cada campo pasado por parametros
                                    //usando funciones llamadas getter y setter.
       strcpy(nuevoEmpleado->nombre,nombre);
       nuevoEmpleado->sexo=sexo;
       nuevoEmpleado->sueldo=sueldo;
       nuevoEmpleado->fecha_nacimiento.dia=dia;
       nuevoEmpleado->fecha_nacimiento.mes=mes;
       nuevoEmpleado->fecha_nacimiento.anio=anio;

    }

    return nuevoEmpleado;
}


int agregarEmpleado(eEmpleado* vec,int tam,eEmpleado* emp)
 {
     int todoOK=0;
     eEmpleado* aux;
     if(vec!=NULL && emp!=NULL && tam>=0)
     {
         *(vec+tam)=*emp;
         aux=(eEmpleado*)realloc(vec,sizeof(eEmpleado)*(tam+1));
         if(aux!=NULL)
         {
             vec=aux;
             todoOK=1;
         }
     }

     return todoOK;

 }
