#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "utn_validaciones.h"
#include "color.h"
#include "servicios.h"
#include "cliente.h"
#define MAX_QTY 1000
#define MAX_SECTOR 3
#define QTY_MARCAS 5
#define QTY_COLORES 5
#define QTY_SERVICIOS 4
#define QTY_CLIENTES 50

int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1.Alta auto\n2.Modificar Auto\n3.Baja Auto\n4.Listar Autos\n5.Listar Marcas\n6.Listar Colores\n7.Listar Servicios\n8.Alta Trabajo\n9.Listar Trabajo\n10.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,5,3)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}
void menu(void)
{
    int numero;
    int flagAlta=0;
    eAutos myCar[MAX_QTY];
    eAutos auxCar[MAX_QTY];
    initCar(myCar,MAX_QTY,0);
    eMarcas misMarcas[QTY_MARCAS]={ {1000,"renault",1},{1001,"fiat",1},{1002,"ford",1},{1003,"chevrolet",1},{1004,"peugeot",1} };
    eColor misColores[QTY_COLORES]={ {5000,"negro",1},{5001,"blanco",1},{5002,"gris",1},{5003,"rojo",1},{5004,"azul",1} };
    eServicios misServicios[QTY_SERVICIOS]={ {20000,"lavado",250,1},{20001,"pulido",300,1},{20002,"encerado",400,1},{20003,"completo",600,1} };
    eCliente misClientes[QTY_CLIENTES]={ {1,"jose","avellaneda",1} , {2,"carlos","lomas de zamora",1}, {3,"manuel","temperley",1}, {4,"alberto","adrogue",1} , {5,"raul","monte grande",1} };
    myCar[0]=forzarAutos(1,"aaabbb",1,1,2,4,1990,1);
    myCar[1]=forzarAutos(2,"bbbccc",4,2,25,9,2015,1);
    myCar[2]=forzarAutos(3,"cccddd",3,5,12,12,2001,1);
    myCar[3]=forzarAutos(4,"dddeee",2,3,11,11,2001,1);
    myCar[4]=forzarAutos(5,"fffggg",5,4,6,7,2018,1);

    do
    {
            numero=opcion();
        switch (numero)
        {
        case 1:
           if( add_Car(myCar,MAX_QTY)==0)
           {
               flagAlta++;
               for(int i=0;i<MAX_QTY;i++)
               {
                   auxCar[i]=myCar[i];
               }


           }
            pause_and_clearScreen();

            break;
        case 2:
            if(flagAlta>0)
            {


            }
            else
            {
                printf("No hay datos cargados.\n");
                pause_and_clearScreen();
            }

            break;
        case 3:
            if(flagAlta>0)
            {
                removeCar(myCar,MAX_QTY,misMarcas,QTY_MARCAS);

            }
            else
            {
                printf("No hay datos cargados.\n");
                pause_and_clearScreen();
            }
            break;
        case 4:
           // if(flagAlta>0)
            //{
                printAllCars(myCar,MAX_QTY,misMarcas,QTY_MARCAS);

            //}
          /*  else
            {
                printf("No hay datos cargados.\n");
                pause_and_clearScreen();
            }*/
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            break;
        }
    }while(numero!=10);

}
