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

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1B[34m"
#define ANSI_COLOR_MAGENTA "\x1B[35m"
#define ANSI_COLOR_CYAN "\x1B[36m"
#define RESET "\x1B[0m"

// functions prototypes
void upperLower(const char *s);
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
void startsWithB(char *string[], size_t size);
void endsWithed(char *string[], size_t size);

int main()
{
    // random generator
    srand((unsigned int)time(NULL));

    // test for upperLower
    const char test[] = "This iS A Test";
    printf("\n%s%s1./ UpperLower Test\n%s", RESET, ANSI_COLOR_YELLOW, RESET);
    upperLower(test);

    // test for convertStrtoInt
    printf("\n%s%s2./ The sum of 4 strings is:%s %d\n", RESET, ANSI_COLOR_YELLOW,
                                    RESET, convertStrtoInt("3", "4", "5", "6"));

    // test for convertStrtoFloat
    printf("\n%s%s3./ The sum of 4 strings is:%s %.2f", RESET, ANSI_COLOR_YELLOW,
                            RESET, convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    // test for compareStr
    printf("\n\n%s%s4./ compareStr Test%s", RESET, ANSI_COLOR_YELLOW, RESET);
    compareStr("Test1", "Test2");

    // test for comparePartialStr
    printf("\n\n%s%s5./ comparePartialStr Test%s", RESET, ANSI_COLOR_YELLOW, RESET);
    comparePartialStr("Test1", "Test2", 4);

    // test for randomize
    printf("\n%s%s6./ Randomized Sentence:%s\n", RESET, ANSI_COLOR_YELLOW, RESET);
    randomize();

    // test for tokenize number
    char str[] = "(267) 436-6281";
    printf("\n\n%s%s7./ Tokenized Number: %s", RESET, ANSI_COLOR_YELLOW, RESET);
    tokenizeTelNum(str);

    // test for reverse
    char line[] = "Hello world";
    printf("\n\n%s%s8./ Reversed string %s \"%s\"%s: %s", RESET,
        ANSI_COLOR_YELLOW, ANSI_COLOR_BLUE, line, ANSI_COLOR_YELLOW, RESET);
    reverse(line);

    // test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\n%s%s9./ Number of Substrings %s\"%s\"%s inside %s\"%s\"%s:%s %d\n",
            RESET, ANSI_COLOR_YELLOW, ANSI_COLOR_BLUE, substring,
            ANSI_COLOR_YELLOW, ANSI_COLOR_BLUE, line1, ANSI_COLOR_YELLOW,
            RESET, countSubstr(line1, substring));

    // test for countChar
    char w = 'w';
    printf("\n%s%s10./ Number of character %s'%c'%s inside %s\"%s\"%s:%s %d\n",
            RESET, ANSI_COLOR_YELLOW, ANSI_COLOR_BLUE, w, ANSI_COLOR_YELLOW,
            ANSI_COLOR_BLUE, line1, ANSI_COLOR_YELLOW, RESET,
            countChar(line1, w));

    // test for countAlpha
    char str1[] = "Hello it's me.";
    printf("\n%s%s11./ Number of alpha characters in %s\"%s\"%s:%s\n",
            RESET, ANSI_COLOR_YELLOW, ANSI_COLOR_BLUE, str1, ANSI_COLOR_YELLOW,
            RESET);
    countAlpha(str1);

    // test for countWords
    char countstring[] = "hello world!";
    printf("\n%s%s12./ Number of words in string is:%s %d\n", RESET, ANSI_COLOR_YELLOW,
        RESET, countWords(countstring));

    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};

    // test for startsWithB
    printf("\n%s%s13./ Words that start with B:\n\n%s", RESET,
        ANSI_COLOR_YELLOW, RESET);
    startsWithB(series, sizeof(series) / sizeof(series[0]));

    // test for endsWithed
    printf("\n%s%s14./ Words that ends with ed:\n\n%s", RESET,
        ANSI_COLOR_YELLOW, RESET);
    endsWithed(series, sizeof(series) / sizeof(series[0]));
}

/**
 * upperLower: 1.Display Strings in Uppercase and Lowercase
 *
 * @param s pointer to a constant char to be printed in uppercase and lowercase
 *
 * @return void
 */
void upperLower(const char *s) {

    // print the string in uppercase
    //
    printf("%s", "\nThe string in uppercase is: ");
    for (size_t i = 0; s[i] != '\0'; i++)
        printf("%c", toupper(s[i]));

    // print the string in lowercase
    //
    printf("%s", "\nThe string in lowercase is: ");
    for (size_t i = 0; s[i] != '\0'; i++)
        printf("%c", tolower(s[i]));

    puts("");
}

/**
 * convertStrtoInt: 2.Converting Strings to Integers for Calculations
 *
 * @param s1 pointer to a constant char to be converted to int
 * @param s2 pointer to a constant char to be converted to int
 * @param s3 pointer to a constant char to be converted to int
 * @param s4 pointer to a constant char to be converted to int
 *
 * @return int
 */
int convertStrtoInt(const char *s1, const char *s2,
                    const char *s3, const char *s4) {

    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

/**
 * convertStrtoFloat: 3.Converting Strings to Floating Point for Calculations
 *
 * @param s1 pointer to a constant char to be converted to float
 * @param s2 pointer to a constant char to be converted to float
 * @param s3 pointer to a constant char to be converted to float
 * @param s4 pointer to a constant char to be converted to float
 *
 * @return float
 */
float convertStrtoFloat(const char *s1, const char *s2,
                        const char *s3, const char *s4) {

    return strtof(s1, NULL) + strtof(s2, NULL) +
            strtof(s3, NULL) + strtof(s4, NULL);
}

/**
 * compareStr: 4.Comparing Strings
 *
 * @param s1 pointer to a constant char to be compared
 * @param s2 pointer to a constant char to be compared
 *
 * @return void
 */
void compareStr(const char *s1, const char *s2) {

    int result = strcmp(s1, s2);

    if (result == 0)
        printf("\n\n%s and %s are equal.", s1, s2);
    else if (result > 0)
        printf("\n\n%s is larger than %s.", s1, s2);
    else
        printf("\n\n%s is smaller than %s.", s1, s2);
}

/**
 * comparePartialStr: 5.Comparing Partial Strings
 *
 * @param s1 pointer to a constant char to be compared
 * @param s2 pointer to a constant char to be compared
 * @param n number of characters to be compared
 *
 * @return void
 */
void comparePartialStr(const char *s1, const char *s2, int n) {

    int result = strncmp(s1, s2, n);

    if (result == 0)
        printf("\n\n%s and %s are equal.\n", s1, s2);
    else if (result > 0)
        printf("\n\n%s is larger than %s.\n", s1, s2);
    else
        printf("\n\n%s is smaller than %s.\n", s1, s2);
}

/**
 * randomize: 6.Randomizing Strings
 *
 * @return void
 */
void randomize(void) {

    char *article[] = {"the", "a", "one", "some", "any"};
    char *articleStart[] = {"The", "A", "One", "Some", "Any"};
    char *noun[] = { "boy", "girl", "dog", "town", "car"};
    char *verb[] = { "drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = { "to", "from", "over", "under", "on"};

    // generate random sentences
    //
    for (size_t i = 0; i < 20; i++) {

        if (i == 0)
            puts("");

        printf("%s %s %s %s %s %s.",
            articleStart[rand() % 5], noun[rand() % 5], verb[rand() % 5],
            preposition[rand() % 5], article[rand() % 5], noun[rand() % 5]);
    }

}

/**
 * tokenizeTelNum: 7.Tokenizing Telephone Numbers
 *
 * @param num pointer to a char to be tokenized
 *
 * @return int
 */
int tokenizeTelNum(char *num) {

    char *pointer = strtok(num, "()- ");

    while (pointer != NULL) {
        printf("%s", pointer);
        pointer = strtok(NULL, "()- ");
    }

    return 0;
}

/**
 * reverse: 8.Display a Sentence with its Words Reversed
 *
 * @param text string to be reversed
 *
 * @return void
 */
void reverse(char *text) {

    char *pointer = strtok(text, " ");

    if (text) {
        reverse(strtok(NULL, " "));
        printf("%s ", pointer);
    }

}

/**
 * countSubstr: 9.Counting the Occurrences of a Substring
 *
 * @param line string
 * @param sub substring that we are searching for
 *
 * @return int
 */
int countSubstr(char *line, char *sub) {

    int res = 0;

    char *substring = strstr(line, sub);

    while (substring != NULL) {
        res++;
        substring = strstr(substring + 1, sub);
    }

    return res;
}

/**
 * countChar: 10.Counting the Occurrences of a Character
 *
 * @param line string
 * @param c character that we are counting occurrences of
 *
 * @return int
 */
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

/**
 * countAlpha: 11.Count the Letters of the Alphabet in a String
 *
 * @param string string to be searched in
 *
 * @return void
 */
void countAlpha(char *string) {

    int res[26] = {0};

    for (size_t i = 0; string[i] != '\0'; i++)
        if (isalpha(string[i]))
            res[tolower(string[i]) - 'a']++;

    for (size_t i = 0; i < 26; i++)
        if (res[i] != 0)
            printf("\n%c, %c | %d", (char)(i + 'A'), (char)(i + 'a'), res[i]);
}

/**
 * countWords: 12.Count the Number of Words in a String
 *
 * @param string string to be searched in
 *
 * @return int
 */
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

/**
 * startsWithB: 13.Print strings starting with "b"
 *
 * @param string array of strings
 * @param size size of the array
 *
 * @return void
 */
void startsWithB(char *string[], size_t size) {

    for (size_t i = 0; i < size; i++)
        if (string[i][0] == 'b' || string[i][0] == 'B')
            printf("%s\n", string[i]);

}

/**
 * endsWithed: 14.Print strings ending with "ed"
 *
 * @param string array of strings
 * @param size size of the array
 *
 * @return void
 */
void endsWithed(char *string[], size_t size){

    for (size_t i = 0; i < size; i++){

        if (string[i][strlen(string[i]) - 2] == 'e' &&
            string[i][strlen(string[i]) - 1] == 'd')
            printf("%s\n", string[i]);
    }
}

