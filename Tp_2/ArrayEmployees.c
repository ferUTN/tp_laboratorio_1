#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ENTRADAS.H"
#include "ArrayEmployees.h"


/** \brief Procedimiento que muestra los datos de un empleado de forma encolumnada
 *
 * \param unEmpleado eEmpleado El empleado a mostrar
 * \return void
 *
 */
static void mostrarUnEmpleado(eEmpleado unEmpleado);


/** \brief Función que busca un lugar libre en el array de empleados
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tamaño del array
 * \return int Retorna el índice de la posición libre o -1 si no hay lugar
 *
 */
static int buscarLibre(eEmpleado listaEmp[], int te);


/** \brief Procedimiento que intercambia dos empleados en el array
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param i int El índice de uno de los empleados
 * \param j int El índice del otro empleado
 * \return void
 *
 */
static void swapEmpleado(eEmpleado listaEmp[],int i, int j);


/** \brief Procedimiento que ordena el array de empleados por apellido y sector
 *         de forma ascendente
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tamaño del array
 * \return void
 *
 */
static void ordenarEmpleadosAsc(eEmpleado listaEmp[], int te);


/** \brief Procedimiento que ordena el array de empleados por apellido y sector
 *         de forma descendente
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tamaño del array
 * \return void
 *
 */
static void ordenarEmpleadosDesc(eEmpleado listaEmp[], int te);


/** \brief Procedimiento que solicita un nuevo nombre para el empleado
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param indice int El índice del array donde se encuentra el empleado
 * \return void
 *
 */
static void modificarNombre(eEmpleado listaEmp[], int indice);


/** \brief Procedimiento que solicita un nuevo apellido para el empleado
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param indice int El índice del array donde se encuentra el empleado
 * \return void
 *
 */
static void modificarApellido(eEmpleado listaEmp[], int indice);


/** \brief Procedimiento que solicita un nuevo salario para el empleado
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param indice int El índice del array donde se encuentra el empleado
 * \return void
 *
 */
static void modificarSalario(eEmpleado listaEmp[], int indice);


/** \brief Procedimiento que solicita un nuevo sector para el empleado
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param indice int El índice del array donde se encuentra el empleado
 * \return void
 *
 */
static void modificarSector(eEmpleado listaEmp[], int indice);


/** \brief Procedimiento que muestra los nombres de las columnas correspondientes
 *         a los datos de los empleados
 *
 * \return void
 *
 */
static void mostrarEncabezado(void);


/** \brief Función que cuenta los empleados activos en el array
 *
 * \param listaEmp[] eEmpleado El array de empleados
 * \param te int El tamaño del array
 * \return int La cantidad que devuelve
 *
 */
static int contarActivos(eEmpleado listaEmp[], int te);



/*  Implementación de las funciones  */



static void mostrarEncabezado(void){
    printf("\n\nID\t   NOMBRE\tAPELLIDO\tSALARIO\t\t      SECTOR\n\n");
}

static void modificarSalario(eEmpleado listaEmp[], int indice){
    listaEmp[indice].salario= pedirFloatPositivo("Nuevo salario");
}

static void modificarSector(eEmpleado listaEmp[], int indice){
    listaEmp[indice].sector= pedirEnteroPositivo("Nuevo sector");
}

static void modificarNombre(eEmpleado listaEmp[], int indice){
    pedirCadena("Nuevo nombre",listaEmp[indice].nombre,TAM_CADENA);
}

static void modificarApellido(eEmpleado listaEmp[], int indice){
    pedirCadena("Nuevo apellido",listaEmp[indice].apellido,TAM_CADENA);
}

static void mostrarUnEmpleado(eEmpleado emp){
    printf("%2d%15s%15s\t%5.2f\t%10d\n", emp.id, emp.nombre,
                                    emp.apellido, emp.salario,
                                     emp.sector);
}

static int buscarLibre(eEmpleado listaEmp[], int te){
    int indice= -1;
    int i;
    for(i=0;i<te;i++){
        if(listaEmp[i].estaLibre){
            indice= i;
            break;
        }
    }
    return indice;
}

static void swapEmpleado(eEmpleado listaEmp[],int i, int j){
    eEmpleado aux;
    aux= listaEmp[j];
    listaEmp[j]= listaEmp[i];
    listaEmp[i]= aux;
}

static void ordenarEmpleadosAsc(eEmpleado listaEmp[], int te){
    int i,j;
    //Ordena por apellido y sector ascendente
    for(i=0;i<te-1;i++){
        for(j=i+1;j<te;j++){
            if(listaEmp[i].estaLibre== OCUPADO){
                //Intercambio si el apellido de indice i es mayor al apellido de indice j
                //o si son iguales en el caso de que el sector de i sea mayor al sector de j
                if (( stricmp(listaEmp[i].apellido,listaEmp[j].apellido) > 0) ||
                   (( stricmp(listaEmp[i].apellido,listaEmp[j].apellido) ==0) &&
                    ( listaEmp[i].sector > listaEmp[j].sector))){

                        swapEmpleado(listaEmp,i,j);
                }
            }

        }
    }
}

static void ordenarEmpleadosDesc(eEmpleado listaEmp[], int te){
    int i,j;
    //Ordena por apellido y sector descendente
    for(i=0;i<te-1;i++){
        for(j=i+1;j<te;j++){
            if(listaEmp[i].estaLibre== OCUPADO){
                //Intercambio si el apellido de indice i es menor al apellido de indice j
                //o si son iguales en el caso de que el sector de i sea menor al sector de j
                if (( stricmp(listaEmp[i].apellido,listaEmp[j].apellido) < 0) ||
                   (( stricmp(listaEmp[i].apellido,listaEmp[j].apellido) ==0) &&
                    ( listaEmp[i].sector < listaEmp[j].sector))){

                        swapEmpleado(listaEmp,i,j);
                }
            }
        }
    }
}

static int contarActivos(eEmpleado listaEmp[], int te){
    int contador= 0;
    int i;
    for(i=0;i<te;i++){
        if(listaEmp[i].estaLibre == OCUPADO){
            contador++;
        }
    }
    return contador;
}

int hardcodearEmpleados(eEmpleado listaEmp[], int te, int cant){

    int ids[]= {10,20,30,40,50,60,70,80};
    char nombres[][50]= {"Carlos","Maria","Lucas","Pedro",
                            "Daniel","Mateo","Ana","Gabriela"};
    char apellidos[][50]= {"Martinez","Alvarez","Martinez","Rey",
                            "Martinez","Perez","Stanley","Martinez"};
    float salarios[]={50000,30000,80000,10000,90000,20000,60000,70000};
    int sectores[]= {5,2,3,3,2,4,1,4};

    int contador= 0;
    if (cant <= 8 && cant >= 0){

        int indice;
        int i;
        for(i=0; i<cant; i++){
            indice= buscarLibre(listaEmp,te);
            if(indice != -1){
                listaEmp[indice].id = ids[i];
                strcpy(listaEmp[indice].nombre, nombres[i]);
                strcpy(listaEmp[indice].apellido, apellidos[i]);
                listaEmp[indice].salario= salarios[i];
                listaEmp[indice].sector= sectores[i];
                listaEmp[indice].estaLibre= OCUPADO;
                contador++;
            }else{
                break;
            }
        }
        printf("\n\n --SE HARDCODEARON %d EMPLEADOS--\n\n",contador);
    }else{
        printf("\n\n --ERROR. SOLO SE PUEDEN HARDCODEAR DE 1 A 8 EMPLEADOS--\n\n");
    }
    return contador;
}

int hayActivos(eEmpleado listaEmp[], int te){
    int resultado= 0;
    int i;
    for(i=0;i<te;i++){
        if(listaEmp[i].estaLibre == OCUPADO){
            resultado= 1;
            break;
        }
    }
    return resultado;
}

//Función initEmployees
int inicializarEmpleados(eEmpleado listaEmp[], int te){
    int i;
    for(i=0;i<te;i++){
        listaEmp[i].estaLibre= LIBRE;
    }
    return 0;
}

//Función addEmployee
int agregarEmpleado(eEmpleado listaEmp[], int te, int id, char nombre[],
                    char apellido[],float salario,int sector){
    int resultado= -1;
    int indice= buscarLibre(listaEmp,te);
    if(indice != -1){
        listaEmp[indice].id= id;
        strcpy(listaEmp[indice].nombre, nombre);
        strcpy(listaEmp[indice].apellido, apellido);
        listaEmp[indice].salario= salario;
        listaEmp[indice].sector= sector;
        listaEmp[indice].estaLibre= OCUPADO;
        resultado= 0;
    }
    return resultado;
}

//Función findEmployeeById
int buscarEmpleadoPorId(eEmpleado listaEmp[], int te, int id){
    int indice= -1;
    int i;
    for(i=0;i<te;i++){
        if(listaEmp[i].id == id && (listaEmp[i].estaLibre== OCUPADO)){
            indice= i;
            break;
        }
    }
    return indice;
}

//Función removeEmployee
int borrarEmpleado(eEmpleado listaEmp[], int te, int id){
    int resultado= -1;
    int indice= buscarEmpleadoPorId(listaEmp,te,id);
    if(indice != -1){
        listaEmp[indice].estaLibre= LIBRE;
        resultado= 0;
    }
    return resultado;
}

//Función sortEmployees
int ordenarEmpleados(eEmpleado listaEmp[], int te, int orden){
    if(orden==ASC){
        ordenarEmpleadosAsc(listaEmp, te);
    }else if(orden==DESC){
        ordenarEmpleadosDesc(listaEmp, te);
    }
    return 0;
}

//Función printEmployees
int mostrarEmpleados(eEmpleado listaEmp[], int te){
    int i;
    mostrarEncabezado();
    for(i=0;i<te;i++){
        if(listaEmp[i].estaLibre == OCUPADO){
            mostrarUnEmpleado(listaEmp[i]);
        }
    }
    printf("\n\n");
    return 0;
}

float obtenerSalarioTotal(eEmpleado listaEmp[], int te){
    float acumSalario= 0;
    int i;
    for(i=0;i<te;i++){
        if(listaEmp[i].estaLibre==OCUPADO){
            acumSalario= acumSalario + listaEmp[i].salario;
        }
    }
    return acumSalario;
}

float obtenerSalarioPromedio(eEmpleado listaEmp[], int te){
    float resultado=-1;
    float acumSalario= obtenerSalarioTotal(listaEmp, te);
    int cantidad= contarActivos(listaEmp, te);
    if(cantidad>0){
        resultado= (float)acumSalario/cantidad;
    }
    return resultado;
}

int contarSalariosMayores(eEmpleado listaEmp[], int te){
    int contador= 0;
    float salarioPromedio= obtenerSalarioPromedio(listaEmp, te);
    int i;
    for(i=0;i<te;i++){
        if(listaEmp[i].estaLibre== OCUPADO && (listaEmp[i].salario > salarioPromedio)){
            contador++;
        }
    }
    return contador;
}

int altaEmpleado(eEmpleado listaEmp[], int te, int id, char cadena[]){
    int resultado= 0;
    int indice= buscarLibre(listaEmp,te);
    if(indice != -1){
        int nuevoId= id + 1;
        char nombre[TAM_CADENA];
        char apellido[TAM_CADENA];
        pedirCadena("Ingrese el nombre",nombre,TAM_CADENA);
        pedirCadena("Ingrese el apellido",apellido,TAM_CADENA);
        float salario= pedirFloatPositivo("Ingrese el salario");
        int sector= pedirEnteroPositivo("Ingrese el sector");
        resultado= agregarEmpleado(listaEmp,te,nuevoId,nombre,apellido,salario,sector);
        strcpy(cadena,"EMPLEADO AGREGADO");
        resultado= 1;
    }else{
        strcpy(cadena,"NO HAY LUGAR");
    }
    return resultado;
}

int modificarEmpleado(eEmpleado listaEmp[], int te, char mensaje[]){
    int fueModificado= -1;

    int id= pedirEnteroPositivo("Ingrese el Id del empleado a modificar");
    int indice= buscarEmpleadoPorId(listaEmp,te,id);
    if(indice != -1){
        fueModificado= 1;
        mostrarEncabezado();
        mostrarUnEmpleado(listaEmp[indice]);
        int opcion= menuDeOpciones("\n1. Mod. Nombre"
                                   "\n2. Mod. Apellido"
                                   "\n3. Mod. Salario"
                                   "\n4. Mod. Sector"
                                   "\n5. CANCELAR"
                                   "\n\nElija opcion",1,5);
        switch (opcion){
            case 1:
                modificarNombre(listaEmp, indice);
                strcpy(mensaje,"Nombre modificado.\n");
                break;
            case 2:
                modificarApellido(listaEmp, indice);
                strcpy(mensaje,"Apellido modificado.\n");
                break;
            case 3:
                modificarSalario(listaEmp, indice);
                strcpy(mensaje,"Salario modificado.\n");
                break;
            case 4:
                modificarSector(listaEmp, indice);
                strcpy(mensaje,"Sector modificado.\n");
                break;
            case 5:
                strcpy(mensaje,"\nSe cancelo la modificacion.\n");
                fueModificado= 0;
                break;
        }
    }else{
        strcpy(mensaje,"El id de empleado no existe.\n");
    }

    return fueModificado;
}

int bajaEmpleado(eEmpleado listaEmp[], int te, char mensaje[]){
    int resultado=-1;
    int id= pedirEnteroPositivo("Ingrese id a dar de baja");
    int indice= buscarEmpleadoPorId(listaEmp,te,id);
    if(indice != -1){
        mostrarEncabezado();
        mostrarUnEmpleado(listaEmp[indice]);
        int opcion= menuDeOpciones("\n1.REALIZAR LA BAJA."
                                   "\n2.CANCELAR."
                                   "\n\nElija opcion",1,2);
        if (opcion==1){
            resultado= borrarEmpleado(listaEmp,te,id);
            strcpy(mensaje,"Baja EFECTUADA.\n\n");
        }else{
            resultado= 1;
            strcpy(mensaje,"Baja CANCELADA.\n\n");
        }
    }else{
        strcpy(mensaje,"El id de empleado no existe.\n\n");
    }

    return resultado;
}

void mostrarInformes(eEmpleado listaEmp[], int te){

    int opcion = menuDeOpciones("\n--INFORMES--\n\n"
                                "\n1. Lista de Empleados"
                                "\n2. Empleados ordenados en forma ascendente"
                                "\n3. Empleados ordenados en forma descendente"
                                "\n4. Salario total"
                                "\n5. Salario promedio"
                                "\n6. Cant. empleados que superan el salario promedio"
                                "\n7. Volver al menu anterior\n\nElija una opcion",1,7);
    switch(opcion){

        case 1:
            printf("\n--Lista de Empleados--\n");
            mostrarEmpleados(listaEmp, te);
            break;
        case 2:
            ordenarEmpleados(listaEmp, te, ASC);
            printf("\n--Empleados Ordenados Por Apellido y Sector Ascendente--\n");
            mostrarEmpleados(listaEmp, te);
            break;
        case 3:
            ordenarEmpleados(listaEmp, te, DESC);
            printf("\n--Empleados Ordenados Por Apellido y Sector Descendente--\n");
            mostrarEmpleados(listaEmp, te);
            break;
        case 4:
            printf("\nSalario total: %.2f\n\n",obtenerSalarioTotal(listaEmp,te));
            break;
        case 5:
            printf("\nPromedio de Salarios: %.2f\n\n",obtenerSalarioPromedio(listaEmp,te));
            break;
        case 6:
            printf("\nCantidad de empleados con salario mayor al promedio: %d\n\n",
                    contarSalariosMayores(listaEmp,te));
            break;
        case 7:
            printf("\n--FIN DE LOS INFORMES--\n\n");
    }
}
