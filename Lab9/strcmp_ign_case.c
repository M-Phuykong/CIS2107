#include <stdio.h>
#include <ctype.h>

#include "stringLibrary.h"

/**
 * Compares s1 and s2 ignoring case. Returns a positive number if s1 would
 * appear after s2 in the dictionary, a negative number if it would appear
 * before s2, or 0 if it the two are equal
 *
 * @param s1 string1
 * @param s2 string2
 *
 * @return int
 */
int strcmp_ign_case(char *s1, char *s2) {

    int i = 0;
    char s1_char;
    char s2_char;

    while (s1[i] != '\0' && s2[i] != '\0') {

        s1_char = tolower(s1[i]);
        s2_char = tolower(s2[i]);

        if (s1_char > s2_char)
            return 1;
        else if (s1_char < s2_char)
            return -1;

        i++;
    }

    return 0;
}