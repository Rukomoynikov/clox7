#pragma once

#include "chunk.h"

void disassembleChunk(Chunk_t * chunk, const char * chunkName);
int disassembleInstruction(Chunk_t * chunk, int offset);