#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "typecast.h"
#include "type.h"

void* GetRealTypeObject(void* Object)
{
  void* realType = Object;

  while(1)
  {
    void* childaddress = tgetchild(realType);
    if (childaddress == NULL)
      return realType;
    else
      realType = childaddress;
  }
}

bool is(void* Object, Type type)
{
  void* realObj = GetRealTypeObject(Object);

  return (as_recursion(realObj, type) != NULL) ? true : false;
}

void* as(void* Object, Type type)
{
  void* realObj = GetRealTypeObject(Object);

  return as_recursion(realObj, type);
}

void* as_recursion(void* RootObject, Type searchtype)
{
  if (gettype(RootObject) == searchtype)
    return RootObject;

  int memberindex = 0;
  while(1)
  {
    void* indexobject = (void*)(RootObject + memberindex);

    if(indexobject != NULL)
      return as_recursion(indexobject, searchtype);
    else
      return NULL;
    memberindex+=4;
  }
}

void* tgetchild(void* Object)
{
  size_t* childaddress = ((size_t*)(Object - (CHILD_POINTER_SIZE + TYPE_SIZE)));
  if (childaddress == NULL)
    return NULL;
  else
    return (void*)(*childaddress);
}

void tsetchild(void* Object, void* child)
{
  *((size_t*)(Object - (CHILD_POINTER_SIZE + TYPE_SIZE))) = (size_t)child;
}

Type gettype(void* Object)
{
  return *(Type*)(Object - TYPE_SIZE);
}

void* tcalloc(size_t size, Type type)
{
  void* ptr = calloc(1, (CHILD_POINTER_SIZE + TYPE_SIZE + size));
  *(Type*)(ptr + CHILD_POINTER_SIZE) = type;
  return (void*)(ptr + (CHILD_POINTER_SIZE + TYPE_SIZE));
}

void tfree(void* ptr)
{
  free((void*)(ptr - (CHILD_POINTER_SIZE + TYPE_SIZE)));
}

void delete(void* Object)
{
  void* RealTypeObject = GetRealTypeObject(Object);

  int memberindex = 0;
  while(1)
  {
    void* indexobject = (void*)(RealTypeObject + memberindex);

    if(indexobject == NULL)
    {
      ((void (*)(void*))(indexobject + 4))(RealTypeObject);
      break;
    }
    memberindex+=4;
  }
}