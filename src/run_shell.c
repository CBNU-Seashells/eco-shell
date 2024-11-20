// run_shell.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STDIN_BUFFER 1000

int executeCommand(char *);

void runShell(void)
{
    char input[STDIN_BUFFER];
    char *cwd = NULL;

    while (1)
    {
        cwd = getcwd(cwd, BUFSIZ);
        printf("eco-shell:%s$ ", cwd);
        if (fgets(input, STDIN_BUFFER, stdin) == NULL)
        {
            break;
        }

        // 개행 문자 제거
        input[strcspn(input, "\n")] = '\0';

        // 입력이 빈 문자열인 경우 무시하고 다음 루프로 넘어감
        if (strlen(input) == 0)
        {
            continue;
        }

        // exit 명령어 처리
        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting eco-shell...\n");
            break;
        }

        // 명령어 실행
        if (executeCommand(input) == EXIT_FAILURE)
        {
            fprintf(stderr, "Cannot execute the command. Try again\n");
        }

        free(cwd);
    }
}