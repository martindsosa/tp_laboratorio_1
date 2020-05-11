#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define QTY_EMPLEADOS 1000
int main()
{
    //int i;
    int respuesta;
    Employee listaDeEmpleados[QTY_EMPLEADOS];

    respuesta = initEmployees(listaDeEmpleados,QTY_EMPLEADOS);
    respuesta = addEmployee(listaDeEmpleados, QTY_EMPLEADOS,id,name,lastName,salary,sector);

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
