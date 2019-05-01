#define LIBRE 1
#define OCUPADO 0
#define ASC 1
#define DESC 0
#define TAM_CADENA 51

typedef struct{
    int id;
    char nombre[TAM_CADENA];
    char apellido[TAM_CADENA];
    float salario;
    int sector;
    int estaLibre;
}eEmpleado;


/** \brief Funci�n para dar la baja l�gica de todos los empleados del array
 *
 * \param listaEmp[] eEmpleado array de empleados
 * \param te int Tama�o del array
 * \return int Retorna 0 si no hubo error en la operaci�n
 *
 */
int inicializarEmpleados(eEmpleado listaEmp[], int te);


/** \brief Funci�n que agrega un empleado al array de empleados
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \param id int El �ltimo id utilizado
 * \param nombre[] char El nombre del empleado
 * \param apellido[] char El apellido del empleado
 * \param salario float El salario del empleado
 * \param sector int El sector del empleado
 * \return int Retorna 1 si se lo pudo agregar o -1 si no hab�a lugar
 *
 */
int agregarEmpleado(eEmpleado listaEmp[], int te, int id, char nombre[],
                    char apellido[],float salario,int sector);


/** \brief Funci�n que busca un empleado en el array seg�n si id
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \param id int El id del empleado a buscar
 * \return int Retorna el �ndice del array en donde se encuentra el empleado
 *             o -1 si no lo encontr�
 *
 */
int buscarEmpleadoPorId(eEmpleado listaEmp[], int te, int id);


/** \brief Funci�n que realiza una baja l�gica de un empleado en el array
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \param id int El id del empleado
 * \return int Retorna 0 si se realiz� la baja l�gica o -1 si no existe el id
 *
 */
int borrarEmpleado(eEmpleado listaEmp[], int te, int id);


/** \brief Funci�n que ordena el array de empleados
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \param orden int Si es 1 ordena de forma ascendete, si es 0 en forma descendente
 * \return int Retorna 0 si se pudo ordenar, o -1 si hubo un error
 *
 */
int ordenarEmpleados(eEmpleado listaEmp[], int te, int orden);


/** \brief Funci�n que muestra el contenido del array en forma encolumnada
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \return int Retorna 0 si no hubo error.
 *
 */
int mostrarEmpleados(eEmpleado listaEmp[], int te);


/** \brief Funci�n que acumula el salario total de todos los empleados
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \return float Retorna el salario acumulado
 *
 */
float obtenerSalarioTotal(eEmpleado listaEmp[], int te);


/** \brief Funci�n que calcula el salario promedio de todos los empleados
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \return float Retorna el salario promedio
 *
 */
float obtenerSalarioPromedio(eEmpleado listaEmp[], int te);


/** \brief Funci�n que cuenta cuantos empleados tienen un salario superior al promedio
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \return int Retorna la cantidad de empleados con salario superior al promedio
 *
 */
int contarSalariosMayores(eEmpleado listaEmp[], int te);


/** \brief Procedimiento que hardcodea hasta 8 empleados en el array de empleados
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \return void
 *
 */
void hardcodearEmpleados(eEmpleado listaEmp[], int te);


/** \brief Funci�n que solicita los datos para cargar un empleado en el array
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \param id int El �ltimo id utilizado
 * \param mensaje[] char Variable que se actualiza a "EMPLEADO AGREGADO" o a "NO HAY LUGAR"
 * \return int Retorna 1 si se carg� al empleado o -1 si no hab�a lugar
 *
 */
int altaEmpleado(eEmpleado listaEmp[], int te, int id, char mensaje[]);


/** \brief Funci�n que ofrece un men� para la modificaci�n de los datos de un empleado
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \param mensaje[] char Variable que se actualiza a "Nombre modificado", "Apellido modificado",
 *                      "Salario modificado", "Sector modificado", "Se cancelo la modificacion",
 *                      "El id de empleado no existe" seg�n corresponda
 * \return int Retorna 1 si se modificaron los datos, 0 si se cancelo la modificacion
 *                  o -1 si no existe el id de empleado
 *
 */
int modificarEmpleado(eEmpleado listaEmp[], int te, char mensaje[]);


/** \brief Funci�n que solicita un id de empleado para realizar una baja logica
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tama�o del array
 * \param mensaje[] char Variable que se actualiza a "Baja EFECTUADA", "Baja CANCELADA"
 *                       o "El id de empleado no existe" seg�n corresponda
 * \return int Retorna 0 si se efectu� la baja, -1 si no existe el id o 1 si se
 *                  cancel� la baja
 *
 */
int bajaEmpleado(eEmpleado listaEmp[], int te, char mensaje[]);


/** \brief Procedimiento que ofrece un men� para mostrar los informes
 *
 * \param listaEmp[] eEmpleado El array de empleados del cual obtener los datos
 * \param te int El tama�o del array
 * \return void
 *
 */
void mostrarInformes(eEmpleado listaEmp[], int te);
