#include "Live2DCubismCore.h"
#include "DebugUtils.h"

csmApi csmVersion csmCallingConvention csmGetVersion()
{
    return 0x5000000;
}

csmApi csmMocVersion csmCallingConvention csmGetLatestMocVersion()
{
    return csmMocVersion_50;
}

csmApi int csmCallingConvention csmHasMocConsistency(void* address, const unsigned int size)
{
    if (address == 0)
    {
        csmiDebugPrint(ERROR, "\"address\" is null", CERROR);
        return 0;
    }
    if (((long) address) % 64 != 0)
    {
        csmiDebugPrint(ERROR, "\"address\" is not aligned", CERROR);
        return 0;
    }

    if (size == 0)
    {
        csmiDebugPrint(ERROR, "\"size\" is null", CERROR);
        return 0;
    }
    if (size % 64 != 0) {
        csmiDebugPrint(ERROR, "\"size\" is not aligned", CERROR);
        return 0;
    }
    return 1;
}
