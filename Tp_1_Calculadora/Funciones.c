#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

long long int factorizar(float num){
    long long int resultado= -1;
    //Si el número es negativo, no le puedo aplicar el factorial
    if(num>=0){
        int entero = (long long int)num;
        //Si la parte decimal es igual a cero, le puedo calcular el factorial:
        if(  (num - entero) == 0  ){
            resultado= factorial(num);
        }
    }
    //Devuelve el resultado del factorial (o -1 si no se pudo factorizar)
    return resultado;
}

long long int factorial(long long int numero){
    long long int resultado;
    if(numero == 0 || numero == 1){
        resultado= 1;
    }else{
        resultado= numero * factorial( numero - 1);
    }
    return resultado;
}

float sumar(float num1, float num2){
    return num1 + num2;
}

float restar(float num1, float num2){
    return num1 - num2;
}

float multiplicar(float num1, float num2){
    return num1*num2;
}

float dividir(float num1, float num2){
    return num1/num2;
}
