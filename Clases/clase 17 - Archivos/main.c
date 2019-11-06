#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE* f=fopen("archivos.txt","r"); //si el archivo no existe lo crea. fopen si falla devuelve null
    //El modo lectura si no existe devuelve null
    //El modo append si no existe lo crea.
    //antes de abrir un archivo en modo escritura es una buena practica abrirlo en modo lectura para comprobar si tiene datos.
   char mensaje[30]="esto es un mensaje";
   char cadena[30];
    if(f==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        //printf("archivo creado con exito.\n");
        //fwrite(mensaje,sizeof(char),strlen(mensaje),f);
        /*//fprintf recibe el fichero que seria el puntero a file
        fprintf(f,"Hola mundo\n");
        //si no se cierra el archivo, este puede corromporse o inutilizable.
        //una buena practica es cerrar el archivo luego de haber trabajado en el.*/

        while(!feof(f))
        {
             //fgets(cadena,29,f);
             //puts(cadena);
             //printf("%s",cadena);

             fread(cadena,sizeof(char),29,f);
             printf("%s",cadena);
        }

        fclose(f);
    }

    return 0;
}
