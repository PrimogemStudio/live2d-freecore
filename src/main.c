#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DebugUtils.h"
#include "Live2DCubismCore.h"

void* allocate(const size_t size)
{
    return malloc(size);
}

void deallocate(void* memory)
{
    free(memory);
}

void* allocateAligned(const size_t size, const int alignment)
{
    int offset = alignment - 1 + sizeof(void*);
    void* allocation = allocate(size + ((int) offset));
    size_t alignedAddress = ((size_t) allocation) + sizeof(void*);
    int shift = alignedAddress % alignment;
    if (shift != 0) alignedAddress += (alignment - shift);
    ((void**)alignedAddress)[-1] = allocation;
    return (void*)alignedAddress;
}

void deallocateAligned(void* alignedMemory)
{
    deallocate(((void**)alignedMemory)[-1]);
}

struct FileData {
    char* data;
    size_t size;
};
typedef struct FileData FileData;

FileData readFile(const char* path) {
    FILE* fp = fopen(path, "r");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* data = malloc(sizeof(char) * size);
    fread(data, size+1, 1, fp);
    fclose(fp);

    FileData fd;
    fd.data = data;
    fd.size = size;

    return fd;
}

int main() {
    const char* path = "/home/coder2/extsources/LpkUnpacker/Test/character/FileReferences_Moc_0.moc3";
    FileData data = readFile(path);
    
    // for (int d = 0; d < data.size; d++) printf("%c\n", data.data[d]);
    csmiDebugPrintArg(INFO, "%d TEMP!\n", CINFO, data.size);
    void* buff = allocateAligned(data.size, 64);
    memcpy(data.data, buff, data.size);
    csmHasMocConsistency(buff, 0);

    return 0;
}
