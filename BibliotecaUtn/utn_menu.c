#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1.Alta\n2.Baja\n3.Modificar\n4.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,4)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}
void menu(void)
{
    int numero;

    do
    {
            numero=opcion();
            switch (numero)
            {
            case 1:
                printf("Alta ok\n");

                break;
            case 2:
                printf("Baja ok\n");
                break;
            case 3:
                printf("Modificar ok\n");
                break;
            case 4:
                printf("Salir ok\n");
                break;
            default:
                break;
            }
    }while(numero!=4);

}

