#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[]={4,2,7,1,9};
    for(int i=0;i<5;i++)
    {
        printf("%d\n",*(numeros + i));//para mostrar un array de elementos de tipo entero,
                        //se usa la aritmetica de punteros
                        //numeros al ser un array comienza desde la direccion del primer elemento
                        // +1 es el desplazamiento en bytes en el array, como es un for, el desplazamiento es en i.
                        // el operador de indireccion (*) va a mostrar el contenido por cada desplazamiento.

    }
    printf("\n\n");
    //para modificar un elemento del array tambien se usa aritmetica de punteros.
    //si quiero modificar el valor del elemento que contiene el 7.
    *(numeros+2)=14; //me desplazo hasta la posicion usando aritmetica de punteros,
                     //accedo al valor con el operador de indireccion (*) y le asigno el 14.
    for(int i=0;i<5;i++)
    {
        printf("%d\n",*(numeros + i));
    }
    return 0;
}
