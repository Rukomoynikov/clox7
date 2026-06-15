//
// Created by Max R on 06/06/2026.
//

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk_t * chunk)
{
    chunk -> count = 0;
    chunk -> capacity = 0;
    chunk -> code = nullptr;
    chunk -> lines = nullptr;
    initValueArray(&chunk -> constants);
}

void writeChunk(Chunk_t * chunk, OpCode_t opCode, int line)
{
    if (chunk -> capacity < chunk -> count + 1)
    {
        int oldCapacity = chunk -> capacity;
        chunk -> capacity = GROW_CAPACITY(oldCapacity);
        chunk -> code = GROW_ARRAY(OpCode_t, chunk -> code, oldCapacity, chunk -> capacity);
        chunk -> lines = GROW_ARRAY(int, chunk -> lines, oldCapacity, chunk -> capacity);
    }

    chunk -> code[chunk -> count] = opCode;
    chunk -> lines[chunk -> count] = line;
    chunk -> count++;
}

void freeChunk(Chunk_t * chunk)
{
    FREE_ARRAY(OpCode_t, chunk -> code, chunk -> capacity);
    FREE_ARRAY(int, chunk -> lines, chunk -> capacity);
    freeValueArray(&chunk -> constants);
    initChunk(chunk);
}

int addConstant(Chunk_t * chunk, Value_t value)
{
    writeValueArray(&chunk ->constants, value);
    return chunk -> constants.count - 1;
}