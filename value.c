#include <stdio.h>

#include "value.h"
#include "memory.h"

void initValueArray(ValueArray_t * array)
{
    array -> count = 0;
    array -> capacity = 0;
    array -> constants = nullptr;
}

void writeValueArray(ValueArray_t * array, Value_t value)
{
    if (array -> capacity < array -> count + 1)
    {
        int oldCapacity = array -> capacity;
        array -> capacity = GROW_CAPACITY(oldCapacity);
        array -> constants = GROW_ARRAY(Value_t, array -> constants, oldCapacity, array ->capacity);
    }

    array -> constants[array -> count] = value;
    array -> count++;
}

void freeValueArray(ValueArray_t * array)
{
    FREE_ARRAY(Value_t, array -> constants, array ->capacity);
    initValueArray(array);
}

void printValue(Value_t value)
{
    printf("%g", value);
}