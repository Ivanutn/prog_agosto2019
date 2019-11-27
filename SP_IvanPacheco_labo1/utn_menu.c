#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"


int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1.Cargar Archivo\n2.Imprimir Lista\n3.Filtrar menores de 45 dias\n4.Filtrar Machos\n5.Generar listado de callejeros\n6.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,6,3)==0)
    {
        opcion=auxOpcion;
    }


    return opcion;
}
int menu(void)
{
    int numero;
    int retorno=0;//todo bien.
    int flag=0;
    char nombreArchivo[20];
    char extension[]=".csv";

    LinkedList* misCachorros;
    misCachorros=ll_newLinkedList();


    if(misCachorros!=NULL)
    {
        do
        {
            numero=opcion();
            switch (numero)
            {
            case 1:
                getString(nombreArchivo,"nombre del archivo 'cachorros' en minuscula\nIngrese el nombre del archivo a cargar:","Error, ingrese minimo 1 y maximo 20 caracteres.\n",1,20,3);

                strcat(nombreArchivo,extension);
                if(controller_loadFromText(nombreArchivo,misCachorros))
                {
                    printf("Archivo cargado con exito.\n");
                    flag=1;
                }
                pauseAndClear();
                break;
            case 2:
                if(flag==0)
                {
                   printf("Primero hay que cargar el archivo\n");
                }
                else
                {
                    controller_listarCachorros(misCachorros);
                }
                 pauseAndClear();
                break;
            case 3:
                if(flag==0)
                {
                   printf("Primero hay que cargar el archivo\n");
                }
                else
                {
                    ll_filter(misCachorros,))
                    controller_guardarFiltrado("filtrar menores de 45",misCachorros);
                }
                 pauseAndClear();

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                break;
            default:
                break;
            }
        }
        while(numero!=6);
    }
    return retorno;
}

