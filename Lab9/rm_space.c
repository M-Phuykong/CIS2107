#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Removes whitespace characters from the beginning and end of s.
 *
 * @param s1 string
 *
 * @return void
 */
void rm_space(char *s1) {
    rm_left_space(s1);
    rm_right_space(s1);
}