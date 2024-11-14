// power.h
#ifndef POWER_H
#define POWER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 전력 소모량 계산 및 출력 함수
void show_power_consumption();

// CPU 사용률 계산 함수
void get_cpu_usage(long *prev_idle, long *prev_total, double *cpu_usage);

// 전력 소모량 계산 함수
double calculate_power(double cpu_usage);

#endif // POWER_H