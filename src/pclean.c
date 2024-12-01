// pclean.c

/*
    TODO
    종료해서는 안되는 프로세스까지 모두 종료시키는 문제 발생
    예를 들면 init 프로세스라든가...
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#define INACTIVE_LIMIT 3600 // 1시간
#define PATH_BUF 1000

// 프로세스가 백그라운드 상태인지 확인하는 함수
int isBackgroundProcess(pid_t pid)
{
    char stat_path[PATH_BUF];
    FILE *stat_file;
    char state;

    snprintf(stat_path, sizeof(stat_path), "/proc/%d/stat", pid);
    stat_file = fopen(stat_path, "r");
    if (!stat_file)
        return 0; // 파일을 열 수 없으면 프로세스가 없음

    // 프로세스의 상태(state) 필드 확인
    fscanf(stat_file, "%*d %*s %c", &state);
    fclose(stat_file);

    // 'S'(Sleeping), 'I'(Idle), 'Z'(Zombie)는 백그라운드 상태로 간주
    return (state == 'S' || state == 'I' || state == 'Z');
}

// 오래된 백그라운드 프로세스를 종료하는 함수
void cleanupProcess(void)
{
    DIR *procDir = opendir("/proc");
    struct dirent *entry;

    // 현재 시간
    time_t currentTime = time(NULL);

    char path[PATH_BUF];
    struct stat statBuf;
    int count_process_terminated = 0; // 삭제된 프로세스가 하나라도 있음: 1+, 하나도 없음: 0

    if (!procDir)
    {
        perror("Failed to open /proc");
        return;
    }

    while ((entry = readdir(procDir)) != NULL)
    {
        pid_t pid = atoi(entry->d_name);
        if (pid <= 0)
            continue; // 유효한 PID만 처리

        // /proc/[pid] 디렉토리의 수정 시간 확인
        snprintf(path, sizeof(path), "/proc/%d", pid);
        if (stat(path, &statBuf) == 0)
        {
            double elapsedTime = difftime(currentTime, statBuf.st_mtime);

            // 오래된 백그라운드 프로세스 종료
            if (elapsedTime >= INACTIVE_LIMIT && isBackgroundProcess(pid))
            {
                // sudo를 사용해 프로세스 종료
                char command[256];
                snprintf(command, sizeof(command), "sudo kill -9 %d", pid);

                int result = system(command);

                if (result == 0)
                {
                    printf("관리자 권한으로 프로세스 종료중: PID = %d, 경과시간 = %.0f 초\n", pid, elapsedTime);
                    printf("프로세스 PID = %d 종료됨.\n", pid);
                    count_process_terminated++;
                }
                else
                {
                    fprintf(stderr, "오류. 프로세스를 종료할 수 없음. PID = %d\n", pid);
                }
            }
        }
    }

    closedir(procDir);

    if (count_process_terminated == 0)
    {
        printf("종료할 프로세스가 없음.\n");
    }
    else if (count_process_terminated > 0)
    {
        printf("장시간 동작이 없는 모든 프로세스 종료됨.\n");
    }
}
