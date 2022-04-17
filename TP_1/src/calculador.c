/*
 * calculador.c
 *
 *  Created on: 16 abr. 2022
 *      Author: martindamian
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculador.h"

/**\brief Menu de opciones
*\param float primer numero
*\param float segundo numero
*\return int devuelve la opcion elegida
**/
int MenuOpciones(float numeroUno,float numeroDos)
{
    int opcion;
    printf("\t\t MENU DE OPCIONES\n");
    printf("\t\t ----------------\n");
    printf(" 1- Ingrese el primer numero (A = %2.f) \n",numeroUno);
    printf(" 2- Ingrese el segundo numero (B = %2.f) \n",numeroDos);
    printf(" 3- Calcular las operaciones \n");
    printf(" 4- Informar todos los resultados \n");
    printf(" 5- Salir \n\n");
    scanf("%d",&opcion);
    system("cls");
    return opcion;
}
/**\brief Suma dos numeros
*\param float primer numero
*\param float segundo numero
*\return int  resultado de la suma de dos numeros
**/
int SumarNumeros(float numeroUno,float numeroDos)
{
    float resultado;
    resultado = numeroUno + numeroDos;
    printf("El resultado de la suma es: %.2f \n",resultado);
    return 0;
}
/**\brief Resta dos numeros
*\param float primer numero
*\param float segundo numero
*\return int  resultado de la resta de dos numeros
**/
int RestarNumeros(float numeroUno,float numeroDos)
{
    float resultado;
    resultado = numeroUno - numeroDos;
    printf("El resultado de la resta es: %.2f \n",resultado);
    return 0;
}
/**\brief Multiplica dos numeros
*\param float primer numero
*\param float segundo numero
*\return int  resultado de la multiplicacion de dos numeros
**/
int MultiplicarNumeros(float numeroUno,float numeroDos)
{
    float resultado;
    resultado = numeroUno * numeroDos;
    printf("El resultado de la multiplicacion es: %.2f \n",resultado);
    return 0;
}
/**\brief Divide dos numeros
*\param float primer numero
*\param float segundo numero
*\return int el resultado de la division de dos numeros
**/
int DividirNumeros(float numeroUno,float numeroDos)
{
    int retorno = -1;
    float resultado;
    if (numeroDos != 0)
    {
        resultado = numeroUno / numeroDos;
        retorno = 0;
        printf("El resultado de la division es: %.2f \n",resultado);
    }
    else
    {
        printf("El divisor no puede ser 0 \n");
    }
    return retorno;
}
/**\brief Resolver el factorial de un numero
*\param float numero
*\return int Devuelve si se puedo resolver el factorial
**/
int Factorial(float numero)
{
    int retorno = -1;
    int numeroUnoEntero = (int)numero;
    long resultado = 1;
    if(numeroUnoEntero < 0)
    {
        printf("%d, no se puede factorear por ser un numero NEGATIVO \n",numeroUnoEntero);
    }
    else if (numeroUnoEntero == 0)
    {
        resultado = 1;
        retorno = 0;
    }
    else
    {
        int i;
        for(i = 1; i <= numeroUnoEntero; i++)
        {
            resultado *= i;
        }
        retorno = 0;
    }
    if(retorno!=-1){
        printf("El factorial de %d es %ld \n",numeroUnoEntero,resultado);
    }

    return retorno;
}
