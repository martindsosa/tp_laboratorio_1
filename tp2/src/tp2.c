/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define ELEMENTS 15

int main()
{
	setbuf(stdout,NULL);
    Employee arrayEmployees[ELEMENTS];

    InitEmployees(arrayEmployees,ELEMENTS);
    Harcodeo(arrayEmployees,ELEMENTS);
    OpcionMenu(arrayEmployees,ELEMENTS);

	return EXIT_SUCCESS;
}
