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
           list[i].isEmpty = 1;
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
    int auxId;
    char auxName[];
    char auxLastName[];
    float auxSalary;
    int auxSector;
    getInt("Ingrese ID: ","ERROR, el ID NO PUEDE SER NEGATIVO",0,1000);
    //printf("Ingrese id: ");
    //scanf("%d",&auxId);

    printf("Ingrese Nombre: ");
    __fpurge(stdin);
    fgets(auxName,25,stdin);
    auxName[strlen(auxName)-1]='\0';
    printf("Ingrese Apellido: ");
    __fpurge(stdin);
    fgets(auxLastName,25,stdin);
    auxLastName[strlen(auxLastName)-1]='\0';
    __fpurge(stdin);
    printf("Ingrese Salario: ");
    scanf("%f",&auxSalary);
    printf("Ingrese Sector: ");
    scanf("%d",&auxSector);

    //falta cargar el estado
    encontro = buscarLibre(list,len);
    if(encontro!=-1)
    {
        retorno = 0;
        //list[encontro] = cargarUnAlumno();
    }
    else
    {
        printf("No hay espacio");
    }

    return retorno;
}
