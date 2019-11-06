#define MAX_SERVICIOS_DESCRIPCION 25
typedef struct
{
    int id;
    char descripcion[MAX_SERVICIOS_DESCRIPCION];
    int precio;
    int estado;
}eServicios;
