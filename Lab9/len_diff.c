#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Shortens the string s to new_len. If the original length of s is less than
 * or equal to new_lens, s is unchanged.
 *
 * @param s1 string 1
 * @param s2 string 2
 *
 * @return int
 */
int len_diff(char *s1, char *s2)
{

    int str_len1 = 0;
    int str_len2 = 0;

    while (s1[str_len1] != '\0')
        str_len1++;

    while (s2[str_len2] != '\0')
        str_len2++;

    if (str_len1 >= str_len2)
        return str_len1 - str_len2;
    else
        return str_len2 - str_len1;
}