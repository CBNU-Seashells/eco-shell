// process.c
#include "../include/process.h"

int run_process(char *args[]) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return -1;
    }
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Execvp failed");
            exit(EXIT_FAILURE);
        }
    } else {
        wait(NULL);
    }
    return 0;
}
