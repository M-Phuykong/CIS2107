// Phuykong Meng, 2023-01-30, CIS2107
// Lab 04 1D Arrays
//
// Write a program that process a 1D Array

// import header
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    srand((unsigned int)time(NULL));

    // int arr[SIZE] = {0, 56, 19, 81, 59, 48, 35, 90, 83, 75, 17, 86, 71, 51, 30, 1, 9, 36, 14, 16, 99, 45, 12, 0, 0, 38, 53, 57, 60, 61, 16,
    // 66, 45, 35, 5, 61, 79, 81, 52, 30};
    int arr[SIZE];

    // Part 1: fillArray
    //
    printf(RESET ANSI_COLOR_YELLOW
           "\t ===== Part 1: fillArray =====" RESET "\n");
    puts("Array before fill:");
    print_array(arr, SIZE);
    puts("");

    puts("Array after fill:");
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
    printf("%s","Enter two numbers: ");
    scanf("%d%d", &input_1, &input_2);

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

int fillArray(int arr[], size_t size){

    for (size_t i = 0; i < size; i++){
        arr[i] = rand() % (MAX + 1) + (MIN);
    }

    return 0;
}

int findSequence(int arr[], size_t size, int num1, int num2){

    for (size_t i = 1; i < size; i++){
        if ((arr[i] == num1 && arr[i - 1] == num2) ||
            (arr[i] == num2 && arr[i - 1] == num1)){
            return i - 1;
        }
    }
    return -1;
}

int findWithRange(int arr[], size_t size, int lowSelectedRange,
                int highSelectedRange){

    if (lowSelectedRange < 0 || highSelectedRange < 0){
        puts("Lower Range or Higher Range can't be less than 0");
        exit(0);
    }

    if (lowSelectedRange >= size || highSelectedRange >= size)
    {
        puts("Lower Range or Higher Range index can't be equal to or bigger "
            "than the array size.");
        exit(0);
    }

    if (lowSelectedRange > highSelectedRange){
        puts("The Lower Range can't be higher than the Higher Range.");
        exit(0);
    }

    int res = 0;

    for (size_t i = lowSelectedRange; i <= highSelectedRange; i++){

        if (arr[i] > res)
            res = arr[i];
    }

    return res;
}

void print_array(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i != 0 && i % 10 == 0)
        {
            puts("");
        }
        printf("%7d", arr[i]);
    }
    puts("");
}

void print_array_range(int arr[], size_t size, int start, int end)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i != 0 && i % 10 == 0)
        {
            puts("");
        }

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

int reverseArray(int arr[], size_t size)
{

    int cur;

    for (size_t i = 0; i < size / 2; i++)
    {
        cur = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = cur;
    }

    return 0;
}

int reverseSelectedRangeWithinArray(int arr[], size_t size, int startRange,
                                    int endRange){

    if (startRange < 0 || endRange < 0)
    {
        puts("Start Range or End Range can't be less than 0");
        exit(0);
    }

    if (startRange >= size || endRange >= size)
    {
        puts("Start Range or End Range index can't be equal to or bigger"
            "than the array size.");
        exit(0);
    }

    if (startRange > endRange)
    {
        puts("The Start Range can't be higher than the End Range.");
        exit(0);
    }

    int cur;
    int range = (endRange - startRange + 1) / 2;

    for (size_t i = 0; i < range; i++){
        cur = arr[startRange + i];
        arr[startRange + i] = arr[endRange - i];
        arr[endRange - i] = cur;
    }

    return 0;
}


