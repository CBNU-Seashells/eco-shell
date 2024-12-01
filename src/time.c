// time.c

#include <stdio.h>
#include <time.h>

void nowTime(char now_time[], int size)
{
    time_t seconds = time(NULL);
    struct tm *now = localtime(&seconds);
    
    snprintf(now_time, size, "%04d/%02d/%02d %02d:%02d:%02d", 1900 + now->tm_year, 
            now->tm_mon + 1, now->tm_mday, now->tm_hour, 
            now->tm_min, now->tm_sec);
}