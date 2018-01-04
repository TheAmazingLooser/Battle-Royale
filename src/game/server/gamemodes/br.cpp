/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include <engine/shared/config.h>

#include <game/server/entities/wall.h>
//#include <game/server/entities/zoomkill.h>
#include <game/server/gamecontext.h>

#include <game/server/gameworld.h>
#include "br.h"

CGameControllerBR::CGameControllerBR(class CGameContext *pGameServer)
: IGameController(pGameServer)
{
	m_pGameType = "Battle Royale";
	//new CWall(&GameServer()->m_World);
}

void CGameControllerBR::Tick()
{
	IGameController::Tick();
}