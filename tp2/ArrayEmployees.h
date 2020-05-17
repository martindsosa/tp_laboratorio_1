#define LIBRE 0
#define OCUPADO 1


struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

int initEmployees(Employee[],int);

int addEmployee(Employee[],int,int,char[],char[],float,int);
int addAnEmployee();
int findEmployeeById(Employee[],int,int);
int removeEmployee(Employee*,int,int);
int sortEmployeesByName(Employee*,int,int);
int printEmployees(Employee*,int);
int findFreeEmployee(Employee*, int);
