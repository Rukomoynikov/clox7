#pragma once

typedef double Value_t;

typedef struct
{
    int count;
    int capacity;
    Value_t * constants;
} ValueArray_t;

void initValueArray(ValueArray_t * array);
void writeValueArray(ValueArray_t * array, Value_t value);
void freeValueArray(ValueArray_t * array);
void printValue(Value_t value);