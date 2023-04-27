#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "stringLibrary.h"

/**
 * Returns a string consisting of the first n strings in strs with the character c
 * used as a separator.For example, if strs contains the strings{"Washington",
 * "Adams", "Jefferson"} and c is '+', the function returns the string
 * "Washington+Adams+Jefferson"
 *
 * @param strs arrays of strings
 * @param n first n-strings
 * @param c character
 *
 * @return  string
 */
char *str_connect(char **strs, int n, char c) {

    int length = 0;
    int j = 0;

    for (size_t i = 0; i  < n; i++) {

        j = 0;

        while (strs[i][j] != '\0'){
            j++;
            length++;
        }
    }

    int new_length = length + (n - 1);
    int counter = 0;
    char *new_string = malloc(new_length + 1);

    for (size_t i = 0; i < n; i++) {

        for (size_t j = 0; i < strs[i][j] != '\0'; j++) {
            new_string[counter] = strs[i][j];
            counter++;
        }

        new_string[counter] = c;

        counter++;
    }

    new_string[--counter] = '\0';

    return new_string;
}