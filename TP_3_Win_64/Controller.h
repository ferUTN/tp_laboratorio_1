#ifndef CONTROLLER_H_INCLUDED
#include "LinkedList.h"

#define CONTROLLER_H_INCLUDED
#endif // CONTROLLER_H_INCLUDED


/** \brief Funci�n que carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* El puntero a la ruta del archivo
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudieron cargar los datos, o -1 si no se cargaron
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Funci�n que carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* El puntero a la ruta del archivo
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudieron cargar los datos, o -1 si no se cargaron
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Funci�n que da de alta un empleado en la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo dar el alta, o -1 si no se pudo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* ultimoId);


/** \brief Funci�n que edita un empleado de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* El puntero a a la lista de empleados
 * \return int Devuelve 0 si se pudo editar, o -1 si no se pudo
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Funci�n que da de baja un empleado de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo realizar la baja, o -1 si no se pudo
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Funci�n que lista los empleados de la lista
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo listar, o -1 si no se pudo
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Funci�n que ordena empleados de una lista
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo ordenar, o -1 si no se pudo
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Funci�n que guarda la lista de empleados en un archivo en modo texto
 *
 * \param path char* El puntero a la ruta del archivo
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo guardar, o -1 si no se pudo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Funci�n que guarda la lista de empleados en un archivo en modo binario
 *
 * \param path char* El puntero a la ruta del archivo
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo guardar, o -1 si no se pudo
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Funci�n que obtiene el ultimo id de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \param ultimoId int* El puntero al �ltimo id
 * \return int Devuelve 0 si se pudo obtener el �ltimo id, o -1 si no se pudo
 *
 */
int controller_cargarUltimoId(LinkedList* pArrayListEmployee, int* ultimoId);

