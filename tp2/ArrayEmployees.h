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
int findEmployeeById(Employees[],int,int);
int removeEmployee(Employee*,int,int);
int sortEmployees(Employee*,int,int);
int printEmployees(Employee*,int);
