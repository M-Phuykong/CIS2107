// Phuykong Meng, 2023-03-14, CIS2107
// Lab 06 Race
//
// The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
// generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
// controlled using the sleep() function. Sometimes it takes a while due to slippage.
//

// import header
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// define inline constant value
//
#define INT_MIN 1
#define INT_MAX 10

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1B[34m"
#define ANSI_COLOR_MAGENTA "\x1B[35m"
#define ANSI_COLOR_CYAN "\x1B[36m"
#define RESET "\x1B[0m"

// function prototype
//
int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);

int main(){

    // set a random seed
    //
    srand((unsigned)time(NULL));

    int hPos =1;                        //hare start position is 1, cannot slip past 1
    int tPos = 1;                       //tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");    //the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");    //the spacing is modeled after the sample

    // simulate the clock
    //
    while(hPos != 70 && tPos != 70){
        sleep(1);                   //slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
        puts("");
    }
    puts("");

    // print the result
    //
    if (hPos == 70 && tPos != 70){
        printf("%s%sHare%s wins. Yuch.\n", RESET, ANSI_COLOR_YELLOW, RESET);
    }
    else {
        printf("%s%sTORTOISE%s WINS!!! YAY!!!\n", RESET, ANSI_COLOR_GREEN, RESET);
    }
}

/**
 * printRace: prints the position of the H and T
 *
 * @param hPos hare position
 * @param tPos tortoise position
 *
 * @return void
 */
void printRace(int hPos,int tPos){

    // static variable to keep the round number
    //
    static int roundNum = 1;

    printf("%s%s%d%s ", RESET, ANSI_COLOR_YELLOW,roundNum, RESET);

    // print the round state
    //
    for (int i = 1; i <= 70; i++) {

        if (!(i == hPos && i == tPos)){

            if (i == hPos){
                printf("%s%sH%s", RESET, ANSI_COLOR_RED, RESET);
            }
            else if (i == tPos){
                printf("%s%sT%s", RESET, ANSI_COLOR_GREEN, RESET);
            }
            else {
                printf("%s", " ");
            }
        }
        else {
            printf("%s", "OUCH!!!");
        }
    }

    roundNum += 1;
}

/**
 * tortMove: controls the tortoise movement
 *
 * @param tPtr pointer to the tortoise position
 *
 * @return void
 */
void tortMove(int *tPtr){

    int numRoll = randomNumberGenerator();

    // fast plod
    //
    if (numRoll >= 1 && numRoll <= 5){
        *tPtr += 3;
    }

    // slip
    //
    else if (numRoll == 6 || numRoll == 7){
        *tPtr -= 6;
    }

    // slow plod
    //
    else {
        *tPtr += 1;
    }

    // reset if less than or equal to 0
    //
    if (*tPtr <= 0)
        *tPtr = 1;

    // clip it to 70 if it's more than 70
    //
    if (*tPtr > 70)
        *tPtr = 70;
}

/**
 * hareMove: controls the hare movement
 *
 * @param hPtr pointer to the hare position
 *
 * @return void
 */
void hareMove(int *hPtr){

    int numRoll = randomNumberGenerator();

    switch (numRoll){

        // small slip
        //
        case 1:
        case 2:
            *hPtr -= 2;
            break;

        // big hop
        //
        case 3:
        case 4:
            *hPtr += 9;
            break;

        // big slip
        //
        case 5:
            *hPtr -= 12;
            break;

        // small hop
        //
        case 6:
        case 7:
        case 8:
            *hPtr += 1;
            break;

        // sleep
        //
        default:
            break;
    }

    // reset if less than or equal to 0
    //
    if (*hPtr <= 0)
        *hPtr = 1;

    // clip to 70 if value is higher
    //
    if (*hPtr > 70)
        *hPtr = 70;
}

/**
 * randomNumberGenerator: generates random number from 1-10
 *
 * @return int
 */
int randomNumberGenerator(){
    return  INT_MIN + rand() % (INT_MAX + 1 - INT_MIN);
}
