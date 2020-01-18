#pragma once

#include <stdbool.h>
#include "../type/type.h"
#include "../type/typecast.h"

typedef struct _Object
{
  End_of_inheritance;
  
  void (*delete)(void*);
  bool (*Equals)(void*, void*);
  Type (*GetType)(void*);
} Object;

Object* new_Object();

void Object_delete(void* this);
bool Object_Equals(void* this, void* Object);
Type Object_GetType(void* this);