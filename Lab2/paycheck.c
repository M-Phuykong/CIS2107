// Phuykong Meng, 2023-01-30, CIS2107
// Lab 02 Paycheck
//
// Write a C program called paycheck to calculate the paycheck for a Temple 
// employee based on the hourlySalary, weeklyTime (working for maximum 40 
// hours) and overtime (working for more than 40 hours). 

// import headers
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// main function
//
int main(int argc, char** argv){

    // variable declaration
    //
    int hourly_salary;
    int weekly_time;
    int regular_pay;
    float overtime_pay;
    float net_pay;
    double employee_number;
    double fract_part;
    double int_part;

    // print welcome message
    //
    puts("Welcome to \"TEMPLE HUMAN RESOURCES\"");
    puts("");

    // get user input for employee number
    //
    printf("%s" , "\tEnter Employee Number: ");
    scanf("%lf", &employee_number);
    
    // if employee number is less than 0 or a float, exit
    //
    fract_part = modf(employee_number, &int_part);
    if (int_part < 0 || fract_part > 0){
        puts("\n\tThis is not a valid Employee Number.");
        puts("\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }

    // get user input for hourly salary
    //
    printf("%s" , "\tEnter Hourly Salary: ");
    scanf("%d", &hourly_salary);

    // if hourly salary is less than 0, exit
    //
    if (hourly_salary < 0){
        puts("\n\tThis is not a valid hourly salary amount.");
        puts("\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }

    // get user input for weekly time
    //
    printf("%s" , "\tEnter Weekly Time: ");
    scanf("%d", &weekly_time);
    
    // if weekly time is less than 0, exit
    //
    if (weekly_time < 0){
        puts("\n\tThis is not a weekly time.");
        puts("\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }

    // if there's an overtime
    //
    if (weekly_time > 40){
        regular_pay = hourly_salary * 40;
        overtime_pay = (weekly_time - 40) * 1.5 * (float)hourly_salary;
    }
    // no overtime
    //
    else {
        regular_pay = weekly_time * hourly_salary;
    }
    // end if
    
    // calculate net_pay
    //
    net_pay = regular_pay + overtime_pay;

    // print the employee information
    //
    puts("\t==============================");
    printf("\tEmployee #: %d\n", (int)employee_number);
    printf("\tHourly Salary: $%.1f\n", (float)hourly_salary);
    printf("\tWeekly Time: %.1f\n", (float)weekly_time);
    printf("\tRegular Pay: $%.1f\n", (float)regular_pay);
    printf("\tOvertime Pay: $%.1f\n", overtime_pay);
    printf("\tNet Pay: $%.1f\n", net_pay);
    puts("\t==============================");

    puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");

    // exit successfully
    //
    exit(0);
}

