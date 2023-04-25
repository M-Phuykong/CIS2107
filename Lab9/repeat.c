#include <stdio.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Returns a new string consisting of the characters in s repeated x times,
 * with the character sep in between. For example, if s is the string all right,
 * x is 3, and sep is, the function returns the new string all right, all right,
 * all right.If s is NULL, the function returns NULL.It is up to the caller to
 * free any memory allocated by the function.
 *
 * @param s string
 * @param x number of times to repeat
 * @param sep separator
 *
 * @return string
 */
char *repeat(char *s, int x, char sep) {

    int length = 0;

    while(s[length] != '\0')
        length++;

    int new_length = length * x + (x - 1);

    char *new_string = malloc(new_length);

    if (new_string == NULL) {
        puts("Error: Fail to allocate memory");
        return NULL;
    }

    


    return new_string;
}