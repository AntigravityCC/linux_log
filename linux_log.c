
#include "linux_log.h"
#include <time.h>


uint64_t clock_ms_get(void)
{
    struct timespec clock_time;
    uint64_t  time_ms;

    clock_gettime(CLOCK_MONOTONIC, &clock_time);
    time_ms = clock_time.tv_sec * 1000 + clock_time.tv_nsec / 1000000;
    return time_ms;
}

uint64_t log_time(void)
{

#if LOG_SHOW_DATE_ENABLE
    struct timespec clock_time;
    time_t time_seconds;
    uint64_t time_ms;
    char str[50];

    clock_gettime(CLOCK_REALTIME, &clock_time);
    time(&time_seconds); // seconds from 1970-1-1:0:0:0
    time_ms = clock_time.tv_nsec / 1000000;
    sprintf(str,"Date: %s:[ms:%ld] LOG: ",asctime(localtime(&time_seconds)),time_ms);
    printf("%s",str);
#endif

    return clock_ms_get();
}

void linux_log_demo(void)
{
    char str[100];
    LOG_ERROR("This is %s : 0x%.4x ", "LOG_ERRTR",0x00FF);
    LOG_WARN("This is %s ","LOG_WARN!");
    sleep(1);
    LOG_INFO("This is %s ","LOG_INFO");
    LOG_DEBUG("This is %s ","LOG_DEBUG!");

    while(1)
    {
        LOG_INFO("This is %s ","LOG_INFO");
        LOG_DEBUG("This is %s ","LOG_DEBUG!");
        usleep(100000);
    }
}
