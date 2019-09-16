#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BibliotecaUtn/utn.h"
#include "../BibliotecaUtn/utn_array.h"

int main()
{

    /** fgets(cant,sizeof,stdin) cant de elementos del array, si se trabaja con arrays, sizeof(del tipo de dato),origne o ingreso de la informacion, si no se trabaja con
    archivos se usa el stdin (standar input)
    fgets coloca un '\n' al final de la cadena. se debe pisar con un '\0' */

    char nombre[]="jose Alberto f 9 ";
    int len;
    int resp;
    len=strlen(nombre);

    resp=valCharacter(nombre,len);
    if(resp==0)
    {
        printf("todo bien.\n");
    }
    else
    {
        printf("todo mal.\n");
    }

    return 0;
}

