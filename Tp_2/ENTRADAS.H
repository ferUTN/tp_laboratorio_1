#ifndef ENTRADAS_H
#define ENTRADAS_H

#endif // ENTRADAS_H

/** \brief Funci�n que solicita un n�mero real mayor a cero
 *
 * \param mensaje[] char Lo que representa el n�mero que se solicita
 * \return float N�mero ingresado validado
 *
 */
float pedirFloatPositivo(char mensaje[]);


/** \brief Funci�n que solicita un n�mero entero dentro de un rango
 *
 * \param mensaje[] char Lo que representa el n�mero que se solicita
 * \param minimo int N�mero menor admitido
 * \param maximo int N�mero mayor admitido
 * \return int N�mero ingresado y validado seg�n el rango
 *
 */
int pedirEnteroRango(char mensaje[], int minimo, int maximo);


/** \brief Funci�n que solicita un n�mero entero mayor a cero
 *
 * \param mensaje[] char Lo que representa el n�mero que se solicita
 * \return int N�mero positivo ingresado
 *
 */
int pedirEnteroPositivo(char mensaje[]);


/** \brief Procedimiento que valida una cadena seg�n un tama�o
 *
 * \param mensaje[] char Lo que representa la cadena
 * \param cadena[] char Cadena a validar
 * \param tam int Tama�o m�ximo de caracteres -1
 * \return void
 *
 */
void validarTamCadena(char mensaje[], char cadena[], int tam);


/** \brief Procedimiento que solicita una cadena y la valida seg�n un tama�o
 *
 * \param mensaje[] char Lo que representa la cadena que se solicita
 * \param cadena[] char La cadena validada seg�n el rango
 * \param tam int La cantidad m�xima de caracteres -1
 * \return void
 *
 */
void pedirCadena(char mensaje[], char cadena[], int tam);


/** \brief Funci�n que devuelve una opci�n de men� validada en un rango
 *
 * \param mensaje[] char El texto del men� de opciones
 * \param primera int El n�mero que corresponde a la primera opci�n del men�
 * \param ultima int El n�mero que corresponde a la �ltima opci�n del men�
 * \return int Retorna la opci�n elegida y validada
 *
 */
int menuDeOpciones(char mensaje[], int primera, int ultima);
