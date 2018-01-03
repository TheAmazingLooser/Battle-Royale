/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_ENTITIES_ZOOMKILL_H
#define GAME_SERVER_ENTITIES_ZOOMKILL_H

#include <game/server/entity.h>

class CZoomkill : public CEntity
{
public:
	CZoomkill(CGameWorld *pGameWorld);
	virtual ~CZoomkill();

	virtual void Reset();
	virtual void Snap(int SnappingClient);

private:
	int m_Id;
};

#endif
