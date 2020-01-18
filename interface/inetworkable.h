#pragma once

#include "../type/type.h"
#include "../type/typecast.h"

typedef struct _INetworkable
{
  End_of_inheritance;

  int* playerNetworkId;

  void (*delete)(void*);
  void (*Connect)(void*);
  void (*Disconnect)(void*);
} INetworkable;

INetworkable* new_INetworkable();

void INetworkable_delete(void* this);