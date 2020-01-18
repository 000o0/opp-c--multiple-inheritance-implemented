#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "type.h"

void* GetRealTypeObject(void* Object)
{
  return NULL;
}

bool is(void* Object, Type type)
{
  return true;
}

void* as(void* Object, Type type)
{
  return NULL;
}

void* tcalloc(size_t size, Type type, void* child)
{
  void* ptr = calloc(1, (CHILD_POINTER_SIZE + TYPE_SIZE + size));
  *(size_t*)ptr = (size_t)child;
  *(Type*)(ptr + CHILD_POINTER_SIZE) = type;
  return (void*)(ptr + (CHILD_POINTER_SIZE + TYPE_SIZE));
}

void tfree(void* ptr)
{
  free((void*)(ptr - (CHILD_POINTER_SIZE + TYPE_SIZE)));
}