#pragma once

#include <stdbool.h>

#include "../../type/type.h"
#include "../../type/typecast.h"
#include "baseplayer.h"
#include "../../interface/inetworkable.h"

typedef struct _XBoxPlayer
{
  BasePlayer* parent;
  INetworkable* iNetworkable;
  End_of_inheritance;
  void (*delete)(struct _XBoxPlayer*);

  int ControllerCount;
  
  void (*Connect)(void*);
  void (*Disconnect)(void*);
} XBoxPlayer;

XBoxPlayer* new_XBoxPlayer(char* playerName, int playerId, int playerNetworkId, int controllerCount);
void XBoxPlayer_delete(XBoxPlayer* this);

void XBoxPlayer_Connect(void* this);

void XBoxPlayer_Disconnect(void* this);