#include <stdio.h>
#include <stdbool.h>
#include "type/type.h"
#include "type/typecast.h"

typedef struct _Object
{
  bool (*Equals)(void*, void*);
  int (*GetHashCode)(void*);
  Type (*GetType)(void*);
} Object;

void new_Object();

void new_Object()
{
  
}

bool Equals(void* this, void* Object)
{
  return GetRealTypeObject(this) == GetRealTypeObject(Object);
}

int main() 
{
  printf("Hello World\n");
  return 0;
}