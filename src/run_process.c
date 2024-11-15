// run_process.c

/*
    TODO
    다른 명령어는 잘 작동하나 cd 명령어가 작동하지 않는 버그 발견. 해결하기
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 일반 쉘 명령어 실행 함수
int run_process(char *args[]) {
    pid_t pid = fork();

    // 포크 실패
    if (pid < 0) {
        perror("Fork fail");
        exit(EXIT_FAILURE);
    }
    // 자식 프로세스
    else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Process execution fail");
            exit(EXIT_FAILURE);
        }
    } 
    // 부모 프로세스
    else {
        wait(NULL);
    }

    return 0;
}
