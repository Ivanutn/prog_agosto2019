#include <stdio.h>
#include <stdlib.h>

int main()
{
    //uso del switch
    int numeroA=0;
    int numeroB=0;
    int opcion;
    int resultado;
    int flagNumeroA=0;
    int flagNumeroB=0;
    float division;
    char seguir='s';

    do{
        printf("1.Ingrese el primer operando:%d\n2.Ingrese el segundo operando:%d\n3.Suma\n4.Resta\n5.Multiplicacion\n6.Division\n7.Salir\n",numeroA,numeroB);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese el primer operando:");
            scanf("%d",&numeroA);
            flagNumeroA=1;
            system("cls");
            break;
        case 2:
            printf("Ingrese el segundo operando:");
            scanf("%d",&numeroB);
            flagNumeroB=1;
            system("cls");
            break;
        case 3:
            if(flagNumeroA==1 && flagNumeroB==1){
                resultado=numeroA+numeroB;
                system("cls");
            }
            else{
                printf("Ingrese ambos operandos.");
            }

            break;
        case 4:
            if(flagNumeroA==1 && flagNumeroB==1){
               resultado=numeroA-numeroB;
               system("cls");
            }
            else{
                printf("Ingrese ambos operandos.");
            }

            break;
        case 5:
            if(flagNumeroA==1 && flagNumeroB==1){
                resultado=numeroA*numeroB;
                system("cls");
            }

             else{
                printf("Ingrese ambos operandos.");
            }
            break;
        case 6:
            if(numeroB!=0 && flagNumeroB==1){
                division=numeroA/numeroB;
            }
            else{
                printf("No se puede dividir por cero.");
            }

            break;
        case 7:
            seguir ='a';
            break;
        default:
            break;
        }

    }while(seguir == 's');

    return 0;
}
