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
void userinput_init() {

}

/*
 * TODO: implement me!
 *
 * Hint: is there anything else that can be reused here?
 */
void userinput_reset() {

}

/*
 * TODO: implement me!
 * 
 * Hint: reset all values... anything that was dynamically allocated should be
 *       freed!
 */
void userinput_cleanup() {

}

/*
 * TODO: implement me!
 *
 * Hints:
 *   - user input may be messy with its whitespace, be sure the command is not
 *   - command should end with '\0'
 *   - don't forget about the error cases! what behaviors should be undefined?
 */
long handle_user_input(const char *user_input, long strlen, char **command) {
    return 0;
}

/*
 * TODO: implement me!
 *
 * Hints:
 *   - we assume that str is a clean string... given this, what error cases
 *     might occur?
 *   - think about tokens' type... we have a pointer to an array of strings
 *     (which are themselves arrays...) how big is the array of strings?
 *      --> you may need to dynamically resize the array
 *      --> see "man 3 malloc" for further hints
 *   - be sure to modify the input string so that each token ends with a NULL
 *     character!
 */
long tokenize_input(char *str, long strlen, char ***tokens) {
    return 0;
}


