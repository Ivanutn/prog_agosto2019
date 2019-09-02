#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcion(int,int);
void menu(void);
int main()
{

   menu();
    return 0;
}

int opcion(int min,int max)
{
    int numero;
    printf("1.numero\n2.suma\n3.salir.\n");
    scanf("%d",&numero);
    while(numero<min || numero>max){
        printf("Error, ingrese una de las opciones.\n1.numero\n2.suma\n3.salir.\n");
        scanf("%d",&numero);
    }

    return numero;
}
void menu(void)
{
    char seguir='s';
    do{


        switch (opcion(1,3))
        {
        case 1:
            printf("numero ok\n");
            break;
        case 2:
            printf("suma ok\n");
            break;
        case 3:
            printf("salir ok\n");
            seguir='n';
            break;

        default:
            break;
        }

    }while(seguir=='s');

}
