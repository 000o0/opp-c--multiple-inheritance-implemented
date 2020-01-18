#pragma once

#include <stdbool.h>

#include "../../type/type.h"
#include "../../type/typecast.h"
#include "../object.h"
#include "../../interface/inetworkable.h"

typedef struct _BasePlayer
{
  Object* parent;
  INetworkable* networkable;
  End_of_inheritance;

  char* playerName;
  int playerId;
  int playerNetworkId;

  void (*delete)(struct _BasePlayer*);
} BasePlayer;

BasePlayer* new_BasePlayer(char* playerName, int playerId, int playerNetworkId);

void BasePlayer_delete(BasePlayer* this);
bool BasePlayer_Equals(void* this, void* Object);