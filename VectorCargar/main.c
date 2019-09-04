#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
//Solicitar 5 numeros al usuario y guardarlos en un vector
//Carga (llenar con valores un vector) secuencial

    int vec[CANT];  //declaracion de un vector
    int i;
    int num;
    int  valor;

    for (i=0; i<CANT; i++)
    {
        printf("\nIngrese el numero de la posicion: %d ", i);
        scanf("%d", &num);
        vec[i]= num;
    }

    //Mostrar los numero ingresados de forma secuencial

    for (i=0; i<CANT; i++)
    {
        printf("\nEl numero de la posicion: %d es %d ", i, vec[i]);
    }

    //Modificar el valor de cualquier número cargado
    //indicando el índice del mismo

    int indice;

    printf("\n Ingrese el indice del numero a modificar");
    scanf("%d", &indice);
    printf("\n Ingrese el nuevo valor para el indice %d ", indice);
    scanf("%d", &valor);
    vec[indice]=valor;

    //Mostar la modificacion
    for (i=0; i<CANT; i++)
    {
         printf("\nEl numero de la posicion: %d es %d ", i, vec[i]);
    }


    //Buscar un valor dentro del Vector

    int flag = 0;

    printf("\n\nIndique el valor que desea buscar ");
    scanf("%d", &valor);

    for (i=0; i<CANT; i++)
    {
        if(vec[i]==valor)
        {
            printf("\nLo encontre!, esta en la posicion: %d \n", i);
            flag = 1;
            break;
        }
    }

    if (flag==0){
       printf("\n:( No lo ubico \n");

    }


    //Buscar el menor y el mayor
    int min, max;
    for (i=0; i<CANT; i++)
    {
        if(i==0){
            min=vec[i];
            max=vec[i];
        }
        else
        {
            if (vec[i]<min){
                min=vec[i];
            }
            if (vec[i]>max){
                max=vec[i];
            }
        }
    }
    printf("\n\n El numero MAYOR es: %d ", max);
    printf("\n\n El numero MENOR es: %d \n\n", min);

    return 0;
}
