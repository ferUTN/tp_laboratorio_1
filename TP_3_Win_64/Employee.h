#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#define TAM_NOM 128

typedef struct
{
    int id;
    char nombre[TAM_NOM];
    int horasTrabajadas;
    int sueldo;
}Employee;

#endif // employee_H_INCLUDED


/** \brief Función que muestra un encabezado de empleado
 *
 * \return void
 *
 */
void employee_mostrarEncabezado();


/** \brief Función que muestra los datos de un empleado
 *
 * \param Employee* El puntero al empleado
 * \return void
 *
 */
void employee_mostrarUno(Employee*);


/** \brief Constructor por defecto de empleado. Crea un empleado en memoria dinamica
 *
 * \return Employee* Devuelve el puntero al empleado creado
 *
 */
Employee* employee_new();


/** \brief Constructor parametrizado de empleado. Crea un empleado en memoria dinamica
           con los datos recibidos como parametros
 *
 * \param id int El id del empleado
 * \param nombre char* El nombre del empleado
 * \param horasTrabajadas int Las horas trabajadas del empleado
 * \param sueldo int El sueldo del empleado
 * \return Employee* Devuelve el puntero al empleado creado
 *
 */
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo);


/** \brief Función que setea el id de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int El id a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setId(Employee* this,int id);


/** \brief Función que obtiene el id de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int* El id obtenido
 * \return int Devuelve 0 si se pudo obtener, o -1 si no se pudo
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief Función que setea el nombre de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El nombre a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Función que obtiene el nombre de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El nombre obtenido
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Función que setea las horas trabajadas de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param horasTrabajadas int Las horas trabajadas a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Función que obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param horasTrabajadas int* Las horas obtenidas
 * \return int Devuelve 0 si se pudo obtener, o -1 si no se pudo
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Función que setea el sueldo de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param sueldo int El sueldo a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief Función que obtiene el sueldo de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param sueldo int* El sueldo a obtener
 * \return int Devuelve 0 si se puedo obtener, o -1 si no se pudo
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);


/** \brief Función que compara dos empleados por su nombre
 *
 * \param void* El puntero a un empleado
 * \param void* El puntero a otro empleado
 * \return int Devuelve -1, 0 o 1 según el orden de los empleados
 *
 */
int employee_compareByName(void*, void*);

/** \brief Función que compara dos empleados por id
 *
 * \param void* El puntero a un empleado
 * \param void* El puntero a otro empleado
 * \return int Devuelve -1, 0 o 1 según el orden de los empleados
 *
 */
int employee_compareById(void*, void*);

/** \brief Función que compara dos empleados por sueldo
 *
 * \param void* El puntero a un empleado
 * \param void* El puntero a otro empleado
 * \return int Devuelve -1, 0 o 1 según el orden de los empleados
 *
 */
int employee_compareBySueldo(void*, void*);

/** \brief Función que compara dos empleados por horas trabajadas
 *
 * \param void* El puntero a un empleado
 * \param void* El puntero a otro empleado
 * \return int Devuelve -1, 0 o 1 según el orden de los empleados
 *
 */
int employee_compareByHorasTrabajadas(void*, void*);
