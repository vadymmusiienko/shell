#ifndef __INPUT_H__
#define __INPUT_H__

#define BUFFER_SIZE 128

/****************
 * Declarations *
 ***************/

// input string buffer from user
char input_buffer[BUFFER_SIZE];
long input_length;

// attributes for parsing input string
char **tokens; // array of "strings" for each token
long num_tokens;

/*************
 * Functions *
 ************/

/*
 * Initialize string parsing attributes for an input
 */
void userinput_init();

/*
 * Free memory and reset values for next iteration through
 */
void userinput_reset();

/*
 * Clean up the attributes from input parsing
 */
void userinput_cleanup();

/*
 * Receive a user input through the string "buf" and return a "cleaned" version
 * of the same string. This means no extra or trailing whitespace in the string
 * with a null-character terminating the string (e.g., '\0'). The user input
 * string will terminate upon receiving a newline character ('\n') as this will
 * signify the end of the command.
 *
 * @param user_input: the (messy) user input string
 * @param strlen: the length of the user input string (to avoid buffer
 *                overflow!)
 * @param command: a pointer to the newly created string (likely a pointer to
 *                 be dereferenced created on the callers stack), this is how
 *                 the clean string is returned to the caller
 * @returns: the length of the clean input string on success, else -1
 */
long handle_user_input(const char *user_input, long strlen, char **command);

/*
 * Transform a clean user string into an array of tokens. The array should end
 * with a NULL token to indicate the end of the array.
 *
 * @param str: the clean input string to tokenize
 * @param strlen: the length of the input string (to avoid buffer overflow!)
 * @param tokens: a pointer to the array of tokens to be created, this is how
 *                the tokens will be returned to the caller
 * @returns: the number of tokens created on success, else -1
 */
long tokenize_input(char *str, long strlen, char ***tokens);

#endif // __INPUT_H__
