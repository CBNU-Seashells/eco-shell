// eco_shell.h
#ifndef ECO_SHELL_H
#define ECO_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>

// 모듈 헤더 포함
#include "command.h"
#include "process.h"
#include "power.h"
#include "cleanup.h"

// 전역 상수
#define BUFFER_SIZE 1024

// 함수 프로토타입
void run_shell();

#endif // ECO_SHELL_H
