#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

#include "stringLibrary.h"

/**
 * Returns the number of positions in which s1 and s2 differ, i.e. it returns
 * the number of changes that would need to be made in order to transform s1
 * s2 where a change could be a character substitution, insertion or deletion.
 *
 * @param s1 string 1
 * @param s2 string 2
 *
 * @return int
 */
int diff(char *s1, char *s2) {

    int count = 0;
    int str1_length = 0;
    int str2_length = 0;

    while (s1[str1_length] != '\0')
        str1_length++;

    while (s2[str2_length] != '\0')
        str2_length++;

    int len = (int) fmin((float) str1_length, (float)str2_length);
    for (size_t i = 0; i < len; i++) {
        if (s1[i] != s2[i])
            count++;
    }

    return count + abs(str1_length - str2_length);
}