/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_VARIABLES_H
#define GAME_VARIABLES_H
#undef GAME_VARIABLES_H // this file will be included several times


// client
MACRO_CONFIG_INT(ClPredict, cl_predict, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Predict client movements")
MACRO_CONFIG_INT(ClNameplates, cl_nameplates, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show name plates")
MACRO_CONFIG_INT(ClNameplatesAlways, cl_nameplates_always, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Always show name plates disregarding of distance")
MACRO_CONFIG_INT(ClNameplatesTeamcolors, cl_nameplates_teamcolors, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Use team colors for name plates")
MACRO_CONFIG_INT(ClNameplatesSize, cl_nameplates_size, 50, 0, 100, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Size of the name plates from 0 to 100%")
MACRO_CONFIG_INT(ClAutoswitchWeapons, cl_autoswitch_weapons, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Auto switch weapon on pickup")

MACRO_CONFIG_INT(ClShowhud, cl_showhud, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show ingame HUD")
MACRO_CONFIG_INT(ClShowChatFriends, cl_show_chat_friends, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show only chat messages from friends")
MACRO_CONFIG_INT(ClShowfps, cl_showfps, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show ingame FPS counter")

MACRO_CONFIG_INT(ClAirjumpindicator, cl_airjumpindicator, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClThreadsoundloading, cl_threadsoundloading, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Load sound files threaded")

MACRO_CONFIG_INT(ClWarningTeambalance, cl_warning_teambalance, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Warn about team balance")

MACRO_CONFIG_INT(ClMouseDeadzone, cl_mouse_deadzone, 300, 0, 0, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMouseFollowfactor, cl_mouse_followfactor, 60, 0, 200, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMouseMaxDistance, cl_mouse_max_distance, 800, 0, 0, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

MACRO_CONFIG_INT(EdShowkeys, ed_showkeys, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

//MACRO_CONFIG_INT(ClFlow, cl_flow, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

MACRO_CONFIG_INT(ClShowWelcome, cl_show_welcome, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMotdTime, cl_motd_time, 10, 0, 100, CFGFLAG_CLIENT|CFGFLAG_SAVE, "How long to show the server message of the day")

MACRO_CONFIG_STR(ClVersionServer, cl_version_server, 100, "version.teeworlds.com", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Server to use to check for new versions")

MACRO_CONFIG_STR(ClLanguagefile, cl_languagefile, 255, "", CFGFLAG_CLIENT|CFGFLAG_SAVE, "What language file to use")

MACRO_CONFIG_INT(PlayerUseCustomColor, player_use_custom_color, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Toggles usage of custom colors")
MACRO_CONFIG_INT(PlayerColorBody, player_color_body, 65408, 0, 0xFFFFFF, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player body color")
MACRO_CONFIG_INT(PlayerColorFeet, player_color_feet, 65408, 0, 0xFFFFFF, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player feet color")
MACRO_CONFIG_STR(PlayerSkin, player_skin, 24, "default", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player skin")

MACRO_CONFIG_INT(UiPage, ui_page, 6, 0, 10, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface page")
MACRO_CONFIG_INT(UiToolboxPage, ui_toolbox_page, 0, 0, 2, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Toolbox page")
MACRO_CONFIG_STR(UiServerAddress, ui_server_address, 64, "localhost:8303", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface server address")
MACRO_CONFIG_INT(UiScale, ui_scale, 100, 50, 150, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface scale")
MACRO_CONFIG_INT(UiMousesens, ui_mousesens, 100, 5, 100000, CFGFLAG_SAVE|CFGFLAG_CLIENT, "Mouse sensitivity for menus/editor")

MACRO_CONFIG_INT(UiColorHue, ui_color_hue, 160, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color hue")
MACRO_CONFIG_INT(UiColorSat, ui_color_sat, 70, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color saturation")
MACRO_CONFIG_INT(UiColorLht, ui_color_lht, 175, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color lightness")
MACRO_CONFIG_INT(UiColorAlpha, ui_color_alpha, 228, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface alpha")

MACRO_CONFIG_INT(GfxNoclip, gfx_noclip, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Disable clipping")

// server
MACRO_CONFIG_INT(SvWarmup, sv_warmup, 0, 0, 0, CFGFLAG_SERVER, "Number of seconds to do warmup before round starts")
MACRO_CONFIG_INT(SvUnpauseTimer, sv_unpause_timer, 0, 0, 0, CFGFLAG_SERVER, "Number of seconds till the game continues")
MACRO_CONFIG_STR(SvMotd, sv_motd, 900, "", CFGFLAG_SERVER, "Message of the day to display for the clients")
MACRO_CONFIG_INT(SvTeamdamage, sv_teamdamage, 0, 0, 1, CFGFLAG_SERVER, "Team damage")
MACRO_CONFIG_STR(SvMaprotation, sv_maprotation, 768, "", CFGFLAG_SERVER, "Maps to rotate between")
MACRO_CONFIG_INT(SvRoundsPerMap, sv_rounds_per_map, 1, 1, 100, CFGFLAG_SERVER, "Number of rounds on each map before rotating")
MACRO_CONFIG_INT(SvRoundSwap, sv_round_swap, 1, 0, 1, CFGFLAG_SERVER, "Swap teams between rounds")
MACRO_CONFIG_INT(SvPowerups, sv_powerups, 1, 0, 1, CFGFLAG_SERVER, "Allow powerups like ninja")
MACRO_CONFIG_INT(SvScorelimit, sv_scorelimit, 20, 0, 1000, CFGFLAG_SERVER, "Score limit (0 disables)")
MACRO_CONFIG_INT(SvTimelimit, sv_timelimit, 0, 0, 1000, CFGFLAG_SERVER, "Time limit in minutes (0 disables)")
MACRO_CONFIG_STR(SvGametype, sv_gametype, 32, "dm", CFGFLAG_SERVER, "Game type (dm, tdm, ctf)")
MACRO_CONFIG_INT(SvTournamentMode, sv_tournament_mode, 0, 0, 1, CFGFLAG_SERVER, "Tournament mode. When enabled, players joins the server as spectator")
MACRO_CONFIG_INT(SvSpamprotection, sv_spamprotection, 1, 0, 1, CFGFLAG_SERVER, "Spam protection")

MACRO_CONFIG_INT(SvRespawnDelayTDM, sv_respawn_delay_tdm, 3, 0, 10, CFGFLAG_SERVER, "Time needed to respawn after death in tdm gametype")

MACRO_CONFIG_INT(SvSpectatorSlots, sv_spectator_slots, 0, 0, MAX_CLIENTS, CFGFLAG_SERVER, "Number of slots to reserve for spectators")
MACRO_CONFIG_INT(SvTeambalanceTime, sv_teambalance_time, 1, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before autobalancing teams")
MACRO_CONFIG_INT(SvInactiveKickTime, sv_inactivekick_time, 3, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before taking care of inactive players")
MACRO_CONFIG_INT(SvInactiveKick, sv_inactivekick, 1, 0, 2, CFGFLAG_SERVER, "How to deal with inactive players (0=move to spectator, 1=move to free spectator slot/kick, 2=kick)")

MACRO_CONFIG_INT(SvStrictSpectateMode, sv_strict_spectate_mode, 0, 0, 1, CFGFLAG_SERVER, "Restricts information in spectator mode")
MACRO_CONFIG_INT(SvVoteSpectate, sv_vote_spectate, 1, 0, 1, CFGFLAG_SERVER, "Allow voting to move players to spectators")
MACRO_CONFIG_INT(SvVoteSpectateRejoindelay, sv_vote_spectate_rejoindelay, 3, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before a player can rejoin after being moved to spectators by vote")
MACRO_CONFIG_INT(SvVoteKick, sv_vote_kick, 1, 0, 1, CFGFLAG_SERVER, "Allow voting to kick players")
MACRO_CONFIG_INT(SvVoteKickMin, sv_vote_kick_min, 0, 0, MAX_CLIENTS, CFGFLAG_SERVER, "Minimum number of players required to start a kick vote")
MACRO_CONFIG_INT(SvVoteKickBantime, sv_vote_kick_bantime, 5, 0, 1440, CFGFLAG_SERVER, "The time to ban a player if kicked by vote. 0 makes it just use kick")

// Battle Royale Custom Vars

MACRO_CONFIG_INT(SvHealthMax, sv_health_max, 200, 1, 200, CFGFLAG_SERVER, "Amount of health you can have max")
MACRO_CONFIG_INT(SvHealthStart, sv_health_start, 25, 1, 200, CFGFLAG_SERVER, "Amount of health you spawn with")
MACRO_CONFIG_INT(SvHealthSpawn, sv_health_spawn, 120, 0, 600, CFGFLAG_SERVER, "Time it takes to respawn in seconds")

MACRO_CONFIG_INT(SvArmorMax, sv_armor_max, 200, 0, 200, CFGFLAG_SERVER, "Amount of armor you can have max")
MACRO_CONFIG_INT(SvArmorStart, sv_armor_start, 0, 0, 50, CFGFLAG_SERVER, "Amount of armor you spawn with")
MACRO_CONFIG_INT(SvArmorSpawn, sv_armor_spawn, 240, 0, 600, CFGFLAG_SERVER, "Time it takes to respawn in seconds")

MACRO_CONFIG_INT(SvHammerStart, sv_hammer_start, 1, 0, 1, CFGFLAG_SERVER, "If you spawn with or without this weapon")
MACRO_CONFIG_INT(SvHammerDamage, sv_hammer_damage, 3, 0, 100, CFGFLAG_SERVER, "Damage this weapon takes")
MACRO_CONFIG_INT(SvHammerAuto, sv_hammer_auto, 0, 0, 1, CFGFLAG_SERVER, "Fullautomatical weapon")
MACRO_CONFIG_INT(SvHammerReload, sv_hammer_reload, 125, 1, 10000, CFGFLAG_SERVER, "Time it takes to hammer again in ms")

MACRO_CONFIG_INT(SvWeaponMaxLevel, sv_weap_max_level, 50, 1, 1000, CFGFLAG_SERVER, "Maximal level of all collectable weapons")

MACRO_CONFIG_INT(SvGunDamage, sv_gun_damage, 1, 0, 100, CFGFLAG_SERVER, "Damage this weapon takes")
MACRO_CONFIG_INT(SvGunDamageGrow, sv_gun_damage_grow, 0.3*100, 0, 10, CFGFLAG_SERVER, "Damage this weapon gains per level (/100)")
MACRO_CONFIG_INT(SvGunExplode, sv_gun_explode, 0, 0, 1, CFGFLAG_SERVER, "Makes the projectile explode on death")
MACRO_CONFIG_INT(SvGunBounce, sv_gun_bounce, 0, 0, 25, CFGFLAG_SERVER, "Amount of bounces this weapon does")
MACRO_CONFIG_INT(SvGunBounceGrow, sv_gun_bounce_grow, 5, 0, 25, CFGFLAG_SERVER, "Amount of level for new bounces")
MACRO_CONFIG_INT(SvGunBounceExplode, sv_gun_bounce_explode, 0, 0, 1, CFGFLAG_SERVER, "Create explosions on bouncing")
MACRO_CONFIG_INT(SvGunSelfdamage, sv_gun_selfdamage, 0, 0, 100, CFGFLAG_SERVER, "Selfdamage on explosion")
MACRO_CONFIG_INT(SvGunStart, sv_gun_start, 0, 0, 1, CFGFLAG_SERVER, "If you spawn with or without this weapon")
MACRO_CONFIG_INT(SvGunAmmo, sv_gun_ammo, 500, -1, 500, CFGFLAG_SERVER, "Amount of ammo this weapon can have maximal")
MACRO_CONFIG_INT(SvGunStartAmmo, sv_gun_start_ammo, 25, -1, 500, CFGFLAG_SERVER, "Amount of ammo this weapon will start with")
MACRO_CONFIG_INT(SvGunRegen, sv_gun_regen, 0, 0, 10000, CFGFLAG_SERVER, "Ammo regeneration in ms")
MACRO_CONFIG_INT(SvGunAuto, sv_gun_auto, 1, 0, 1, CFGFLAG_SERVER, "Fullautomatical weapon")
MACRO_CONFIG_INT(SvGunProjectiles, sv_gun_projectiles, 1, 1, 76, CFGFLAG_SERVER, "Amount of projectiles this weapons shoot")
MACRO_CONFIG_INT(SvGunProjectilesGrow, sv_gun_projectiles_grow, 15, 1, 76, CFGFLAG_SERVER, "Amount of level for a new projectile")
MACRO_CONFIG_INT(SvGunReload, sv_gun_reload, 125, 1, 10000, CFGFLAG_SERVER, "Time it takes to shoot again in ms")
MACRO_CONFIG_INT(SvGunReloadGrow, sv_gun_reload_grow, 0.5*100, 1, 500, CFGFLAG_SERVER, "Time for faster reload per level (/100)")
MACRO_CONFIG_INT(SvGunSpawn, sv_gun_spawn, 300, 1, 600, CFGFLAG_SERVER, "Time it takes to respawn in seconds")

MACRO_CONFIG_INT(SvShotgunDamage, sv_shotgun_damage, 1, 0, 100, CFGFLAG_SERVER, "Damage this weapon starts with")
MACRO_CONFIG_INT(SvShotgunDamageGrow, sv_shotgun_damage_grow, 0.1*100, 0, 100, CFGFLAG_SERVER, "Damage grow per level (/100)")
MACRO_CONFIG_INT(SvShotgunExplode, sv_shotgun_explode, 0, 0, 1, CFGFLAG_SERVER, "Makes the projectile explode on death")
MACRO_CONFIG_INT(SvShotgunBounce, sv_shotgun_bounce, 0, 0, 25, CFGFLAG_SERVER, "Amount of bounces this weapon does")
MACRO_CONFIG_INT(SvShotgunBounceExplode, sv_shotgun_bounce_explode, 0, 0, 1, CFGFLAG_SERVER, "Create explosions on bouncing")
MACRO_CONFIG_INT(SvShotgunSelfdamage, sv_shotgun_selfdamage, 1, 0, 1, CFGFLAG_SERVER, "Selfdamage on explosion")
MACRO_CONFIG_INT(SvShotgunSpawn, sv_shotgun_spawn, 300, 0, 600, CFGFLAG_SERVER, "Time it takes to respawn in seconds")
MACRO_CONFIG_INT(SvShotgunStart, sv_shotgun_start, 0, 0, 1, CFGFLAG_SERVER, "If you spawn with or without this weapon")
MACRO_CONFIG_INT(SvShotgunAmmo, sv_shotgun_ammo, 250, -1, 250, CFGFLAG_SERVER, "Amount of ammo this weapon can have maximal")
MACRO_CONFIG_INT(SvShotgunStartAmmo, sv_shotgun_start_ammo, 10, -1, 250, CFGFLAG_SERVER, "Amount of ammo this weapon will start with")
MACRO_CONFIG_INT(SvShotgunRegen, sv_shotgun_regen, 0, 0, 10000, CFGFLAG_SERVER, "Ammo regeneration in ms")
MACRO_CONFIG_INT(SvShotgunProjectiles, sv_shotgun_projectiles, 5, 1, 76, CFGFLAG_SERVER, "Amount of projectiles this weapons starts with")
MACRO_CONFIG_INT(SvShotgunProjectilesGrow, sv_shotgun_projectiles_grow, 5, 1, 100, CFGFLAG_SERVER, "Amount of level needed for a new projectile")
MACRO_CONFIG_INT(SvShotgunReload, sv_shotgun_reload, 500, 1, 10000, CFGFLAG_SERVER, "Time it takes to shoot again in ms")

//MACRO_CONFIG_INT(SvGrenadeBounce, sv_grenade_bounce, 0, 0, 25, CFGFLAG_SERVER, "Amount of bounces this weapon does")
MACRO_CONFIG_INT(SvGrenadeBounceGrow, sv_grenade_bounce_grow, 20, 0, 25, CFGFLAG_SERVER, "Amount of bounces every X level")
MACRO_CONFIG_INT(SvGrenadeBounceExplode, sv_grenade_bounce_explode, 1, 0, 1, CFGFLAG_SERVER, "Create explosions on bouncing")
MACRO_CONFIG_INT(SvGrenadeDamage, sv_grenade_damage, 3, 0, 100, CFGFLAG_SERVER, "Damage this weapon starts with")
MACRO_CONFIG_INT(SvGrenadeDamageGrow, sv_grenade_damage, 0.5*100, 0, 10, CFGFLAG_SERVER, "Damage this weapon gains per level (/100)")
MACRO_CONFIG_INT(SvGrenadeSelfdamage, sv_grenade_selfdamage, 5, 0, 100, CFGFLAG_SERVER, "Selfdamage on explosion")
MACRO_CONFIG_INT(SvGrenadeSpawn, sv_grenade_spawn, 300, 0, 600, CFGFLAG_SERVER, "Time it takes to respawn in seconds")
MACRO_CONFIG_INT(SvGrenadeStart, sv_grenade_start, 0, 0, 1, CFGFLAG_SERVER, "If you spawn with or without this weapon")
MACRO_CONFIG_INT(SvGrenadeAmmo, sv_grenade_ammo, 50, -1, 50, CFGFLAG_SERVER, "Amount of ammo this weapon can have maximal")
MACRO_CONFIG_INT(SvGrenadeStartAmmo, sv_grenade_start_ammo, 5, -1, 50, CFGFLAG_SERVER, "Amount of ammo this weapon will start with")
MACRO_CONFIG_INT(SvGrenadeRegen, sv_grenade_regen, 0, 0, 10000, CFGFLAG_SERVER, "Ammo regeneration in ms")
MACRO_CONFIG_INT(SvGrenadeProjectiles, sv_grenade_projectiles, 1, 1, 76, CFGFLAG_SERVER, "Amount of projectiles this weapons shoot")
MACRO_CONFIG_INT(SvGrenadeProjectilesGrow, sv_grenade_projectiles_grow, 12, 1, 100, CFGFLAG_SERVER, "Amount of level per 1 new projectile")
MACRO_CONFIG_INT(SvGrenadeReload, sv_grenade_reload, 500, 1, 10000, CFGFLAG_SERVER, "Time it takes to shoot again in ms")

//MACRO_CONFIG_INT(SvLaserExplode, sv_laser_explode, 0, 0, 1, CFGFLAG_SERVER, "Create explosions on bouncing")
MACRO_CONFIG_INT(SvLaserSelfdamage, sv_laser_selfdamage, 1, 0, 20, CFGFLAG_SERVER, "Selfdamage on explosion")
MACRO_CONFIG_INT(SvLaserSpawn, sv_laser_spawn, 300, 0, 600, CFGFLAG_SERVER, "Time it takes to respawn in seconds")
MACRO_CONFIG_INT(SvLaserStart, sv_laser_start, 0, 0, 1, CFGFLAG_SERVER, "If you spawn with or without this weapon")
MACRO_CONFIG_INT(SvLaserAmmo, sv_laser_ammo, 50, -1, 50, CFGFLAG_SERVER, "Amount of ammo this weapon can have maximal")
MACRO_CONFIG_INT(SvLaserStartAmmo, sv_laser_start_ammo, 2, -1, 50, CFGFLAG_SERVER, "Amount of ammo this weapon will start with")
MACRO_CONFIG_INT(SvLaserRegen, sv_laser_regen, 0, 0, 10000, CFGFLAG_SERVER, "Ammo regeneration in ms")
MACRO_CONFIG_INT(SvLaserProjectiles, sv_laser_projectiles, 1, 1, 76, CFGFLAG_SERVER, "Amount of projectiles this weapons shoot")
MACRO_CONFIG_INT(SvLaserReload, sv_laser_reload, 800, 1, 10000, CFGFLAG_SERVER, "Time it takes to shoot again in ms")

//unused but added :3
MACRO_CONFIG_INT(SvNinjaSwitch, sv_ninja_switch, 0, 0, 1, CFGFLAG_SERVER, "Gives the possibility to switch your weapon while having ninja")
MACRO_CONFIG_INT(SvNinjaDuration, sv_ninja_duration, 15, -1, 10000, CFGFLAG_SERVER, "Time you got the Weapon")
MACRO_CONFIG_INT(SvNinjaStart, sv_ninja_start, 0, 0, 1, CFGFLAG_SERVER, "If you spawn with or without this weapon")
MACRO_CONFIG_INT(SvNinjaAuto, sv_ninja_auto, 0, 0, 1, CFGFLAG_SERVER, "Fullautomatical weapon")
MACRO_CONFIG_INT(SvNinjaReload, sv_ninja_reload, 800, 1, 10000, CFGFLAG_SERVER, "Time it takes to shoot again in ms")
MACRO_CONFIG_INT(SvNinjaDamage, sv_ninja_damage, 9, 0, 100, CFGFLAG_SERVER, "Damage this weapon takes")
MACRO_CONFIG_INT(SvNinjaSpawn, sv_ninja_spawn, 99999999, 0, 99999999, CFGFLAG_SERVER, "Time it takes to respawn in seconds")

// Wall variables
MACRO_CONFIG_INT(SvWallExtraTick, sv_wall_extra_tick,10,-10,10, CFGFLAG_SERVER, "Changes the thinkness of the Wall depending on the tick")
MACRO_CONFIG_INT(SvWallDamage, sv_wall_damage,1,1,500, CFGFLAG_SERVER, "Damage of the wall.")
MACRO_CONFIG_INT(SvWallDamageTickDelay, sv_wall_wall_damage_tick_delay,10,1,500, CFGFLAG_SERVER, "Delay (in ticks) between each attack.")

MACRO_CONFIG_INT(SvExplosivePower, sv_explosive_power, 6, 0, 50, CFGFLAG_SERVER, "Power of an explosion. Important for rocket jumps for example")
MACRO_CONFIG_INT(SvExplosiveSelfdamageAuto, sv_explosive_selfdamage_auto, 1, 0, 1, CFGFLAG_SERVER, "Half of damage goes to explosion damage if activated")

// Gameplay Vars
MACRO_CONFIG_INT(SvMinPlayers, sv_min_players, 5, 2, 16, CFGFLAG_SERVER, "Number of players needed for the start!")
//MACRO_CONFIG_INT(SvAntiZoom, sv_anti_zoom, 1, 0, 1, CFGFLAG_SERVER, "Enable anti zoom!")
//MACRO_CONFIG_INT(SvAntiZoomNum, sv_anti_zoom_num, 0, 0, 10000, CFGFLAG_SERVER, "Number of useless objects which get generated!.")


// debug
#ifdef CONF_DEBUG // this one can crash the server if not used correctly
	MACRO_CONFIG_INT(DbgDummies, dbg_dummies, 0, 0, 15, CFGFLAG_SERVER, "")
#endif

MACRO_CONFIG_INT(DbgFocus, dbg_focus, 0, 0, 1, CFGFLAG_CLIENT, "")
MACRO_CONFIG_INT(DbgTuning, dbg_tuning, 0, 0, 1, CFGFLAG_CLIENT, "")
#endif
