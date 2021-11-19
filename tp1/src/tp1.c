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
    float resultadoSuma;
    float resultadoResta;
    float resultadoMulti;
    float resultadoDivision;
    long int resultadoFactorialUno;
    long int resultadoFactorialDos;
    int numeroUnoInt;
    int numeroDosInt;
    int operacionElegida;
    int flagCalculo = -1;

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
            	if (numeroUno != 0 || numeroDos != 0){
            		printf("Calculando la SUMA de (%.2f + %.2f)\n",numeroUno,numeroDos);
					printf("Calculando la RESTA de (%.2f - %.2f)\n",numeroUno,numeroDos);
					printf("Calculando la MULTIPLICACION de (%.2f * %.2f)\n",numeroUno,numeroDos);
					printf("Calculando la DIVISION de (%.2f / %.2f)\n",numeroUno,numeroDos);
					printf("Calculando el factorial de (%.2f !)\n",numeroUno);
					printf("Calculando el factorial de (%.2f !)\n",numeroDos);
					resultadoSuma = SumarNumeros(numeroUno,numeroDos);
					resultadoResta = RestarNumeros(numeroUno,numeroDos);
					resultadoMulti = MultiplicarNumeros(numeroUno,numeroDos);
					resultadoDivision = DividirNumeros(numeroUno,numeroDos);
					resultadoFactorialUno = Factorial(numeroUno);
					resultadoFactorialDos = Factorial(numeroDos);
					flagCalculo = 0;
            	}
            	else{
            		printf ("Para realizar los calculos uno de los operandos debe ser distinto de cero !!!\n");
            	}
                break;
            case 4:
            {
            	if (numeroUno != 0 || numeroDos != 0){
            		if (flagCalculo == 0){
						flagCalculo = -1;
            			printf("El resultado de la suma es: %.2f \n",resultadoSuma);
						printf("El resultado de la resta es: %.2f \n",resultadoResta);
						printf("El resultado de la multiplicacion es: %.2f \n",resultadoMulti);
						if (resultadoDivision != -999999){
							printf("El resultado de la division es: %.2f \n",resultadoDivision);
						}
						else
						{
							printf("El divisor no puede ser 0 \n");
						}
						if (resultadoFactorialUno == -1){
							printf("%.2f, no se puede factorear por ser un numero NEGATIVO \n",numeroUno);
						}
						else{
							numeroUnoInt = (int)numeroUno;
							printf("El factorial de %d es %ld \n",numeroUnoInt,resultadoFactorialUno);
						}
						if (resultadoFactorialDos == -1){
							printf("%.2f, no se puede factorear por ser un numero NEGATIVO \n",numeroDos);
						}
						else{
							numeroDosInt = (int)numeroDos;
							printf("El factorial de %d es %ld \n",numeroDosInt,resultadoFactorialDos);
						}
            		}
            		else{
            			printf("Para informar los calculos primero debe calcularlos (opcion3)\n");
            		}
            	}
            	else{
            		printf ("Para informar calculos primero debe ingresar operandos !!!\n");
            	}
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

