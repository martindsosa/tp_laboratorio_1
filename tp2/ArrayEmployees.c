#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

/** \brief Inicializa el campo isEmpty de la estructura en 1(TRUE) para idicar que esta vacio.
* \param list Employee[]lista de empleados
* \param len int tamaño del Array
* \return int Return (-1) Si el puntero apunta a null o el largo es invalido,(0) si es OK
*
*/
int initEmployees(Employee list[], int len)
{
    int i;
    int retorno = -1;
    if (len > 0)
    {
       for(i=0;i<len;i++)
       {
           list[i].isEmpty = LIBRE;
       }
       retorno = 0;
    }
    return retorno;
}
/** \brief Agrega a una lista ya existente los valores recibidos por parametro
* en la primer posicion vacia
* \param list employee[] lista de empleados
* \param len int tamaño de la lista
* \param id int identificacion del empleado
* \param name[] char nombre del empleado
* \param lastName[] char apellido del empleado
* \param salary float sueldo del empleado
* \param sector int sector
* \return
*/
int addEmployee(Employee list[],int len,int id,char name[],
                char lastName[],float salary,int sector)
{
    int retorno = -1;
    int encontro;

    Employee myEmployee;

    printf("Ingrese Nombre: ");

    fflush(stdin);
    fgets(name,25,stdin);
    name[strlen(name)-1]='\0';

    printf("Ingrese Apellido: ");
    fflush(stdin);
    fgets(lastName,25,stdin);
    lastName[strlen(lastName)-1]='\0';
    salary = getInt("Ingrese salario: ","El salario esta fuera de rango. Reingrese : ",0,100000 );
    sector = getInt("Ingrese sector: ","No existe ese sector. Reingrese : ",1,10);
    encontro = findFreeEmployee(list,len);
    if(encontro!=-1)
    {
        retorno = 0;
        id = encontro +1;
        myEmployee.id = id;
        strcpy(myEmployee.name,name);
        strcpy(myEmployee.lastName,lastName);
        myEmployee.salary = salary;
        myEmployee.sector = sector;
        myEmployee.isEmpty = OCUPADO;

        list[encontro] = myEmployee;
    }

    return retorno;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    int auxId;
    int i;
    int encontro;
    int reintentos = 0;

    printEmployees(list,len);
    printf("Ingrese el ID Empleado: ");
    scanf("%d", &auxId);
    do
    {
        for(i=0;i<len; i++)
        {
            if(list[i].isEmpty == OCUPADO && auxId == list[i].id)
            {
                encontro = 1;
                list[i].isEmpty = LIBRE;
            }
        }
        if (encontro!=1)
        {
            reintentos++;
            printEmployees(list,len);
            printf("Error ! No se encontro Id Empleado, Reingrese: ");
            scanf("%d",&auxId);
        }

    }while(encontro != 1 || reintentos == 2);
return encontro;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{

return 0;
//return NULL;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployeesByName(Employee* list, int len, int order)
{

return 0;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
    int i;
    char flagHayEmpleados;
    printf("%8s %51s %51s %12s  %5s\n","Id","Apellido","Nombre","Salario","[Sector]\n");
    for(i=0;i<length;i++)
    {
        if (list[i].isEmpty == OCUPADO)
        {
            flagHayEmpleados = 's';
            printf("%6d %51s %51s %12.2f   [ %d ]\n",list[i].id,list[i].lastName
                                                  ,list[i].name,list[i].salary
                                                  ,list[i].sector);
        }
    }
    if(flagHayEmpleados !='s')
    {
        printf("No hay empleado dado de alta!!! \n");

    }
return 0;
}

int findFreeEmployee(Employee* list, int sizeEmployee)
{
    int i;
    int index = -1;
    for(i=0; i<sizeEmployee; i++)
    {
        if(list[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
