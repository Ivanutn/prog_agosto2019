#include <stdio.h>
#include <stdlib.h>
typedef struct
{

}eGenerico;

eGenerico* generico_new();
eGenerico* generico_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void generico_delete();

int generico_setId(eGenerico* this,int id);
int generico_getId(eGenerico* this,int* id);

int generico_setNombre(eGenerico* this,char* nombre);
int generico_getNombre(eGenerico* this,char* nombre);

int generico_setHorasTrabajadas(eGenerico* this,int horasTrabajadas);
int generico_getHorasTrabajadas(eGenerico* this,int* horasTrabajadas);

int generico_setSueldo(eGenerico* this,int sueldo);
int generico_getSueldo(eGenerico* this,int* sueldo);
