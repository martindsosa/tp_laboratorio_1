#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define ELEMENTS 1000
int main()
{
    //int i;
    int r;
    int index;
    int opcion;
    Employee arrayEmployees[ELEMENTS];

    r = initEmployees(arrayEmployees, ELEMENTS);

    do
    {
        printf ("\n1.Cargar un Empleado\n");
        printf ("2.Modicar un Empleado\n");
        printf ("3.Baja de un Empleado\n");
        printf ("4.Listado de Empleados por orden alfabetico y sector\n");
        printf ("5.SALIR\n");
        printf ("ELIJA UNA OPCION: ");
        scanf ("%d", &opcion);
        switch(opcion)
        {
            case 1:
                r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);
                break;
            case 2:
                index = findEmployeeById(arrayEmployees, ELEMENTS,9);
                break;
            case 3:
                r = removeEmployee(arrayEmployees, ELEMENTS,20);
                break;
            case 4:
                r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);
                r = printEmployees(arrayEmployees, ELEMENTS);
                break;
       }


    }while(opcion !=5);

    /*for(i=0;i<QTY_EMPLEADOS;i++)
    {
        printf("%8d %10s %10s %10f %d [%10d]\n"),listaDeAlumnos[i].id,
                                                 listaDeAlumnos[i].lastName,
                                                 listaDeAlumnos[i].name,
                                                 listaDeAlumnos[i].salary,
                                                 listaDeAlumnos[i].sector,
                                                 listaDeAlumnos[i].isEmpty;
    }*/
    return 0;
}
