#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stringLibrary.h"

/**
 * Returns a new string based on s, but without any duplicate characters.
 *
 * For example, if s is the string, "There's always money in the banana stand."
 * , the function returns the string " Ther's alwymonitbd.". It is up to the
 * caller to free the memory allocated by the function.
 *
 * @param s string
 *
 * @return string
 */
char *dedup(char *s) {

    int length = 0;

    while(s[length] != '\0')
        length++;

    char *hash = malloc(length);

    if (hash == NULL) {
        puts("Error: Fail to allocate memory");
        return NULL;
    }

    char *new_string = malloc(length);

    if (new_string == NULL) {
        puts("Error: Fail to allocate memory");
        return NULL;
    }

    int counter = 0;
    bool is_duplicate = false;

    for (size_t i = 0; i < length; i++) {

        // check if character already exist in the hash
        //
        for (size_t j = 0; j < length; j++) {
            if (hash[j] == s[i]) {
                is_duplicate = true;
                break;
            }
            is_duplicate = false;
        }

        if (!is_duplicate) {
            hash[counter] = s[i];
            new_string[counter] = s[i];
            counter++;
        }
    }
    new_string[counter] = '\0';

    // resize the array to the new length
    //
    if (realloc(new_string, counter) == NULL){
        puts("Error: Fail to re-allocate memory");
        return NULL;
    }

    free(hash);

    return new_string;
}