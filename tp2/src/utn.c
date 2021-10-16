/*
 * utn.c
 *
 *  Created on: 16 oct. 2021
 *      Author: martindamian
 */


/*
 * utn.c
 *
 *  Created on: 9 may. 2021
 *      Author: Martin Damian Sosa
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/** \brief RECIBE UN ENTERO Y CONTROLA QUE ESTE DENTRO DE UN RANGO
 *
 * \param CHAR MENSAJE PARA PEDIR EL NUMERO
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param INT MIN NUMERO MINIMO DENTRO DEL RANGO
 * \param INT MAX NUMERO MAXIMO DENTRO DEL RANGO
 * \return INT NUMERO DENTRO DEL RANGO
 *
 */

int GetInt(char mensaje[],char mensajeError[],int min,int max)
{
    int numero;
    printf ("%s",mensaje);
    scanf("%d",&numero);
    //__fpurge(stdin);
    fflush(stdin);
    while(numero<min || numero>max)
    {
        printf ("%s",mensajeError);
        scanf("%d",&numero);
        //__fpurge(stdin);
        fflush(stdin);

    }
    return numero;

}
/** \brief RECIBE UN ENTERO MENSAJE Y LO DEVUELVE
 *
 * \param CHAR MENSAJE PARA PEDIR EL NUMERO
 * \param
 * \param
 * \param
 * \return INT NUMERO DENTRO DEL RANGO
 *
 */

int GetIntSinRango(char mensaje[])
{
    int numero;
    printf ("%s",mensaje);
    scanf("%d",&numero);
    fflush(stdin);

    return numero;
}

/** \brief RECIBE UN FLOAT Y CONTROLA QUE ESTE DENTRO DE UN RANGO
 *
 * \param CHAR MENSAJE PARA PEDIR EL NUMERO
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param FLOAT MIN NUMERO MINIMO DENTRO DEL RANGO
 * \param FLOAT MAX NUMERO MAXIMO DENTRO DEL RANGO
 * \return FLOAT NUMERO DENTRO DEL RANGO
 *
 */

float GetFloat(char mensaje[],char mensajeError[],float min,float max)
{
    float numero;
    printf ("%s",mensaje);
    scanf("%f",&numero);
    fflush(stdin);
    while(numero<min || numero>max)
    {
        printf ("%s",mensajeError);
        scanf("%f",&numero);
        fflush(stdin);
    }
    return numero;

}
/** \brief RECIBE UN CHAR Y CONTROLA QUE SEA UNA U OTRA RESPUESTA
 *
 * \param CHAR MENSAJE PARA PEDIR EL CHAR
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param CHAR RESPUESTA1 UNA RESPUESTA ACEPTADA
 * \param CHAR RESPUESTA2 OTRA RESPUESTA ACEPTADA
 * \return CHAR CARACTER LETRA QUE RESPONDIO
 *
 */


char GetChar(char mensaje[],char mensajeError[],char respuesta1,char respuesta2)
{
    char caracter;
    printf ("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);

    caracter = tolower(caracter);
    while(caracter!= respuesta1 && caracter != respuesta2)
    {
        printf ("%s",mensajeError);
        fflush(stdin);
        scanf("%c",&caracter);

    }
    return caracter;
}
/** \brief LA FUNCION DETERMINA SI EL NUMERO ES PAR O IMPAR
 *
 * \param MENSAJE PARA PEDIR EL DATO
 * \param MENSAJEERROR MENSAJE DE ERROR
 * \return DEVUELVE 0 SI ES IMPAR
 *         DEVUELVE 1 SI ES PAR
 */
int EsPar(char mensaje[],char mensajeError[])
{
    int resultado = 0;
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    if(numero%2 == 0)
    {
        resultado = 1;
    }
    return resultado;
}
/** \brief Factorial de un numero
 *
 * \param CHAR MENSAJE DE ERROR
 * \param INT NUMPARAFACTOREAR NUMERO PARA FACTOREAR
 * \return DEVUELVE EL NUMERO FACTORIADO O -1 SI EL NUMERO NO SE PUEDE FACTOREAR
 *
 */

int GetFactorial(char mensajeError[],int numParaFactorear){
    long resultado = 1;
    int i;
    if(numParaFactorear < 0)
    {

        printf("%s",mensajeError);
        resultado = -1;
    }
    else if (numParaFactorear == 0){
        resultado = 1;
    }else{
        for(i = 1; i <= numParaFactorear; i++)
        {
            resultado *= i;
        }
    }
    return resultado;
}
/** \brief INGRESO DE UNA CADENA DE CHAR
 * \param CHAR MENSAJE PARA PEDIR EL CADENA
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 *
 */
void GetString(char mensaje[],char mensajeError[],char cadena[],int lenCadena)
{
		printf("%s",mensaje);
	    fflush(stdin);
	    scanf("%[^\n]",cadena);
	    while(strlen(cadena)>lenCadena)
	    {
	    	printf("%s",mensajeError);
	    	fflush(stdin);
	    	scanf("%[^\n]",cadena);
	    }
}
