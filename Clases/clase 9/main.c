#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BibliotecaUtn/utn.h"
#include "../BibliotecaUtn/utn_array.h"
#include "../BibliotecaUtn/utn_menu.h"

typedef struct
{
    int id_carrera;
    char descripcion[50];
    int estado;//estado vacio en 0 y 1 ocupado
}eCarrera;
int main()
{
    menu();
    eCarrera hardcodearCarrera[2]={ {1,"Programacion",0},{2,"SPD",0}};
    return 0;
}
