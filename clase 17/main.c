#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
}eEmpleado;

eEmpleado* newEmpleado(void);
eEmpleado* newEmpleadoParam(int id,char* nombre,float sueldo);

//creacion de setters.
//los setters al ser compactos, validan y asignan.
int setIdEmpleado(eEmpleado* e,int id);
int setSueldoEmpleado(eEmpleado* e,float sueldo);
int setNombreEmpleado(eEmpleado* e,char* nombre);

//getters.
int getIdEmpleado(eEmpleado* e,int* id);
int getSueldoEmpleado(eEmpleado* e,float* sueldo);
int getNombreEmpleado(eEmpleado* e,char* nombre);

//funcion para mostrar
int mostrarEmpleado(eEmpleado* e);
int mostrarEmpleados(eEmpleado* e,int tam);

//funcion para ordenar, bajo cualquier criterio.

/** INICIO MAIN  */
int main()
{
    //array de punteros a empleados
    //puntero auxiliar estatico que lo guarda en el array de dir de memorias que es dinamica.
    //
    int tam=0;
    eEmpleado* auxEmpleado=NULL; //hasta que no se hace un malloc, una buena practica es mejor asignarle NULL.
    eEmpleado** lista=(eEmpleado**)malloc(sizeof(eEmpleado*));
    //reserva espacio en memoria para un empleado(4 bytes), se castea a doble puntero lista
    //guardas una direccion de memoria de forma estatica, que a su vez apunta un vector de dir de memoria
    //que ellas apuntan en memoria a otras direcciones de memoria que contienen datos de tipo eEmpleado.
    if(lista==NULL)
    {
        printf("no se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }



    return 0;
}

/**INICIO DE DESARROLLO DE FUNCIONES */
eEmpleado* newEmpleado(void)
{
    //Constructor vacio.
    eEmpleado* nuevo=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(nuevo!=NULL)
    {
        nuevo->id=0;
        strcpy(nuevo->nombre," ");
        nuevo->sueldo=0;

    }
     return nuevo;
}

eEmpleado* newEmpleadoParam(int id,char* nombre,float sueldo)
{

    eEmpleado* nuevo=newEmpleado();
    if(nuevo!=NULL)
    {
        //setIdEmpleado(nuevo,id); //a la hora de dar de alta si todos los setters devuelven 1 se carga con exito.
        //ejemplo
        if(setIdEmpleado(nuevo,id) && setSueldoEmpleado(nuevo,sueldo) && setNombreEmpleado(nuevo,nombre)) //no es necesario que sea igual a 1.
        {
            printf("Empleado cargado con exit.\n");
        }

    }
    //constructor correctamente codeado al uso de los setters y sus validaciones.
    return nuevo;
}

//uso de getters y setters.

int setIdEmpleado(eEmpleado* e,int id) //recibe el puntero a empleado y el id.
{
    int todoOK=0;
    if(e!=NULL && id>=10000 && id<=20000)//id valido segun reglas de negocio.
    {
        e->id=id;
        todoOK=1;
    }
    return todoOK;
}

int setSueldoEmpleado(eEmpleado* e,float sueldo)
{
    int todoOK=0;
    if(e!=NULL && sueldo>0 )
    {
        e->sueldo=sueldo;
        todoOK=1;
    }
    return todoOK;
}

int setNombreEmpleado(eEmpleado* e,char* nombre)
{
    int todoOK=0;
    if(e!=NULL && nombre!=NULL && strlen(nombre)<20 )
    {
        strcpy(e->nombre,nombre);
        todoOK=1;
    }
    return todoOK;
}

//creacion de getters.
//los datos ya fueron cargados y validados.
int getIdEmpleado(eEmpleado* e,int* id)
{
    //int id=-1; //en caso de no conseguir el id.

    //recibe el id por referencia.
    int todoOK=0;
    if(e!=NULL && id!=NULL)
    {
        *id=e->id;
        todoOK=1;
    }
    return todoOK;
}

int getSueldoEmpleado(eEmpleado* e,float* sueldo)
{
    int todoOK=0;
    if(e!=NULL && sueldo!=NULL)
    {
        *sueldo=e->sueldo;
        todoOK=1;
    }
    return todoOK;
}

int getNombreEmpleado(eEmpleado* e,char* nombre)
{
    int todoOK=0;
    if(e!=NULL && nombre!=NULL)
    {
        strcpy(nombre,e->nombre); //copio lo que tengo guardado en la estructura y lo paso a la variable.
        todoOK=1;
    }
    return todoOK;
}

int mostrarEmpleado(eEmpleado* e)
{
    int todoOK=0;
    if(e!=NULL)
    {
       // printf("%d  %s  %.2f\n",getIdEmpleado(e,e->id),getNombreEmpleado(e,e->nombre),getSueldoEmpleado(e,e->sueldo));
        printf("%d  %s  %.2f\n",e->id,e->nombre,e->sueldo);
    }
    return todoOK;
}

int mostrarEmpleados(eEmpleado* e,int tam)
{
    int todoOK=0;
    if(e!=NULL && tam>0)
    {
        printf("ID   nombre    Sueldo\n");
        for(int i=0;i<tam;i++)
        {
            mostrarEmpleado(e+i);
        }


    }
    return todoOK;
}
