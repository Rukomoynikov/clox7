//
// Created by Max R on 06/06/2026.
//

#pragma once

#include "common.h"
#include "value.h"

typedef enum
{
  OP_RETURN,
  OP_CONSTANT,
} OpCode_t;

typedef struct
{
  int count;
  int capacity;
  OpCode_t * code;
  ValueArray_t constants;
  int * lines;
} Chunk_t;

void initChunk(Chunk_t * chunk);
void writeChunk(Chunk_t * chunk, OpCode_t opCode, int line);
void freeChunk(Chunk_t * chunk);
int addConstant(Chunk_t * chunk, Value_t value);