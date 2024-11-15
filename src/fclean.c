// fclean.c

/*
    TODO
    삭제해야 할 파일은 아래와 같다.
    1. 임시파일(/tmp/)
    2. 캐시파일(/var/cache/)
    3. 로그파일(/var/log/)
    일단 아래 cleanup_temp_files 함수로 임시파일 삭제만 구현해 보려 했으나 접근 권한이 없어 삭제되지 않음
    나머지 파일 삭제기능 추가 및 권한 문제 해결하기

    옵션 만들기
    1. -a 삭제할 수 있는 모든 파일 삭제
    2. -t 임시파일만 삭제
    3. -l 로그파일만 삭제
    4. -c 캐시파일만 삭제
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define FILEPATH_BUFFER 500

void cleanup_files(void) {
    const char* temp_dir = "/tmp/";
    struct dirent* entry;

    DIR* dir = opendir(temp_dir);

    if (dir == NULL) {
        perror("Failed to open /tmp/");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        char filepath[FILEPATH_BUFFER];

        snprintf(filepath, sizeof(filepath) - 1, "%s%s", temp_dir, entry->d_name);
        if(remove(filepath) ==0){
            printf("Temporary files cleaned up.\n");
        }
        else{
            fprintf(stderr, "Failed to cleanup temporary files\n");
            exit(EXIT_FAILURE);
        }
    }

    closedir(dir);
}