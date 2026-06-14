#include "debug.h"

#include <stdio.h>

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
        printf("OP_RETURN");
        break;
    default:
        printf("Unknown opcode %d\n", instruction);
        return offset + 1;
    }

    return offset + 1;
}