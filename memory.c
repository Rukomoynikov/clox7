//
// Created by Max R on 08/06/2026.
//

#include "memory.h"
#include <stdlib.h>

void * reallocate(void * pointer, size_t oldCapacity, size_t newCapacity)
{
    if (newCapacity == 0)
    {
        free(pointer);
        return nullptr;
    }

    void * result = realloc(pointer, newCapacity);
    if (result == nullptr) exit(1);
    return result;
}