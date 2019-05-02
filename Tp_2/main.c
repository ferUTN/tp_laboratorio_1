#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "ENTRADAS.H"
#define T 1000

int main(void)
{
    eEmpleado listaEmpleados[T];
    inicializarEmpleados(listaEmpleados, T);

    //Hasta 8 empleados para hardcodear
    int cantidad= 8;
    hardcodearEmpleados(listaEmpleados, T, cantidad);

    //Variable para utilizar como clave primaria en la lista de empleados
    int id= 99;

    int opcion;
    char mensaje[100];
    do{
        if (!hayActivos(listaEmpleados,T)){
            printf("\n\n-- No hay empleados activos, las opciones 2 a 4 estan deshabilitadas.--\n");
        }
        opcion = menuDeOpciones("\n1. ALTA"
                                "\n2. MODIFICAR"
                                "\n3. BAJA"
                                "\n4. INFORMAR"
                                "\n5. SALIR\n\nElija una opcion",1,5);
        switch(opcion){
            case 1:
                if(altaEmpleado(listaEmpleados,T,id,mensaje)==1){
                    id++;
                }
                printf("\n%s\n\n",mensaje);
                break;
            case 2:
                if(hayActivos(listaEmpleados,T)){
                    modificarEmpleado(listaEmpleados,T,mensaje);
                    printf("\n%s\n\n",mensaje);
                }
                break;
            case 3:
                if(hayActivos(listaEmpleados,T)){
                    bajaEmpleado(listaEmpleados, T, mensaje);
                    printf("\n%s\n\n",mensaje);
                }
                break;
            case 4:
                if(hayActivos(listaEmpleados,T)){
                    mostrarInformes(listaEmpleados,T);
                }
        }

    }while(opcion!=5);

    return 0;
}
