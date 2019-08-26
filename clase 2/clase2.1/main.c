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
    int suma;
    int resta;
    int multiplicacion;
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
                suma=resultado;
                printf("Suma es:%d\n",suma);


            }
            else{
                printf("Ingrese ambos operandos.\n");
                system("pause");
                system("cls");
            }

            break;
        case 4:
            if(flagNumeroA==1 && flagNumeroB==1){
               resultado=numeroA-numeroB;
               resta=resultado;
               printf("Resta es:%d\n",resta);

            }
            else{
                printf("Ingrese ambos operandos.\n");
            }

            break;
        case 5:
            if(flagNumeroA==1 && flagNumeroB==1){
                resultado=numeroA*numeroB;
                multiplicacion=resultado;
                printf("Multiplicacion es:%d\n",multiplicacion);

            }

             else{
                printf("Ingrese ambos operandos.\n");
            }
            break;
        case 6:
            if(numeroB!=0 && flagNumeroB==1 && flagNumeroA==1){
                division=(float)numeroA/numeroB;
                printf("Division:%.2f\n",division);
            }
            else{
                printf("No se puede dividir por cero.\n");
            }

            break;
        case 7:
            seguir ='a';
            break;
        default:
            break;

        }
        system("pause");
        system("cls");

    }while(seguir == 's');

    return 0;
}
