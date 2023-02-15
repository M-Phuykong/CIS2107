// Phuykong Meng, 2023-01-30, CIS2107
// Lab 04 1D Arrays
//
// Write a program that process a 1D Array

// import header
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// define constant value
//
#define MIN 0
#define MAX 100
#define SIZE 40

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define RESET "\x1B[0m"

// function prototype
//
int fillArray(int arr[], size_t size);
int findSequence(int arr[], size_t size, int num1, int num2);
int findWithRange(int arr[], size_t size,
                int lowSelectedRange, int highSelectedRange);
int reverseArray(int arr[], size_t size);
int reverseSelectedRangeWithinArray(int arr[], size_t size,
                                    int startRange, int endRange);

void print_array(int arr[], size_t size);
void print_array_range(int arr[], size_t size, int start, int end);

// main function
//
int main(int argc, char **argv){

    // seed random
    //
    srand((unsigned int)time(NULL));

    // array declaration with size of SIZE
    //
    int arr[SIZE];

    // Part 1: fillArray
    //
    printf(RESET ANSI_COLOR_YELLOW
           "\t ===== Part 1: fillArray =====" RESET "\n");
    puts("Array before fill:");
    print_array(arr, SIZE);
    puts("");

    puts("Array after fill:");

    // call the fillArray() function to fill the array with
    // random value
    //
    fillArray(arr, SIZE);
    print_array(arr, SIZE);
    puts("");

    // Part 2: findWithRange
    //
    printf(RESET ANSI_COLOR_YELLOW
        "\t ===== Part 2: findWithRange =====" RESET "\n");

    puts("Array:");
    print_array_range(arr, SIZE, 10, 19);
    puts("");

    // print the result for the function findWithRange() since it
    // will return the maximum number within the range
    //
    printf("Max: %s%s%d%s \n", RESET, ANSI_COLOR_GREEN,
            findWithRange(arr, SIZE, 10, 19), RESET);
    puts("");

    // Part 3: reverseArray
    //
    printf(RESET ANSI_COLOR_YELLOW
        "\t ===== Part 3: reverseArray =====" RESET "\n");

    puts("");
    puts("Original Array:");
    print_array(arr, SIZE);
    puts("");

    puts("Reversed Array:");

    // reverse the array with the reverseArray() function
    //
    reverseArray(arr, SIZE);
    print_array(arr, SIZE);
    puts("");

    // Part 4: reverseSelectedRangeWithinArray
    //
    printf(RESET ANSI_COLOR_YELLOW
        "\t ===== Part 4: reverseSelectedRangeWithinArray =====" RESET "\n");

    puts("");
    puts("Original Array:");
    print_array_range(arr, SIZE, 15, 24);
    puts("");

    printf("Reversing between %d and %d:\n", 15, 24);

    // reverse the array from the index 15 to index 24
    //
    reverseSelectedRangeWithinArray(arr, SIZE, 15, 24);
    print_array_range(arr, SIZE, 15, 24);
    puts("");

    // Part 5: findSequence
    //
    printf(RESET ANSI_COLOR_YELLOW
           "\t ===== Part 5: findSequence =====" RESET "\n");

    puts("");
    puts("Original Array:");
    print_array(arr, SIZE);
    puts("");

    int input_1;
    int input_2;

    // get user input
    //
    printf("%s","Enter two numbers: ");
    scanf("%d%d", &input_1, &input_2);

    // find the sequence with the findSequence() function
    //
    int index = findSequence(arr, SIZE, input_1, input_2);
    if (index != -1){
        printf("Sequence found at index %d\n", index);
    } else {
        printf("Sequence not found.\n");
    }

    // run successfully
    //
    return 0;
}

/**
 * Part 1: Fill the given array with a random number
 *
 * @param arr an array
 * @param size the size of array
 *
 * @return exit status 0
 */
int fillArray(int arr[], size_t size){

    // loop through the array and fill it
    //
    for (size_t i = 0; i < size; i++){
        arr[i] = rand() % (MAX + 1) + (MIN);
    }

    return 0;
}

/**
 * Part 5: Find the sequence within the array
 *
 * @param arr an array
 * @param size the size of array
 * @param num1 the first number of the sequence
 * @param num2 the second number of the sequence
 *
 * @return the index of the first number else -1
 */
int findSequence(int arr[], size_t size, int num1, int num2){

    // loop trough the array and check if the first and second number
    // matches the input sequence number
    //
    for (size_t i = 1; i < size; i++){
        if ((arr[i] == num1 && arr[i - 1] == num2) ||
            (arr[i] == num2 && arr[i - 1] == num1)){
            return i - 1;
        }
    }
    return -1;
}

/**
 * Part 2: Find the largest number within the range
 *
 * @param arr an array
 * @param size the size of array
 * @param lowSelectedRange the lowest index of the range (inclusive)
 * @param highSelectedRange the highest index of the range (inclusive)
 *
 * @return the largest number within the range
 */
int findWithRange(int arr[], size_t size, int lowSelectedRange,
                int highSelectedRange){

    // check if both of the range is less than zero
    //
    if (lowSelectedRange < 0 || highSelectedRange < 0){
        puts("Lower Range or Higher Range can't be less than 0");
        exit(0);
    }

    // check if both of the range is bigger or equal to the size of the array
    //
    if (lowSelectedRange >= size || highSelectedRange >= size)
    {
        puts("Lower Range or Higher Range index can't be equal to or bigger "
            "than the array size.");
        exit(0);
    }

    // check for the logical error where the lower range is higher than the
    // high range
    //
    if (lowSelectedRange > highSelectedRange){
        puts("The Lower Range can't be higher than the Higher Range.");
        exit(0);
    }

    // declare res variable with the smallest value of INT
    //
    int res = INT_MIN;

    // loop through the array
    //
    for (size_t i = lowSelectedRange; i <= highSelectedRange; i++){

        // update res if the value at index i is larger than res
        //
        if (arr[i] > res)
            res = arr[i];
    }

    return res;
}

/**
 * Print the array
 *
 * @param arr an array
 * @param size the size of array
 *
 * @return none
 */
void print_array(int arr[], size_t size)
{
    // loop through the array
    //
    for (size_t i = 0; i < size; i++)
    {
        // break line after every 10 steps
        //
        if (i != 0 && i % 10 == 0)
        {
            puts("");
        }
        printf("%7d", arr[i]);
    }
    puts("");
}

/**
 * Print the array where the given start and end range is coloured
 *
 * @param arr an array
 * @param size the size of array
 * @param start the start index of the range (inclusive)
 * @param end the last index of the range (inclusive)
 *
 * @return none
 */
void print_array_range(int arr[], size_t size, int start, int end)
{
    // loop through the array
    //
    for (size_t i = 0; i < size; i++)
    {
        // break line after every 10 steps
        //
        if (i != 0 && i % 10 == 0)
        {
            puts("");
        }

        // if the index within the range print the color version
        // with a 7 space left padding
        //
        if (i >= start && i <= end)
        {
            printf("%s%s%7d%s", RESET, ANSI_COLOR_RED, arr[i], RESET);
        }
        else
        {
            printf("%7d", arr[i]);
        }
    }
    puts("");
}

/**
 * Part 3: Reverse the given array
 *
 * @param arr an array
 * @param size the size of array
 *
 * @return exit status 0
 */
int reverseArray(int arr[], size_t size)
{
    int cur;

    // only loop through half of the array to swap the value
    //
    for (size_t i = 0; i < size / 2; i++)
    {
        // 3 stage swap
        //
        cur = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = cur;
    }

    return 0;
}

/**
 * Part 4: Reverse the array within the select range
 *
 * @param arr an array
 * @param size the size of array
 * @param startRange the start index of the range (inclusive)
 * @param endRange the last index of the range (inclusive)
 *
 * @return exit status 0
 */
int reverseSelectedRangeWithinArray(int arr[], size_t size, int startRange,
                                    int endRange){

    // check if both selected range is smaller than 0 or negative
    //
    if (startRange < 0 || endRange < 0)
    {
        puts("Start Range or End Range can't be less than 0");
        exit(0);
    }

    // check if the both selected range is bigger or equal the size of the
    // array
    //
    if (startRange >= size || endRange >= size)
    {
        puts("Start Range or End Range index can't be equal to or bigger"
            "than the array size.");
        exit(0);
    }

    // check if the start range is higher than the end range
    //
    if (startRange > endRange)
    {
        puts("The Start Range can't be higher than the End Range.");
        exit(0);
    }

    int cur;
    // the amount of iteration that the for loop needs to run.
    // it's the half of the range's length.
    //
    int range = (endRange - startRange + 1) / 2;

    // loop for half of the array range and swap value
    //
    for (size_t i = 0; i < range; i++){
        cur = arr[startRange + i];
        arr[startRange + i] = arr[endRange - i];
        arr[endRange - i] = cur;
    }

    return 0;
}


