#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "baseplayer.h"
#include "../object.h"
#include "../../type/type.h"
#include "../../type/typecast.h"

BasePlayer* new_BasePlayer(char* playerName, int playerId, int playerNetworkId)
{
  Object* object = new_Object();
  object->Equals = BasePlayer_Equals;

  INetworkable* networkable = new_INetworkable();

  size_t strlength = strlen(playerName) + 1;
	char* cloneplayerName = (char*)calloc(1, strlength);
	if (cloneplayerName != NULL)
		strcpy(cloneplayerName, playerName);

  BasePlayer instance = 
  {
    .parent = object,
    .networkable = networkable,
    __End_of_inheritance__,
    
    .playerName = cloneplayerName,
    .playerId = playerId,
    .playerNetworkId = playerNetworkId,
    
    .delete = BasePlayer_delete
  };
  
  BasePlayer* pinstance = (BasePlayer*)tcalloc(sizeof(BasePlayer), BasePlayer_t, NULL);
  if (pinstance != NULL)
		*pinstance = instance;

  return pinstance;
}

void BasePlayer_delete(BasePlayer* this)
{
  this->parent->delete(this->parent);
  this->networkable->delete(this->networkable);

  free(this->playerName);
  tfree(this);
}

bool BasePlayer_Equals(void* this, void* Object)
{
  BasePlayer* _this = this;
  BasePlayer* _Object = GetRealTypeObject(Object);

  if (_this->playerId == _Object->playerId)
    return true;
  else
    return false;
}