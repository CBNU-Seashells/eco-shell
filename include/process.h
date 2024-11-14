// process.h
#ifndef PROCESS_H
#define PROCESS_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

// 프로세스 실행 함수
int run_process(char *args[]);

#endif // PROCESS_H
