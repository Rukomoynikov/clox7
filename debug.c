#include "debug.h"

#include <stdio.h>

int constantInstruction(const char * name, Chunk_t * chunk, int offset)
{
    uint8_t constantIndex = chunk -> code[offset + 1];
    printf("%-16s %4d '", name, constantIndex);
    printValue(chunk -> constants.constants[constantIndex]);
    printf("'\n");
    return offset + 2;
}

int simpleInstruction(const char * name, int offset)
{
    printf("%s\n", name);
    return offset + 1;
}

void disassembleChunk(Chunk_t * chunk, const char * chunkName)
{
    printf("== %s ==\n", chunkName);

    for (int offset = 0; offset < chunk -> count;)
    {
        offset = disassembleInstruction(chunk, offset);
    }
}

int disassembleInstruction(Chunk_t * chunk, int offset)
{
    printf("%04d ", offset);
    OpCode_t instruction = chunk -> code[offset];

    switch (instruction)
    {
    case OP_RETURN:
        printf("OP_RETURN\n");
        break;
    case OP_CONSTANT:
        return constantInstruction("OP_CONSTANT", chunk, offset);
    default:
        printf("Unknown opcode %d\n", instruction);
        return offset + 1;
    }

    return offset + 1;
}