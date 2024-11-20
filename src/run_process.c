// run_process.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define HOME_DIRECTORY_BUFFER 30

// 현재 작업 디렉터리
char *cwd = NULL;

// run_shell.c에서 선언한 home_dir
extern char *home_dir;

int i = 0;

// 일반 쉘 명령어 실행 함수
int runProcess(char *args[])
{
    pid_t pid = fork();

    // 포크 실패
    if (pid < 0)
    {
        perror("Fork fail");
        exit(EXIT_FAILURE);
    }
    // 자식 프로세스
    else if (pid == 0)
    {
        // 명령어가 cd인 경우 자식 프로세스가 아닌 부모 프로세스에서 cd를 처리하도록 함
        if (strcmp(args[0], "cd") == 0)
        {
            exit(EXIT_SUCCESS);
        }

        if (execvp(args[0], args) == -1)
        {
            perror("Process execution fail");
            exit(EXIT_FAILURE);
        }
    }
    // 부모 프로세스
    else
    {
        wait(NULL);

        if (strcmp(args[0], "cd") == 0)
        {
            // 커맨드라인에 "cd"를 입력할 경우
            if (args[1] == NULL)
            {
                if (chdir(home_dir) != 0)
                {
                    perror("Process execution fail");
                }
            }
            // 커맨드라인에 "cd ~"를 입력할 경우
            else if (strcmp(args[1], "~") == 0)
            {
                if (chdir(home_dir) != 0)
                {
                    perror("Process execution fail");
                }
            }
            else
            {
                if (chdir(args[1]) != 0)
                {
                    perror("Process execution fail");
                }
            }
        }
    }

    return 0;
}
