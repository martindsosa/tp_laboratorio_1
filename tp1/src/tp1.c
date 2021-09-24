/*
 ============================================================================
 Name        : tp1.c
 Author      : Martin D. Sosa
 Version     :
 Copyright   : Your copyright notice
 Description :
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


    do
    {
        operacionElegida = MenuOpciones(numeroUno,numeroDos);
        switch(operacionElegida)
        {
            case 1:
                printf("Ingrese el primer numero ");
                scanf("%f",&numeroUno);
                break;
            case 2:
                printf("Ingrese el segundo numero ");
                scanf("%f",&numeroDos);
                break;
            case 3:
                printf("Calculando la SUMA de (%.2f + %.2f)\n",numeroUno,numeroDos);
                printf("Calculando la RESTA de (%.2f - %.2f)\n",numeroUno,numeroDos);
                printf("Calculando la MULTIPLICACION de (%.2f * %.2f)\n",numeroUno,numeroDos);
                printf("Calculando la DIVISION de (%.2f / %.2f)\n",numeroUno,numeroDos);
                printf("Calculando el factorial de (%.2f !)\n",numeroUno);
                printf("Calculando el factorial de (%.2f !)\n",numeroDos);

                system("pause");
                system("cls");
                break;
            case 4:
            {
                SumarNumeros(numeroUno,numeroDos);
                RestarNumeros(numeroUno,numeroDos);
                MultiplicarNumeros(numeroUno,numeroDos);
                DividirNumeros(numeroUno,numeroDos);
                Factorial(numeroUno);
                Factorial(numeroDos);
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

