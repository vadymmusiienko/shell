#ifndef __EXEC_H__
#define __EXEC_H__

#include <sys/types.h> // for pid_t

/****************
 * Declarations *
 ***************/

// for the execve environment
char *env;

/*************
 * Functions *
 ************/

/*
 * Initialize execution engine attributes for shell
 */
void exec_init();

/*
 * Clean up the attributes from execution
 */
void exec_cleanup();

/*
 * Takes a command and arguments array as input and executes the command in
 * a child process created by the function.
 *
 * @param command: the binary executable to run
 * @param argv: the arguments to the command to run
 * @returns: the pid_t of the child process created on success, else error code
 */
pid_t execute_process(const char *command, char **argv);

#endif // __EXEC_H__
