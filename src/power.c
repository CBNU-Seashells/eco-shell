// power.c

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 1000

typedef struct{
    int energy_now;
    int energy_full;
    int power_now;
}POWER;

const char* energy_now_path = "/sys/class/power_supply/BAT1/energy_now";
const char* energy_full_path = "/sys/class/power_supply/BAT1/energy_full";
const char* power_now_path = "/sys/class/power_supply/BAT1/power_now";

void showPowerConsumption(void) {
    FILE* fp_energy_now = fopen(energy_now_path, "r");
    FILE* fp_energy_full = fopen(energy_full_path, "r");
    FILE* fp_power_now = fopen(power_now_path, "r");
    
    POWER power = {0, 0, 0};

    char buf[MAX_BUF];
    
    power.energy_now = atoi(fgets(buf, sizeof(buf), fp_energy_now));
    power.energy_full = atoi(fgets(buf, sizeof(buf), fp_energy_full));
    power.power_now = atoi(fgets(buf, sizeof(buf), fp_power_now));

    double energy_now_wh = (double)power.energy_now / 1000000;
    double energy_now_percent = ((double)power.energy_now / power.energy_full) * 100;
    double power_now_w = (double)power.power_now / 1000000;
    double remaining_hours = (double)energy_now_wh / power_now_w;

    printf("현재 전력 소비량: %.2fW\n", power_now_w);
    printf("현재 배터리 잔량: %.2fWH(%.2f%%)\n", energy_now_wh, energy_now_percent);
    printf("남은 배터리 지속 시간: %.2fH\n", remaining_hours);
}
