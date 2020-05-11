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
