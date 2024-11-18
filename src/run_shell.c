// run_shell.c

/*
    TODO
    eco-shell에서 아무것도 입력하지 않고 엔터키를 누르면 segmentaion fault 발생하는 버그 수정
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STDIN_BUFFER 1000

int executeCommand(char *);

void runShell(void)
{
    char input[STDIN_BUFFER];

    while (1)
    {
        printf("eco-shell> ");
        if (fgets(input, STDIN_BUFFER, stdin) == NULL)
        {
            break;
        }

        // 개행 문자 제거
        input[strcspn(input, "\n")] = '\0';

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
    }
}