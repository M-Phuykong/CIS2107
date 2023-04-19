#include "stringLibrary.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    puts("#1 all_letters Test");
    char *s = "Hello World";
    printf("%d\n", all_letters(s));

    puts("#2 num_in_range Test");
    s = "Yellow";
    printf("%d\n", num_in_range(s, 'f', 'm'));

    return 0;
}
