/*
 * ArrayEmployees.h
 *
 *  Created on: 8 may. 2021
 *      Author: Martin Damian Sosa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define OCUPADO 0
#define LIBRE 1
#define REINTENTOS 3

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int OpcionMenu(Employee*,int);
int InitEmployees(Employee*,int);

int AddEmployee(Employee*,int,int,char[],char[],float,int);
int FindEmployeeById(Employee*, int,int);
int RemoveEmployee(Employee*, int, int);
int SortEmployees(Employee*, int, int);
int PrintEmployees(Employee*, int);
int EmployeesGetIndexLibre(Employee*, int);
int EmployeeGetID();
Employee EntryEmployee(int, char[], char[], float, int);
int ModifyEmployees(Employee* , int, int);
Employee EmployeeModifyOne(Employee );
void PrintListTotal(Employee* list,int);
void Harcodeo(Employee* list,int len);

#endif /* ARRAYEMPLOYEES_H_ */
