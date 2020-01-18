#include <stdio.h>
#include <stdbool.h>

#include "object.h"
#include "../type/type.h"
#include "../type/typecast.h"

Object* new_Object()
{
  Object instance = 
  {
    .delete = Object_delete,
    .Equals = Object_Equals,
    .GetType = Object_GetType
  };
  
  Object* pinstance = (Object*)tcalloc(sizeof(Object), Object_t, NULL);
  if (pinstance != NULL)
		*pinstance = instance;

  return pinstance;
}

void Object_delete(void* this)
{
  tfree(this);
}

bool Object_Equals(void* this, void* Object)
{
  return GetRealTypeObject(this) == GetRealTypeObject(Object);
}

Type Object_GetType(void* this)
{
  void* pinstance = GetRealTypeObject(this);
  return *(Type*)(pinstance - TYPE_SIZE); 
}