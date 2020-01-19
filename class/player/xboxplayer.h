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
  END_OF_INHERITANCE;
  void (*delete)(struct _XBoxPlayer*);

  int ControllerCount;
  
  void (*Connect)(INetworkable*);
  void (*Disconnect)(INetworkable*);
} XBoxPlayer;

XBoxPlayer* new_XBoxPlayer(char* playerName, int playerId, int playerNetworkId, int controllerCount);
void XBoxPlayer_delete(XBoxPlayer* this);

void XBoxPlayer_Connect(INetworkable* this);

void XBoxPlayer_Disconnect(INetworkable* this);