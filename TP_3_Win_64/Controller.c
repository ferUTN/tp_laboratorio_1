#include <stdlib.h>
#include "Funciones.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    int estado= -1;
    FILE* miArchivo;
    miArchivo= fopen (path, "r");
    if(miArchivo != NULL && pArrayListEmployee != NULL){
        ll_clear(pArrayListEmployee);
        estado= parser_EmployeeFromText(miArchivo, pArrayListEmployee);
        fclose(miArchivo);
    }
    return estado;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    int estado= -1;
    FILE* miArchivo;
    miArchivo= fopen (path, "rb");
    if(miArchivo != NULL && pArrayListEmployee != NULL){
        ll_clear(pArrayListEmployee);
        estado= parser_EmployeeFromBinary(miArchivo, pArrayListEmployee);
        fclose(miArchivo);
    }
    return estado;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* ultimoId){
    int id;
    char nombre[TAM_NOM];
    int horasTrabajadas;
    int sueldo;
    int estado= -1;
    if(pArrayListEmployee != NULL && ultimoId != NULL){
        pedirCadena("Ingrese el nombre",nombre,TAM_NOM);
        pedirEnteroPositivo("Ingrese las horas trabajadas", &horasTrabajadas);
        pedirEnteroPositivo("Ingrese el sueldo", &sueldo);
        id= *ultimoId;
        id++;
        Employee* this= employee_newParametros(id,nombre,horasTrabajadas,sueldo);
        ll_add(pArrayListEmployee, this);
        *ultimoId= id;
        estado= 0;
    }
    return estado;
}


int controller_editEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    int id;
    int i;
    int indice= -1;
    int opcion;
    char nombre[TAM_NOM];
    int sueldo;
    int horasTrabajadas;
    Employee* this;

    if(pArrayListEmployee != NULL){
        pedirEnteroPositivo("Ingrese Id de empleado a modificar", &id);

        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            if( this->id == id ){
                indice= i;
                break;
            }
        }
        if(indice != -1){
            do{
                employee_mostrarEncabezado();
                employee_mostrarUno(this);
                pedirEnteroRango("\n1. Modificar nombre"
                                 "\n2. Modificar horas trabajadas"
                                 "\n3. Modificar sueldo"
                                 "\n4. VOLVER al menu anterior"
                                 "\n\nElija una opcion", &opcion, 1, 4);
                estado= 0;
                switch(opcion){
                    case 1:
                        pedirCadena("Ingrese el nuevo nombre", nombre,TAM_NOM);
                        employee_setNombre(this,nombre);
                        printf("\nNombre modificado!");
                        break;
                    case 2:
                        pedirEnteroPositivo("Ingrese la nueva cantidad de horas trabajadas", &horasTrabajadas);
                        employee_setHorasTrabajadas(this, horasTrabajadas);
                        printf("\nHoras modificas!");
                        break;
                    case 3:
                        pedirEnteroPositivo("Ingrese el nuevo sueldo", &sueldo);
                        employee_setSueldo(this, sueldo);
                        printf("\nSueldo modificado!");
                        break;
                }
            }while(opcion != 4);
        }
    }
    return estado;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    int id;
    int i;
    int indice= -1;
    int opcion;
    Employee* this;
    if (pArrayListEmployee != NULL){
        pedirEnteroPositivo("Ingrese Id de empleado a dar de baja", &id);

        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            if( this->id == id ){
                indice= i;
                break;
            }
        }
        if(indice != -1){
            employee_mostrarEncabezado();
            employee_mostrarUno(this);
            pedirEnteroRango("\n1. Dar de baja al empleado"
                             "\n2. CANCELAR\n\nElija una opcion",&opcion,1,2);
            if(opcion==1){
                ll_remove(pArrayListEmployee,indice);
                estado= 0;
            }else{
                estado= 1;
            }
        }
    }
    return estado;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    Employee* this;
    int i;
    int contador= 0;
    if(pArrayListEmployee != NULL){
        employee_mostrarEncabezado();
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            employee_mostrarUno(this);
            contador++;
            if(contador== 500){
                system("pause");
                contador= 0;
            }
        }
        estado= 0;
    }
    return estado;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    int opcion;
    if(pArrayListEmployee != NULL){

        pedirEnteroRango("\n1. Ordenar empleado por id"
                         "\n2. Ordenar empleado por nombre"
                         "\n3. Ordenar empleado por sueldo"
                         "\n4. Ordenar empleado por horas trabajadas"
                         "\n5. CANCELAR"
                         "\n\nElija una opcion", &opcion, 1, 5);
        if(opcion!=5){
            printf("\n\n--ORDENANDO... (puede demorar)--\n");
            switch(opcion){
                case 1:
                    ll_sort(pArrayListEmployee, employee_compareById, 1);
                    break;
                case 2:
                    ll_sort(pArrayListEmployee, employee_compareByName, 1);
                    break;
                case 3:
                    ll_sort(pArrayListEmployee, employee_compareBySueldo, 1 );
                    break;
                case 4:
                    ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, 1 );
            }
            printf("\n\n--Ordenamiento Finalizado--\n\n");
        }

        estado= 0;
    }
    return estado;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int estado= -1;
    int i;
    FILE* miArchivo= fopen(path,"w");
    if(miArchivo!= NULL && pArrayListEmployee != NULL){
        Employee* this;
        fprintf(miArchivo,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= ll_get(pArrayListEmployee, i);
            fprintf(miArchivo,"%d,%s,%d,%d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        fclose(miArchivo);
        estado= 0;
    }
    return estado;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    int estado= -1;
    int i;
    FILE* miArchivo= fopen(path,"wb");
    if(miArchivo!= NULL && pArrayListEmployee!= NULL){
        Employee* this;
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= ll_get(pArrayListEmployee, i);
            fwrite(this, sizeof(Employee),1,miArchivo);
        }
        fclose(miArchivo);
        estado= 0;
    }
    return estado;
}


int controller_cargarUltimoId(LinkedList* pArrayListEmployee, int* ultimoId){
    int estado= -1;
    int i;
    if(pArrayListEmployee != NULL && ultimoId != NULL){
        Employee* this;
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= ll_get(pArrayListEmployee, i);
            if(this->id >= *ultimoId){
                *ultimoId= this->id;
            }
        }
        estado= 0;
    }
    return estado;
}
