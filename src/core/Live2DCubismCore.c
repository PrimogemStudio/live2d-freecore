#include "Live2DCubismCore.h"

csmApi csmVersion csmCallingConvention csmGetVersion()
{
    return 0x5000000;
}

csmApi csmMocVersion csmCallingConvention csmGetLatestMocVersion()
{
    return csmMocVersion_50;
}
