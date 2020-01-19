#pragma once

#include <stdbool.h>

#include "../../type/type.h"
#include "../../type/typecast.h"

typedef struct _BasePlayer
{
  END_OF_INHERITANCE;
  void (*delete)(struct _BasePlayer*);

  char* playerName;
  int playerId;
  int playerNetworkId;
} BasePlayer;

BasePlayer* new_BasePlayer(char* playerName, int playerId, int playerNetworkId);
void BasePlayer_delete(BasePlayer* this);