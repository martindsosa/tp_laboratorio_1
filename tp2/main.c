#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define ELEMENTS 1000
int main()
{
    int r;
    int index;
    int id;
    char name[51];
    char lastName[51];
    int salary=0;
    int sector=0;
    int opcion;
    Employee arrayEmployees[ELEMENTS];

    r = initEmployees(arrayEmployees, ELEMENTS);

    do
    {
        printf("+++++++++ M E N U   P R I N C I P A L++++++++++++++\n\n");
        printf ("*1.Cargar un Empleado\n");
        printf ("*2.Modicar un Empleado\n");
        printf ("*3.Baja de un Empleado\n");
        printf ("*4.Listado de Empleados por orden alfabetico y sector\n");
        printf ("*5.SALIR\n");
        printf ("ELIJA UNA OPCION: ");
        scanf ("%d", &opcion);
        switch(opcion)
        {
            case 1:
                r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);
                if (r == 0)
                {
                    printf("Se dio de ALTA el empleado con EXITO !! \n");
                }
                else
                {
                    printf("No hay ESPACIO para cargar un nuevo empleado \n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                index = findEmployeeById(arrayEmployees, ELEMENTS,9);
                break;
            case 3:
                r = removeEmployee(arrayEmployees, ELEMENTS,20);
                if (r== 1)
                {
                    printf("\nPRODUCTO ELIMINADO !!!\n");
                }
                else
                {
                    printf("\nNo se realizo baja...\n");
                }
                break;
            case 4:
                system("cls");
                r = sortEmployeesByName(arrayEmployees, ELEMENTS, 1);
                r = printEmployees(arrayEmployees, ELEMENTS);
                system("pause");
                system("cls");

                break;
       }
    }while(opcion !=5);

    return 0;
}
