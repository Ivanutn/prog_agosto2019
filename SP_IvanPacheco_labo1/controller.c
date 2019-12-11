#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pLinkedListCachorros)
{
    int retorno = 0;

    FILE* pFile;
    pFile = fopen(path, "r");
    if(pLinkedListCachorros!=NULL)
    {
        if(path!=NULL)
        {
            if(pFile!=NULL)
            {
                parser_cachorrosFromText(pFile, pLinkedListCachorros);
                retorno = 1;
            }
            else
            {


                printf("NO SE PUDO ABRIR EL ARCHIVO.\n");
                system("pause");
                retorno = 0;
            }
        }
        else
        {
            printf("falla path\n");
            retorno=0;
        }
    }
    else
    {
        printf("falla linkedlist\n");
            retorno=0;
    }

    return retorno;
}

int controller_listarCachorros(LinkedList* pLinkedListCachorros)
{
    int todoOK=0;
    eCachorro* perrinhos=NULL;
    int aux_id_cachorro;
    char aux_nombre[30];
    int aux_dias;
    char aux_raza[30];
    char aux_reservado[3];
    char aux_genero;

    if(pLinkedListCachorros!=NULL)
    {

        for(int i=0;i<ll_len(pLinkedListCachorros);i++)
        {
            perrinhos=(eCachorro*)ll_get(pLinkedListCachorros,i);
            if(perrinhos!=NULL)
            {
                cachorro_getId(perrinhos,&aux_id_cachorro);
                cachorro_getNombre(perrinhos,aux_nombre);
                cachorro_getDias(perrinhos,&aux_dias);
                cachorro_getRaza(perrinhos,aux_raza);
                cachorro_getReservado(perrinhos,aux_reservado);
                cachorro_getGenero(perrinhos,&aux_genero);
                printf("%5d %10s %5d %10s %10s %5c\n",aux_id_cachorro,aux_nombre,aux_dias,aux_raza,aux_reservado,aux_genero);
            }
        }
        todoOK=1;
    }
    return todoOK;

}

int controller_guardarFiltroMayores45Dias(char* path , LinkedList* pLinkedListCachorros)
{
    int retorno = 0;
    eCachorro* perrinhos=NULL;
    int aux_id_cachorro;
    char aux_nombre[30];
    int aux_dias;
    char aux_raza[30];
    char aux_reservado[3];
    char aux_genero;

    LinkedList* nuevaListaFiltrada=NULL;
    FILE* newArchivo = fopen(path, "w");

    if(newArchivo != NULL && pLinkedListCachorros != NULL)
    {


        fprintf(newArchivo, "id_cachorro,nombre,dias,raza,reservado,genero\n");
        nuevaListaFiltrada=ll_filter(pLinkedListCachorros,filtro_menores45dias);
        if(nuevaListaFiltrada!=NULL)
        {
          for(int i = 0; i<ll_len(nuevaListaFiltrada); i++)
            {
            perrinhos = ll_get(nuevaListaFiltrada,i);
            cachorro_getId(perrinhos, &aux_id_cachorro);
            cachorro_getNombre(perrinhos, aux_nombre);
            cachorro_getDias(perrinhos, &aux_dias);
            cachorro_getRaza(perrinhos,aux_raza);
            cachorro_getReservado(perrinhos,aux_reservado);
            cachorro_getGenero(perrinhos,&aux_genero);
            fprintf(newArchivo,"%5d %10s %5d %10s %10s %c\n",aux_id_cachorro,aux_nombre,aux_dias,aux_raza,aux_reservado,aux_genero);
            }
        }

        fclose(newArchivo);
        retorno = 1;
    }
    return retorno;
}

int controller_guardarFiltroMachos(char* path , LinkedList* pLinkedListCachorros)
{
        int retorno = 0;
    eCachorro* perrinhos=NULL;
    int aux_id_cachorro;
    char aux_nombre[30];
    int aux_dias;
    char aux_raza[30];
    char aux_reservado[3];
    char aux_genero;

    LinkedList* nuevaListaFiltrada=NULL;
    FILE* newArchivo = fopen(path, "w");

    if(newArchivo != NULL && pLinkedListCachorros != NULL)
    {


        fprintf(newArchivo, "id_cachorro,nombre,dias,raza,reservado,genero\n");
        nuevaListaFiltrada=ll_filter(pLinkedListCachorros,filtro_machos);
        if(nuevaListaFiltrada!=NULL)
        {
          for(int i = 0; i<ll_len(nuevaListaFiltrada); i++)
            {
            perrinhos = ll_get(nuevaListaFiltrada,i);
            cachorro_getId(perrinhos, &aux_id_cachorro);
            cachorro_getNombre(perrinhos, aux_nombre);
            cachorro_getDias(perrinhos, &aux_dias);
            cachorro_getRaza(perrinhos,aux_raza);
            cachorro_getReservado(perrinhos,aux_reservado);
            cachorro_getGenero(perrinhos,&aux_genero);
            fprintf(newArchivo,"%5d %10s %5d %10s %10s %c\n",aux_id_cachorro,aux_nombre,aux_dias,aux_raza,aux_reservado,aux_genero);
            }
        }

        fclose(newArchivo);
        retorno = 1;
    }
    return retorno;

}
