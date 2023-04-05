/*
    Name:       Phuykong Meng
    Section:    04
    Lab:        CIS2107_Lab08_Manual
    Goal:       To design and implement functions taking pointers as arguments
                to process characters and strings.
*/

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int matrix[5][5];
    int counter = 1;

    for (size_t r = 0; r < 5; r++)
        for (size_t c = 0; c < 5; c++)
            matrix[r][c] = counter++;

    for (size_t r = 0; r < 5; r++){
        for (size_t c = 0; c < 5; c++){

            if (r == 0 || r == 4 || c ==0 || c == 4){
                matrix[r][c] = 0;
            }
        }
    }

    for (size_t r = 0; r < 5; r++){
        for (size_t c = 0; c < 5; c++){
            printf("%5d ", matrix[r][c]);

        }
        puts("");
    }

    






    return 0;
}