/*
    Name :      Phuykong Meng
    Section :   04
    Lab :       CIS2107_Lab08_Manual
    Goal :      To design and implement functions taking pointers as arguments
                to process characters and strings.
*/

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// functions prototypes
void *upperLower(const char *s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr(char *line, char *sub);
int countChar(char *line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main()
{
    // random generator
    srand((unsigned int)time(NULL));

    // test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    // test for convertStrtoInt
    printf("\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    // test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5",
                                                                "5.5", "6.5"));

    // test for compareStr
    compareStr("Test1", "Test2");

    // test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    // test for randomize
    randomize();

    // test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    // test for reverse
    puts("\n");
    char line[] = "Hello world";
    reverse(line);

    // test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings \"%s\" inside %s: %d\n", substring, line1,
        countSubstr(line1, substring));

    // test for countChar
    char w = 'w';
    printf("\nNumber of character '%c' inside %s: %d\n", w, line1,
        countChar(line1, w));

    // test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    // test for countWords
    char countstring[] = "hello world!";
    printf("\nNumber of words in string is: %d\n", countWords(countstring));

    // test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    // // test for endsWithed
    // endsWithed(series);
}

// 1.(Displaying Strings in Uppercase and Lowercase)
void *upperLower(const char *s) {

    // print the string in uppercase
    printf("%s", "\nThe string in uppercase is: ");
    for (size_t i = 0; s[i] != '\0'; i++)
        printf("%c", toupper(s[i]));

    // print the string in lowercase
    printf("%s", "\nThe string in lowercase is: ");
    for (size_t i = 0; s[i] != '\0'; i++)
        printf("%c", tolower(s[i]));

    puts("");
}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2,
                    const char *s3, const char *s4) {

    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

// 3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2,
                        const char *s3, const char *s4) {

    return strtof(s1, NULL) + strtof(s2, NULL) +
            strtof(s3, NULL) + strtof(s4, NULL);

}
// 4.(Comparing Strings)
void compareStr(const char *s1, const char *s2) {

    int result = strcmp(s1, s2);

    if (result == 0)
        printf("\n\n%s and %s are equal.", s1, s2);
    else if (result > 0)
        printf("\n\n%s is larger than %s.", s1, s2);
    else
        printf("\n\n%s is smaller than %s.", s1, s2);
}

// 5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {

    int result = strncmp(s1, s2, n);

    if (result == 0)
        printf("\n\n%s and %s are equal.\n", s1, s2);
    else if (result > 0)
        printf("\n\n%s is larger than %s.\n", s1, s2);
    else
        printf("\n\n%s is smaller than %s.\n", s1, s2);
}

// 6.(Random Sentences)
void randomize(void) {

    char *article[] = {"the", "a", "one", "some", "any"};
    char *articleStart[] = {"The", "A", "One", "Some", "Any"};
    char *noun[] = { "boy", "girl", "dog", "town", "car"};
    char *verb[] = { "drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = { "to", "from", "over", "under", "on"};

    // generate random sentences
    for (size_t i = 0; i < 20; i++) {

        if (i == 0)
            puts("");

        printf("%s %s %s %s %s %s.",
            articleStart[rand() % 5], noun[rand() % 5], verb[rand() % 5],
            preposition[rand() % 5], article[rand() % 5], noun[rand() % 5]);
    }

}
// 7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {

    char *pointer = strtok(num, "()- ");

    puts("\n");

    while (pointer != NULL) {
        printf("%s", pointer);
        pointer = strtok(NULL, "()- ");
    }

    return 0;
}
// 8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {

    char *pointer = strtok(text, " ");

    if (text) {
        reverse(strtok(NULL, " "));
        printf("%s ", pointer);
    }

}

// 9.(Counting the Occurrences of a Substring)
int countSubstr(char *line, char *sub) {

    int res = 0;

    char *substring = strstr(line, sub);

    while (substring != NULL) {
        res++;
        substring = strstr(substring + 1, sub);
    }

    return res;
}

// 10.(Counting the Occurrences of a Character)
int countChar(char *line, char c) {
    int res = 0;

    char *substring = strchr(line, c);

    while (substring != NULL)
    {
        res++;
        substring = strchr(substring + 1, c);
    }

    return res;
}

// 11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {

    int res[26] = {0};

    for (size_t i = 0; string[i] != '\0'; i++)
        if (isalpha(string[i]))
            res[tolower(string[i]) - 'a']++;

    for (size_t i = 0; i < 26; i++)
        if (res[i] != 0)
            printf("\n%lu, %lu | %d", i + 'A', i + 'a', res[i]);

}

// 12.(Counting the Number of Words in a String)
int countWords(char *string) {

    int res = 0;

    char *substring = strtok(string, " ");

    puts("");

    while (substring != NULL) {
        res++;
        substring = strtok(NULL, " ");
    }

    return res;
}

// 13.(Strings Starting with "b")
void startsWithB(char *string[]) {





}

// 14.(Strings Ending with "ed")
void endsWithed(char *string[]){

}

