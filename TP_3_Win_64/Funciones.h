#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED

/** \brief Funci�n que solicita un n�mero entero positivo y lo valida
 *
 * \param char[] Lo que representa el n�mero que se solicita
 * \param int* El puntero al n�mero
 * \return int Devuelve 0 si se pudo cargar, o -1 si no se pudo
 *
 */
int pedirEnteroPositivo(char[], int*);


/** \brief Funci�n que solicita un n�mero entero dentro de un rango y lo valida
 *
 * \param char[] Lo que representa el n�mero que se solicita
 * \param int* El puntero al n�mero
 * \param int N�mero menor admitido
 * \param int N�mero mayor admitido
 * \return int Devuelve 0 si se pudo cargar, o -1 si no se pudo
 *
 */
int pedirEnteroRango(char[], int*, int, int);


/** \brief Funci�n que valida el tama�o de una cadena
 *
 * \param char[] Lo que representa la cadena
 * \param char* El puntero a la cadena validada seg�n el tama�o
 * \param int Tama�o m�ximo de caracteres -1
 * \return int Devuelve 0 si se pudo validar, o -1 si no se pudo
 *
 */
int validarTamCadena(char[], char*, int);


/** \brief Funci�n que solicita una cadena y la valida seg�n el tama�o
 *
 * \param char[] Lo que representa la cadena
 * \param char* El puntero a la cadena validada seg�n el tama�o
 * \param int Tama�o m�ximo de caracteres -1
 * \return int Devuelve 0 si se pudo validar, o -1 si no se pudo
 *
 */
int pedirCadena(char[], char*, int);

