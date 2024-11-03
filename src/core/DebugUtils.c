#include "Live2DCubismCore.h"

csmLogFunction logCallback = 0;

csmApi void csmCallingConvention csmSetLogFunction(csmLogFunction func)
{
    logCallback = func;
}

csmApi csmLogFunction csmCallingConvention csmGetLogFunction()
{
    return logCallback;
}
