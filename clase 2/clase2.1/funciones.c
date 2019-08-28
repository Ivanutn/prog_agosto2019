#include <stdio.h>
#include <stdlib.h>
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

int funcionFactorial(int num1)
{
    int resultado;
    int factorial=1;
    int i;

    if(num1==0){
        num1=1;
        resultado=num1;
    }
    else{
        for(i=1;i<=num1;i++)
        {
           factorial=factorial*i;
        }
        resultado=factorial;
    }

    return resultado;
}

