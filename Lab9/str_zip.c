#include <stdio.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Returns a new string consisting of all of the characters of s1 and s2
 * interleaved with each other.
 *
 * For example, is s1 is "Spongebob" and s2 is "Patrick", the function returns
 * "SPpaotnrgiecbkob"
 *
 * @param s1 string 1
 * @param s2 string 2
 *
 * @return string
 */
char *str_zip(char *s1, char *s2) {

    int s1_length = 0;
    int s2_length = 0;

    while(s1[s1_length] != '\0')
        s1_length++;

    while(s2[s2_length] != '\0')
        s2_length++;

    // Allocate memory for the new string where the size is the sum of
    // the length of s1 and s2 plus 1 for the null character
    //
    char *new_string = malloc(sizeof(char) * (s1_length + s2_length + 1));

    // check if we have enough memory
    //
    if (new_string == NULL) {
        puts("Error: Fail to allocate memory");
        return NULL;
    }

    int i = 0;
    int j = 0;
    int counter = 0;

    while (s1[i] != '\0' && s2[j] != '\0') {
        if (counter % 2 == 0)
            new_string[counter] = s1[i++];
        else
            new_string[counter] = s2[j++];
        counter++;
    }

    // Check for the remaining characters in s1 and s2
    //
    while (s1[i] != '\0')
        new_string[counter++] = s1[i++];

    while (s2[j] != '\0')
        new_string[counter++] = s2[j++];

    return new_string;
}