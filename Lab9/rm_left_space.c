#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Removes whitespace characters from the beginning of s
 *
 * @param s1 string
 *
 * @return void
 */
void rm_left_space(char *s1) {

    char *tmp = s1;

    // move pointer while there's a space
    //
    while (*tmp == ' ') {
        tmp++;
    }

    // we can then copy the string from the temporary pointer to the beginning
    // of the string
    //
    while (*tmp != '\0') {
        *s1 = *tmp;
        s1++;
        tmp++;
    }

    // pointer is pointing to the last character of the string
    // so we need to set the next character to null
    //
    *s1 = '\0';

}