#include <stdio.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Returns an array of string consisting of the characters in s split into
 * tokens based on the delimeter c, followed by a NULL pointer. For example,
 * if s is "I am ready for a nice vacation" and c is ' ', it
 * returns { "I", "am", "ready", "for", "a", "nice", "vacation", NULL }
 *
 * @param s string to split
 * @param c delimeter
 *
 * @return array of string
 */
char **str_chop_all(char *s, char c) {

    int length = 0;
    int delimeter_count = 0;

    while(s[length] != '\0') {
        if (s[length] == c) {
            delimeter_count++;
        }
        length++;
    }

    // free 2d array, the first malloc determines the number of items
    //
    // we add two because we need to add the NULL pointer and the one off
    //
    char **new_string = malloc(sizeof(char *) * (delimeter_count + 2));

    if (new_string == NULL) {
        puts("Error: Fail to allocate memory");
        return NULL;
    }

    int counter = 0;
    int str_length = 0;
    int i = 0;

    while (i < length) {

        str_length = 0;

        // find the length of the string until a delimiter is found or
        // the end of the string is reached
        //
        for(size_t j = i; s[j] != c && s[j] != '\0'; j++) {
            str_length++;
        }

        // We allocate our memory based on the length of the string
        //
        new_string[counter] = malloc(str_length + 1);

        if (new_string[counter] == NULL) {
            puts("Error: Fail to allocate memory");
            return NULL;
        }

        // copy the string into the new array
        //
        for (size_t j = i; s[j] != c; j++) {
            new_string[counter][j - i] = s[j];
        }

        new_string[counter][str_length] = '\0';

        i += str_length + 1;
        counter++;
    }

    return new_string;
}