#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entradas.h"

void validarTamCadena(char mensaje[], char cadena[], int tam){
    while( strlen(cadena) > tam){
        printf("Error. %s: ", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}

void pedirCadena(char mensaje[], char cadena[], int tam){
    char buffer[1000];
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%[^\n]", buffer);
    validarTamCadena(mensaje, buffer, tam);
    strcpy(cadena, buffer);
}

float pedirFloatPositivo(char mensaje[]){
    float unFloat;
    printf("%s: ", mensaje);
    scanf("%f", &unFloat);
    while(unFloat<=0){
        printf("Error. %s: ", mensaje);
        scanf("%f", &unFloat);
    }
    return unFloat;
}

int pedirEnteroPositivo(char mensaje[]){
    int unEntero;
    printf("%s: ", mensaje);
    scanf("%d", &unEntero);
    while(unEntero <= 0){
        printf("Error. %s: ", mensaje);
        scanf("%d", &unEntero);
    }
    return unEntero;
}

int pedirEnteroRango(char mensaje[], int minimo, int maximo){
    int unEntero;
    printf("%s: ", mensaje);
    scanf("%d", &unEntero);
    while(unEntero < minimo || unEntero > maximo){
        printf("Error.\n\n%s: ", mensaje);
        scanf("%d", &unEntero);
    }
    return unEntero;
}

int menuDeOpciones(char mensaje[],int primera, int ultima){
    int opcion;
    opcion= pedirEnteroRango(mensaje,primera,ultima);
    return opcion;
}
