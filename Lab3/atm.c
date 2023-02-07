// Phuykong Meng, 2023-02-06, CIS2107
// Lab 03 ATM Machine
//
// Write a C Program for an ATM machine.
//
// The types of ATM transaction are:
// 1. Balance.
// 2. Cash withdrawal.
// 3. Cash deposition.
// 4. Quit.

// import header
//
#include <stdio.h>
#include <stdlib.h>

// function prototype
//
int cash_deposition(int*, int*);
int cash_withdrawal(int*, int*);
int check_balance(int*);
int print_receipt();

// main function
//
int main(int argc, char **argv) {

    // default PIN
    //
    const int PIN = 3014;

    // initialize local variable
    //
    int balance = 5000;
    int counter = 3;
    int input = 0;
    int total_deposit = 0;
    int total_withdrawal = 0;

    // welcome message
    //
    puts("\t===== Welcome to CIS2107 ATM Machine =====");
    puts("");

    // validate the money amount
    //
    do {
        printf("Please Validate Your Balance By Entering the Amount (Attempts Left: %d):\n",
                counter);
        scanf("%d", &input);
        counter--;

    // check to see if the user try 3 times already or if the input is valid
    // (not negative and equal the amount)
    //
    } while (counter > 0 &&
        (input <= 0 ||
        input != balance));

    // if user used up all their attempts, we exit with an exception
    //
    if (counter < 0){
        puts("The max amount of attempts has been reached."
            "Balance does not match.\n");
        exit(1);
    }
    puts("");

    // reset counter
    //
    counter = 3;

    // validate the PIN number
    //
    do
    {
        printf("Please Validate Your PIN (Attempts Left: %d):\n",
            counter);
        scanf("%d", &input);
        counter--;

    // check to see if the user try 3 times already or if the input is valid
    // (not negative and equal the amount)
    //
    } while (counter > 0 &&
            (input <= 0 ||
            input != PIN));

    if (counter < 0)
    {
        puts("The max amount of attempts has been reached."
            "Balance does not match.\n");
        exit(1);
    }
    puts("");

    // print the menu before we let the user choose the option
    //
    do {
        puts("Please Select an Option");
        puts("1: Balance.");
        puts("2. Cash withdrawal.");
        puts("3. Cash deposition.");
        puts("4. Quit.\n");

        // get the input
        //
        scanf("%d", &input);

        // switch condition for the options
        //
        switch (input) {

            // check the balance
            //
            case 1:
                check_balance(&balance);
                break;

            // cash Withdrawal
            //
            case 2:
                cash_withdrawal(&balance, &total_withdrawal);
                break;

            // cash Deposit
            //
            case 3:
                cash_deposition(&balance, &total_deposit);
                break;

            // quit
            //
            case 4:
                break;

            // not a valid option
            //
            default:
                puts("Please pick a valid option");
                break;
        }

    // keep running until the user quit
    //
    } while (input != 4);

    // print the total amount of deposit and withdrawal
    //
    printf("Total Amount Deposited: $%d\n", total_deposit);
    printf("Total Amount Withdrawal: $%d\n", total_withdrawal);
    printf("Current Balance: $%d\n", balance);

    // closing message
    //
    puts("");
    puts("\t===== Thank you for using CIS2107 ATM Machine =====");

    // run successfully
    //
    return 0;
}

/**
 * Simulate cash depositing for the user
 *
 * @param balance a pointer to the current balance object
 * @param total_deposit a pointer to the total_deposit object
 *
 * @return exit status 0
 */
int cash_deposition(int *balance, int *total_deposit){

    int input;

    if (*total_deposit > 10000){
        puts("Daily Deposit Limit Reached.\n");
        puts("");
        return 1;
    }

    puts("Please Input the Withdrawal Amount:");
    scanf("%d", &input);

    if (input < 0)
    {
        puts("Withdrawal Amount cannot be Negative.\n");
        return 1;
    }
    else if ((input + *total_deposit) > 10000)
    {
        puts("Daily Deposit Limit Reached.\n");
        return 1;
    }

    *total_deposit += input;
    *balance += input;

    print_receipt();

    return 0;
}

/**
 * Simulate cash withdrawing for the user
 *
 * @param balance a pointer to the current balance object
 * @param total_withdrawal a pointer to the total_withdrawal object
 *
 * @return exit status 0
 */
int cash_withdrawal(int *balance, int *total_withdrawal){

    int input;

    if (*total_withdrawal > 1000){
        puts("Daily Withdrawal Limit Reached.\n");
        return 1;
    }

    puts("Please Input the Withdrawal Amount:");
    scanf("%d", &input);

    if (input < 0){
        puts("Withdrawal Amount cannot be Negative.\n");
        return 1;
    }
    else if (input % 20 != 0)
    {
        puts("Can only withdraw amounts that are multiples of 20s.\n");
        return 1;
    }
    else if ((input + *total_withdrawal) > 1000){
        puts("Daily Withdrawal Limit Reached.\n");
        return 1;
    }

    *total_withdrawal += input;
    *balance -= input;

    print_receipt();

    return 0;
}

/**
 * Print the the current balance
 *
 * @param balance a pointer to the current balance object
 * @return exit status 0
 */
int check_balance(int *balance) {

    printf("Your current balance: $%d\n", *balance);
    puts("");
    return 0;
}

/**
 * Ask the user if they want a receipt
 *
 * @param none
 * @return exit status 0
 */
int print_receipt(){

    int input;

    puts("\nWould you like a receipt?");
    puts("1. Yes");
    puts("2. No");

    scanf("%d", &input);

    // if the user do want a receipt then we print
    //
    if (input == 1){
        puts("Receipt printing...");
    }
    puts("");
}