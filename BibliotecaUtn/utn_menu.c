#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_estudiante.h"
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
    eEstudiante misEstudiantes[MAX_QTY]={
        {1,"jose",1,1,1},
        {2,"alvaro",2,2,1},
        {3,"rambo",1,2,1},
        {4,"Zed",2,1,1},
    };
    eEstudiante auxEstudiantes[MAX_QTY];
    eMateria misMaterias[MAX_QTY]={ {1,0,"programacion"},{2,0,"spd"}};
    eCurso misCursos[MAX_QTY];
   // inicializarArray(misEstudiantes,MAX_QTY);



    do
    {
            numero=opcion();
        switch (numero)
        {
        case 1:

            cargaArray(misEstudiantes,MAX_QTY,misMaterias,MAX_QTY);
            for(int i=0; i<MAX_QTY; i++)
            {
                auxEstudiantes[i]=misEstudiantes[i];
            }
            system("pause");
            system("cls");
            break;
        case 2:


            system("pause");
            system("cls");

            break;
        case 3:

            break;
        case 4:
            mostrarArrayDeElementos(misEstudiantes,MAX_QTY,misMaterias,MAX_QTY);
            system("pause");
            system("cls");
            break;
        case 5:
            informe_UNO(misEstudiantes,MAX_QTY,misMaterias,MAX_QTY,misCursos,MAX_QTY);

            break;
        case 6:
            break;
        default:
            break;
        }
    }while(numero!=6);

}

