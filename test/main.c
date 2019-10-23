#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../BibliotecaUtn/utn.h"
#define R 20
int main()
{
    FILE *pFile;
    int cant;
    int tam;
  //  FILE *archivo;
    char nombre[R];
    pFile=fopen("datos.txt","r");//evitas el warning.
    //if((pFile=fopen("datos.txt","r"))==NULL)//el modo de lectura R devuelve null si el archivo no existe
    //por algun motivo tira un warning dentro de la condicion. funciona pero el warning sigue.
    if(pFile==NULL)
    {
        pFile=fopen("datos.txt","w");//evitas el warning.
        //if( (pFile=fopen("datos.txt","w")==NULL))
        if(pFile==NULL)
        {
            printf("No se pudo abrir el archivo.\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("archivo creado con exito.\n");
             printf("Ingrese nombre:");
        fgets(nombre,R,stdin);
        removerSaltoDeLinea(nombre);
        fprintf(pFile,"%s \n",nombre);
            fclose(pFile);
        }

    }
    else
    {
        printf("el archivo ya existe\n");
        pFile=fopen("datos.txt","a");
        if(pFile!=NULL)
        {
            printf("Ingrese nombre:");
        fgets(nombre,R,stdin);
        removerSaltoDeLinea(nombre);
        fprintf(pFile,"%s ",nombre);
        fclose(pFile);

        }
        /*tam=strlen(nombre);
        cant=fwrite(nombre,sizeof(char),tam,pFile);
        if(cant<tam)
        {
            printf("hubo un error.\n");
        }
        else
        {
            printf("carga de forma correcta.\n");

        }*/
       // fclose(pFile);
    }
/*
    printf("ingrese nombre del archivo y agregue una extension:");
    fgets(nombre,20,stdin);
    removerSaltoDeLinea(nombre);

    archivo=fopen(nombre,"r");
    if(archivo==NULL)
    {
        archivo=fopen(nombre,"w");
        if(archivo==NULL)
        {
            printf("no se pudo crear el archivo.\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("archivo creado con exito.\n");
            fclose(archivo);
        }
    }
    else
    {
        printf("el archivo ya existe.\n");
        fclose(archivo);
    }
*/
    return 0;
}
