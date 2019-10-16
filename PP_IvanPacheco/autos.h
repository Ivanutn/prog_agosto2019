#include <stdio.h>
#include <stdlib.h>
#include "utn_validaciones.h"
#include "fechas.h"
#include "marcas.h"
#define MAX_CARACTERES 51
#define MAX_PATENTES 7
typedef struct
{
    int id;
    char patente[MAX_CARACTERES];
    int idMarca;
    int idColor;
    eFechas modelo;
    int isEmpty;
}eAutos;

int initCar(eAutos myCar[],int sizeAutos,int value);

int getFreePosition(eAutos myCar[],int sizeAutos,int* position);

int add_Car(eAutos myCar[],int sizeAutos);

int newCar(eAutos myCar[],int sizeAutos,int posicion);

int findCarPatente(eAutos myCar[],int sizeAutos,char* patente);

int getDescripcionMarca(eMarcas miMarca[],int sizeMarca,int id,char* descripcion);

void printOneAutos(eAutos myCar,eMarcas miMarca[],int sizeMarca);

int printAllCars(eAutos myCar[],int sizeCar,eMarcas misMarcas[],int sizeMarcas);

int removeCar(eAutos myCar[],int sizeCar,eMarcas misMarcas[],int sizeMarca);

eAutos forzarAutos(int id, char* patente, int marca, int color,int dia,int mes,int anio, int estado);
