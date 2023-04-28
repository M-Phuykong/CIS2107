#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Removes whitespace characters from the end of s
 *
 * @param s1 string
 *
 * @return void
 */
void rm_right_space(char *s1) {

    int str_size = 0;

    while (*s1 != '\0') {
        s1++;
        str_size++;
    }

    // decrease the pointer until the last character that is not a whitespace
    //
    while (s1[str_size] == ' ') {
        s1--;
    }

    *s1 = '\0';
}