#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID, jobType;
    float salary;
} Employee;

Employee * readEmployeeArray(FILE* fp);
int getSize(Employee * array);
void freeArray(void** array);
Employee * getEmployeeByID(Employee * array, int ID);
void setID(Employee *p, int ID);
int getID(Employee *p);
void setSalary(Employee *p, float salary);
float getSalary(Employee *p);
void setJobType(Employee *p, float salary);
float getJobType(Employee *p);

int main (void)
{
    FILE *File;

    Employee * employeeArray = readEmployeeArray(File);

    int TestID = getID(employeeArray);
    printf("Employee ID: %d\n", TestID);

    printf("Employee Salary: %.3f\n", getSalary(employeeArray + 2));
    setSalary(employeeArray + 1, 69.420);
    printf("Employee Salary: %.3f\n", getSalary(getEmployeeByID(employeeArray, 64)));

    freeArray((void*)&employeeArray);
    if (employeeArray == NULL) printf(":D");

    return 0;
}

//open file, read employee data, sort into array and close file
Employee * readEmployeeArray(FILE* fp)
{
    int totalEmployees;

    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("Error while opening file"); 
        return(0);
    }

    fscanf (fp, "%d", &totalEmployees);

    Employee * array = malloc(totalEmployees * sizeof(Employee));

    if(array == NULL)
    {
        printf("Failed to allocate memory.\n");
        return(0);
    }

    for(int i = 0; i < totalEmployees; i++)
    {
        fscanf (fp, "%d %d %f", &array[i].ID, &array[i].jobType, &array[i].salary);
    }

    fclose (fp);
    return array;
}

void freeArray(void** array)
{    
    free (*array);
    *array = NULL;
}

int getSize(Employee * array)
{
    return *((int*)array - 1);
}

//loop through array and check for matching ID #
Employee * getEmployeeByID(Employee * array, int ID)
{
    for(size_t i = 0; i < (getSize(array)); i++)
    {                
        if(array[i].ID == ID) 
        {
            return (array + i);
        }
    }
    printf("Error: ID not found in records.\n");
    return NULL;
}

void setID(Employee *p, int ID)
{
    p->ID = ID;
}
int getID(Employee *p)
{
    return p->ID;
}
void setSalary(Employee *p, float salary)
{
    p->salary = salary;
}
float getSalary(Employee *p)
{
    return p->salary;
}
void setJobType(Employee *p, float salary)
{
    p->salary = salary;
}
float getJobType(Employee *p)
{
    return p->salary;
}