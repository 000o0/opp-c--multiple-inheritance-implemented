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
  while (1)
  {
    void* indexobject = (void*)*(size_t*)(RootObject + memberindex);
    if (indexobject != NULL)
    {
      void* recursionresult = as_recursion(indexobject, searchtype);
      if (recursionresult == NULL)
        memberindex += sizeof(void*);
      else
        return recursionresult;
    }
    else
      return NULL;
  }

  return NULL;
}

void* tgetchild(void* Object)
{
  void* ptr = ((char*)Object) - (size_t)(CHILD_POINTER_SIZE + TYPE_SIZE);
  
  if (ptr == NULL)
    return NULL;
  else
    return (void*)(*(size_t*)ptr);
}

void tsetchild(void* Object, void* child)
{
  *((size_t*)((char*)Object - (CHILD_POINTER_SIZE + TYPE_SIZE))) = (size_t)child;
}

Type gettype(void* Object)
{
  return *(Type*)((char*)Object - TYPE_SIZE);
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
    void* indexobject = (void*)*(size_t*)(RealTypeObject + memberindex);

    if(indexobject == NULL)
    {
      ((void (*)(void*))(void*)*(size_t*)(RealTypeObject + memberindex + sizeof(void*)))(RealTypeObject);
      break;
    }
    memberindex+=sizeof(void*);
  }
}