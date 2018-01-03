/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include <engine/shared/config.h>

#include <game/server/entities/wall.h>
#include <game/server/entities/zoomkill.h>
#include <game/server/gamecontext.h>

#include <game/server/gameworld.h>
#include "br.h"

CGameControllerBR::CGameControllerBR(class CGameContext *pGameServer)
: IGameController(pGameServer)
{
	m_pGameType = "Battle Royale";
	new CWall(&GameServer()->m_World);

	// YoungFlyme's style xD Not workin good tho :c
	for (int i=0;i<g_Config.m_SvAntiZoomNum;i++)
	{
		new CZoomkill(&GameServer()->m_World);
	}//CZoomkill
}

void CGameControllerBR::Tick()
{
	IGameController::Tick();
}
