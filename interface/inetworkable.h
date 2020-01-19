#pragma once

#include "../type/type.h"
#include "../type/typecast.h"

typedef struct _INetworkable
{
  END_OF_INHERITANCE;
  void (*delete)(void*);

  int* playerNetworkId;
  void (*Connect)(struct _INetworkable*);
  void (*Disconnect)(struct _INetworkable*);
} INetworkable;

INetworkable* new_INetworkable();
void INetworkable_delete(void* this);