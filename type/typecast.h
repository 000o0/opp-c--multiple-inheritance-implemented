#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "type.h"

#define End_of_inheritance void* End_of_inheritance
#define __End_of_inheritance__ NULL

void* GetRealTypeObject(void* Object);

bool is(void* Object, Type type);
void* as(void* Object, Type type);

void* as_recursion(void* RootObject, Type searchtype);

void* tgetchild(void* Object);
void tsetchild(void* Object, void* child);
Type gettype(void* Object);
void* tcalloc(size_t size, Type type);
void tfree(void* ptr);

void delete(void* Object);