// command.c

/*
    TODO
    특수 명령어에는 환경 친화적 기능 명령어 함수가 들어가야 함
    프로세스 정리, 파일 정리, 에코모드 구현하기
*/

#include <stdio.h>
#include <string.h>

#define ARGS_BUFFER 50

void showPowerConsumption(void);
void cleanupFiles(char* []);
void cleanupProcess(void);
void ecoMode(void);
int runProcess(char *[]);

int executeCommand(char *input)
{
    char *args[ARGS_BUFFER];
    char *token;
    int i = 0;

    // 명령어 토큰화
    token = strtok(input, " ");

    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;

    // 환경 친화 명령어 실행
    if (strcmp(args[0], "power") == 0)
    {
        // 전력 소모량 출력 명령 - power
        showPowerConsumption();

        return 0;
    }
    else if (strcmp(args[0], "fclean") == 0)
    {
        // 불필요한 파일 정리 명령 - fclean
        cleanupFiles(args);

        return 0;
    }
    else if (strcmp(args[0], "pclean") == 0)
    {
        // 불필요한 프로세스 종료 명령 - pclean
        cleanupProcess();

        return 0;
    }
    else if (strcmp(args[0], "ecomode"))
    {
        // 에코모드 - ecomode
        // 추후 옵션 인자 처리를 위해 주석으로 args를 넣었음
        ecoMode(/*args*/);
    }

    // 일반 쉘 명령어 실행
    return runProcess(args);
}
