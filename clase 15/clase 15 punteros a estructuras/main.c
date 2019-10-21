#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int edad;
    char nombre[20];
    float altura;
    eFecha fechaNac;
}ePersona;
int main()
{
    //punteros a estructuras
    ePersona per1;
    ePersona* p;
    p=&per1;
    strcpy(per1.nombre,"juan");
    printf("%s\n",per1.nombre);
    printf("%s\n",p->nombre);
    printf("%s\n",(*p).nombre); //(*p) se convierte en la estructura, sin los parentesis se convierte en el valor apuntado.

    p->fechaNac.anio=1990;//el operador flecha se usa cuando lo que esta a la izq es un puntero. luego se usa el operador punto (.)
    p->fechaNac.mes=12;
    p->fechaNac.dia=1;
    printf("Ingrese altura:");
    scanf("%f",&p->altura);//requiere la direccion de memoria
    printf("altura:%.2f",p->altura);
    return 0;
}
