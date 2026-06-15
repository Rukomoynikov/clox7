#include "chunk.h"
#include "debug.h"

int main(void)
{
    Chunk_t chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1);
    int constant_2 = addConstant(&chunk, 2);

    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant_2, 123);

    writeChunk(&chunk, OP_RETURN, 123);
    disassembleChunk(&chunk, "main");
    freeChunk(&chunk);
    return 0;
}
