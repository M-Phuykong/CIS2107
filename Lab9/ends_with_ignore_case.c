#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "stringLibrary.h"

/**
 * Returns 1 if suff is a suffix of s ignoring case or 0 otherwise.
 *
 * @param s string
 * @param suff suffix
 *
 * @return int
 */
int ends_with_ignore_case(char *s, char *suff) {

    if (s == NULL || suff == NULL)
        return 0;

    int length = 0;
    int suff_length = 0;

    while(s[length] != '\0')
        length++;

    while(suff[suff_length] != '\0')
        suff_length++;

    int start = length - suff_length;
    for (size_t i = start; i < length; i++) {

        // if we found a mismatch character than we assume that the suffix
        // does not exist
        //
        if (tolower(s[i]) != tolower(suff[i - start]))
            return 0;
    }

    return 1;
}