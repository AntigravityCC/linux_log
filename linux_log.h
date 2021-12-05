#ifndef _LINUX_LOG_H_
#define _LINUX_LOG_H_

#include <stdio.h>
#include <stdint.h>


#define ANSI_BLACK   "30m"      /* Black */
#define ANSI_RED     "31m"      /* Red */
#define ANSI_GREEN   "32m"      /* Green */
#define ANSI_YELLOW  "33m"      /* Yellow */
#define ANSI_BLUE    "34m"      /* Blue */
#define ANSI_MAGENTA "35m"      /* Magenta */
#define ANSI_CYAN    "36m"      /* Cyan */
#define ANSI_WHITE   "37m"      /* White */

#define ANSI_START      "\033["
#define ANSI_RESET      "\033[0m"

#define COLOR_INFO    ANSI_GREEN
#define COLOR_DEBUG   ANSI_BLUE
#define COLOR_WARN    ANSI_YELLOW
#define COLOR_ERROR   ANSI_RED

//#define LOG_NEW_LINE  ""  /* no new line */ 
#define LOG_NEW_LINE  "\n"  /* new line */ 
#define LOG_MORE_MSG_ENABLE     1  /* more mesage .such as file,fun,line,time */ 
#define LOG_SHOW_DATE_ENABLE    1  /* date in more mesage */ 

/* level switch */ 
#define  LOG_ERROR_ENABLE    1
#if LOG_ERROR_ENABLE
#define  LOG_WARN_ENABLE     1
#if LOG_WARN_ENABLE
#define  LOG_INFO_ENABLE     1
#if LOG_INFO_ENABLE
#define  LOG_DEBUG_ENABLE    1
#endif
#endif
#endif


#if (!LOG_MORE_MSG_ENABLE) /*LOG_MORE_MSG_ENABLE*/

#if LOG_ERROR_ENABLE
#define LOG_ERROR(format, args...)\
printf( ANSI_START COLOR_ERROR "[ERROR]: " format LOG_NEW_LINE ANSI_RESET, ##args )
#else 
#define LOG_ERROR(...)
#endif

#if LOG_WARN_ENABLE
#define LOG_WARN(format, args...)\
printf( ANSI_START COLOR_WARN "[WARN]: " format LOG_NEW_LINE ANSI_RESET, ##args )
#else
#define LOG_WARN(...)
#endif

#if LOG_INFO_ENABLE
#define LOG_INFO(format, args...)\
printf( ANSI_START COLOR_INFO "[INFO]: " format LOG_NEW_LINE ANSI_RESET, ##args )
#else
#define LOG_INFO(...)
#endif

#if LOG_DEBUG_ENABLE
#define LOG_DEBUG(format, args...)\
printf( ANSI_START COLOR_DEBUG "[DEBUG]: " format LOG_NEW_LINE ANSI_RESET, ##args )
#else
#define LOG_DEBUG(...)
#endif

#else               /*LOG_MORE_MSG_ENABLE*/

/*error*/
#if LOG_ERROR_ENABLE
#define LOG_ERROR(format, args...)\
printf( ANSI_START COLOR_ERROR "[ERROR]--[%s]-[%s]-[%d]-[%ld]: " format LOG_NEW_LINE ANSI_RESET, __FILE__, __FUNCTION__ , __LINE__, log_time(),##args)
#else 
#define LOG_ERROR(...)
#endif

/*warn*/
#if LOG_WARN_ENABLE
#define LOG_WARN(format, args...)\
printf( ANSI_START COLOR_WARN "[WARN]--[%s]-[%s]-[%d]-[%ld]: " format LOG_NEW_LINE ANSI_RESET, __FILE__, __FUNCTION__ , __LINE__, log_time(),##args)
#else
#define LOG_WARN(...)
#endif

/*info*/
#if LOG_INFO_ENABLE
#define LOG_INFO(format, args...)\
printf( ANSI_START COLOR_INFO  "[INFO]--[%s]-[%s]-[%d]-[%ld]: "  format LOG_NEW_LINE ANSI_RESET, __FILE__, __FUNCTION__ , __LINE__, log_time(),##args)
#else
#define LOG_INFO(...)
#endif

/*debug*/
#if LOG_DEBUG_ENABLE
#define LOG_DEBUG(format, args...)\
printf( ANSI_START COLOR_DEBUG "[DEBUG]--[%s]-[%s]-[%d]-[%ld]: " format LOG_NEW_LINE ANSI_RESET, __FILE__, __FUNCTION__ , __LINE__,log_time(), ##args)
#else
#define LOG_DEBUG(...)
#endif

#endif          /*LOG_MORE_MSG_ENABLE*/

extern void linux_log_demo(void);

#endif /*_LINUX_LOG_H_*/