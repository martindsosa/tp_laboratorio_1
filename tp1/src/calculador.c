/*
 * calculador.c
 *
 *  Created on: 23 sep. 2021
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
    printf(" 5- Salir \n");
    scanf("%d",&opcion);
    return opcion;
}
/**\brief Suma dos numeros
*\param float primer numero
*\param float segundo numero
*\return float  resultado de la suma de dos numeros
**/
float SumarNumeros(float numeroUno,float numeroDos)
{
    float resultado;
    resultado = numeroUno + numeroDos;

    return resultado;
}
/**\brief Resta dos numeros
*\param float primer numero
*\param float segundo numero
*\return float  resultado de la resta de dos numeros
**/
float RestarNumeros(float numeroUno,float numeroDos)
{
    float resultado;
    resultado = numeroUno - numeroDos;

    return resultado;
}
/**\brief Multiplica dos numeros
*\param float primer numero
*\param float segundo numero
*\return float  resultado de la multiplicacion de dos numeros
**/
float MultiplicarNumeros(float numeroUno,float numeroDos)
{
    float resultado;
    resultado = numeroUno * numeroDos;

    return resultado;
}
/**\brief Divide dos numeros
*\param float primer numero
*\param float segundo numero
*\return float el resultado de la division de dos numeros
**/
float DividirNumeros(float numeroUno,float numeroDos)
{
    float resultado = -999999;
    if (numeroDos != 0)
    {
        resultado = numeroUno / numeroDos;
    }

    return resultado;
}
/**\brief Resolver el factorial de un numero
*\param float numero
*\return long int Devuelve el numero factoreado o -1-> si el numero es negativo.
**/
long int Factorial(float numero)
{
    int numeroEntero ;
    int i;
    long resultado = 1;

    numeroEntero = (int)numero;
    if(numeroEntero < 0)
    {
        resultado = -1;
    }
    else if (numeroEntero == 0)
    {
        resultado = 1;
    }
    else
    {
        for(i = 1; i <= numeroEntero; i++)
        {
            resultado *= i;
        }
    }
    return resultado;
}

