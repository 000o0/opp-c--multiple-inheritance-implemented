#pragma once

#include <stdbool.h>

#include "../../type/type.h"
#include "../../type/typecast.h"
#include "baseplayer.h"
#include "../../interface/inetworkable.h"

typedef enum _OSType
{
  windows_10,
  windows_7,
  windows_vista
} OSType;

typedef struct _PcPlayer
{
  BasePlayer* parent;
  INetworkable* iNetworkable;
  End_of_inheritance;
  void (*delete)(struct _PcPlayer*);

  char* PCName;
  OSType osType;
  
  void (*Connect)(void*);
  void (*Disconnect)(void*);
} PcPlayer;

PcPlayer* new_PcPlayer(char* playerName, int playerId, int playerNetworkId, char* PCName, OSType osType);
void PcPlayer_delete(PcPlayer* this);

void PcPlayer_Connect(void* this);

void PcPlayer_Disconnect(void* this);