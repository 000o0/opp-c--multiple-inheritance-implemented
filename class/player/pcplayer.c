#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "pcplayer.h"
#include "baseplayer.h"
#include "../../type/type.h"
#include "../../type/typecast.h"

PcPlayer* new_PcPlayer(char* playerName, int playerId, int playerNetworkId, char* PCName, OSType osType)
{
  BasePlayer* basePlayer = new_BasePlayer(playerName, playerId, playerNetworkId);
  INetworkable* networkable = new_INetworkable();

  size_t strlength = strlen(PCName) + 1;
	char* clonePCName = (char*)calloc(1, strlength);
	if (clonePCName != NULL)
		strcpy(clonePCName, PCName);

  PcPlayer instance = 
  {
    .parent = basePlayer,
    .iNetworkable = networkable,
    __end_of_inheritance__,
    .delete = PcPlayer_delete,
    
    .PCName = clonePCName,
    .osType = osType,
    .Connect = PcPlayer_Connect,
    .Disconnect = PcPlayer_Disconnect
  };
  
  PcPlayer* pinstance = (PcPlayer*)tcalloc(sizeof(PcPlayer), PcPlayer_t);
  if (pinstance != NULL)
		*pinstance = instance;
  
  tsetchild(basePlayer, pinstance);
  tsetchild(networkable, pinstance);

  pinstance->iNetworkable->playerNetworkId = &pinstance->parent->playerNetworkId;
  pinstance->iNetworkable->Connect = pinstance->Connect;
  pinstance->iNetworkable->Disconnect = pinstance->Disconnect;

  return pinstance;
}

void PcPlayer_delete(PcPlayer* this)
{
  this->parent->delete(this->parent);
  this->iNetworkable->delete(this->iNetworkable);

  free(this->PCName);
  tfree(this);
}

void PcPlayer_Connect(INetworkable* this)
{
  PcPlayer* _this = as(this, PcPlayer_t);
  printf("%s 님이 접속하셨습니다. PC이름: %s OS: %d\n", _this->parent->playerName, _this->PCName, _this->osType);
}

void PcPlayer_Disconnect(INetworkable* this)
{
  PcPlayer* _this = as(this, PcPlayer_t);
  printf("%s 님이 서버에서 나가셨습니다. PC이름: %s OS: %d\n", _this->parent->playerName, _this->PCName, _this->osType);
}