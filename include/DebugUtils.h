#include "stdio.h"

#define csmiDebugPrint(type, base, i) printf("\033[0m\033[1;%dm[%s/%s] [%s -> %s:%d] %s \033[0m", i, type, __TIME__, __FILE__, __func__, __LINE__, base)
#define csmiDebugPrintArg(type, base, i, ...) printf("\033[0m\033[1;%dm[%s/%s] [%s -> %s:%d] ", i, type, __TIME__, __FILE__, __func__, __LINE__);printf(base, __VA_ARGS__);printf("\033[0m")

#define DEBUG "DEBUG"
#define INFO "INFO"
#define WARN "WARN"
#define ERROR "ERROR"
#define FATAL "FATAL"

#define CERROR 31
#define CWARN 33
#define CINFO 32
#define CDEBUG 36
