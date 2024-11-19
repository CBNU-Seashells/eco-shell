// run_shell.c

/*
    TODO
    eco-shell에서 아무것도 입력하지 않고 엔터키를 누르면 segmentaion fault 발생하는 버그 수정
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

#define STDIN_BUFFER 1000
#define HOME_DIRECTORY_BUFFER 30

struct passwd *pw;

// 홈 디렉터리 (e.g. /home/user1)
char *home_dir;

int executeCommand(char *);

void runShell(void)
{
    char input[STDIN_BUFFER];

    // 현재 작업 디렉터리(절대 경로)
    char *cwd = NULL;

    // '~'을 포함한 현재 작업 디렉터리('~' == 홈 디렉터리)
    char cwd_tilde[BUFSIZ];

    pw = getpwuid(getuid());

    // 문자열 저장 버퍼
    char temp[BUFSIZ];
    int i = 0;
    int j = 0;

    home_dir = pw->pw_dir;

    while (1)
    {
        cwd = getcwd(cwd, BUFSIZ);
        strcpy(cwd_tilde, "~");

        /*
            cwd에 home_dir이 포함되어 있거나 cwd == home_dir일 경우
            커맨드라인에서 현재 작업 디렉터리를 '~'를 포함해서 출력
        */
        if (strstr(cwd, home_dir) != NULL || strcmp(cwd, home_dir) == 0)
        {
            for (i = strlen(home_dir), j = 0; cwd[i] != '\0'; i++, j++)
            {
                temp[j] = cwd[i];
            }
            temp[j] = '\0';
            strcat(cwd_tilde, temp);
            cwd_tilde[strlen(cwd_tilde)] = '\0';

            printf("eco-shell:%s$ ", cwd_tilde);
        }
        /*
            cwd에 home_dir이 포함되어 있지 않고 cwd != home_dir일 경우
            커맨드라인에서 현재 작업 디렉터리를 절대 경로로 출력
        */
        else
        {
            printf("eco-shell:%s$ ", cwd);
        }

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
        cwd = NULL;
    }
}