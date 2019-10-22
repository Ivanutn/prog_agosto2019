#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#define MAX_CARACTERES 41
#define QTY 8

int valNumber(char* string,int cant)
{
    int retorno=1;
    if(string!=NULL)
    {
        for(int i=0; string[i]!='\0' && i<cant; i++)
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
    }

    return retorno;
}
int valFloat(char* string,int cant)
{
    int retorno=1;
    int contadorPuntos=0;
    if(string!=NULL && cant >0)
    {
        for(int i=0; string[i]!='\0' && i<cant; i++)
        {
            if( (string[i]<'0' || string[i]>'9') && (string[i]<'.' || string[i]>'.' ))
            {

                retorno=1;
                break;
            }
            else if(string[i]=='.')
            {
                contadorPuntos++;
            }
            if(contadorPuntos>1)
            {
                retorno=1;
                break;
            }
            else
            {

                retorno=0;

            }
        }
    }

    return retorno;

}
int valCharacter(char* string,int cant)
{
    int retorno=1;//

    if(string!=NULL && cant >0 )
    {

        for(int i=0; i<cant && string[i]!='\0'; i++)
        {
            if((string[i]<'a' || string[i]>'z') && (string[i]<' '|| string[i]>' ') && (string[i]<'A' || string[i]>'Z') )
            {
                retorno=1;
                break;
            }
            else
            {
                retorno=0;
            }
        }
    }

    return retorno;
}

int getInt(int* input,char message[],char eMessage[],int lowLimit,int highLimit,int reintentos)
{
   int numero;
    int retorno=0;
    int contReintentos=0;
    char auxNum[QTY];

    do
    {
        printf("%s",message);
        fflush(stdin);
        fgets(auxNum,QTY,stdin);
        for(int i=0; i<strlen(auxNum); i++)
        {
            if(auxNum[i]=='\n')
            {
                auxNum[i]='\0';
            }
        }

        if(valNumber(auxNum,QTY)==1)
        {
            contReintentos++;
            printf("%s",eMessage);
        }
        else
        {
             numero=atoi(auxNum);
             if(numero<lowLimit || numero>highLimit)
             {
                printf("%s",eMessage);
                contReintentos++;
             }
             else
             {
                 *input=numero;//valor por referencia, modifico el original.
                 retorno=0;
                 break;
             }


        }
        if(contReintentos==reintentos)
        {
            printf("Alcanzado el maximo de reintentos.\nAdios ! \n");
            system("pause");
            system("cls");
            retorno=1;
        }

    }while(contReintentos!=reintentos);

    return retorno;

}

int getFloat(float* input,char message[],char eMessage[],float lowLimit,float highLimit,int reintentos)
{
   float numero;
    int retorno=0;
    int intentos=0;
    char auxFlotante[QTY];


    do{

        printf("%s",message);
        fflush(stdin);
        fgets(auxFlotante,QTY,stdin);
        for(int i=0; i<strlen(auxFlotante); i++)
        {
            if(auxFlotante[i]=='\n')
            {
                auxFlotante[i]='\0';
            }
        }

        if(valFloat(auxFlotante,QTY)==1)
        {
            printf("%s\n",eMessage);
            intentos++;
        }
        else
        {
            numero=atof(auxFlotante);
            if(numero<lowLimit || numero>highLimit)
            {
                printf("%s\n",eMessage);
                intentos++;
            }
            else
            {
                *input=numero;
                break;
            }


        }




        if(intentos==reintentos)
        {
            printf("superado cantidad de intentos.\nAdios\n");
            retorno=1;
            break;
        }
    }while(intentos!=reintentos);


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

int getString(char* input,char message[],char eMessage[],int lowLimit,int highLimit,int reintentos)
{
    char nombre[MAX_CARACTERES];
    int retorno=0;
    int contReintentos=0;
    do
    {
        printf("%s",message);
        fflush(stdin);
        fgets(nombre,MAX_CARACTERES,stdin);
        for(int i=0;i<strlen(nombre);i++)
        {
            if(nombre[i]=='\n')
            {
                nombre[i]='\0';
            }
        }
        if(valCharacter(nombre,MAX_CARACTERES)==1)
        {
            contReintentos++;
            printf("%s",eMessage);
        }
        else
        {
            if(strlen(nombre)<lowLimit || strlen(nombre)>highLimit)
            {
                printf("%s",eMessage);
                contReintentos++;
            }
            else
            {
                strcpy(input,nombre);
                retorno=0;
                break;
            }
        }

        if(contReintentos==reintentos)
        {
            printf("Alcanzado el maximo de reintentos.\nAdios ! \n");
            system("pause");
            system("cls");
            retorno=1;
        }

    }while(contReintentos!=reintentos);




    return retorno;

}

int getSex(char* input,char message[],char eMessage[],int intentos)
{
    char letra;
    char auxLetra[256];
    int largoCadena;
    int rValidar;
    int retorno=0;
    int intentosAux=0;

    do
    {
        printf("%s",message);
        fflush(stdin);
        gets(auxLetra);
        auxLetra[0]=tolower(auxLetra[0]);
        largoCadena=strlen(auxLetra);
        rValidar=valCharacter(auxLetra,256);
        if(largoCadena>2 || rValidar==1)
        {
            printf("%s",eMessage);
            intentosAux++;
        }

        else
        {
                if(auxLetra[0]=='m' && auxLetra[1]=='\0')
                {
                    letra=auxLetra[0];
                    *input=letra;
                    break;

                }
                else if(auxLetra[0]=='f'&& auxLetra[1]=='\0')
                {
                    letra=auxLetra[0];
                    *input=letra;
                    break;
                }
                else
                {
                    printf("%s",eMessage);
                    intentosAux++;
                    system("pause");
                    system("cls");
                }


        }
          if(intentosAux==intentos)
        {
            printf("Superado la cantidad de intentos.\n");
            system("pause");
            system("cls");
            retorno=1;
            break;
        }
    }while(intentosAux!=intentos);

    return retorno;
}

int botonSeguir(char string[],char* message,char* eMessage,int cantidad)
{
    int retorno=1;
    char auxiliar[256];
    int rValidar;
    printf("%s",message);
    gets(auxiliar);
    rValidar=valCharacter(auxiliar,256);
    if(rValidar==0 && strlen(auxiliar)<2)
    {
        strcpy(string,auxiliar);
        strcpy(string,strlwr(string));
        if(string[0]=='s')
        {
            retorno=0;
        }
    }
    else
    {
        printf("%s",eMessage);
        retorno=1;
        system("pause");
        system("cls");

    }


    return retorno;
}
