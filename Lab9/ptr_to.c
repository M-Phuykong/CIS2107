#include <stdio.h>

#include "stringLibrary.h"

/**
 * Returns a pointer to the first occurrence of n in the string h or NULL if it
 * isn't found
 *
 * @param h string to search in
 * @param n substring
 *
 * @return int
 */
char *ptr_to(char *h, char *n) {

    while (*h != '\0')
    {
        if (*h == *n)
        {
            return h;
        }
        h++;
    }

    return NULL;
}