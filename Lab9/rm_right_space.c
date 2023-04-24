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

    while (s1[str_size] == ' ') {
        str_size--;
    }

    *s1 = '\0';
}