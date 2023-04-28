#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Modifies s so that it consists of only its last n characters.
 * If n is ≥ the length of s, the original string is unmodified.
 *
 * For example if we call take_last("Brubeck" 5), when the function finishes,
 * the original string becomes "ubeck"
 *
 * @param s string
 * @param n number of characters to keep
 *
 * @return void
 */
void take_last(char *s, int n) {

    int length = 0;

    while(s[length] != '\0')
        length++;

    if (n >= length)
        return;

    // replace all the beginning characters with the last n characters
    //
    for (size_t i = 0; i < n; i++)
        s[i] = s[length - n + i];

    // add the null character to cut the string off at the n characters
    //
    s[n] = '\0';
}