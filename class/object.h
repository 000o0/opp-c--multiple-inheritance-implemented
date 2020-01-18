#pragma once

#include <stdbool.h>
#include "../type/type.h"

typedef struct _Object
{
  void (*delete)(void*);
  bool (*Equals)(void*, void*);
  Type (*GetType)(void*);
} Object;

Object* new_Object();

void Object_delete(void* this);
bool Object_Equals(void* this, void* Object);
Type Object_GetType(void* this);