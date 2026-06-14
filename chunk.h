//
// Created by Max R on 06/06/2026.
//

#pragma once

#include "common.h"

typedef enum
{
  OP_RETURN
} OpCode_t;

typedef struct
{
  int count;
  int capacity;
  OpCode_t * code;
} Chunk_t;

void initChunk(Chunk_t * chunk);
void writeChunk(Chunk_t * chunk, OpCode_t opCode);
void freeChunk(Chunk_t * chunk);