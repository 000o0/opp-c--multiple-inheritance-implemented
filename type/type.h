#pragma once

#define TYPE_SIZE sizeof(Type) 
#define CHILD_POINTER_SIZE sizeof(void*) 

typedef enum _Type
{
  BasePlayer_t,
  PcPlayer_t,
  XboxPlayer_t,
  INetworkable_t
} Type;