// power.c
#include "../include/power.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CPU 사용률을 계산하는 함수
void get_cpu_usage(long *prev_idle, long *prev_total, double *cpu_usage) {
    FILE *fp;
    char buffer[128];
    unsigned long user, nice, system, idle;
    unsigned long total;

    // /proc/stat 파일에서 CPU 사용량 읽기
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to read /proc/stat");
        return;
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %lu %lu %lu %lu", &user, &nice, &system, &idle);
    fclose(fp);

    total = user + nice + system + idle;
    long idle_diff = idle - *prev_idle;
    long total_diff = total - *prev_total;

    // CPU 사용률 계산
    if (total_diff != 0) {
        *cpu_usage = 100.0 * (1.0 - ((double)idle_diff / (double)total_diff));
    } else {
        *cpu_usage = 0.0;
    }

    // 이전 상태 업데이트
    *prev_idle = idle;
    *prev_total = total;
}

// CPU 사용률 기반 전력 소모량 추정 함수
double calculate_power(double cpu_usage) {
    // 단순한 전력 소모량 계산 (기본 전력 + CPU 사용률에 비례한 전력)
    // 예시: 기본 전력 20W + CPU 사용률에 따라 최대 30W 추가
    double base_power = 20.0; // 기본 전력 (W)
    double max_additional_power = 30.0; // 추가 가능한 최대 전력 (W)
    return base_power + (cpu_usage / 100.0) * max_additional_power;
}

// 전력 소모량 출력 함수
void show_power_consumption() {
    static long prev_idle = 0;
    static long prev_total = 0;
    double cpu_usage = 0.0;

    // CPU 사용률 계산
    get_cpu_usage(&prev_idle, &prev_total, &cpu_usage);

    // 전력 소모량 계산
    double power_consumption = calculate_power(cpu_usage);

    // 결과 출력
    printf("현재 CPU 사용률: %.2f%%\n", cpu_usage);
    printf("추정 전력 소모량: %.2fW\n", power_consumption);
}

