#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "ENTRADAS.H"

#define T 1000

int main()
{
    eEmpleado listaEmpleados[T];
    inicializarEmpleados(listaEmpleados, T);

    //Hasta 8 empleados para hardcodear
    hardcodearEmpleados(listaEmpleados, 8);

    //Variable para utilizar como clave primaria en la lista de empleados
    int id= 99;

    int opcion;
    char mensaje[100];
    do{
        opcion = menuDeOpciones("\n1. ALTA"
                                "\n2. MODIFICAR"
                                "\n3. BAJA"
                                "\n4. INFORMAR"
                                "\n5. SALIR\n\nElija una opcion",1,5);
        switch(opcion)
        {
            case 1:
                if (altaEmpleado(listaEmpleados,T,id,mensaje)){
                    id++;
                }
                printf("\n%s\n\n",mensaje);
                break;
            case 2:
                modificarEmpleado(listaEmpleados,T,mensaje);
                printf("\n%s\n\n",mensaje);
                break;
            case 3:
                bajaEmpleado(listaEmpleados, T, mensaje);
                printf("\n%s\n\n",mensaje);
                break;
            case 4:
                mostrarInformes(listaEmpleados,T);
        }

    }while(opcion!=5);

    return 0;
}
