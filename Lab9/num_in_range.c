#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Returns the number of characters c in s1 such that b <= c <= t.
 *
 * @param s1 string to be searched in
 * @param b lower bound
 * @param t upper bound
 *
 * @return int
 */
int num_in_range(char *s1, char b, char t) {

    int count = 0;

    for (size_t i = 0; s1[i] != '\0'; i++) {

        // check if the ASCII value is between the given range
        //
        if (s1[i] >= b && s1[i] <= t)
            count++;
    }

    return count;
}