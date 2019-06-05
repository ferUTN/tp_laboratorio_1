#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

void employee_mostrarEncabezado(){
    printf("\n\tID\t\t\tNOMBRE \t\tHORAS TRABAJADAS \tSUELDO \n\n");
}

void employee_mostrarUno(Employee* this){
    if(this != NULL){
        printf("\t%2d \t%22s \t\t%d \t\t\t%d\n", this->id, this->nombre,this->horasTrabajadas, this->sueldo);
    }
}

Employee* employee_new(){
    Employee* this;
    this= (Employee*)malloc(sizeof(Employee));
    return this;
}

Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo){
    Employee* this= employee_new();
    if(this != NULL){
        this->id= id;
        strcpy(this->nombre, nombre);
        this->horasTrabajadas= horasTrabajadas;
        this->sueldo= sueldo;
    }
    return this;
}

int employee_setId(Employee* this, int id){
    int estado= -1;
    if(this != NULL){
        this-> id= id;
        estado= 0;
    }
    return estado;
}

int employee_getId(Employee* this,int* id){
    int estado= -1;
    if(this != NULL){
        *id= this->id;
        estado= 0;
    }
    return estado;
}

int employee_setNombre(Employee* this, char* nombre){
    int estado= -1;
    if(this != NULL && nombre != NULL){
        strcpy(this->nombre,nombre);
        estado= 0;
    }
    return estado;
}
int employee_getNombre(Employee* this, char* nombre){
    int estado= -1;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        estado= 0;
    }
    return estado;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
    int estado= -1;
    if(this != NULL){
        this->horasTrabajadas= horasTrabajadas;
        estado= 0;
    }
    return estado;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
    int estado= -1;
    if(this != NULL && horasTrabajadas != NULL) {
        *horasTrabajadas= this->horasTrabajadas;
        estado= 0;
    }
    return estado;
}

int employee_setSueldo(Employee* this, int sueldo){
    int estado= -1;
    if(this != NULL){
        this->sueldo= sueldo;
        estado= 0;
    }
    return estado;
}

int employee_getSueldo(Employee* this, int* sueldo){
    int estado= -1;
    if(this != NULL && sueldo != NULL){
        *sueldo= this->sueldo;
        estado= 0;
    }
    return estado;
}


int employee_compareByName(void* emp1, void* emp2){
    Employee* e1 = (Employee*) emp1;
    Employee* e2 = (Employee*) emp2;
    return stricmp(e1->nombre,e2->nombre);
}

int employee_compareById(void* emp1, void* emp2){
    Employee* e1 = (Employee*) emp1;
    Employee* e2 = (Employee*) emp2;
    int retorno;
    if( e1->id > e2->id ){
        retorno= 1;
    }else if( e1->id > e2->id ){
        retorno= -1;
    }else{
        retorno= 0;
    }
    return retorno;
}

int employee_compareBySueldo(void* emp1, void* emp2){
    Employee* e1 = (Employee*) emp1;
    Employee* e2 = (Employee*) emp2;
    int retorno;
    if( e1->sueldo > e2->sueldo){
        retorno= 1;
    }else if( e1->sueldo < e2->sueldo ){
        retorno= -1;
    }else{
        retorno= 0;
    }
    return retorno;
}

int employee_compareByHorasTrabajadas(void* emp1, void* emp2){
    Employee* e1 = (Employee*) emp1;
    Employee* e2 = (Employee*) emp2;
    int retorno;
    if( e1->horasTrabajadas > e2->horasTrabajadas){
        retorno= 1;
    }else if( e1->horasTrabajadas < e2->horasTrabajadas ){
        retorno= -1;
    }else{
        retorno= 0;
    }
    return retorno;
}
