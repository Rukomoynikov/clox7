#include "chunk.h"
#include "debug.h"

int main(void)
{
    Chunk_t chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk, "main");
    freeChunk(&chunk);
    return 0;
}
