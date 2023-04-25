#include <stdio.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Returns a new string consisting of all of the letters of s, but padded with
 * spaces at the end so that the total length of the returned string is an
 * even multiple of d. If the length of s is already an even multiple of d,
 * the function returns a copy of s.The function returns NULL on failure or
 * if s is NULL.Otherwise, it returns the new string. It is up to the caller to
 * free any memory allocated by the function.
 *
 * @param s string
 * @param d multiple
 *
 * @return  string
 */
char *pad(char *s, int d) {

    if (s == NULL)
        return NULL;

    int length = 0;

    while(s[length] != '\0')
        length++;

    if (length % d == 0)
        return s;

    // check if the string length fits in the multiple of d
    //
    int extra_space = d;

    // if the d is already greater than the string length than we can
    // pad the remaining character of the string to fit d
    // else we would need to increase d by itself.
    //
    while (extra_space < length)
        extra_space += d;

    char *new_string = malloc(extra_space);

    if (new_string == NULL) {
        puts("Error: Fail to allocate memory");
        return NULL;
    }

    for (size_t i = 0; i < length; i++)
        new_string[i] = s[i];

    for (size_t i = length; i < extra_space; i++)
        new_string[i] = '-';

    new_string[extra_space] = '\0';

    return new_string;
}