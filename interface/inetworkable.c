#include <stdio.h>

#include "inetworkable.h"
#include "../type/type.h"
#include "../type/typecast.h"

INetworkable* new_INetworkable()
{
  INetworkable instance = 
  {
    __end_of_inheritance__,
    .delete = INetworkable_delete
  };
  
  INetworkable* pinstance = (INetworkable*)tcalloc(sizeof(INetworkable), INetworkable_t);
  if (pinstance != NULL)
		*pinstance = instance;

  return pinstance;
}

void INetworkable_delete(void* this)
{
  tfree(this);
}