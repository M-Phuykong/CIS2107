#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Shortens the string s to new_len. If the original length of s is less than
 * or equal to new_lens, s is unchanged.
 *
 * @param s string
 * @param new_len new length
 *
 * @return void
 */
void shorten(char *s, int new_len) {

    int str_len = 0;

    while (s[str_len] != '\0')
        str_len++;

    if (new_len >= str_len)
        return;

    // shorten the string by setting the new length to the null terminator
    //
    s[new_len] = '\0';
}