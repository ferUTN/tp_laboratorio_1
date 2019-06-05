#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "parser.h"

#define TAM_BUFFER 500


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    int estado = -1;
    int cantidad;

    if(pFile != NULL && pArrayListEmployee != NULL){
        Employee* this;
        char id[TAM_BUFFER], nombre[TAM_BUFFER], horasTrabajadas[TAM_BUFFER], sueldo[TAM_BUFFER];

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        do{
            cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
            if (cantidad == 4){
                this = (Employee*)malloc(sizeof(Employee));
                this->id = atoi(id);
                strcpy(this->nombre, nombre);
                this->horasTrabajadas= atoi(horasTrabajadas);
                this->sueldo= atoi(sueldo);
                ll_add(pArrayListEmployee, this);
            }else{
                break;
            }
        }while(!feof(pFile));
        estado= 0;
    }
    return estado;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    int estado= -1;
    if(pFile != NULL && pArrayListEmployee != NULL){
        Employee* this;
        while(!feof(pFile)){
            this = (Employee*)malloc(sizeof(Employee));
            if ( fread(this, sizeof(Employee),1,pFile) == 1 ){
                ll_add(pArrayListEmployee, this);
            }else{
                break;
            }
        }
        estado= 0;
    }
    return estado;
}
