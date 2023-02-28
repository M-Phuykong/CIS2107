/*

Name: Phuykong Meng
Date: 2023-02-28
Course: CSI2107

HW#: Lab 06: ““Arrays of Pointers to Functions”
Objective: To design and implement array of function pointer.
The purpose of this program is to modify existing code related to examslecting
grades for individual students in a 2D matrix and determining the minimum, maximum,
and each average.

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

// import header
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// define inline constant value
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1B[34m"
#define ANSI_COLOR_MAGENTA "\x1B[35m"
#define ANSI_COLOR_CYAN "\x1B[36m"
#define RESET "\x1B[0m"

// function prototype
//
void printArray(int students, int exams, const int grades[students][exams]);
void minimum(int students, int exams, const int grades[students][exams]);
void maximum(int students, int exams, const int grades[students][exams]);
void average(int students, int exams, const int grades[students][exams]);

// constant declaration
//
const int FUNCTION_NUM = 4;

// declare enum for the choices of the function
//
enum CHOICES {PRINT_ARRAY, MINIMUM, MAXIMUM, AVERAGE, EXIT};

static int students;
static int exams;

int main(int argc, char const *argv[])
{
    int userChoice = 0;

    // initialize array of 4 pointers to a function that each take 2 int
    // and a 2D array argument and returns void
    //
    void (*processGrades[FUNCTION_NUM])(int, int, const int [students][exams])=
                                    {printArray, minimum, maximum, average};

    printf("%sEnter the number of students:\n%s", ANSI_COLOR_YELLOW, RESET);
    scanf("%d", &students);

    printf("%sEnter the number of exams:\n%s", ANSI_COLOR_YELLOW, RESET);
    scanf("%d", &exams);

    puts("");

    int studentGrades[students][exams];

    for (size_t r = 0; r < students; r++){
        for (size_t c = 0; c < exams; c++){

            printf("%sEnter grade for student %zu, exam %zu:\n%s",ANSI_COLOR_YELLOW, r, c, RESET);
            scanf("%d", &studentGrades[r][c]);
        }

    }
    puts("");

    do {
        printf("%s%s", ANSI_COLOR_YELLOW ,"Enter a choice:\n");
        printf("\t%s%s%d%s Print the array of grades\n", RESET, ANSI_COLOR_GREEN, PRINT_ARRAY, RESET);
        printf("\t%s%s%d%s Find the minimum grade\n", RESET, ANSI_COLOR_GREEN, MINIMUM, RESET);
        printf("\t%s%s%d%s Find the maximum grade\n", RESET, ANSI_COLOR_GREEN, MAXIMUM, RESET);
        printf("\t%s%s%d%s Print the average on all tests for each student\n", RESET, ANSI_COLOR_GREEN, AVERAGE, RESET);
        printf("\t%s%s%d%s End Program\n", RESET, ANSI_COLOR_GREEN, EXIT, RESET);
        puts(RESET);

        printf("%sPlease select your options:\n%s", ANSI_COLOR_YELLOW, RESET);
        scanf("%d", &userChoice);
        puts("");

        switch (userChoice)
        {
        case PRINT_ARRAY:
            (*processGrades[PRINT_ARRAY])(students, exams, studentGrades);
            break;

        case MINIMUM:
            (*processGrades[MINIMUM])(students, exams, studentGrades);
            break;

        case MAXIMUM:
            (*processGrades[MAXIMUM])(students, exams, studentGrades);
            break;

        case AVERAGE:
            (*processGrades[AVERAGE])(students, exams, studentGrades);
            break;

        default:
            break;
        }

    } while (userChoice != EXIT);


    // exit successfully
    //
    return 0;
}

void printArray(int students, int exams, const int grades[students][exams]){

    printf("%sThe array is:\n%s", ANSI_COLOR_BLUE, RESET);
    printf("%15s", " ");

    for (size_t exam = 0; exam < exams; exam++){
        printf("%s  [%zu]", ANSI_COLOR_BLUE, exam);
    }
    puts(RESET);

    for (size_t i = 0; i < students; i++){

        printf("%s\nstudentGrades[%zu]  %s", ANSI_COLOR_BLUE, i, RESET);

        for (size_t j = 0; j < exams; j++){

            printf("%s%-5d", ANSI_COLOR_CYAN, grades[i][j]);

        }

    }

    puts(RESET);
    puts("");

}

void minimum(int students, int exams, const int grades[students][exams]){
    int lowest_grade = INT_MAX;

    for (size_t r = 0; r < students; r++){
        for (size_t c = 0; c < exams; c++){
            if (grades[r][c] < lowest_grade)
                lowest_grade = grades[r][c];
        }
    }

    printf("%sLowest grade: %d\n%s", ANSI_COLOR_BLUE, lowest_grade, RESET);
    puts("");
}

void maximum(int students, int exams, const int grades[students][exams]){
    int highest_grade = INT_MIN;

    for (size_t r = 0; r < students; r++) {
        for (size_t c = 0; c < exams; c++){
            if (grades[r][c] > highest_grade)
                highest_grade = grades[r][c];
        }
    }

    printf("%sHighest grade: %d\n%s", ANSI_COLOR_BLUE, highest_grade, RESET);
    puts("");
}

void average(int students, int exams, const int grades[students][exams]){

    float average = 0;

    for (size_t r = 0; r < students; r++){

        average = 0;

        for (size_t c = 0; c < exams; c++)
            average += grades[r][c];

        average /= exams;

        printf("%sThe average grade for student %zu is %.2f\n%s",ANSI_COLOR_BLUE ,r, average, RESET);
    }

    puts("");

}
