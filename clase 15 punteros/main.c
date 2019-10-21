#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);
int main()
{

    int a=10;
    int b=6;
    printf("dentro del main\nA:%d   B:%d\n",a,b);
    swap(&a,&b);//la funcion recibe como paramentros dos enteros de tipo puntero,
                //le paso las direcciones de memoria de a y b por referencia usando &
               // esto me permite hacer el swap de las variables dentro de main.
    printf("luego del swap\nA:%d   B:%d\n",a,b);
    return 0;
}
void swap(int* a, int* b)
//le pasamos punteros de tipo entero, direcciones de memoria.
{
    int aux;// no es necesario que el aux sea de tipo puntero, porque se intercambian el contenido apuntado
            // por la direccion de memoria.
    aux=*a;//aux guarda el contenido al que apunta el puntero a.
    *a=*b; // el puntero b guarda su contenido en el puntero a.
    *b=aux;//aux guarda en el puntero b lo que contenia el puntero a.

    printf("dentro de swap\nA:%d  B:%d\n",*a,*b);//uso el operador de indireccion (*) para mostrar su contenido
                                        //sino solamente mostraria la direccion de memoria que apuntan esos punteros.
}
