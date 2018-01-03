/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */

#include <game/generated/protocol.h>
#include <game/server/gamecontext.h>
#include "zoomkill.h"
#include <engine/shared/config.h>

// Puurly only laser here
CZoomkill::CZoomkill(CGameWorld *pGameWorld)
: CEntity(pGameWorld, CGameWorld::ENTTYPE_LASER)
{
	m_Pos = vec2((3+(rand()%(GameServer()->Collision()->GetWidth()-4)))*32, (3+(rand()%(GameServer()->Collision()->GetHeight()-4)))*32);
	
	m_Id = Server()->SnapNewID();

	GameWorld()->InsertEntity(this);
}

void CZoomkill::Reset()
{
	GameServer()->m_World.DestroyEntity(this);
}

CZoomkill::~CZoomkill()
{
	Server()->SnapFreeID(m_Id);
}

void CZoomkill::Snap(int SnappingClient)
{
	// Dont show any Spec in the freeview this shit.
	if ((GameServer()->m_apPlayers[SnappingClient]->GetTeam() == TEAM_SPECTATORS && GameServer()->m_apPlayers[SnappingClient]->m_SpectatorID == SPEC_FREEVIEW))
		return;

	// Invert the clipping!
	if(NetworkClipped(SnappingClient) == 1 || g_Config.m_SvAntiZoom == 0)
		return;


	//if (m_Entitie == CGameWorld::ENTTYPE_LASER)
	{
		CNetObj_Laser *pLaser = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, m_Id, sizeof(CNetObj_Laser)));
		if(!pLaser)
			return;

		pLaser->m_X = (int)m_Pos.x;
		pLaser->m_Y = (int)m_Pos.y;
		pLaser->m_FromX = (int)m_Pos.x+rand()%64;
		pLaser->m_FromY = (int)m_Pos.y+rand()%64;
		pLaser->m_StartTick = Server()->Tick();
	}
}
