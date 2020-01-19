#include <stdio.h>

#include "type/type.h"
#include "type/typecast.h"
#include "class/player/baseplayer.h"
#include "class/player/pcplayer.h"
#include "class/player/xboxplayer.h"
#include "interface/inetworkable.h"

int main() 
{
  PcPlayer* player = new_PcPlayer("김수한무", 723455332, 23443234, "김수한무의 PC", windows_10);
  
  //BasePlayer* baseplayer = as(player, BasePlayer_t);
  //INetworkable* networkable = as(player, INetworkable_t);

  printf("%s", player->PCName);

  //delete(player);
  return 0;
}