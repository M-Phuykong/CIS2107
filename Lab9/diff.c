#include <stdlib.h>
#include <stdio.h>
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

    // get the shortest string length to iterate through
    //
    int len = 0;
    if (str1_length >= str2_length)
        len = str2_length;
    else
        len = str1_length;

    // check all the differences between the two strings with the shortest
    // string length
    //
    for (size_t i = 0; i < len; i++) {
        if (s1[i] != s2[i])
            count++;
    }

    // if any of the two string is longer than the other then the differences
    // of the two string's length will need to be added
    //
    return count + abs(str1_length - str2_length);
}