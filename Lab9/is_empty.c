#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Returns 1 if s is NULL, consists of only the null character (") or only
 * whitespace, returns 0 otherwise.
 *
 * @param s string to be checked
 *
 * @return int
 */
int is_empty(char *s) {

    // if we find a character then we know it is never empty
    //
    while (*s != '\0') {
        if (*s != ' ')
            return 0;
        s++;
    }

    return 1;
}