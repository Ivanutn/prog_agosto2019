#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total=5;
    int vectorNumero[total];
    int vector2[]={2,5,4,87,9};
    for(int i=0;i<total;i++){
        printf("Ingrese un numero:");
        scanf("%d",&vectorNumero[i]);
    }

    printf("numeros ingresados\n");

    for(int i=0;i<total;i++){
         printf("%3d\n",vectorNumero[i]);
    }
    printf("\nNumeros harcodeados.\n");
    for(int i=0;i<total;i++){
        printf("%3d\n",vector2[i]);
    }

    return 0;
}
