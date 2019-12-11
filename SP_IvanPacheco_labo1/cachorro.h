#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int id_cachorro;
   char nombre[30];
   int dias;
   char raza[30];
   char reservado[3];
   char genero;
}eCachorro;

eCachorro* cachorro_new();
eCachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* reservadoStr,char genero);
void cachorro_delete();

int cachorro_setId(eCachorro* this,int id);
int cachorro_getId(eCachorro* this,int* id);

int cachorro_setNombre(eCachorro* this,char* nombre);
int cachorro_getNombre(eCachorro* this,char* nombre);

int cachorro_setDias(eCachorro* this,int dias);
int cachorro_getDias(eCachorro* this,int* dias);

int cachorro_setRaza(eCachorro* this,char* raza);
int cachorro_getRaza(eCachorro* this,char* raza);

int cachorro_setReservado(eCachorro* this,char* reservado);
int cachorro_getReservado(eCachorro* this,char* reservado);

int cachorro_setGenero(eCachorro* this,char genero);
int cachorro_getGenero(eCachorro* this,char* genero);

int filtro_menores45dias(void* pElement);
int filtro_machos(void* pElement);

LinkedList* map_nombre_raza(void* pElement);

