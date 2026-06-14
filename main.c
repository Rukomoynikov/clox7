#include "chunk.h"
#include "debug.h"

int main(void)
{
    Chunk_t chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1);
    int constant_2 = addConstant(&chunk, 2);

    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);

    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant_2);

    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk, "main");
    freeChunk(&chunk);
    return 0;
}
