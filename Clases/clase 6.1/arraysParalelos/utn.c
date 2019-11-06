#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
int getInt(int* input,char message[],char eMessage[],int lowLimit,int highLimit,int intentos)
{
    int numero;
    int retorno=0;
    int intentosAux=0;
    printf("%s",message);
    fflush(stdin);
    scanf("%d",&numero);

    while(numero<lowLimit || numero>highLimit)
    {
        printf("%s",eMessage);
        intentosAux++;
        system("pause");
        system("cls");

        if(intentosAux==intentos)
        {
            printf("superado el limite de intentos.\n");
            exit(1);
        }
        else
        {
            printf("%s",message);
            fflush(stdin);
            scanf("%d",&numero);
        }

    }

    *input=numero;//valor por referencia, modifico el original.


    return retorno;

}

int getFloat(float* input,char message[],char eMessage[],float lowLimit,float highLimit)
{
    float numero;
    int retorno=0;
    printf("%s",message);
    scanf("%f",&numero);
    if(numero<lowLimit || numero>highLimit){
        printf("%s",eMessage);
        system("pause");
        system("cls");
        retorno=1;
    }
    else{
        *input=numero;
    }

    return retorno;

}
int getCharacter(char* input,char message[],char eMessage[],char lowChar,char highChar)
{
    char letra;
    int retorno=0;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&letra);
    letra=tolower(letra);
    if(letra<lowChar || letra>highChar){
        printf("%s",eMessage);
        retorno=1;
    }
    else{
        *input=letra;
    }
    return retorno;
}

int getString(char* input,char message[],char eMessage[],int lowLimit,int highLimit)
{
    char nombre[31];
    char auxiliar[256];
    int retorno=0;
    printf("%s",message);
    fflush(stdin);
    gets(auxiliar);
    if(strlen(auxiliar)<lowLimit || strlen(auxiliar)>highLimit){
        printf("%s",eMessage);
        retorno=1;
    }
    else{
        strcpy(nombre,auxiliar);
        strcpy(input,nombre);
    }
    return retorno;

}
int getSex(char* input,char message[],char eMessage[],int intentos)
{
    char letra;
    int retorno=0;
    int intentosAux=0;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&letra);
    letra=tolower(letra);
    while(letra!='f' && letra!='m')
    {
        printf("%s",eMessage);
        system("pause");
        system("cls");
        intentosAux++;
        if(intentosAux==intentos)
        {
            printf("Superado la cantidad de intentos.\n");
            exit(1);
        }
        else
        {
            printf("%s",message);
            fflush(stdin);
            scanf("%c",&letra);
            letra=tolower(letra);
        }
    }
    if(letra=='m')
    {
        *input=letra;

    }
    else if(letra=='f')
    {
        *input=letra;
    }


    return retorno;
}
