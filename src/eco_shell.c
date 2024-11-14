// eco_shell.c
#include "../include/eco_shell.h"

void run_shell() {
    char input[BUFFER_SIZE];

    while (1) {
        printf("eco-shell> ");
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) break;

        // 개행 문자 제거
        input[strcspn(input, "\n")] = '\0';

        // exit 명령어 처리
        if (strcmp(input, "exit") == 0) {
            printf("Exiting eco-shell...\n");
            break;
        }

        // 명령어 실행
        if (execute_command(input) == -1) {
            fprintf(stderr, "Command execution failed\n");
        }
    }
}

int main() {
    printf("Welcome to Eco-Shell!\n");
    run_shell();
    return 0;
}
