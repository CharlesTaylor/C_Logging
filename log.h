#ifndef __LOG__
#define __LOG__

#include <stdio.h>

#define LOG_LEVEL_SILENT  0
#define LOG_LEVEL_NORMAL  1
#define LOG_LEVEL_VERBOSE 2
#define LOG_LEVEL_DEBUG   4
//#define LOG_LEVEL_SO_ON 8 16 32 ..
#ifndef LOG_FILENAME
#define LOG_FILENAME "log.txt"
#endif

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_NORMAL
#endif

FILE *__logger_log_file;

#define LOGGER_INIT() do{\
	__logger_log_file = fopen(LOG_FILENAME,"w+"); \
	}while(0)

#define LOGGER_PRINT(...) fprintf(__logger_log_file,__VA_ARGS__)

#define LOGGER_LOG(LEVEL,...) do{\
	if(LOG_LEVEL >= (LEVEL)){\
		LOGGER_PRINT(__VA_ARGS__);\
	}\
	}while(0)

#define LOGGER_LOG_EXC(LEVEL,...) do{\
	if(LOG_LEVEL & (LEVEL)){\
		LOGGER_PRINT(__VA_ARGS__);\
	}\
	}while(0)

#define LOGGER_FREE() fclose(__logger_log_file)

#endif
