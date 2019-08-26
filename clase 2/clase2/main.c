#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char seguir='s';
    char letra;
    char letraMaxima;
    char letraMinima;

    int numero;
    int contPares=0;
    int contImpar=0;
    int contCeros=0;
    int numMaximo=0;
    int numMinimo=0;
    int flag=0;
    int sumaNegativos=0;
    int acumuladorPositivos=0;
    int contPositivos=0;

    int contadorIntentos=0;
    float promedioPositivos;

    do
    {
       printf("Ingrese una letra:");
       fflush(stdin);
       scanf("%c",&letra);

       printf("Ingrese un numero entre -100 y 100:");
       scanf("%d",&numero);

       while(numero< -100 || numero> 100)
       {
           printf("Error.Ingrese un numero -100 y 100:");
           scanf("%d",&numero);
           contadorIntentos++;
           if(contadorIntentos==2){
            printf("Demasiados intentos. Salir");
            exit(1);
           }
       }
       printf("Desea seguir ingresando numeros ? S/N:");
       fflush(stdin);
       scanf("%c",&seguir);
       seguir=tolower(seguir);
       system("cls");

       if(numero%2==0){
            contPares++;
       }
       else{
            contImpar++;
       }
       if(numero==0){
            contCeros++;
       }
       if(numero>=0){
            acumuladorPositivos=acumuladorPositivos+numero;
            contPositivos++;
       }
       else{
            sumaNegativos=sumaNegativos+numero;
       }
       if(numero>numMaximo || flag==0){
            numMaximo=numero;
            letraMaxima=letra;
       }
       if(numero<numMinimo || flag==0){
            numMinimo=numero;
            letraMinima=letra;
            flag=1;
       }



    }while(seguir=='s');



    printf("Cantidad de pares:%d\n",contPares);
    printf("Cantidad de impares:%d\n",contImpar);
    printf("Cantidad de ceros:%d\n",contCeros);
    printf("Numero maximo:%d\nLetra maximo:%c\n",numMaximo,letraMaxima);
    printf("Numero minimo:%d\nLetra minimo:%c\n",numMinimo,letraMinima);
    printf("La suma de los negativos es:%d\n",sumaNegativos);
    if(contPositivos>0){
       promedioPositivos=(float)acumuladorPositivos/contPositivos;
       printf("El promedio de los positivos es:%.2f\n",promedioPositivos);
    }


    return 0;

}
