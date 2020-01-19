#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "type.h"

#define CHILD_POINTER_SIZE sizeof(void*) 

#define END_OF_INHERITANCE void* end_of_inheritance
#define __end_of_inheritance__ .end_of_inheritance = NULL

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