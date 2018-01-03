/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include <game/generated/protocol.h>
#include <game/server/gamecontext.h>
#include "projectile.h"
#include <engine/shared/config.h>

CProjectile::CProjectile(CGameWorld *pGameWorld, int Type, int Owner, vec2 Pos, vec2 Dir, int Span,
		int Damage, bool Explosive, float Force, int SoundImpact, int Weapon)
: CEntity(pGameWorld, CGameWorld::ENTTYPE_PROJECTILE)
{
	m_Type = Type;
	m_Pos = Pos;
	m_Direction = Dir;
	m_LifeSpan = Span;
	m_Owner = Owner;
	m_Force = Force;
	m_Damage = Damage;
	m_SoundImpact = SoundImpact;
	m_Weapon = Weapon;
	m_StartTick = Server()->Tick();
	m_Explosive = Explosive;

	GameWorld()->InsertEntity(this);
}

void CProjectile::Reset()
{
	GameServer()->m_World.DestroyEntity(this);
}

void CProjectile::DoBounce(vec2 Hitpos) {
      /*  vec2 PrevPos = GetPos((Server()->Tick()-m_StartTick-1)/(float)Server()->TickSpeed());
        vec2 CurPos = GetPos((Server()->Tick()-m_StartTick)/(float)Server()->TickSpeed());
        m_Pos = PrevPos;
		
        vec2 Dir = normalize(CurPos-PrevPos);
        m_StartTick = Server()->Tick();
 
		m_Pos = PrevPos;*/
		vec2 PrevPos = GetPos((Server()->Tick()-m_StartTick-1)/(float)Server()->TickSpeed());
        vec2 CurPos = GetPos((Server()->Tick()-m_StartTick)/(float)Server()->TickSpeed());

		vec2 BouncePos = vec2(0,0);
		GameServer()->Collision()->IntersectLine(PrevPos, CurPos, &CurPos, &BouncePos);

		m_Pos = BouncePos;
		vec2 TempPos = m_Pos;
		vec2 TempDir = m_Direction * 4.0f;
		GameServer()->Collision()->MovePoint(&TempPos, &TempDir, 1.0f, 0);
		m_Pos = TempPos;
		m_Direction = normalize(TempDir);
		m_StartTick = Server()->Tick();
		m_Bounces++;
}

vec2 CProjectile::GetPos(float Time)
{
	float Curvature = 0;
	float Speed = 0;

	switch(m_Type)
	{
		case WEAPON_GRENADE:
			Curvature = GameServer()->Tuning()->m_GrenadeCurvature;
			Speed = GameServer()->Tuning()->m_GrenadeSpeed;
			break;

		case WEAPON_SHOTGUN:
			Curvature = GameServer()->Tuning()->m_ShotgunCurvature;
			Speed = GameServer()->Tuning()->m_ShotgunSpeed;
			break;

		case WEAPON_GUN:
			Curvature = GameServer()->Tuning()->m_GunCurvature;
			Speed = GameServer()->Tuning()->m_GunSpeed;
			break;
	}

	return CalcPos(m_Pos, m_Direction, Curvature, Speed, Time);
}


void CProjectile::Tick()
{
        float Pt = (Server()->Tick()-m_StartTick-1)/(float)Server()->TickSpeed();
        float Ct = (Server()->Tick()-m_StartTick)/(float)Server()->TickSpeed();
        vec2 PrevPos = GetPos(Pt);
        vec2 CurPos = GetPos(Ct);
        int Collide = GameServer()->Collision()->IntersectLine(PrevPos, CurPos, &CurPos, 0);
        CCharacter *OwnerChar = GameServer()->GetPlayerChar(m_Owner);
        CCharacter *TargetChr = GameServer()->m_World.IntersectCharacter(PrevPos, CurPos, 6.0f, CurPos, OwnerChar);

        int NadeBounces = 0;
        if (OwnerChar->GetPlayer())
        {
        	switch(m_Type)
			{
				case WEAPON_GRENADE:
                	NadeBounces = floor(OwnerChar->GetPlayer()->m_GrenadeLevel/g_Config.m_SvGrenadeBounceGrow);
                 break;
     
				case WEAPON_GUN:
	                NadeBounces = floor(OwnerChar->GetPlayer()->m_GunLevel/g_Config.m_SvGunBounceGrow);
                 break;
			}
        }
     
        m_LifeSpan--;
     
        if(TargetChr || Collide || m_LifeSpan < 0 || GameLayerClipped(CurPos))
        {
                if(m_LifeSpan >= 0 || m_Weapon == WEAPON_GRENADE)
                        GameServer()->CreateSound(CurPos, m_SoundImpact);
     
                if(TargetChr && !m_Explosive)
                        TargetChr->TakeDamage(m_Direction * max(0.001f, m_Force), m_Damage, m_Owner, m_Weapon);
     
                if((m_Type == WEAPON_GUN && g_Config.m_SvGunBounce >= 1 && Collide && g_Config.m_SvGunBounce > m_Bounces) || (m_Type == WEAPON_SHOTGUN && g_Config.m_SvShotgunBounce >= 1 && Collide && g_Config.m_SvShotgunBounce > m_Bounces) || (m_Type == WEAPON_GRENADE && NadeBounces >= 1 && Collide && NadeBounces > m_Bounces))
				{
					DoBounce(CurPos);
					switch(m_Type)
					{
						case WEAPON_GRENADE:
                        if(g_Config.m_SvGrenadeBounceExplode==1)
							GameServer()->CreateExplosion(CurPos, m_Owner, m_Weapon, false);
                        break;
     
						case WEAPON_SHOTGUN:
                        if(g_Config.m_SvShotgunBounceExplode==1)
							GameServer()->CreateExplosion(CurPos, m_Owner, m_Weapon, false);
                        break;
     
						case WEAPON_GUN:
                        if(g_Config.m_SvGunBounceExplode==1)
							GameServer()->CreateExplosion(CurPos, m_Owner, m_Weapon, false);
                        break;
					}
				} else {
					if(m_Explosive)
						GameServer()->CreateExplosion(CurPos, m_Owner, m_Weapon, false);
					GameServer()->m_World.DestroyEntity(this);
				}
        }
}

void CProjectile::TickPaused()
{
	++m_StartTick;
}

void CProjectile::FillInfo(CNetObj_Projectile *pProj)
{
	pProj->m_X = (int)m_Pos.x;
	pProj->m_Y = (int)m_Pos.y;
	pProj->m_VelX = (int)(m_Direction.x*100.0f);
	pProj->m_VelY = (int)(m_Direction.y*100.0f);
	pProj->m_StartTick = m_StartTick;
	pProj->m_Type = m_Type;
}

void CProjectile::Snap(int SnappingClient)
{
	float Ct = (Server()->Tick()-m_StartTick)/(float)Server()->TickSpeed();

	if(NetworkClipped(SnappingClient, GetPos(Ct)))
		return;

	CNetObj_Projectile *pProj = static_cast<CNetObj_Projectile *>(Server()->SnapNewItem(NETOBJTYPE_PROJECTILE, m_ID, sizeof(CNetObj_Projectile)));
	if(pProj)
		FillInfo(pProj);
}
