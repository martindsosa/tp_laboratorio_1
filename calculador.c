#include <stdio.h>
#include <stdlib.h>
#include "calculador.h"

/**\brief Solicita dos numeros y llama a las funciones que hacen los calculos correspondientes.
*\return int
**/
int menuOpciones()
{
    float numeroUno=0;
    float numeroDos=0;
    int operacionElegida;
    do
    {
        printf(" 1- Ingrese el primer numero (A = %2.f) \n",numeroUno);
        printf(" 2- Ingrese el segundo numero (B = %2.f) \n",numeroDos);
        printf(" 3- Calcular las operaciones \n");
        printf(" 4- Informar todos los resultados \n");
        printf(" 5- Salir \n\n");
        scanf("%d",&operacionElegida);
        system("cls");

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
                printf("Calculando la suma de (%.2f + %.2f)\n",numeroUno,numeroDos);
                printf("Calculando la resta de (%.2f - %.2f)\n",numeroUno,numeroDos);
                printf("Calculando la multiplicacion de (%.2f * %.2f)\n",numeroUno,numeroDos);
                printf("Calculando la suma de (%.2f / %.2f)\n",numeroUno,numeroDos);
                printf("Calculando el factorial de (%.2f !)\n",numeroUno);
                printf("Calculando el factorial de (%.2f !)\n",numeroDos);

                system("pause");
                system("cls");
                break;
            case 4:
            {
                suma(numeroUno,numeroDos);
                resta(numeroUno,numeroDos);
                multiplicacion(numeroUno,numeroDos);
                division(numeroUno,numeroDos);
                factorial(numeroUno);
                factorial(numeroDos);
                system("pause");
                system("cls");
                break;
            }
            case 5:
                break;
            default:
                printf("Error, no existe esa opcion en menu \n\n");
        }

    }while(operacionElegida != 5);

    return 0;
}
/**\brief Suma dos numeros
*\param float primer numero
*\param float segundo numero
*\return int  resultado de la suma de dos numeros
**/
int suma(float numeroUno,float numeroDos)
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
int resta(float numeroUno,float numeroDos)
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
int multiplicacion(float numeroUno,float numeroDos)
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
int division(float numeroUno,float numeroDos)
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
int factorial(float numero)
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
