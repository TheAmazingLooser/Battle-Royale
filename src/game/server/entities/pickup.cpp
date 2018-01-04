/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include <game/generated/protocol.h>
#include <game/server/gamecontroller.h>
#include "pickup.h"
#include <game/server/gamecontext.h>
#include <engine/shared/config.h>

CPickup::CPickup(CGameWorld *pGameWorld, int Type, int SubType)
: CEntity(pGameWorld, CGameWorld::ENTTYPE_PICKUP)
{
	m_Type = Type; // 0-3
	if (Type == 3)
		m_Type = 2;
	m_Subtype = SubType; // 0-4
	if (Type == 0 or Type == 1)
		m_Type = rand()%2; // Randomize it ^^ 0-1
	else if (Type == 2 || Type == 3) // Rip that :3
	{
		m_Subtype = 1+rand()%4;
	}else if (Type == 5)
	{
		if (SubType == 0)
			SubType = 1+rand()%4;
		m_Unique = true;
		m_Type = 2;
		m_Subtype = SubType;
	}
	m_ProximityRadius = PickupPhysSize;

	Reset();

	GameWorld()->InsertEntity(this);
}

void CPickup::Reset()
{
	if (g_pData->m_aPickups[m_Type].m_Spawndelay > 0)
		m_SpawnTick = Server()->Tick() + Server()->TickSpeed() * g_pData->m_aPickups[m_Type].m_Spawndelay;
	else
		m_SpawnTick = -1;
}

void CPickup::Tick()
{
	// wait for respawn
	if(m_SpawnTick > 0)
	{
		if(Server()->Tick() > m_SpawnTick && !m_Unique)
		{
			//New item
			if (m_Type == 0 or m_Type == 1)
				m_Type = rand()%2; // Randomize it ^^ 0-1
			else if (m_Type == 2) // Rip that :3
			{
				m_Subtype = 1+rand()%4;
			}

			// respawn
			m_SpawnTick = -1;

			if(m_Type == POWERUP_WEAPON)
				GameServer()->CreateSound(m_Pos, SOUND_WEAPON_SPAWN);
		}
		else
			return;
	}
	// Check if a player intersected us
	CCharacter *pChr = GameServer()->m_World.ClosestCharacter(m_Pos, 20.0f, 0);
	if(pChr && pChr->IsAlive() && GameServer()->m_pController && GameServer()->m_pController->IsStarted())
	{
		// player picked us up, is someone was hooking us, let them go
		int RespawnTime = -1;
		switch (m_Type)
		{
			case POWERUP_HEALTH:
				if(pChr->IncreaseHealth(1))
				{
					GameServer()->CreateSound(m_Pos, SOUND_PICKUP_HEALTH);
					RespawnTime = g_Config.m_SvHealthSpawn; //## g_pData->m_aPickups[m_Type].m_Respawntime
				}
				break;

			case POWERUP_ARMOR:
				if(pChr->IncreaseArmor(1))
				{
					GameServer()->CreateSound(m_Pos, SOUND_PICKUP_ARMOR);
					RespawnTime = g_Config.m_SvArmorSpawn;
				}
				break;

			case POWERUP_WEAPON:
				if(m_Subtype >= 0 && m_Subtype < NUM_WEAPONS)
				{
					if(m_Subtype == WEAPON_GRENADE)
					{
						if(pChr->GiveWeapon(m_Subtype, g_Config.m_SvGrenadeStartAmmo))
						{
							GameServer()->CreateSound(m_Pos, SOUND_PICKUP_GRENADE);
							RespawnTime = g_Config.m_SvGrenadeSpawn;

							if (pChr->GetPlayer())
							{
								if (pChr->GetPlayer()->m_GrenadeLevel < g_Config.m_SvWeaponMaxLevel)
									pChr->GetPlayer()->m_GrenadeLevel += 1;
								char aBuf[256];
								str_format(aBuf, sizeof(aBuf), "Weapon player='%d:%s' weap=%d/ level=%d",
									pChr->GetPlayer()->GetCID(), Server()->ClientName(pChr->GetPlayer()->GetCID()),m_Subtype, pChr->GetPlayer()->m_GrenadeLevel);
								GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_DEBUG, "game", aBuf);
							}
						}else if (pChr->GetPlayer() && pChr->GetPlayer()->m_GrenadeLevel < g_Config.m_SvWeaponMaxLevel)
						{
							GameServer()->CreateSound(m_Pos, SOUND_PICKUP_SHOTGUN);
							RespawnTime = g_Config.m_SvGrenadeSpawn;
							pChr->GetPlayer()->m_GrenadeLevel += 1;
						}
					}else if (m_Subtype == WEAPON_SHOTGUN)
					{
						if(pChr->GiveWeapon(m_Subtype, g_Config.m_SvShotgunStartAmmo))
						{
							GameServer()->CreateSound(m_Pos, SOUND_PICKUP_SHOTGUN);
							RespawnTime = g_Config.m_SvShotgunSpawn;

							if (pChr->GetPlayer())
							{
								if (pChr->GetPlayer()->m_ShotgunLevel < g_Config.m_SvWeaponMaxLevel)
									pChr->GetPlayer()->m_ShotgunLevel += 1;
								char aBuf[256];
								str_format(aBuf, sizeof(aBuf), "Weapon player='%d:%s' weap=%d/ level=%d",
									pChr->GetPlayer()->GetCID(), Server()->ClientName(pChr->GetPlayer()->GetCID()),m_Subtype, pChr->GetPlayer()->m_ShotgunLevel);
								GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_DEBUG, "game", aBuf);
							}
						}else if (pChr->GetPlayer() && pChr->GetPlayer()->m_ShotgunLevel < g_Config.m_SvWeaponMaxLevel)
						{
							GameServer()->CreateSound(m_Pos, SOUND_PICKUP_SHOTGUN);
							RespawnTime = g_Config.m_SvShotgunSpawn;
							pChr->GetPlayer()->m_ShotgunLevel += 1;
						}
					}else if (m_Subtype == WEAPON_RIFLE)
					{
						if(pChr->GiveWeapon(m_Subtype, g_Config.m_SvLaserStartAmmo))
						{
							GameServer()->CreateSound(m_Pos, SOUND_PICKUP_SHOTGUN);
							RespawnTime = g_Config.m_SvLaserSpawn;

							if (pChr->GetPlayer())
							{
								if (pChr->GetPlayer()->m_RifleLevel < g_Config.m_SvWeaponMaxLevel)
									pChr->GetPlayer()->m_RifleLevel += 1;
								char aBuf[256];
								str_format(aBuf, sizeof(aBuf), "Weapon player='%d:%s' weap=%d/ level=%d",
									pChr->GetPlayer()->GetCID(), Server()->ClientName(pChr->GetPlayer()->GetCID()),m_Subtype, pChr->GetPlayer()->m_RifleLevel);
								GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_DEBUG, "game", aBuf);
							}
						}else if (pChr->GetPlayer() && pChr->GetPlayer()->m_RifleLevel < g_Config.m_SvWeaponMaxLevel)
						{
							GameServer()->CreateSound(m_Pos, SOUND_PICKUP_SHOTGUN);
							RespawnTime = g_Config.m_SvLaserSpawn;
							pChr->GetPlayer()->m_RifleLevel += 1;
						}
					}else if (m_Subtype == WEAPON_GUN)
					{
						if(pChr->GiveWeapon(m_Subtype, g_Config.m_SvGunStartAmmo))
						{
							GameServer()->CreateSound(m_Pos, SOUND_PICKUP_SHOTGUN);
							RespawnTime = g_Config.m_SvGunSpawn;

							if (pChr->GetPlayer())
							{
								if (pChr->GetPlayer()->m_GunLevel < g_Config.m_SvWeaponMaxLevel)
									pChr->GetPlayer()->m_GunLevel += 1;
								char aBuf[256];
								str_format(aBuf, sizeof(aBuf), "Weapon player='%d:%s' weap=%d/ level=%d",
									pChr->GetPlayer()->GetCID(), Server()->ClientName(pChr->GetPlayer()->GetCID()),m_Subtype, pChr->GetPlayer()->m_GunLevel);
								GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_DEBUG, "game", aBuf);
							}
						}else if (pChr->GetPlayer() && pChr->GetPlayer()->m_GunLevel < g_Config.m_SvWeaponMaxLevel)
						{
							GameServer()->CreateSound(m_Pos, SOUND_PICKUP_SHOTGUN);
							RespawnTime = g_Config.m_SvGunSpawn;
							pChr->GetPlayer()->m_GunLevel += 1;
						}
					}
				}
				break;

			case POWERUP_NINJA:
				{
					// activate ninja on target player
					pChr->GiveNinja();
					RespawnTime = g_Config.m_SvNinjaSpawn;

					// loop through all players, setting their emotes
					CCharacter *pC = static_cast<CCharacter *>(GameServer()->m_World.FindFirst(CGameWorld::ENTTYPE_CHARACTER));
					for(; pC; pC = (CCharacter *)pC->TypeNext())
					{
						if (pC != pChr)
							pC->SetEmote(EMOTE_SURPRISE, Server()->Tick() + Server()->TickSpeed());
					}

					pChr->SetEmote(EMOTE_ANGRY, Server()->Tick() + 1200 * Server()->TickSpeed() / 1000);
					break;
				}

			default:
				break;
		};

		if(RespawnTime >= 0)
		{
			char aBuf[256];
			str_format(aBuf, sizeof(aBuf), "pickup player='%d:%s' item=%d/%d",
				pChr->GetPlayer()->GetCID(), Server()->ClientName(pChr->GetPlayer()->GetCID()), m_Type, m_Subtype);
			GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_DEBUG, "game", aBuf);
			if (!m_Unique)
				m_SpawnTick = Server()->Tick() + Server()->TickSpeed() * RespawnTime;
			else
				m_SpawnTick = Server()->Tick() + Server()->TickSpeed() * RespawnTime;
		}
	}
}
void CPickup::TickPaused()
{
	if(m_SpawnTick != -1)
		++m_SpawnTick;
}

void CPickup::Snap(int SnappingClient)
{
	if(m_SpawnTick != -1 || NetworkClipped(SnappingClient))
		return;

	CNetObj_Pickup *pP = static_cast<CNetObj_Pickup *>(Server()->SnapNewItem(NETOBJTYPE_PICKUP, m_ID, sizeof(CNetObj_Pickup)));
	if(!pP)
		return;

	pP->m_X = (int)m_Pos.x;
	pP->m_Y = (int)m_Pos.y;
	pP->m_Type = m_Type;
	pP->m_Subtype = m_Subtype;
}
