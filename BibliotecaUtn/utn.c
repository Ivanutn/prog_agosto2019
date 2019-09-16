#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int valNumber(char* string,int cant)
{
    int retorno=1;//si retorna 1 hubo un error. 0 todo bien.

    for(int i=0;string[i]!='\0' && i<cant;i++)
    {
        if(string[i]<'0' || string[i]>'9')
        {
            retorno=1;
            break;
        }
        else
        {
            retorno=0;

        }
    }
    return retorno;
}

int getInt(int* input,char message[],char eMessage[],int lowLimit,int highLimit)
{
    int numero;
    int retorno=0;
    char auxNum[30];
    printf("%s",message);
    fflush(stdin);
    gets(auxNum);

    if(valNumber(auxNum,30)==0)
    {
        numero=atoi(auxNum);
    }

    if(numero<lowLimit || numero>highLimit){
        printf("%s",eMessage);
        retorno=1;
    }
    else{
        *input=numero;//valor por referencia, modifico el original.
    }

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

