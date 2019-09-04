#include <stdio.h>
#include <stdlib.h>
#define TOTAL 5
int main()
{

    int vectorNumero[TOTAL];
    int vector2[]={2,5,4,87,9};
    for(int i=0;i<TOTAL;i++){
        printf("Ingrese un numero:");
        scanf("%d",&vectorNumero[i]);
    }

    printf("numeros ingresados\n");

    for(int i=0;i<TOTAL;i++){
         printf("%3d\n",vectorNumero[i]);
    }
    printf("\nNumeros harcodeados.\n");
    for(int i=0;i<TOTAL;i++){
        printf("%3d\n",vector2[i]);
    }

    return 0;
}
