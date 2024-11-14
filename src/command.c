// command.c
#include "../include/command.h"
#include "../include/process.h"
#include "../include/power.h"
#include "../include/cleanup.h"

int execute_command(char *input) {
    char *args[64];
    char *token;
    int i = 0;

    // 명령어 토큰화
    token = strtok(input, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // 특수 명령어 처리
    if (strcmp(args[0], "power") == 0) {
        show_power_consumption();
        return 0;
    } else if (strcmp(args[0], "cleanup") == 0) {
        cleanup_temp_files();
        return 0;
    }

    // 일반 명령어 실행
    return run_process(args);
}
