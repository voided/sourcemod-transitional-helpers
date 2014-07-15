
#if defined __thelpers_gamerules_included
	#endinput
#endif

#define __thelpers_gamerules_included


/**
 * Base gamerules class.
 * Note: this represents the gamerules proxy entity, but this makes no functional difference for usage.
*/
methodmap CGameRules < CBaseEntity
{
};


/**
 * Gamerules for multiplayer games.
*/
methodmap CMultiplayRules < CGameRules
{
};


/**
 * Gamerules for teamplay based multiplayer games.
*/
methodmap CTeamplayRules < CMultiplayRules
{
};


/**
 * Gamerules for round and team based multiplayer games.
*/
methodmap CTeamplayRoundBasedRules < CTeamplayRules
{
	/**
	 * Gets the current round state of the game.
	*/
	property int RoundState
	{
		public get() { return GameRules_GetProp( "m_iRoundState" ); }
	}

	/**
	 * Is the game currently in overtime?
	*/
	property bool IsInOvertime
	{
		public get() { return GameRules_GetProp( "m_bInOvertime" ) == 1; }
	}
	/**
	 * Is the game in setup?
	*/
	property bool IsInSetup
	{
		public get() { return GameRules_GetProp( "m_bInSetup" ) == 1; }
	}
};


/**
 * Returns the gamerules proxy entity for this game, or INVALID_ENTITY if the entity has not been created yet.
*/
stock CGameRules GameRules_GetEntity()
{
#if defined GAME_TF2
	return CGameRules:Entity_FindByClassname( INVALID_ENTITY, "tf_gamerules" );
#elseif defined GAME_CSS || defined GAME_CSGO
	return CGameRules:Entity_FindByClassname( INVALID_ENTITY, "cs_gamerules" );
#elseif defined GAME_DODS
	return CGameRules:Entity_FindByClassname( INVALID_ENTITY, "dod_gamerules" );
#elseif defined GAME_HL2MP
	return CGameRules:Entity_FindByClassname( INVALID_ENTITY, "hl2mp_gamerules" );
#elseif defined GAME_L4D || defined GAME_L4D2
	return CGameRules:Entity_FindByClassname( INVALID_ENTITY, "terror_gamerules" );
#elseif defined GAME_DOTA
	return CGameRules:Entity_FindByClassname( INVALID_ENTITY, "dota_gamerules" );
#else
	// todo: throw error
	return CGameRules:INVALID_ENTITY;
#endif
}
