#pragma once

#include <stdbool.h>
#include "type.h"

#define End_of_inheritance void* End_of_inheritance
#define __End_of_inheritance__ NULL

void* GetRealTypeObject(void* Object);

bool is(void* Object, Type type);
void* as(void* Object, Type type);

void* tcalloc(size_t size, Type type, void* child);
void tfree(void* ptr);