#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
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

    while (*tmp == ' ') {
        tmp++;
    }

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