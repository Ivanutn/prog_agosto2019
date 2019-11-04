#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARACTERES 41
#define MAX_QTY 5
int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1.Alta\n2.Alta Curso\n3.Modificar\n4.Listar\n5.Informe\n6.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,6,3)==0)
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
            break;
        case 2:


            system("pause");
            system("cls");

            break;
        case 3:

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
    }while(numero!=6);

}

