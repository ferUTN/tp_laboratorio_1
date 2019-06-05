#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"

#define ID_INICIO 1000
#define PATH_TXT "data.csv"
#define PATH_BIN "data.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   (data.csv)
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). (data.bin)
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).     (data.csv)
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).   (data.bin)
    10. Salir
*****************************************************/


int main(){

    LinkedList* listaEmpleados= ll_newLinkedList();
    int ultimoId= ID_INICIO;
    int opcion;

    do{
        if (ll_isEmpty(listaEmpleados) == 1){
            printf("\n\n-- No hay empleados en la lista, las opciones 4 a 9 estan deshabilitadas.--\n");
        }else if (ll_isEmpty(listaEmpleados) == -1){
            printf("\n\n-- No se pueden cargar empleados a la lista, las opciones 1 a 9 estan deshabilitadas.--\n");
        }
        pedirEnteroRango("\n1. CARGAR EMPLEADOS DE data.csv (MODO TEXTO)"
                         "\n2. CARGAR EMPLEADOS DE data.bin (MODO BINARIO)"
                         "\n3. ALTA DE EMPLEADO"
                         "\n4. MODIFICAR EMPLEADO"
                         "\n5. BAJA DE EMPLEADO"
                         "\n6. LISTAR EMPLEADOS"
                         "\n7. ORDENAR EMPLEADOS"
                         "\n8. GUARDAR EMPLEADOS EN data.csv (MODO TEXTO)"
                         "\n9. GUARDAR EMPLEADOS EN data.bin (MODO BINARIO)"
                         "\n10. SALIR\n\nElija una opcion", &opcion, 1, 10);
        switch(opcion){
            case 1:
                if(controller_loadFromText(PATH_TXT, listaEmpleados) == -1){
                    printf("\n\nERROR. No se pudo realizar la carga desde data.csv\n");
                }else{
                    controller_cargarUltimoId(listaEmpleados, &ultimoId);
                    printf("\n\n--Empleados cargados desde data.csv--\n\n");
                }
            break;
            case 2:
                if(controller_loadFromBinary(PATH_BIN, listaEmpleados) == -1){
                    printf("\n\nERROR. No se pudo realizar la carga desde data.bin\n");
                }else{
                    controller_cargarUltimoId(listaEmpleados, &ultimoId);
                    printf("\n\n--Empleados cargados desde data.bin--\n\n");
                }
                break;
            case 3:
                controller_addEmployee(listaEmpleados, &ultimoId);
                break;
            case 4:
                if(!ll_isEmpty(listaEmpleados)){
                    if (controller_editEmployee(listaEmpleados) == -1){
                        printf("\n\n--Error. El empleado no existe--\n\n");
                    };
                }
                break;
            case 5:
                if(!ll_isEmpty(listaEmpleados)){
                    opcion= controller_removeEmployee(listaEmpleados);
                    if(opcion==0){
                        printf("\n\n--Empleado dado de baja--\n\n");
                    }else if(opcion== 1){
                        printf("\n\n--Baja cancelada--\n\n");
                    }else{
                        printf("\n\n--Error. El empleado no existe--\n\n");
                    }
                }
                break;
            case 6:
                if(!ll_isEmpty(listaEmpleados)){
                    controller_ListEmployee(listaEmpleados);
                }
                break;
            case 7:
                if(!ll_isEmpty(listaEmpleados)){
                    controller_sortEmployee(listaEmpleados);
                }
                break;
            case 8:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_saveAsText(PATH_TXT, listaEmpleados)==0){
                        printf("\n\n--Datos guardados en %s (MODO TEXTO)--\n\n",PATH_TXT);
                    }else{
                        printf("\nError. No se pudieron guardar los datos en %s", PATH_TXT);
                    };
                }
                break;
            case 9:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_saveAsBinary(PATH_BIN, listaEmpleados)==0){
                        printf("\n\n--Datos guardados en %s (MODO BINARIO)--\n\n",PATH_TXT);
                    }else{
                        printf("\nError. No se pudieron guardar los datos en %s", PATH_TXT);
                    }
                }
                break;
            case 10:
                printf("\n\nSaliendo del sistema.\n");
                ll_clear(listaEmpleados);
                ll_deleteLinkedList(listaEmpleados);
        }
    }while(opcion != 10);

    return 0;
}
