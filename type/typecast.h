#pragma once

#include <stdbool.h>
#include "type.h"

void* GetRealTypeObject(void* Object);

bool is(void* Object, Type type);
void* as(void* Object, Type type);

void* tcalloc(size_t size, Type type, void* child);
void tfree(void* ptr);