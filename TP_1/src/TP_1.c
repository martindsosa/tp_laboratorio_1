/*
 ============================================================================
 Name        : TP_1.c
 Author      : MARTIN D. SOSA
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculador.h"

int main()
{
	setbuf(stdout,NULL);
	float numeroUno=0;
    float numeroDos=0;
    int operacionElegida;
    int flagIngresoNumero = 0;
    int flagCalculo = 0;
    do
    {
        operacionElegida = MenuOpciones(numeroUno,numeroDos);
        switch(operacionElegida)
        {
            case 1:
                printf("Ingrese el primer numero ");
                scanf("%f",&numeroUno);
                flagIngresoNumero = 1;
                break;
            case 2:
                printf("Ingrese el segundo numero ");
                scanf("%f",&numeroDos);
                flagIngresoNumero = 1;
                break;
            case 3:
            	if(flagIngresoNumero == 1){
            		printf("Calculando la SUMA de (%.2f + %.2f)\n",numeroUno,numeroDos);
					printf("Calculando la RESTA de (%.2f - %.2f)\n",numeroUno,numeroDos);
					printf("Calculando la MULTIPLICACION de (%.2f * %.2f)\n",numeroUno,numeroDos);
					printf("Calculando la DIVISION de (%.2f / %.2f)\n",numeroUno,numeroDos);
					printf("Calculando el factorial de (%.2f !)\n",numeroUno);
					printf("Calculando el factorial de (%.2f !)\n",numeroDos);
					flagCalculo = 1;
            	}else{
            		printf("Para realizar los calculos debe ingresar a la opcion 1 o 2 del menu !!\n");
            	}

                system("pause");
                system("cls");
                break;
            case 4:
            {
            	if(flagCalculo == 1){
            		SumarNumeros(numeroUno,numeroDos);
					RestarNumeros(numeroUno,numeroDos);
					MultiplicarNumeros(numeroUno,numeroDos);
					DividirNumeros(numeroUno,numeroDos);
					Factorial(numeroUno);
					Factorial(numeroDos);
					flagCalculo = 0;
            	}else{
            		printf("Falta realizar los calculos!!! (opcion 3)\n");
            	}

                system("pause");
                system("cls");
                break;
            }
            case 5:
                printf(" Gracias por haber utilizar la calculadora...");
                break;
            default:
                printf("Error, no existe esa opcion en menu \n\n");
        }

    }while(operacionElegida != 5);

	return EXIT_SUCCESS;
}
