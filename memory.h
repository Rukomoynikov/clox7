//
// Created by Max R on 08/06/2026.
//

#include "common.h"

#pragma once

void * reallocate(void * pointer, size_t oldCapacity, size_t newCapacity);

#define GROW_CAPACITY(oldCapacity) ((oldCapacity) < 8 ? 8 : (oldCapacity) * 2)

#define GROW_ARRAY(type, pointer, oldCapacity, newCapacity) \
    (type *)reallocate(pointer, sizeof(type) * (oldCapacity), sizeof(type) * newCapacity)

#define FREE_ARRAY(type, pointer, oldCapacity) \
    (reallocate(pointer, sizeof(type) * (oldCapacity), 0))