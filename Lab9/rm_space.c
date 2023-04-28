#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Removes whitespace characters from the beginning and end of s.
 *
 * @param s1 string
 *
 * @return void
 */
void rm_space(char *s1) {

    // remove left and right whitespace by calling both functions
    //
    rm_left_space(s1);
    rm_right_space(s1);
}