/*
 * ArrayEmplooyees.c
 *
 *  Created on: 8 may. 2021
 *      Author: Martin Damian Sosa
 */
#include "ArrayEmployees.h"
#include "utn.h"
int EmployeeIdIncremental = 200;

int OpcionMenu(Employee* list,int len)
{
	int opcion;
	int auxId=0;
	char auxName[25];
	char auxLastName[25];
	int auxSalary=0;
	int auxSector=0;
	int encontroEmpleado;
	int id;
	int resp;
	int orden;
	do
	{
		printf("\nMENU ABM DE EMPLEADOS\n");
		printf("*********************\n");
		printf("	1. ALTA \n");
		printf("	2. MODIFICACION \n");
		printf("	3. BAJA\n");
		printf("	4. LISTADO ORDENADO POR EMPLEADO Y SECTOR\n");
		printf("	10. SALIR\n");
		printf("Elija una opcion : ");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				//ALTA
				resp = AddEmployee(list,len,auxId,auxName,auxLastName,auxSalary,auxSector)== 1;
				if(resp == 1)
				{
					printf(" * EMPLEADO DADO DE ALTA EXITOSAMENTE\n");
				}
				else
				{
					if(resp == 0)
					{
						printf(" * NO SE DIO DE ALTA EMPLEADO\n");
					}
					else
					{
						printf(" * ERROR!! SIN ESPACIO PARA DAR DE ALTA EMPLEADO\n");
					}
				}
			break;
			case 2:
				//MODIFICACION
				encontroEmpleado = PrintEmployees(list, len);
				if (encontroEmpleado == 1)
				{
					id = GetIntSinRango("\n\nIngrese IdEmpleado a MODIFICAR : ");
					if(ModifyEmployees(list, len, id)==1)
					{
						printf(" * EMPLEADO MODIFICADO !!!\n");
					}
					else
					{
						printf(" * NO SE PUDO REALIZAR MODIFICACION !!!\n");
					}
				}
				else
				{
					printf(" * NO HAY EMPLEADO DADOS DE ALTA !!!\n");
				}
			break;
			case 3:
				//BAJA
				encontroEmpleado = PrintEmployees(list, len);
				if (encontroEmpleado == 1)
				{
					id = GetIntSinRango("\n\nIngrese IdEmpleado a dar de Baja : ");
					if(RemoveEmployee(list, len, id)==1)
					{
						printf(" * EMPLEADO DADO DE BAJA !!!\n");
					}
					else
					{
						printf(" * NO SE PUDO REALIZAR LA BAJA !!!\n");
					}
				}
				else
				{
					printf(" * NO HAY EMPLEADO DADOS DE ALTA !!!\n");
				}
			break;
			case 4:
				printf("Ordenar la lista de EMPLEADOS\n");
				orden = GetInt("1.A-Z  2.Z-A ","Error! Numero fuera de rango.Reingrese ",1,2);
				if(SortEmployees(list, len, orden)==0)
				{
					PrintEmployees(list, len);
					PrintListTotal(list,len);
				}
				//TOTAL Y PROMEDIO DE SALARIOS
				//CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO
			break;
			case 10:
				printf("Gracias por usar el sistema de ABM \n\n");
			break;
			default:
				printf("Error, no existe esa opcion en menu \n\n");

		}
	}while(opcion!=10);

	return EXIT_SUCCESS;
}


/** \brief Inicializa el campo isEmpty de la estructura en 1(TRUE) para indicar que esta vacio.
* \param list Employee[]lista de empleados
* \param len int tamaño del Array
* \return int Return (-1) Si el puntero apunta a null o el largo es invalido,(0) si es OK
*
*/
int InitEmployees(Employee* list, int len)
{
    int i;
    int retorno = -1;

    if (list != NULL && len > 0)
    {
       for(i=0;i<len;i++)
       {
           list[i].isEmpty = LIBRE;
       }
       retorno = 0;
    }

    return retorno;
}

Employee EntryEmployee(int id,char name[],char lastName[],float salary,int sector)
{
	Employee myEmployee;
	myEmployee.id = id;
	GetString("Ingrese Nombre: ", "Error! Demasiado largo Reingrese: ",name, 25);
	strcpy(myEmployee.name,name);
	GetString("Ingrese Apellido: ", "Error! Demasiado largo Reingrese: ",lastName, 25);
	strcpy(myEmployee.lastName,lastName);
	myEmployee.salary = GetFloat("Ingrese Salario: ","Error! Salario Fuera de rango. Reingrese ", 0, 100000);
	myEmployee.sector = GetInt("Ingrese Sector: ", "Error! Sector Valido 1-10 Reingrese ",1, 10);

	return myEmployee;

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
int AddEmployee(Employee list[],int len,int id,char name[],char lastName[],float salary,int sector)
{

    int retorno = -1;
    int indice;
    char resp;

    indice = EmployeesGetIndexLibre(list,len);

    if (indice != -1)
    {
    	id = EmployeeGetID();
    	list[indice] = EntryEmployee(id,name,lastName,salary,sector);
    	resp = GetChar("Desea realizar el alta? ","Error Reingrese ",'s','n');
    	if(resp == 's')
    	{
    		list[indice].isEmpty = OCUPADO;
    		retorno = 1;
    	}
    	else
    	{
    		retorno = 0;
    	}
    }

	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
*			pointer received or employee not found]
*
*/
int FindEmployeeById(Employee* list, int len,int id)
{
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				return i;
			}
		}
	}
	return -1;
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
int RemoveEmployee(Employee* list, int len, int id)
{
	int index;
	int flagReintentos = 0;
	char resp;

	index = FindEmployeeById(list,len,id);
	if(index == -1)
	{
		while (index == -1 && flagReintentos < REINTENTOS)
		{
			PrintEmployees(list, len);
			id = GetIntSinRango("\nReingrese IdEmpleado a dar de Baja : ");
			index = FindEmployeeById(list,len,id);
			flagReintentos ++;
		}
	}
	if(index != -1)
	{
		resp = GetChar("Confirma la baja ? ","Respuesta erronea.Reingrese s o n ",'s','n');
		if(resp == 's')
		{
			list[index].isEmpty = LIBRE;
			return 1;
		}
	}
	return -1;
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
int SortEmployees(Employee* list, int len, int order)
{
	int i;
	int j;
	Employee auxEmpleado;

	if(list != NULL && len > 0)
	{
		if(order == 1)
		{
			for(i=0; i<len-1; i++)
			{
				for(j=i+1; j<len; j++)
				{
					if(strcmp(list[i].lastName,list[j].lastName)>0)
					{
						auxEmpleado = list[i];
						list[i] = list[j];
						list[j] = auxEmpleado;
					}
					else
					{
						if(strcmp(list[i].lastName,list[j].lastName)==0)
						{
							if(list[i].sector > list[j].sector)
							{
								auxEmpleado = list[i];
								list[i] = list[j];
								list[j] = auxEmpleado;
							}
						}
					}
				}
			}
		}
		else
		{
			for(i=0; i<len-1; i++)
			{
				for(j=i+1; j<len; j++)
				{
					if(strcmp(list[i].lastName,list[j].lastName)<0)
					{
						auxEmpleado = list[j];
						list[j] = list[i];
						list[i] = auxEmpleado;
					}
					else
					{
						if(strcmp(list[i].lastName,list[j].lastName)==0)
						{
							if(list[i].sector > list[j].sector)
							{
								auxEmpleado = list[i];
								list[i] = list[j];
								list[j] = auxEmpleado;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		return -1;
	}
	return 0;
}
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int 0 si no hay empleados 1 si hay empleados dados de alta
*
*/
int PrintEmployees(Employee* list, int length)
{
	int i;
	int existeUnEmpleado=0;

	if(list != NULL && length > 0)
	{
		printf("\n**  ID                 NOMBRE                   APELLIDO      SALARIO   NUM SECTOR **");
		printf("\n* --------------------------------------------------------------------------------- *\n");
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				printf("\n%5d -\t",list[i].id);
				printf("%20s  -\t",list[i].name);
				printf("%20s  -\t",list[i].lastName);
				printf("%10.2f -\t",list[i].salary);
				printf("%5d",list[i].sector);
				existeUnEmpleado = 1;
			}
		}
		return existeUnEmpleado;
	}
	return 0;
}

/**\brief obtener indice valido y libre
 *
 * @param list Employee
 * @param len int
 * @return retorno int  -1 si es NULL o largo invalido
 */
int EmployeesGetIndexLibre(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == LIBRE) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
/**\brief incrementa EmployeeIdIncremental en 1
 *
 * @return ID de empleado incrementado
 */
int EmployeeGetID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return EmployeeIdIncremental += 1;
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
int ModifyEmployees(Employee* list, int len, int id)
{
	int index;
	int flagReintentos = 0;
	char resp;
	Employee auxiliar;

	index = FindEmployeeById(list,len,id);
	if(index == -1)
	{
		while (index == -1 && flagReintentos < REINTENTOS)
		{
			PrintEmployees(list, len);
			id = GetIntSinRango("\nReingrese IdEmpleado a MODIFICAR : ");
			index = FindEmployeeById(list,len,id);
			flagReintentos ++;
		}
	}
	if(index != -1)
	{
		index = FindEmployeeById(list, len, id);
		auxiliar = EmployeeModifyOne(list[index]);
		resp = GetChar("Confirma la/s MODIFICACIONES ? ","Respuesta erronea.Reingrese s o n ",'s','n');
		if(resp == 's')
		{
			list[index] = auxiliar;
			//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
			return 1;
		}
	}
	return -1;
}
Employee EmployeeModifyOne(Employee list) {
	Employee auxiliar = list;
	int opcion;

	do
	{
		printf("\nSUBMENU MODIFICACION DE EMPLEADO\n");
		printf("********************************\n");
		printf("	1. NOMBRE \n");
		printf("	2. APELLIDO \n");
		printf("	3. SALARIO\n");
		printf("	4. SECTOR\n");
		printf("	10. SALIR\n");
		printf("Elija una opcion : ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				GetString("Ingrese nuevo NOMBRE: ","Fuera de rango.Reingrese ",auxiliar.name,51);
			break;
			case 2:
				GetString("Ingrese nuevo APELLIDO: ","Fuera de rango.Reingrese ",auxiliar.lastName,51);
			break;
			case 3:
				auxiliar.salary = GetFloat("Ingrese nuevo SALARIO: ","Fuera de RANGO.Reingrese ",0,100000);
			break;
			case 4:
				auxiliar.sector = GetInt("Ingrese nuevo SECTOR: ","Fuera de RANGO.Reingrese ",1,10);
			break;
			case 10:
				printf("Gracias por usar el subsistema de MODIFICACIONES \n\n");
			break;
			default:
				printf("Error, no existe esa opcion en menu \n\n");
		}
	}while(opcion!=10);

	return auxiliar;
}
void PrintListTotal(Employee* list,int len)
{
	int i;
	float totalSalarios = 0;
	int cantidadEmpleados = 0;
	float salarioPromedio;
	int cantidadSalariosMayorPromedio = 0;

	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				totalSalarios += list[i].salary;
				cantidadEmpleados++;
			}
		}
		salarioPromedio = totalSalarios/cantidadEmpleados;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].salary>salarioPromedio)
			{
				cantidadSalariosMayorPromedio++;
			}
		}
		printf("\n* --------------------------------------------------------------------------------- *\n");
		printf("						TOTAL DE SALARIOS   $\t %.2f \n",totalSalarios);
		printf("						SALARIO PROMEDIO    $\t %.2f \n",salarioPromedio);
		printf(" Cantidad de empleados que superan el promedio:  %d ",cantidadSalariosMayorPromedio);
		printf("\n* --------------------------------------------------------------------------------- *\n");
	}
}

void Harcodeo(Employee* list,int len)
{
	int id[10]= {100,101,102,103,104,105,106,107,108,109};
	char name[10][10]={"carlos","raul","roberto","martin","jose","carla","sandra","lorena","sabrina","pedro"};
	char lastname[10][10]={"sosa","soria","sosa","rodriguez","carrera","veliz","sosa","fernandez","gonzalez","pereira"};
	float salario[10]={123.45,200,1400.20,460.50,600,723.10,360.20,700.50,810.50,1000};
	int sector[10]={1,3,2,4,4,7,9,2,10,2};
	int estado[10]={0,0,0,0,0,0,0,0,0,0};

    for(int i=0; i<len; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastname[i]);
        list[i].salary = salario[i];
        list[i].sector = sector[i];
        list[i].isEmpty = estado[i];
    }


}
