/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_ENTITIES_WALL_H
#define GAME_SERVER_ENTITIES_WALL_H

#include <game/server/entity.h>

class CWall : public CEntity
{
public:
	CWall(CGameWorld *pGameWorld);
	virtual ~CWall();

	virtual void Reset();
	virtual void Tick();
	virtual void TickPaused();
	virtual void Snap(int SnappingClient);

	void StartMove();
	
protected:
	bool HitCharacter(vec2 From, vec2 To);
	void HitBehind();

private:
	vec2 m_TLPos;
	vec2 m_TRPos;
	vec2 m_BLPos;
	vec2 m_BRPos;
	vec2 m_EndPos;
	float m_LeftGrow;
	float m_RightGrow;
	float m_TopGrow;
	float m_BotGrow;
	int m_Id1;
	int m_Id2;
	int m_Id3;
	int m_Id4;
	int m_StartTick;
	int m_MoveTick;
	bool m_Moving;
};

#endif
