// Phuykong Meng, 2023-02-20, CIS2107
// Lab 05 2D Arrays
//
// Write a program that process a 2D Array

// import header
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// function prototype
int columnSum(size_t row, size_t col, size_t colChoice, const int arr[row][col]);
void displayOutputs(size_t row, size_t col, const int arr[row][col]);
bool isSquare(size_t row, size_t col);
int max(size_t row, size_t col, const int arr[row][col]);
int rowSum(size_t col, const int row[]);

// main function
//
int main(int argc, char **argv){

    // delcare row and col variable
    //
    int row;
    int col;

    puts("Let's create a 2Dim array!");

    puts("");

    printf("\tHow many rows? ");
    scanf("%d", &row);

    printf("\tHow many columns? ");
    scanf("%d", &col);

    puts("");

    // init the array of size row & col
    //
    int arr[row][col];

    // take user input
    //
    for (size_t r = 0; r < row; r++){
        for (size_t c = 0; c < col; c++){
            printf("\tenter [%zu][%zu]: ", r, c);
            scanf("%d", &arr[r][c]);
        }
    }

    puts("");

    // iterate through row and get the sum of each row
    //
    for (size_t r = 0; r < row; r++){
        printf("Sum of row %zu = %d\n", r + 1, rowSum(col, arr[r]));
    }

    puts("");

    // iterate through the col and get the sum of each col
    //
    for (size_t c = 0; c < col; c++){
        printf("Sum of col %zu = %d\n", c + 1, columnSum(row, col, c, arr));
    }

    puts("");

    // check if the array is a square
    //
    bool square = isSquare(row, col);
    if (square)
        puts("This is a square array.");
    else
        puts("This is not a square array.");

    puts("");

    // prints out the 2d array
    //
    puts("Here is your 2Dim array:");
    displayOutputs(row, col, arr);

    // return successfully
    //
    return 0;
}

/**
 * columnSum: Get the sum of the chosen column
 *
 * @param row the 2d array row size
 * @param col the 2d array column size
 * @param colChoice the column index to sum
 * @param arr the 2D array
 *
 * @return sum of the column
 */
int columnSum(size_t row, size_t col, size_t colChoice, const int arr[row][col])
{

    int sum = 0;

    // iterate through each row and get the value at
    // "colChoice" index
    //
    for (size_t r = 0; r < row; r++){
        sum += arr[r][colChoice];
    }

    // return the sum
    //
    return sum;
}

/**
 * displayOutputs: Print the 2D Array
 *
 * @param row the 2d array row size
 * @param col the 2d array column size
 * @param arr the 2D array
 *
 * @return void
 */
void displayOutputs(size_t row, size_t col, const int arr[row][col]){

    // output contents of array
    //
    for (size_t r = 0; r < row; r++){

        printf("%s", "[");

        for (size_t c = 0; c < col; c++){

            // if the last element then we don't need a comma and space
            //
            if (c == col - 1)
                printf("%d", arr[r][c]);
            else
                printf("%d, ", arr[r][c]);
        }

        printf("%s", "]");
        puts("");
    }
}

/**
 * isSquare: Check if 2D array is a square
 *
 * @param row the 2d array row size
 * @param col the 2d array column size
 *
 * @return bool
 */
bool isSquare(size_t row, size_t col){

    if (row == col){
        return true;
    }

    return false;
}

/**
 * max: Get the max of the 2D array
 *
 * @param row the 2d array row size
 * @param col the 2d array column size
 * @param arr the 2D array
 *
 * @return max
 */
int max(size_t row, size_t col, const int arr[row][col]){

    int res = INT_MIN;

    // loop through row
    //
    for (size_t r = 0; r < row; r++){

        // loop through the col
        //
        for (size_t c = 0; c < col; c++){

            if (arr[r][c] > res)
                res = arr[r][c];
        }
    }

    // return maximum number
    //
    return res;
}

/**
 * rowSum: Get the sum of the chosen row
 *
 * @param col the 2d array column size
 * @param row a 1D array consisting of the row
 *
 * @return sum of the row
 */
int rowSum(size_t col, const int row[]){

    int sum = 0;

    // loop through the row
    //
    for (size_t c = 0; c < col; c++){
        sum += row[c];
    }

    return sum;
}