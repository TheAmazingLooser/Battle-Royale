/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_BR_H
#define GAME_SERVER_GAMEMODES_BR_H

#include <game/server/entity.h>
#include <game/server/gamecontext.h>

class CGameControllerBR : public IGameController
{
public:

	CGameControllerBR(class CGameContext *pGameServer);
	virtual void Tick();
};

#endif

