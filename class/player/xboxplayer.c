#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "xboxplayer.h"
#include "../../type/type.h"
#include "../../type/typecast.h"
#include "baseplayer.h"
#include "../../interface/inetworkable.h"

XBoxPlayer* new_XBoxPlayer(char* playerName, int playerId, int playerNetworkId, int controllerCount)
{
  BasePlayer* basePlayer = new_BasePlayer(playerName, playerId, playerNetworkId);
  INetworkable* networkable = new_INetworkable();

  XBoxPlayer instance = 
  {
    .parent = basePlayer,
    .iNetworkable = networkable,
    __end_of_inheritance__,
    .delete = XBoxPlayer_delete,
    
    .ControllerCount = controllerCount,

    .Connect = XBoxPlayer_Connect,
    .Disconnect = XBoxPlayer_Disconnect
  };
  
  XBoxPlayer* pinstance = (XBoxPlayer*)tcalloc(sizeof(XBoxPlayer), XboxPlayer_t);
  if (pinstance != NULL)
		*pinstance = instance;
  
  tsetchild(basePlayer, pinstance);
  tsetchild(networkable, pinstance);

  pinstance->iNetworkable->playerNetworkId = &pinstance->parent->playerNetworkId;
  pinstance->iNetworkable->Connect = pinstance->Connect;
  pinstance->iNetworkable->Disconnect = pinstance->Disconnect;

  return pinstance;
}

void XBoxPlayer_delete(XBoxPlayer* this)
{
  this->parent->delete(this->parent);
  this->iNetworkable->delete(this->iNetworkable);

  tfree(this);
}

void XBoxPlayer_Connect(INetworkable* this)
{
  XBoxPlayer* _this = as(this, XboxPlayer_t);

  printf("%s 님이 접속하셨습니다. 컨트롤러 개수: %d\n", _this->parent->playerName, _this->ControllerCount);
}

void XBoxPlayer_Disconnect(INetworkable* this)
{
  XBoxPlayer* _this = as(this, XboxPlayer_t);

  printf("%s 님이 서버에서 나가셨습니다. 컨트롤러 개수: %d\n", _this->parent->playerName, _this->ControllerCount);
}