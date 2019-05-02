#ifndef ENTRADAS_H
#define ENTRADAS_H

#endif // ENTRADAS_H

/** \brief Función que solicita un número real mayor a cero
 *
 * \param mensaje[] char Lo que representa el número que se solicita
 * \return float Número ingresado validado
 *
 */
float pedirFloatPositivo(char mensaje[]);


/** \brief Función que solicita un número entero dentro de un rango
 *
 * \param mensaje[] char Lo que representa el número que se solicita
 * \param minimo int Número menor admitido
 * \param maximo int Número mayor admitido
 * \return int Número ingresado y validado según el rango
 *
 */
int pedirEnteroRango(char mensaje[], int minimo, int maximo);


/** \brief Función que solicita un número entero mayor a cero
 *
 * \param mensaje[] char Lo que representa el número que se solicita
 * \return int Número positivo ingresado
 *
 */
int pedirEnteroPositivo(char mensaje[]);


/** \brief Procedimiento que valida una cadena según un tamaño
 *
 * \param mensaje[] char Lo que representa la cadena
 * \param cadena[] char Cadena a validar
 * \param tam int Tamaño máximo de caracteres -1
 * \return void
 *
 */
void validarTamCadena(char mensaje[], char cadena[], int tam);


/** \brief Procedimiento que solicita una cadena y la valida según un tamaño
 *
 * \param mensaje[] char Lo que representa la cadena que se solicita
 * \param cadena[] char La cadena validada según el rango
 * \param tam int La cantidad máxima de caracteres -1
 * \return void
 *
 */
void pedirCadena(char mensaje[], char cadena[], int tam);


/** \brief Función que devuelve una opción de menú validada en un rango
 *
 * \param mensaje[] char El texto del menú de opciones
 * \param primera int El número que corresponde a la primera opción del menú
 * \param ultima int El número que corresponde a la última opción del menú
 * \return int Retorna la opción elegida y validada
 *
 */
int menuDeOpciones(char mensaje[], int primera, int ultima);
