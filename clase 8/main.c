#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BibliotecaUtn/utn.h"
#include "../BibliotecaUtn/utn_array.h"

int main()
{
    char num[]="168";
    /** fgets(cant,sizeof,stdin) cant de elementos del array, si se trabaja con arrays, sizeof(del tipo de dato),origne o ingreso de la informacion, si no se trabaja con
    archivos se usa el stdin (standar input)
    fgets coloca un '\0' al final de la cadena.*/

    if(valNumber(num)==0)
    {
        printf("se ingreso un numero de forma correcta.\n");
    }
    else
    {
        printf("No se ingreso un numero.\n");
    }

    return 0;
}

