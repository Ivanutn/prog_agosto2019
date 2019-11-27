#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "cachorro.h"
#include "LinkedList.h"

int parser_cachorrosFromText(FILE* pFile, LinkedList* pLinkedListCachorros)
{
    eCachorro* nuevoCachorro;
    int retorno = 0;
    char buffer[6][20];
    int cant;

    if(pLinkedListCachorros!=NULL)
    {

        fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
            if(cant == 6)
            {
                nuevoCachorro = cachorro_new();
                nuevoCachorro = cachorro_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
                ll_add(pLinkedListCachorros, nuevoCachorro);
                retorno = 0;
            }
            else
            {
                printf("NO SE HA LEIDO CORRECTAMENTE.\n");
                system("pause");
                retorno = 1;
                break;

            }
        }
    }
    fclose(pFile);
    return retorno;
}

