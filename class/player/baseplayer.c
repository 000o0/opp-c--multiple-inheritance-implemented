#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "baseplayer.h"
#include "../../type/type.h"
#include "../../type/typecast.h"

BasePlayer* new_BasePlayer(char* playerName, int playerId, int playerNetworkId)
{
  size_t strlength = strlen(playerName) + 1;
	char* cloneplayerName = (char*)calloc(1, strlength);
	if (cloneplayerName != NULL)
		strcpy(cloneplayerName, playerName);

  BasePlayer instance = 
  {
    __end_of_inheritance__,
    .delete = BasePlayer_delete,
    
    .playerName = cloneplayerName,
    .playerId = playerId,
    .playerNetworkId = playerNetworkId
  };
  
  BasePlayer* pinstance = (BasePlayer*)tcalloc(sizeof(BasePlayer), BasePlayer_t);
  if (pinstance != NULL)
		*pinstance = instance;

  return pinstance;
}

void BasePlayer_delete(BasePlayer* this)
{
  free(this->playerName);
  tfree(this);
}