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
int mostrarEmpleados(eEmpleado** e,int tam);

//funcion para ordenar, bajo cualquier criterio.

//funcion para agrandar lista.

eEmpleado** agrandarLista(eEmpleado** vec,int tam);


//quiero guardar en un archivo binario
int guardarEmpleadosBinario(eEmpleado** lista,int tam,char* path);

//cargar desde binario.



/** INICIO MAIN  */
int main()
{
    //array de punteros a empleados
    //puntero auxiliar estatico que lo guarda en el array de dir de memorias que es dinamica.
    //
    char buffer[3][30];
    int cant;
    int tam=0; //cumple 2 funciones . 1ero me inidica el tamanio de la lista, 2do me da el indice de la lista.
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


    FILE* f= fopen("personas.csv","r");
    if(f==NULL)
    {
        exit(EXIT_FAILURE);
    }
    fscanf(f,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]); //expresiones regulares ^ (acento circunflejo) significa todo. la expresion[^,] significa lee todo hasta que encuentres la coma(,)
    //lectura fantasma.

    while(!feof(f))
    {
        cant=fscanf(f,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);
        if(cant==3)
        {
            auxEmpleado=newEmpleadoParam(atoi(buffer[0]),buffer[1],atof(buffer[2]) );
            //antes fallaba porque los parametros del newEmpleadoParam, no estaban en orden.
            if(auxEmpleado!=NULL)
            {

                *(lista+tam)=auxEmpleado;
                tam++;
                if((lista=agrandarLista(lista,tam+1))!=NULL)
                {
                    //printf("Empleado agregado a la lista.\n");
                }
            }


        }
        else
        {
            break;
        }
    }
    fclose(f);
    mostrarEmpleados(lista,tam);
    if(guardarEmpleadosBinario(lista,tam,"empleados.bin"))
    {
        printf("empleados guardados con exito.\n");
    }
    else
    {
        printf("empleados no fueron guardados.\n");// se llama serializar o deserializar
    }

  /**--------------------------------------------------*/

    /** levanto el archivo o leerlo de  binario */


    printf("\n\nEMPLEADOS DE LA LISTA 2\n\n");
    eEmpleado** lista2 =(eEmpleado**)malloc(sizeof(eEmpleado));//me sirve para levantarlo de archivo binario


    int tam2=0;
    if(lista2==NULL)
    {
        printf("no se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }


    f= fopen("empleados.bin","rb");
    if(f==NULL)
    {
        exit(EXIT_FAILURE);
    }

    while(!feof(f))
    {
        auxEmpleado=newEmpleado();
        if(auxEmpleado!=NULL)
        {
            cant=fread( auxEmpleado,sizeof(eEmpleado),1,f);
            if(cant==1)
            {
                *(lista2+tam2)=auxEmpleado;
                tam2++;
                if((lista2=agrandarLista(lista2,tam2+1))!=NULL)
                {
                    //printf("Empleado agregado a la lista.\n");
                }
            }
            else
            {
                break;
            }

        }
    }

    mostrarEmpleados(lista2,tam2);


    fclose(f);

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
        if(setIdEmpleado(nuevo,id) && setNombreEmpleado(nuevo,nombre) && setSueldoEmpleado(nuevo,sueldo)) //no es necesario que sea igual a 1.
        //los seteos se deben respetar en orden a la hora de llamar a la funcion.
        {
            //printf("Empleado parametrizado.\n");
        }

    }
    else
    {
        nuevo=NULL;
    }
    //constructor correctamente codeado al uso de los setters y sus validaciones.
    return nuevo;
}

//uso de getters y setters.

int setIdEmpleado(eEmpleado* e,int id) //recibe el puntero a empleado y el id.
{
    int todoOK=0;
    if(e!=NULL)
    {
        if(id>=1 && id<20000)//id valido segun reglas de negocio.
        {
            e->id=id;
            todoOK=1;
        }

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
        printf("%d\t%s   \t%5.2f\n",e->id,e->nombre,e->sueldo);
        todoOK=1;
    }
    return todoOK;
}

int mostrarEmpleados(eEmpleado** e,int tam)
{
    int todoOK=0;
    if(e!=NULL && tam>0)
    {
        printf("ID      NOMBRE       Sueldo\n");
        for(int i=0;i<tam;i++)
        {
            mostrarEmpleado(*(e+i));
        }
        todoOK=1;

    }
    return todoOK;
}

eEmpleado** agrandarLista(eEmpleado** vec,int tam)
{
    eEmpleado** aux=(eEmpleado**)realloc(vec,sizeof(eEmpleado*)*tam); //sizeof por tipo de dato puntero (eEmpleado*)
    if(aux!=NULL)
    {
        vec=aux;
    }
    return vec;
}

int guardarEmpleadosBinario(eEmpleado** lista,int tam,char* path)
{
    int todoOK=0;
    int cant;
    FILE* f;

    if(lista!=NULL && tam>0 && path!=NULL)
    {
        f=fopen(path,"wb");
        if(f==NULL)
        {
            return todoOK;
        }
        for(int i=0;i<tam;i++)
        {
          cant=fwrite(*(lista+i),sizeof(eEmpleado),1,f);//funciona como fscanf "viaja" de origen a destino
            //*(lista+i) me posiciono en esa direccion de memoria, con el * accedo al dato y eso es lo que escribo en el archivo.
           if(cant<1)
           {
               return todoOK;
           }
        }
        fclose(f);
        todoOK=1;
    }
    return todoOK;
}
