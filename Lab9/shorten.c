#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Shortens the string s to new_len. If the original length of s is less than
 * or equal to new_lens, s is unchanged.
 *
 * @param s string
 * @param new_len new length
 *
 * @return  void
 */
void shorten(char *s, int new_len) {

    int str_len = 0;
    char* new_string = malloc(new_len + 1);

    while (s[str_len] != '\0')
        str_len++;

    if (new_len >= str_len)
        return;

    for (int i = 0; i < new_len; i++){
        new_string[i] = s[i];
    }
    new_string[new_len] = '\0';

    // *s = new_string;
    printf("%p %p", s, new_string);


    // free(new_string);

}