#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Returns the index of the first occurrence of n in the string h or -1 if it
 * isn't found
 *
 * @param h string to search in
 * @param n substring
 *
 * @return int
 */
int find(char *h, char *n) {

    int counter = 0;

    while (*h != '\0') {
        if (*h == *n) {
            return counter;
        }
        h++;
        counter++;
    }

    return -1;
}