#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"

float sumar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX+numeroY;
    return resultado;
}
float restar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX-numeroY;
    return resultado;
}
float dividir(float numeroX, float numeroY)
{
    float resultado;
    if(numeroY == 0)
    {
        printf("\n\nNo se puede dividir por '0'\n\n");
    }
    else
    {
        resultado = numeroX/numeroY;
    }
    return resultado;
}
float multiplicar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX*numeroY;
    return resultado;
}
unsigned long factorial(int numero)
{
    int fact=1;
    int i;
    if(numero == 0)
    {
        printf("\n\nEl operando no puede ser '0'\n\n");
    }
    else
    {
        for(i=1; i<=numero; i++)
            fact=fact*i;
    }
    return fact;
}
int getInt(char* mensaje)
{
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}

float getFloat(char* mensaje)
{
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;

}

char getChar(char* mensaje)
{
    fflush(stdin);
    char aux;
    printf("%s",mensaje);
    scanf("%c",&aux);
    aux = tolower(aux);
    return aux;
}

int validarNumeroConSignos(char* pBuffer)
{
    int i=0;
    int j;
    int retornoValidacion=0;
    int acumuladorSignos=0;
    int acumuladorSignosNegativos=0;

    j=strlen(pBuffer);

    while (i<j && retornoValidacion==0)
    {
        if (isdigit(pBuffer[i])!=0||pBuffer[i]=='.'||pBuffer[i]==','||pBuffer[i]=='-')
        {
            if(pBuffer[i]=='.'||pBuffer[i]==',')
            {
                acumuladorSignos++;
            }
            if (pBuffer[i]=='-')
            {
                acumuladorSignosNegativos++;
            }
            if(acumuladorSignos>1||acumuladorSignosNegativos>1)
            {
                retornoValidacion=1;
                break;
            }
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}

float getFloatPositivo(const char* MSJ)
{

    float valorFlotante;
    char buffer[30];

    do
    {
        printf("INGRESE %s : ", MSJ);
        fflush(stdin);
        gets(buffer);

        while(validarNumeroConSignos(buffer)==1)
        {
            printf("[ERROR] REINGRESE NUMERO: ");
            fflush(stdin);
            gets(buffer);
            system("cls");
        }

        valorFlotante=atof(buffer);

        if(valorFlotante<0)
        {
            puts("[ERROR] VALOR SOLO POSITIVO\n");
            system("pause");
            system("cls");
        }

    }
    while(valorFlotante<0);

    return valorFlotante;
}

int esLetra(char* letras)
{
    int retorno;
    retorno = esCadena(letras);
    return retorno;
}
int esCadena(char* cadena)
{
    int i=0;
    int j;
    int realizoValidacion=1;

    j=strlen(cadena);

    while(i<j && realizoValidacion == 1)
    {
        if(isalpha(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            realizoValidacion = 0;
            break;
        }
    }
    return realizoValidacion;
}

int getNombre(char* dato, char* msj)
{
    char buffer[1000];
    int retorno = 0;

    printf("%s", msj);
    fflush(stdin);
    gets(buffer);
    if(esCadena(buffer))
    {
        strcpy(dato, buffer);
        retorno = 1;
    }
    else
    {
        printf("ERROR. SOLO LETRAS\n");
        system("pause");
        system("cls");
    }
    return retorno;
}

/********************** PARA ABM **********************/

int esDato(char* dato, char* texto)
{
    int esDatoExito = 0;
    do
    {
        printf("INGRESE %s :", texto);
        fflush(stdin);
        gets(dato);
        if(esCadena(dato)==0)
        {
            printf("RE ");
        }
        esDatoExito = 1;
    }
    while(esCadena(dato)==0);
    return esDatoExito;
}

int esDia(char* texto)
{
    int dia;
    int salir = 0;
    do
    {
        printf("INGRESE DIA: ");
        fflush(stdin);
        scanf("%d",&dia);
        if(dia<1 || dia>31)
        {
            printf("RE ");
        }
        else
        {
            salir=1;
        }
    }
    while(salir == 0);
    return dia;
}

int esMes(char* texto)
{
    int mes;
    int salir = 0;
    do
    {
        printf("INGRESE MES: ");
        fflush(stdin);
        scanf("%d",&mes);
        if(mes<1 || mes>12)
        {
            printf("RE ");
        }
        else
        {
            salir=1;
        }
    }
    while(salir == 0);
    return mes;
}

int esAnio(char* texto)
{
    int anio;
    int salir = 0;
    do
    {
        printf("INGRESE ANIO: ");
        fflush(stdin);
        scanf("%d",&anio);
        if(anio<1900 || anio>2050)
        {
            printf("RE ");
        }
        else
        {
            salir=1;
        }
    }
    while(salir == 0);
    return anio;
}

char esDatoSexo(char* texto)
{
    int salir=0;
    char dato;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        scanf("%c",&dato);
        dato=tolower(dato);
        if(dato == 'f'|| dato =='m' )
        {
            salir=1;
        }
        else
        {
            printf("RE ");
        }
    }
    while(salir == 0);
    return dato;
}
int esTelefono(char* dato, char* texto)
{
    int esDatoExito = 0;
    int salir=0;
    int cantidadChar=0;
    int cantidadGuion = 0;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        gets(dato);
        for(int i = 0; i<(cantidadChar=strlen(dato)); i++)
        {
            if(dato[i]=='-')
            {
                cantidadGuion++;
            }
        }
        if(cantidadGuion==0||cantidadGuion==1)
        {
            salir =1;
            esDatoExito=1;
        }
        else
        {
            printf("RE ");
        }
    }
    while(salir == 0);
    return esDatoExito;
}

int esDatoEmail(char* dato, char* texto)
{
    int esDatoExito = 0;
    int salir=0;
    int cantidadChar=0;
    int cantidadArrobas = 0;
    int cantidadPuntos =0;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        gets(dato);
        for(int i = 0; i<(cantidadChar=strlen(dato)); i++)
        {
            if(dato[i]=='@')
            {
                cantidadArrobas++;
            }
            else if(dato[i]=='.')
            {
                cantidadPuntos++;
            }
        }
        if(cantidadArrobas==1&&cantidadPuntos==1)
        {
            esDatoExito=1;
            salir=1;
        }
        else
        {
            printf("RE ");
            cantidadArrobas = 0;
            cantidadPuntos = 0;
        }
    }
    while(salir == 0);
    return esDatoExito;
}

int esNumero(char* cadena)
{
    int i=0;
    int j;
    int realizoValidacion=0;

    j=strlen(cadena);

    while(i<j && realizoValidacion == 0)
    {
        if(isdigit(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            realizoValidacion=1;
        }
    }
    return realizoValidacion;
}

int esNumerico(char* numeros, char* texto)
{
    int esNumericoExito = 0;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        gets(numeros);
        if(esNumero(numeros)==1)
        {
            printf("RE ");
        }
        esNumericoExito = 1;
    }
    while(esNumero(numeros)==1);
    return esNumericoExito;
}


int burbujeo(char cadena[], int largoCadena, char signo)
{
    int retorno=0;
    char aux;
    if(signo=='<')
    {
        for(int i = 0; i< largoCadena-1; i++)
        {
            for(int j = i; j< largoCadena; j++)
            {
                if(cadena[i]>cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                    fflush(stdin);
                }
            }
        }
        retorno = 1;
    }
    else if(signo=='>')
    {
        for(int i = 0; i< largoCadena-1; i++)
        {
            for(int j = i; j< largoCadena; j++)
            {
                if(cadena[i]<cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                    fflush(stdin);
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}
int menu(LinkedList* lista)
{
    int opcion = 0;
    system("cls");
    printf("BIENVENIDO AL TP NUMERO 3.\t\t\t");
    printf("CANTIDAD EN LISTA: %d\n\n", ll_len(lista));
    printf("1. CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO data.csv (MODO TEXTO).\n");
    printf("2. CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO data.bin (MODO BINARIO).\n");
    printf("3. ALTA DE EMPLEADO.\n");
    printf("4. MODIFICAR DATOS DE EMPLEADO.\n");
    printf("5. BAJA DE EMPLEADO.\n");
    printf("6. LISTAR EMPLEADO.\n");
    printf("7. ORDENAR EMPLEADOS.\n");
    printf("8. GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCGIVO data.csv (MODO TEXTO).\n");
    printf("9. GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCGIVO data.bin (MODO BINARIO).\n");
    printf("10. FILTRAR POR CRITEIOR Y GUARDA EN ARCHIVO.\n");
    printf("11. SALIR.\n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opcion);
    return opcion;
}

