#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cachorro.h"

int controller_loadFromText(char* path , LinkedList* pLinkedListCachorros);
int controller_listarCachorros(LinkedList* pLinkedListCachorros);
int controller_guardarFiltroMayores45Dias(char* path , LinkedList* pLinkedListCachorros);
int controller_guardarFiltroMachos(char* path , LinkedList* pLinkedListCachorros);
