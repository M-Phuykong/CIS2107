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

    puts("#3 diff Test");
    char *s1 = "Book";
    char *s2 = "Back";
    printf("%d\n", diff(s1, s2));

    puts("#4 shorten Test");
    char* shorten_str = "Hello World";
    shorten(shorten_str, 5);
    printf("%s\n", shorten_str);

    return 0;
}
