#include "input.h"

#include "util/memset.h"
#include "util/string.h"

#include <stdlib.h> // for malloc, realloc, free only!

/*
 * TODO: implement me!
 *
 * Hint: what should the initial values of each of the attributes be input
 *       attributes be?
 */
void userinput_init() { userinput_reset(); }

/*
 * TODO: implement me!
 *
 * Hint: is there anything else that can be reused here?
 */
void userinput_reset() {
    memset(input_buffer, 0, BUFFER_SIZE);
    input_length = 0;
    if (tokens != NULL) {
        free(tokens);
        tokens = NULL;
    }
    num_tokens = 0;
}

/*
 * TODO: implement me!
 *
 * Hint: reset all values... anything that was dynamically allocated should be
 *       freed!
 */
void userinput_cleanup() { userinput_reset(); }

/*
 * Remove extra whitespace and add '\0'
 */
long handle_user_input(const char *user_input, long strlen, char **command) {
    if (strlen < 0 || !user_input || !command) {
        return -1;
    }

    char *clean_input = malloc(strlen + 1); // + 1 for '\0'
    if (clean_input == NULL) {
        return -1;
    }

    long left = 0;
    long right = 0;

    // Skip leading spaces
    while (right < strlen && user_input[right] == ' ') {
        right++;
    }

    // Clean up the string
    for (; right < strlen; ++right) {
        char current_char = user_input[right];

        // End of line
        if (current_char == '\n') {
            break;
        }

        // Copy the first whitespace and other chars
        if (current_char != ' ' || user_input[right - 1] != ' ') {
            clean_input[left] = current_char;
            left++;
        }
    }

    // Remove trailing space
    if (left > 0 && clean_input[left - 1] == ' ') {
        left--;
    }

    // End the string
    clean_input[left] = '\0';

    // Shrink space
    char *optimized = realloc(clean_input, left + 1);
    if (optimized == NULL) {
        return -1;
    }
    clean_input = optimized;

    // Pass clean optimal string to the callee
    *command = clean_input;

    input_length = left;
    return left;
}

/*
 * Tokenize a clean string
 */
long tokenize_input(char *str, long strlen, char ***tokens) {
    if (strlen < 0 || !str || !tokens) {
        return -1;
    }

    if (strlen == 0) {
        *tokens = NULL;
        return 0;
    }

    // Tokenize (spaces become '\0')
    *tokens = malloc((strlen + 2) *
                     sizeof(char *)); // Create pointers to every string
    if (*tokens == NULL) {
        return -1;
    }
    (*tokens)[0] = &str[0];

    long num_tokens = 1;
    for (long left = 0; left < strlen; ++left) {
        if (str[left] == ' ') {
            str[left] = '\0';
            (*tokens)[num_tokens] = &str[left + 1];
            num_tokens++;
        }
    }
    (*tokens)[num_tokens] = NULL;

    // Optimize space
    char **tmp =
        realloc(*tokens, (num_tokens + 1) * sizeof(char *)); // +1 for NULL
    if (tmp == NULL) {
        free(*tokens);
        *tokens = NULL;
        return -1;
    }
    *tokens = tmp;

    return num_tokens;
}
