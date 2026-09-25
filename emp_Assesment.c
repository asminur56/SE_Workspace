#include <stdio.h>

struct Employee 
{
    int id;
    char name[50];
    float basicSalary;
};

/* Function to calculate salary after 10% bonus */
float calculateSalary(float basicSalary) 
{
    return basicSalary + (basicSalary * 0.10);
}

int main() 
{
    struct Employee emp[5];
    FILE *file;
    int i;

    /* Accept details of 5 employees */
    printf("Enter details of 5 employees:\n");

    for (i = 0; i < 5; i++) {
        printf("\nEmployee %d\n", i + 1);

        printf("Enter Employee ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Enter Basic Salary: ");
        scanf("%f", &emp[i].basicSalary);
    }

    /* Display employee details with final salary */
    printf("\n========== Employee Details ==========\n");

    for (i = 0; i < 5; i++) {
        printf("\nEmployee ID   : %d", emp[i].id);
        printf("\nName          : %s", emp[i].name);
        printf("\nBasic Salary  : %.2f", emp[i].basicSalary);
        printf("\nFinal Salary  : %.2f\n", calculateSalary(emp[i].basicSalary));
    }

    /* Store employee details in employee.txt */
    file = fopen("employee.txt", "w");

    if (file == NULL) {
        printf("\nError opening file!\n");
        return 1;
    }

    for (i = 0; i < 5; i++) 
	{
        fprintf(file, "%d|%s|%.2f|%.2f\n",
                emp[i].id,
                emp[i].name,
                emp[i].basicSalary,
                calculateSalary(emp[i].basicSalary));
    }

    fclose(file);

    printf("\nEmployee details successfully stored in employee.txt\n");

    /* Read and display information from file */
    file = fopen("employee.txt", "r");

    if (file == NULL) 
   {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\n========== Information From File ==========\n");

    int id;
    char name[50];
    float basicSalary, finalSalary;

    while (fscanf(file, "%d|%49[^|]|%f|%f", &id, name, &basicSalary, &finalSalary) == 4) 
	{

        printf("\nEmployee ID   : %d", id);
        printf("\nName          : %s", name);
        printf("\nBasic Salary  : %.2f", basicSalary);
        printf("\nFinal Salary  : %.2f\n", finalSalary);
    }

    fclose(file);

    return 0;
}