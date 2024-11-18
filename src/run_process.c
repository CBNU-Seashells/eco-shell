// run_process.c

/*
    TODO
    다른 명령어는 잘 작동하나 cd 명령어가 작동하지 않는 버그 발견. 해결하기
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
            if (chdir(args[1]) != 0)
            {
                perror("Process execution fail");
            }
        }
    }

    return 0;
}
