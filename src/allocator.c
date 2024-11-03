#include <stdlib.h>

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
