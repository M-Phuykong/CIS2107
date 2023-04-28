#include <stdlib.h>
#include <stdbool.h>

#include "stringLibrary.h"

/**
 * Changes s so that the first letter of every word is in upper case and
 * additional letter is in lower case
 *
 * @param s string to be capitalized
 *
 * @return void
 */
void capitalize(char *s) {

    bool space = false;
    int i = 0;

    while (s[i] != '\0'){

        // Two conditions when we need to capitalize:
        // 1. The first letter of the string
        // 2. The letter after a space (start of a new word)
        //
        if ((i == 0 && s[i] != ' ') || (space)){
            s[i] -= 32;
            space = false;
        }

        if (s[i] == ' '){
            space = true;
        }

        i++;
    }
}