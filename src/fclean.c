// fclean.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define FILEPATH_BUFFER 500

void cleanupTmpFiles(){
    const char* temp_dir = "/tmp/";
    struct dirent* entry;
    char filepath[FILEPATH_BUFFER];
    
    // /tmp/ 디렉토리를 엽니다.
    DIR* dir = opendir(temp_dir);
    if (dir == NULL) {
        perror("Failed to open /tmp/");
        return;
    }

    // /tmp/의 파일들을 순회합니다.
    while ((entry = readdir(dir)) != NULL) {
        // "." 및 ".." 디렉토리는 건너뜁니다.
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // 파일의 전체 경로 생성
        snprintf(filepath, sizeof(filepath), "%s%s", temp_dir, entry->d_name);

        // 삭제 명령어 생성
        char command[FILEPATH_BUFFER + 100];
        snprintf(command, sizeof(command), "sudo rm -rf %s", filepath);

        // 시스템 호출로 파일 삭제
        int result = system(command);
        if (result == 0) {
            printf("Deleted: %s\n", filepath);
        } else {
            fprintf(stderr, "Failed to delete: %s\n", filepath);
        }
    }

    // 디렉토리 닫기
    closedir(dir);
    printf("Temporary files cleanup completed with sudo.\n");
}

void cleanupLogFiles(){
    const char* temp_dir = "/var/log/";
    struct dirent* entry;
    char filepath[FILEPATH_BUFFER];
    
    // /tmp/ 디렉토리를 엽니다.
    DIR* dir = opendir(temp_dir);
    if (dir == NULL) {
        perror("Failed to open /var/log/");
        return;
    }

    // /tmp/의 파일들을 순회합니다.
    while ((entry = readdir(dir)) != NULL) {
        // "." 및 ".." 디렉토리는 건너뜁니다.
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // 파일의 전체 경로 생성
        snprintf(filepath, sizeof(filepath), "%s%s", temp_dir, entry->d_name);

        // 삭제 명령어 생성
        char command[FILEPATH_BUFFER + 100];
        snprintf(command, sizeof(command), "sudo rm -rf %s", filepath);

        // 시스템 호출로 파일 삭제
        int result = system(command);
        if (result == 0) {
            printf("Deleted: %s\n", filepath);
        } else {
            fprintf(stderr, "Failed to delete: %s\n", filepath);
        }
    }

    // 디렉토리 닫기
    closedir(dir);
    printf("Log files cleanup completed with sudo.\n");
}

void cleanupCacheFiles(){
    const char* temp_dir = "/var/cache/";
    struct dirent* entry;
    char filepath[FILEPATH_BUFFER];
    
    // /tmp/ 디렉토리를 엽니다.
    DIR* dir = opendir(temp_dir);
    if (dir == NULL) {
        perror("Failed to open /var/cache/");
        return;
    }

    // /tmp/의 파일들을 순회합니다.
    while ((entry = readdir(dir)) != NULL) {
        // "." 및 ".." 디렉토리는 건너뜁니다.
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // 파일의 전체 경로 생성
        snprintf(filepath, sizeof(filepath), "%s%s", temp_dir, entry->d_name);

        // 삭제 명령어 생성
        char command[FILEPATH_BUFFER + 100];
        snprintf(command, sizeof(command), "sudo rm -rf %s", filepath);

        // 시스템 호출로 파일 삭제
        int result = system(command);
        if (result == 0) {
            printf("Deleted: %s\n", filepath);
        } else {
            fprintf(stderr, "Failed to delete: %s\n", filepath);
        }
    }

    // 디렉토리 닫기
    closedir(dir);
    printf("Cache files cleanup completed with sudo.\n");
}

void cleanupAllFiles(){
    cleanupTmpFiles();
    printf("\n");

    cleanupLogFiles();
    printf("\n");

    cleanupCacheFiles();
    printf("\n");
}

void cleanupHelp(void){
    printf("fclean: delete useless files to clear disk space.\n");
    printf("Usage: fclean <option>\n");
    printf("  -t: clear temporary files\n");
    printf("  -l: clear log files\n");
    printf("  -c: clear cache files\n");
    printf("  -a: clear all files above\n");
}

void cleanupFiles(char* cleanup_args[]) {
    if (cleanup_args[1] == NULL) {
        cleanupHelp();
        return;
    }

    if(strcmp(cleanup_args[1], "-t") == 0){
        cleanupTmpFiles();
    }
    else if(strcmp(cleanup_args[1], "-l") == 0){
        cleanupLogFiles();
    }
    else if(strcmp(cleanup_args[1], "-c") == 0){
        cleanupCacheFiles();
    }
    else if(strcmp(cleanup_args[1], "-a") == 0){
        cleanupAllFiles();
    }
    else if(strcmp(cleanup_args[1], "-h") == 0){
        cleanupHelp();
    }
    else{
        fprintf(stderr, "%s: Not a valid option for fclean\n", cleanup_args[1]);
        cleanupHelp();
    }
}