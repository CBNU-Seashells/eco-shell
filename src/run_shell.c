// run_shell.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

#define STDIN_BUFFER 1000
#define HOME_DIRECTORY_BUFFER 30

// 현재 작업 디렉터리(절대 경로)
char *cwd = NULL;

// '~'을 포함한 현재 작업 디렉터리('~' == 홈 디렉터리)
char cwd_tilde[BUFSIZ];

/*
    홈 디렉터리 (e.g. /home/user1)
    최초 1회 홈 디렉터리 정보를 받아서 home_dir에 저장한다.
*/
char *home_dir;

int executeCommand(char *);

/*
    eco-shell을 작동시킨다.

    최초 1회 홈 디렉터리 정보를 받아 home_dir에 저장하고
    이후엔 while 무한 루프를 통해 명령행에 명령어를 계속 입력받고
    명령행에 "exit"을 입력하면 무한 루프를 빠져나와 eco-shell을 정상 종료한다.
*/
void runShell(void)
{
    // 명령행에서 입력받은 문자열을 저장할 버퍼
    char input[STDIN_BUFFER];

    // 임시 문자열 저장 버퍼
    char temp[BUFSIZ];

    int i = 0;
    int j = 0;

    home_dir = getenv("HOME");

    // setenv("PATH", , 1);

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

            printf("\033[1;32meco-shell\033[0m:\033[1;34m%s\033[0m$ ", cwd_tilde);
        }
        /*
            cwd에 home_dir이 포함되어 있지 않고 cwd != home_dir일 경우
            커맨드라인에서 현재 작업 디렉터리를 절대 경로로 출력
        */
        else
        {
            printf("\033[1;32meco-shell\033[0m:\033[1;34m%s\033[0m$ ", cwd);
        }

        // 명령행에서 입력을 받을 때 에러 발생 시 eco-shell 종료
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
            printf("에코쉘을 종료합니다. 다음에 또 봐요!\n");
            break;
        }

        // 명령어 실행
        if (executeCommand(input) == EXIT_FAILURE)
        {
            // 다른 함수에서 명령어를 입력했을 때 실행에 실패하면 EXIT_FAILURE를 반환하도록 함.
            // 그래서 executeCommand 함수의 반환값이 EXIT_FAILURE면 아래 문장이 출력되는 것을 기대했는데,
            // 그냥 일반적인 bash 쉘에서 나오는 오류문이 출력된다.
            // 이유는 모르겠다...
            fprintf(stderr, "명령어를 실행할 수 없습니다. 다시 시도하세요.\n");
        }

        free(cwd);
        cwd = NULL;
    }
}