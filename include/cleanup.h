// cleanup.h
#ifndef CLEANUP_H
#define CLEANUP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

// 불필요한 파일 정리 함수
void cleanup_temp_files();

#endif // CLEANUP_H
