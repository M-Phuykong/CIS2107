// Phuykong Meng, 2023-01-30, CIS2107
// Lab 02 Revenue
//
// Write a C program called revenue to calculate the revenue from a sale based 
// on the unit price and quantity of a product input by 
// the user.

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
    double fract_part;
    double int_part;
    double quantity;
    double item_price;
    double cost;
    double discount;
    double discount_amount;
    double total;

    // print welcome message
    //
    puts("Welcome to \"Temple\" store");
    puts("");

    // get user input for item price
    //
    printf("%s" , "\tEnter item price: ");
    scanf("%lf", &item_price);

    // if item price is less than 0, exit
    //
    if (item_price < 0){
        puts("\n\tThis is not a valid item price.");
        puts("\tPlease run the program again");
        puts("\nThank You for using \"Temple\" store");
        exit(1);
    }

    // get user input for employee number
    //
    printf("%s" , "\tEnter quantity: ");
    scanf("%lf", &quantity);

    // if employee number is less than 0 or a float, exit
    //
    fract_part = modf (quantity, &int_part);
    if (int_part < 0 || fract_part != 0){
        puts("\n\tThis is not a valid quantity order.");
        puts("\tPlease run the program again");
        puts("\nThank You for using \"Temple\" store");
        exit(1);
    }

    // get the discount percentage based on the quantity
    //
    if (quantity >= 49 && quantity <= 99) {
        discount = 10;
    }
    else if (quantity <= 149){
        discount = 15;
    }
    else{
        discount = 25;
    }

    // calculate the cost, discount_amount and the total amount
    //
    cost = item_price * quantity;
    discount_amount = cost * (discount / 100);
    total = cost - discount_amount; 

    // print if everything is okay
    //
    printf("\n\tThe item price is: $%.1f\n", item_price);
    printf("\tThe order is: %d item(s)\n", (int)quantity);
    printf("\tThe cost is: $%.1f\n", cost);
    printf("\tThe discount is: %.1f%%\n", discount);
    printf("\tThe discount amount is: $%.1f\n", discount_amount);
    printf("\tThe total is: $%.1f\n", total);

    // closing message
    //
    puts("\nThank You for using \"Temple\" store");

    // exit successfully
    //
    exit(0);
}


