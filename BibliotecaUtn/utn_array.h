#define MAX_CARACTERES 41
typedef struct
{
    int dia;
    int mes;
    int anio;

}eFechaIngreso;

typedef struct
{

    char nombre[MAX_CARACTERES];
    char apellido[MAX_CARACTERES];
    int legajo;
    eFechaIngreso fecha_de_ingreso;
    char sexo;
    int edad;
    int nota1;
    int nota2;
    float promedio;
    int estado;

}eAlumno;
int sumaVector(int* array,int cantidad);
float promedioVector(eAlumno array[],int cantidad);
/** \brief La funcion inicializa el campo estado del array en 0 para cada elemento, eso indica que
 *         el array de vectores en ese indice se encuentra vacio y que es posible cargar datos
 *
 * \param  eAlumno pArray[] vector de estructuras a trabajar
 * \param int cantidad total de elementos que posee el vector de estructuras
 * \return int retorna un 0 (cero) si cumplio su tarea, devuelve -1 en caso de error.
 *
 */
int inicializarArray(eAlumno pArray[],int cantidad);
/** \brief La funcion recorre el array de estructuras buscando en el campo estado un cero, que indica el espacio libre.
 *
 * \param  eAlumno pArray[] vector de estructuras a trabajar
 * \param  int cantidad total de elementos que posee el vector de estructuras
 * \return int retorna la primera posicion que encuentre en el campo estado.
 *         retorna -1, si no hay espacio libre, si la cantidad es menor a cero o si el pArray es null.
 *
 */
int buscarEspacioLibre(eAlumno pArray[],int cantidad);
/** \brief La funcion solamente muestra los datos de una estructura
 *
 * \param  eAlumno pArray
 * \return no retorna nada al ser void.
 *
 */
void mostrarUnElemento(eAlumno pArray);
int mostrarArrayDeElementos(eAlumno pArray[],int cantidad);
int cargaArray(eAlumno pArray[],int cantidad);
int vectorMaximo(int* array,int cantidad,int* max);
int vectorMinimo(int* array,int cantidad,int* min);

