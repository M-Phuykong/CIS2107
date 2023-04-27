#include "stringLibrary.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    puts("# 1 all_letters Test");
    char *s = "Hello World";
    printf("%d\n\n", all_letters(s));

    puts("# 2 num_in_range Test");
    s = "Yellow";
    printf("%d\n\n", num_in_range(s, 'f', 'm'));

    puts("# 3 diff Test");
    char s1[] = "Books";
    char s2[] = "Back";
    printf("%d\n\n", diff(s1, s2));

    puts("# 4 shorten Test");
    char shorten_str[] = "Hello World";
    shorten(shorten_str, 5);
    printf("%s\n\n", shorten_str);

    puts("# 5 len_diff Test");
    char s3[] = "Philadelphia";
    char s4[] = "Hello";
    printf("%d\n\n", len_diff(s3, s4));

    puts("# 6 rm_left_space Test");
    char s5[] = "    Hello World";
    rm_left_space(s5);
    printf("%s\n\n", s5);

    puts("# 7 rm_right_space Test");
    char s6[] = "Hello   ";
    rm_right_space(s6);
    printf("%s\n\n", s6);

    puts("# 8 rm_space Test");
    char s7[] = "    Hello World   ";
    rm_space(s7);
    printf("%s\n\n", s7);

    puts("# 9 find Test");
    char s8[] = "Hello";
    printf("%d\n\n", find(s8, "l"));

    puts("# 10 ptr_to Test");
    char s9[] = "Hello";
    printf("%p\n\n", ptr_to(s9, "l"));

    puts("# 11 is_empty Test");
    char s10[] = " ";
    printf("%d\n\n", is_empty(s10));

    puts("# 12 str_zip Test");
    char s11[] = "Temple";
    char s12[] = "Hello";
    printf("%s\n\n", str_zip(s11, s12));

    puts("# 13 capitalize Test");
    char s13[] = "hello world a";
    capitalize(s13);
    printf("%s\n\n", s13);

    puts("# 14 strcmp_ign_case Test");
    char s14[] = "hello";
    char s15[] = "goodbye";
    printf("%d\n\n", strcmp_ign_case(s14, s15));

    puts("# 15 take_last Test");
    char s16[] = "hello";
    take_last(s16, 3);
    printf("%s\n\n", s16);

    puts("# 16 dedup Test");
    char s17[] = "Hello";
    printf("%s\n\n", dedup(s17));

    puts("# 17 pad Test");
    char s18[] = "Hello";
    printf("%s\n\n", pad(s18, 6));

    puts("# 18 ends_with_ignore_case Test");
    char s19[] = "Coding";
    char s20[] = "ing";
    printf("%d\n\n", ends_with_ignore_case(s19, s20));

    puts("# 19 repeat Test");
    char s21[] = "Hello";
    printf("%s\n\n", repeat(s21, 3, '-'));

    puts("# 20 replace Test");
    char s22[] = "Steph is the X";
    printf("%s\n\n", replace(s22, "X", "Best"));

    puts("# 21 str_connect Test");
    char *strs[] = {"Hello", "World", "Hello", "World"};
    printf("%s\n\n", str_connect(strs, 4, '-'));

    puts("# 22 rm_empties Test");
    char *strs2[] = {"Hello", "World", " ","Hello", "World", " ", " ", NULL};
    rm_empties(strs2);
    for (size_t i = 0; strs2[i] != NULL; i++) {
        printf("%s ", strs2[i]);
    }
    puts("\n");

    puts("# 23 str_chop_all Test");
    char s23[] = "Hello/World/hello/world";
    char **strs3 = str_chop_all(s23, '+');
    for (size_t i = 0; strs3[i] != NULL; i++) {
        printf("%s ", strs3[i]);
    }

    return 0;
}
