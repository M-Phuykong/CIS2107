#include <stdio.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Returns a copy of the string s, but with each instance of pat replaced with
 * rep, note that len(pat) can be less than, greater than, or equal to len(rep).
 * The function allocates memory for the resulting string, and it is up to
 * the caller to free it. For example, if we call replace("NBA X", "X", "rocks"),
 * what is returned is the new string NBA rocks (but remember, pat could be longer
 * than an individual character and could occur multiple times).
 *
 * @param s string
 * @param pat pattern to be replaced
 * @param rep replacement
 *
 * @return  string
 */
char *replace(char *s, char *pat, char *rep) {

    int length = 0;
    int pat_length = 0;
    int rep_length = 0;

    while(s[length] != '\0')
        length++;

    while(pat[pat_length] != '\0')
        pat_length++;

    while(rep[rep_length] != '\0')
        rep_length++;

    int pat_counter = 0;
    int j = 0;

    for (size_t i = 0; i < length; i++){

        if (s[i] == pat[j])
            j++;
        else
            j = 0;

        if (pat[j] == '\0') {
            pat_counter++;
            j = 0;
        }
    }

    int new_length = length + ((rep_length - pat_length) * pat_counter);
    char *new_string = malloc(new_length + 1);

    if (new_string == NULL) {
        puts("Error: Fail to allocate memory");
        return NULL;
    }

    int counter = 0;
    int prev = 0;
    int i = 0;
    j = 0;

    while (i < length) {

        if (s[i] != pat[j]) {
            new_string[counter] = s[i];
            counter++;
            i++;
        }

        else {

            while (rep[j] != '\0') {
                new_string[counter] = rep[j];
                j++;
                counter++;
            }

            i += pat_length;
            j = 0;
        }
    }

    return new_string;
}