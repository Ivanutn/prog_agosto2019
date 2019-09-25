#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BibliotecaUtn/utn.h"
#include "../BibliotecaUtn/utn_menu.h"
#define MAX 40



typedef struct
{
    int legajo;
    char nombre[MAX];
    int id_carrera;
    int estado;

}eEstudiante;

typedef struct
{
    int id_carrera;
    int estado;
    char descripcion[MAX];

}eCarrera;

typedef struct
{
  int id_materia;
  char nombre_materia[MAX];
}eMateria;

typedef struct
{
    int id_materia;
    int id_estudiante;
    int nota;
    //estructura que relaciona muchos a muchos (estudiantes y materias)
}eCurso;

int inicializarArray(eEstudiante pArray[],int cantidad);
int buscarEspacioLibre(eEstudiante pArray[],int cantidad);
int buscarLegajo(eEstudiante pArray[],int cantidad,int legajo,int* posicionLegajo);
int cargaArray(eEstudiante pArray[],int cantidad,eCarrera carreras[], int cantCarrera);
void mostrarUnElemento(eEstudiante pArray,eCarrera pCarrera);
int mostrarArrayDeElementos(eEstudiante pArray[],int cantidad,eCarrera pCarrera[],int cantCarrera);
int obtenerDescripcion(eCarrera carrera[],int cantCarrera,int id_encontrar,char* descripcion);
int bajaLogica(eEstudiante array[],int cantidad,eCarrera carrera[],int cantCarrera);
