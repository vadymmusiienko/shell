#include "exec.h"

#include <stdlib.h> // for malloc, realloc, and free
#include <unistd.h> // for fork

/*
 * TODO: implement me!
 */
void exec_init(char *environment) { env = environment; }

/*
 * TODO: implement me!
 */
void exec_cleanup() { env = NULL; }

/*
 * TODO: implement me!
 */
pid_t execute_process(const char *command, char **argv) {
    pid_t pid = fork();

    // Fork failed
    if (pid < 0) {
        return pid;
    }

    // Child
    if (pid == 0) {
        char *const envp[] = {env, NULL};
        execve(command, argv, envp);
        return -1;
    }

    return pid;
}
