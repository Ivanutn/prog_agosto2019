#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
int utn_getInt(int* input,char message[],char eMessage[],int lowLimit,int highLimit)
{
    int numero;
    char auxiliar[256];
    int retorno=1;
    printf("%s",message);
    fflush(stdin);
    gets(auxiliar);
    if(utn_valNumber(auxiliar)==0 ){
        printf("dentro de la validacion del auxiliar.\n\n");
        numero=atoi(auxiliar);
    }
    if(numero<lowLimit || numero>highLimit){
        printf("%s",eMessage);
        retorno;
    }
    else{
        *input=numero;//valor por referencia, modifico el original.
        retorno=0;
    }

    return retorno;

}

int utn_getFloat(float* input,char message[],char eMessage[],float lowLimit,float highLimit)
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
int utn_getCharacter(char* input,char message[],char eMessage[],char lowChar,char highChar)
{
    char letra;
    int retorno=0;
    printf("%s",message);
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

int utn_getString(char* input,char message[],char eMessage[],int lowLimit,int highLimit)
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

int utn_valCharacter(char string[])
{
    int retorno=1;
    for(int i=0;string[i]!= '\0';i++){
        if( (string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z'  ) ){

            retorno=1;
            break;

        }
        else{
            retorno=0;
        }
    }
    return retorno;

}

int utn_valNumber(char string[])
{
    int retorno=1;
    for(int i=0;string[i]!= '\0';i++){
        if( (string[i]<'0' || string[i]>'9') ){

            retorno=1;
            break;

        }
        else{
            retorno=0;
        }
    }
    return retorno;
}
