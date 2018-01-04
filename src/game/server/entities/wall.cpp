/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */

#include <game/generated/protocol.h>
#include <game/server/gamecontext.h>
#include "wall.h"
#include <engine/shared/config.h>


CWall::CWall(CGameWorld *pGameWorld)
: CEntity(pGameWorld, CGameWorld::ENTTYPE_LASER)
{
	int ExtraPos = 0;
	m_TLPos = vec2(ExtraPos,ExtraPos);
	m_TRPos = vec2( GameServer()->Collision()->GetWidth()*32-ExtraPos,ExtraPos);
	m_BLPos = vec2(ExtraPos, GameServer()->Collision()->GetHeight()*32-ExtraPos);
	m_BRPos = vec2( GameServer()->Collision()->GetWidth()*32-ExtraPos, GameServer()->Collision()->GetHeight()*32-ExtraPos);
	m_EndPos = vec2((3+(rand()%(GameServer()->Collision()->GetWidth()-4)))*32, (3+(rand()%(GameServer()->Collision()->GetHeight()-4)))*32);
	m_LeftGrow = (m_EndPos.x -m_TLPos.x)*33/100;
	m_RightGrow = (m_TRPos.x-m_EndPos.x)*33/100;
	m_TopGrow = (m_EndPos.y-m_TLPos.y)*33/100;
	m_BotGrow = (m_EndPos.y - m_BLPos.y)*33/100;
	m_StartTick =  0;
	
	//Noobstyle...
	m_Id1 = Server()->SnapNewID();
	m_Id2 = Server()->SnapNewID();
	m_Id3 = Server()->SnapNewID();
	m_Id4 = Server()->SnapNewID();

	m_MoveTick = Server()->Tick();
	m_Moving = false;

	GameServer()->SendBroadcast("A wall has got spawned. Prepare for something shitty!", -1);

	GameWorld()->InsertEntity(this);
}

void CWall::Reset()
{
	GameServer()->m_World.DestroyEntity(this);
}

void CWall::StartMove()
{
	m_MoveTick = Server()->Tick();
	m_Moving = true;
	// PosCalc
	m_LeftGrow = (m_EndPos.x-m_TLPos.x)*33/100;
	m_RightGrow = (m_TRPos.x-m_EndPos.x)*33/100;
	m_TopGrow = (m_EndPos.y-m_TLPos.y)*33/100;
	m_BotGrow = (m_EndPos.y - m_BLPos.y)*33/100;
	GameServer()->SendBroadcast("The wall begin to shrink", -1);
}


CWall::~CWall()
{
	Server()->SnapFreeID(m_Id1);
	Server()->SnapFreeID(m_Id2);
	Server()->SnapFreeID(m_Id3);
	Server()->SnapFreeID(m_Id4);
}

bool CWall::HitCharacter(vec2 From, vec2 To)
{
	vec2 At;
	CCharacter *pHit = GameServer()->m_World.IntersectCharacter(From, To, 0.f, At, 0);
	if(!pHit)
		return false;

	pHit->TakeDamage(vec2(0.1f, 0.1f), g_Config.m_SvWallDamage, -1, WEAPON_NINJA);
	return true;
}

void CWall::HitBehind()
{
	CCharacter *p = (CCharacter *)GameServer()->m_World.FindFirst(CGameWorld::ENTTYPE_CHARACTER);
	for(; p; p = (CCharacter *)p->TypeNext())
 	{
		if(p->m_Pos.x < m_TLPos.x || p->m_Pos.x < m_BLPos.x || p->m_Pos.x > m_BRPos.x || p->m_Pos.x > m_TRPos.x || p->m_Pos.y < m_TRPos.y || p->m_Pos.y < m_TLPos.y || p->m_Pos.y > m_BRPos.y || p->m_Pos.y > m_BLPos.y)
		{
			p->TakeDamage(vec2(0.1f, 0.1f), g_Config.m_SvWallDamage, -1, WEAPON_NINJA);
			GameServer()->SendBroadcast("You are behind the wall!", p->GetPlayer()->GetCID());
		}
	}

}

void CWall::Tick()
{
	char aBuf[256];
	GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_DEBUG, "game", aBuf);
	int Delay = g_Config.m_SvWallDamageTickDelay;
	if(Server()->Tick()%Delay == 0 or Delay < 2)
	{
		HitCharacter(m_TLPos,m_TRPos);
		HitCharacter(m_BLPos,m_BRPos);
		HitCharacter(m_TLPos,m_BLPos);
		HitCharacter(m_TRPos,m_BRPos);
		HitBehind();
	}
	if (m_MoveTick != -1 && m_MoveTick +9000 < Server()->Tick() && !m_Moving)
	{
		StartMove();
	} else if (m_Moving && m_MoveTick + 4000 < Server()->Tick())
	{
		m_Moving = false;
	} else {
		if (Server()->Tick()%50 == 0 && m_Moving)
		{
			if (m_TLPos.x < m_LeftGrow)
				m_TLPos.x += 32;

			if (m_TRPos.x > m_RightGrow)
				m_TRPos.x -= 32;

			if (m_BLPos.x < m_LeftGrow)
				m_BLPos.x += 32;

			if (m_BRPos.x > m_RightGrow)
				m_BRPos.x -= 32;

			// Y
			if (m_TLPos.y < m_TopGrow)
				m_TLPos.y += 32;

			if (m_TRPos.y < m_TopGrow)
				m_TRPos.y += 32;

			if (m_BLPos.y > m_BotGrow)
				m_BLPos.y -= 32;

			if (m_BRPos.y > m_BotGrow)
				m_BRPos.y -= 32;
		}
	}
}

void CWall::TickPaused()
{
	++m_StartTick;
}

void CWall::Snap(int SnappingClient)
{
	// Is too big, Clipping not allowed to see it overall!
	//if(NetworkClipped(SnappingClient))
	//	return;

	int ExtraTick = g_Config.m_SvWallExtraTick;

	CNetObj_Laser *pTop = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, m_Id1, sizeof(CNetObj_Laser)));
	if(!pTop)
		return;

	pTop->m_X = (int)m_TLPos.x;
	pTop->m_Y = (int)m_TLPos.y;
	pTop->m_FromX = (int)m_TRPos.x;
	pTop->m_FromY = (int)m_TRPos.y;
	pTop->m_StartTick = Server()->Tick()+ExtraTick;
	
	

	CNetObj_Laser *pBot = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, m_Id2, sizeof(CNetObj_Laser)));
	if(!pBot)
		return;

	pBot->m_X = (int)m_BRPos.x;
	pBot->m_Y = (int)m_BRPos.y;
	pBot->m_FromX = (int)m_BLPos.x;
	pBot->m_FromY = (int)m_BLPos.y;
	pBot->m_StartTick = Server()->Tick()+ExtraTick;
	
	

	CNetObj_Laser *pLeft = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, m_Id3, sizeof(CNetObj_Laser)));
	if(!pLeft)
		return;

	pLeft->m_X = (int)m_TLPos.x;
	pLeft->m_Y = (int)m_TLPos.y;
	pLeft->m_FromX = (int)m_BLPos.x;
	pLeft->m_FromY = (int)m_BLPos.y;
	pLeft->m_StartTick = Server()->Tick()+ExtraTick;
	
	

	CNetObj_Laser *pRight = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, m_Id4, sizeof(CNetObj_Laser)));
	if(!pRight)
		return;

	pRight->m_X = (int)m_TRPos.x;
	pRight->m_Y = (int)m_TRPos.y;
	pRight->m_FromX = (int)m_BRPos.x;
	pRight->m_FromY = (int)m_BRPos.y;
	pRight->m_StartTick = Server()->Tick()+ExtraTick;
}
