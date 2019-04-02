#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    float operandoA= 0;
    float operandoB= 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMult;
    float resultadoDiv;
    long long int factorialOperandoA;
    long long int factorialOperandoB;

    int calculosRealizados= 0;

    int opcion;
    char seguir= 's';
    do{
        printf("Operando A: %f\n", operandoA);
        printf("Operando B: %f\n", operandoB);

        if(calculosRealizados)
        {
            printf("\n--SE REALIZARON LOS CALCULOS DE TODAS LAS OPERACIONES--\n\n");
        }
        else
        {
            printf("\n--OPERACIONES ENTRE OPERANDOS AUN NO CALCULADAS--\n\n");
        }

        printf("1. Ingresar 1er operando\n2. Ingresar 2do operando\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n");
        printf("\n----------------------");
        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\nIngrese el 1er operando: ");
            scanf("%f", &operandoA);
            calculosRealizados= 0;
            break;
        case 2:
            printf("\nIngrese el 2do operando: ");
            scanf("%f", &operandoB);
            calculosRealizados= 0;
            break;
        case 3:
            resultadoSuma= sumar(operandoA, operandoB);
            resultadoResta= restar(operandoA, operandoB);
            resultadoMult= multiplicar(operandoA, operandoB);
            if(operandoB != 0)
            {
                resultadoDiv= dividir(operandoA, operandoB);
            }

            factorialOperandoA= factorizar(operandoA);
            factorialOperandoB= factorizar(operandoB);

            calculosRealizados=1;
            break;
        case 4:

            if(calculosRealizados){
                printf("\n--RESULTADOS--\n");
                printf("\n1er operando: %f", operandoA);
                printf("\n2do operando: %f\n", operandoB);
                printf("\nSUMA: %f", resultadoSuma);
                printf("\nRESTA: %f", resultadoResta);
                printf("\nMULTIPLICACION: %f", resultadoMult);

                if(operandoB==0)                {
                    printf("\nNO SE PUEDE DIVIDIR POR 0!");
                }else{
                    printf("\nDIVISION: %f", resultadoDiv);
                }

                if(factorialOperandoA>=0){
                    //Según arquitectura, cambiar %I64d por %lld
                    printf("\nFACTORIAL DEL 1er OPERANDO: %I64d", factorialOperandoA);
                }else{
                    printf("\nNO SE PUEDE CALCULAR EL FACTORIAL DEL 1er OPERANDO");
                }

                if(factorialOperandoB>=0){
                    //Según arquitectura, cambiar %I64d por %lld
                    printf("\nFACTORIAL DEL 2do OPERANDO: %I64d", factorialOperandoB);
                }else{
                    printf("\nNO SE PUEDE CALCULAR EL FACTORIAL DEL 2do OPERANDO");
                }

                printf("\n");
            }else{
                printf("\n--PRIMERO DEBE CALCULAR TODAS LAS OPERACIONES!--\n");
            }
            break;
        case 5:
            printf("\nSaliendo del programa.\n");
            seguir= 'n';
            break;

        default:
            printf("No ingreso una opcion valida.\n");
        }
        printf("\n");
        system("pause");
        system("cls");

    }while(seguir=='s');

    return 0;
}
