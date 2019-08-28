#include <stdio.h>
#include <stdlib.h>

int funcionSuma(int,int);
int funcionResta(int,int);
int funcionMultiplicar(int,int);
float funcionDividir(int,int);
int main()
{
    //uso del switch
    int numeroA=0;
    int numeroB=0;
    int opcion;
    int resultado;
    int flagNumeroA=0;
    int flagNumeroB=0;
    float resulDivision;
    char seguir='s';

    do{
        printf("1.Ingrese el primer operando A=%d\n2.Ingrese el segundo operando B=%d\n3.Suma\n4.Resta\n5.Multiplicacion\n6.Division\n7.Salir\n",numeroA,numeroB);
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

                resultado=funcionSuma(numeroA,numeroB);
                printf("Suma es:%d\n",resultado);


            }
            else{
                printf("Ingrese ambos operandos.\n");
                system("pause");
                system("cls");
            }

            break;
        case 4:
            if(flagNumeroA==1 && flagNumeroB==1){

               resultado=funcionResta(numeroA,numeroB);
               printf("Resta es:%d\n",resultado);

            }
            else{
                printf("Ingrese ambos operandos.\n");
            }

            break;
        case 5:
            if(flagNumeroA==1 && flagNumeroB==1){

                resultado=funcionMultiplicar(numeroA,numeroB);
                printf("Multiplicacion es:%d\n",resultado);

            }

             else{
                printf("Ingrese ambos operandos.\n");
            }
            break;
        case 6:
            if(flagNumeroB==1 && flagNumeroA==1){
                resulDivision=funcionDividir(numeroA,numeroB);
                if(resulDivision!=0){
                    printf("Division:%.2f\n",resulDivision);
                }
                else{
                    printf("No se puede dividir por cero.\n");
                }

            }
            else{
                printf("Ingrese ambos operandos.\n");
            }


            break;
        case 7:
            seguir ='a';
            break;
        default:
            printf("Error.Ingrese una de las opciones.\n");
            break;

        }
        system("pause");
        system("cls");

    }while(seguir == 's');

    return 0;
}
int funcionSuma(int num1,int num2)
{
    int resultado;
    return resultado=num1+num2;

}
int funcionResta(int num1,int num2)
{
     int resultado;
     return resultado=num1-num2;

}
int funcionMultiplicar(int num1,int num2)
{
     int resultado;
     return resultado=num1*num2;

}
float funcionDividir(int num1,int num2)
{
     float resultado;
     float retorno;
     if(num2!=0){
         resultado=(float)num1/num2;
         retorno=resultado;
     }
     else{
        retorno=0;
     }
     return retorno;




}
