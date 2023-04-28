#include <stdio.h>
#include <stdlib.h>

#include "stringLibrary.h"

/**
 * Words is an array of string terminated with a NULL pointer.The function
 * removes any empty strings(i.e., strings of length 0) from the array.
 *
 * @param words array of strings
 *
 * @return void
 */
void rm_empties(char **words) {

    int i = 0;
    int word_count = 0;

    for (size_t i = 0; words[i] != NULL; i++) {
        if (words[i][0] != '\0') {
            word_count++;
        }
    }

    // allocate 2d array
    //
    char **new_words = malloc(sizeof(char *) * (word_count + 1));
    int counter = 0;
    int word_length = 0;

    for (size_t i = 0; words[i] != NULL; i++) {

        word_length = 0;

        // check for the word length for each string
        //
        for (size_t j = 0; words[i][j] != '\0'; j++) {

            if (words[i][j] != ' ')
                word_length++;
            else
                break;
        }

        // if there is at least one character in the string then we know that
        // the string is not empty
        //
        if (word_length > 0) {

            new_words[counter] = malloc(word_length + 1);

            for (size_t j = 0; j < word_length; j++) {
                new_words[counter][j] = words[i][j];
            }

            new_words[counter][word_length] = '\0';
            counter++;
        }
    }

    new_words[counter] = NULL;

    // copy all the new words into the old array
    //
    for (size_t i = 0; i < word_count; i++) {
        words[i] = new_words[i];
    }

    // free the new array from memory
    //
    free(new_words);

}