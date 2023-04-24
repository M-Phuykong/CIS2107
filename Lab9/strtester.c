#include "stringLibrary.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    puts("#1 all_letters Test");
    char *s = "Hello World";
    printf("%d\n\n", all_letters(s));

    puts("#2 num_in_range Test");
    s = "Yellow";
    printf("%d\n\n", num_in_range(s, 'f', 'm'));

    puts("#3 diff Test");
    char s1[] = "Book";
    char s2[] = "Back";
    printf("%d\n\n", diff(s1, s2));

    puts("#4 shorten Test");
    char shorten_str[] = "Hello World";
    shorten(shorten_str, 5);
    printf("%s\n\n", shorten_str);

    puts("#5 len_diff Test");
    char s3[] = "Philadelphia";
    char s4[] = "Hello";
    printf("%d\n\n", len_diff(s3, s4));

    puts("#6 rm_left_space Test");
    char s5[] = "    Hello World";
    rm_left_space(s5);
    printf("%s\n\n", s5);

    puts("#7 rm_right_space Test");
    char s6[] = "Hello   ";
    rm_right_space(s6);
    printf("%s\n\n", s6);

    puts("#8 rm_space Test");
    char s7[] = "    Hello World   ";
    rm_space(s7);
    printf("%s\n\n", s7);

    puts("#9 find Test");
    char s8[] = "Hello";
    printf("%d\n\n", find(s8, "l"));

    puts("#10 ptr_to Test");
    char s9[] = "Hello";
    printf("%p\n\n", ptr_to(s9, "l"));

    puts("#11 is_empty Test");
    char s10[] = " ";
    printf("%d\n\n", is_empty(s10));


    return 0;
}
