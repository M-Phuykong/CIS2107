// Phuykong Meng, 2023-01-30, CIS2107
// Lab 02 Paycheck
//
// Write a C program called paycheck to calculate the paycheck for a Temple 
// employee based on the hourlySalary, weeklyTime (working for maximum 40 
// hours) and overtime (working for more than 40 hours). 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    int employee_number;
    int hourly_salary;
    int weekly_time;

    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n");

    printf("Enter Employee Number: ");
    scanf("%d", &employee_number);

    printf("Enter Hourly Salary: ");
    scanf("%d", &hourly_salary);

    printf("Enter Weekly Time: ");
    scanf("%d", &weekly_time);

    printf("%d, %d, %d\n", employee_number, hourly_salary, weekly_time);


}