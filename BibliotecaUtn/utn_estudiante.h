#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BibliotecaUtn/utn.h"
#include "../BibliotecaUtn/utn_menu.h"
#define MAX 40



typedef struct
{
    int id_estudiante;
    char nombre[MAX];
    int id_carrera;
    int id_materia;
    int estado;

}eEstudiante;

typedef struct
{
    int id_materia;
    int estado;
    char descripcion[MAX];

}eMateria;

typedef struct
{
    int id_materia;
    int id_estudiante;
    int nota;
    int estado;
    //estructura que relaciona muchos a muchos (estudiantes y materias)
}eCurso;

typedef struct
{
    int id_carrera;
    char descripcion[MAX];
    int id_materia;
    int estado;

}eCarrera;//opciones de carrera

int inicializarArray(eEstudiante pArray[],int cantidad);
int buscarEspacioLibre(eEstudiante pArray[],int cantidad);
int buscarLegajo(eEstudiante pArray[],int cantidad,int legajo,int* posicionLegajo);
int cargaArray(eEstudiante pArray[],int cantidad,eMateria materias[], int cantCarrera);
void mostrarUnElemento(eEstudiante pArray,eMateria materias);
int mostrarArrayDeElementos(eEstudiante pArray[],int cantidad,eMateria materias[],int cantCarrera);
int obtenerDescripcion(eMateria materias[],int cantCarrera,int id_encontrar,char* descripcion);
int bajaLogica(eEstudiante array[],int cantidad,eMateria materias[],int cantCarrera);
int informe_UNO(eEstudiante arrayEstudiante[],int sizeEstudiante,eMateria arrayCarrera[],int sizeCarrera,eCurso arrayCurso[],int sizeCurso);
