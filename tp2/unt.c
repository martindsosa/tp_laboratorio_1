#include <stdio.h>
#include "utn.h"
#include <ctype.h>
/** \brief RECIBE UN ENTERO Y CONTROLA QUE ESTE DENTRO DE UN RANGO
 *
 * \param CHAR LABEL MENSAJE PARA PEDIR EL NUMERO
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param INT MIN NUMERO MINIMO DENTRO DEL RANGO
 * \param INT MAX NUMERO MAXIMO DENTRO DEL RANGO
 * \return INT NUMERO DENTRO DEL RANGO
 *
 */

int getInt(char label[],char mensajeError[],int min,int max)
{
    int numero;
    printf ("%s",label);

    fflush(stdin);
    scanf("%d",&numero);
    while(numero<min || numero>max)
    {
        printf ("%s",mensajeError);
        fflush(stdin);
        scanf("%d",&numero);

    }
    return numero;

}
/** \brief RECIBE UN FLOAT Y CONTROLA QUE ESTE DENTRO DE UN RANGO
 *
 * \param CHAR LABEL MENSAJE PARA PEDIR EL NUMERO
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param FLOAT MIN NUMERO MINIMO DENTRO DEL RANGO
 * \param FLOAT MAX NUMERO MAXIMO DENTRO DEL RANGO
 * \return FLOAT NUMERO DENTRO DEL RANGO
 *
 */

float getFloat(char label[],char mensajeError[],float min,float max)
{
    float numero;
    printf ("%s",label);
    scanf("%f",&numero);
    while(numero<min || numero>max)
    {
        printf ("%s",mensajeError);
        scanf("%f",&numero);
    }
    return numero;

}
/** \brief RECIBE UN CHAR Y CONTROLA QUE SEA UNA U OTRA RESPUESTA
 *
 * \param CHAR LABEL MENSAJE PARA PEDIR EL CHAR
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param CHAR RESPUESTA1 UNA RESPUESTA ACEPTADA
 * \param CHAR RESPUESTA2 OTRA RESPUESTA ACEPTADA
 * \return CHAR CARACTER LETRA QUE RESPONDIO
 *
 */
char getCharSiNo(char label[],char mensajeError[],char respuesta1,char respuesta2)
{
    char caracter;
    printf ("%s",label);
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
 * \param LABEL MENSAJE PARA PEDIR EL DATO
 * \param MENSAJEERROR MENSAJE DE ERROR
 * \return DEVUELVE 0 SI ES IMPAR
 *         DEVUELVE 1 SI ES PAR
 */
int esPar(char label[],char mensajeError[])
{
    int resultado = 0;
    int numero;
    printf("%s",label);
    scanf("%d",&numero);
    if(numero%2 == 0)
    {
        resultado = 1;
    }
    return resultado;
}

char getNuevoChar(char label[],char mensajeError[],char minimo,char maximo)
{
    char caracter;
    printf("%s",label);
    fflush(stdin);
    scanf("%c",&caracter);
    while(caracter<minimo || caracter>maximo)
    {
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%c",&caracter);

    }
    return caracter;
}
