#include <stdio.h>

#include "class/object.h"

int main() 
{
  Object* object = new_Object();
  object->delete(object);
  return 0;
}