#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#include "stringLibrary.h"
/**
 * Returns 1 if all of the characters in the string are either upper or
 * lower-case of the the alphabet, 0 otherwise.
 *
 * @param s string to be searched in
 *
 * @return int
 */
int all_letters(char *s) {

    int lower_a = 97;
    int lower_z = 122;

    int upper_a = 65;
    int upper_z = 90;

    int space = 32;

    for (size_t i = 0; s[i] != '\0'; i++) {

        if (s[i] == space)
            continue;

        if (!
        ((s[i] >= lower_a && s[i] <= lower_z) ||
         (s[i] >= upper_a && s[i] <= upper_z)))
            return 0;
    }
    return 1;
}