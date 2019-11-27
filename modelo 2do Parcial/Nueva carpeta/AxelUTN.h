/** \brief                  SUMA DOS OPERANDOS.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            RESULTADO DE LA SUMA.
 */
float sumar(float numeroX, float numeroY);

/** \brief                  RESTA DOS OPERANDOS.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            RESULTADO DE LA RESTA.
 */
float restar(float numeroX, float numeroY);

/** \brief                  DIVIDE ENTRE DOS OPERANDOS, VERIFICA SI SE INGRESA 0.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO
 * \return float            DEVUELVE RESULTADO DE DIVISION.
 */
float dividir(float numeroX, float numeroY);

/** \brief                  MULTIPLICA DOS OPERANDOS. VERIFICA QUE EL OPERANDOS B NO SEAN 0.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            DEVUELVE RESULTADO DE MULTIPLICACION.
 */
float multiplicar(float numeroX, float numeroY);

/** \brief                  SACA FACTORIAL DEL NUMERO A QUE PEDIMOS.
 * \param numeroX int       NUMERO QUE NOS BRINDA EL USUARIO. VERIFICA SI EL NUMERO ES 0.
 * \return unsigned long    RESULTADO FACTORIAL NUMERO X. RETORNA EL RESULTADO FACTORIAL DEL NUMERO QUE NOS MANDO EL USUARIO.
 */
unsigned long factorial(int numero);

int getInt(char* mensaje);

/** \brief                  PIDE UN FLOAT Y LO DEVUELVE
 * \param numero float      FLOAT A PEDIR.
 * \return float            DEVUELVE FLOAT.
 */
float getFloat(char* mensaje);

/** \brief                  PIDE UN CHAR Y LO DEVUELVE
 * \param texto char        CHAR A PEDIR.
 * \return char             DEVUELVE CHAR.
 */
char getChar(char* mensaje);



/** \brief                  FUNCION QUE VALIDA ENTRADA DE NUMEROS.
 *
 * \param pBuffer char*     PEDIMOS UNA CADENA DE CHAR.
 * \return int              RETORNA VALIDACION.
 *
 */
int validarNumeroConSignos(char* pBuffer);

/** \brief                  PEDIMOS UN FLOAT Y VALIDAMOS QUE SEA POSITIVO.
 *
 * \param MSJ const char*   PEDIMOS UN MENSAJE A MOSTRAR.
 * \return float            RETORNA VALIDACION.
 *
 */
float getFloatPositivo(const char* MSJ);

/** \brief                  PEDIMOS UNA LETRA Y VERIFICAMOS QUE SOLO LEA UNA LETRA.
 *
 * \param letra char*       VARIABLE QUE CONTIENE EL CHAR.
 * \return  int             DEVUELVE ESTA DE LA OPERACION (1 SI CONTIENE LETRAS, 0 SI NO CONTIENE).
 *
 */
int esLetra(char* letras);

/** \brief                  VALIDA QUE SOLO SEAN LETRAS LAS INGRESADAS.
 * \param cadena* char      RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \return int              DEVUELVE SI SE PUDO REALIZAR ACCION.
 */
int esCadena(char* cadena);


/** \brief                  PIDE HASTA QUE EL DATO SEA CORRECTO.
 *
 * \param dato char*        RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \param texto char*       RECIBE UN PUNTERO A CADENA CON TEXTO A MOSTRAR POR EJEMPLO (NOMBRE, APELLIDO, DIRECCION, ETC.
 * \return int              DEVUELVE VALIDANDO LA ENTRADA DE ESE TIPO DE DATO QUE QUEREMOS 0 SI SON SOLO DATOS 1 SI TIENE ERROR.
 *
 */
int esDato(char* dato, char* texto);

int getNombre(char* dato, char* msj);

char esDatoSexo(char* texto);

int esTelefono(char* dato, char* texto);

int esDatoEmail(char* dato, char* texto);

int esDia(char* texto);

int esMes(char* texto);

int esAnio(char* texto);

int esNumero(char* numeros);

int esNumerico(char* numeros, char* texto);

/** \brief                  ORDENA UN ARRAY
 *
 * \param cadena[] char     RECIBE UNA CADENA SEA CUAL SEA.
 * \param largoCadena int   RECIBE UN LARGO DE LA CADENA.
 * \param signo char        RECIBE UN SIGNO PARA SABER DE QUE MANERA QUEREMOS ORDENARLA, EJ.: <  menor, >  mayor.
 * \return int              DEVUELVE ENTERO PARA SABER SI SE PUDO REALIZAR ACCION.
 *
 */
int burbujeo(char cadena[],int largoCadena,char signo);
int menu(LinkedList* lista);
