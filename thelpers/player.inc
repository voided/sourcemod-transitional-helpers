
#if defined __thelpers_client_included
	#endinput
#endif

#define __thelpers_client_included


methodmap CBasePlayer < CBaseCombatCharacter
{
	public CBasePlayer( int clientIndex )
	{
		if ( clientIndex == 0 )
		{
			return CBasePlayer:INVALID_ENTITY;
		}
		
		return CBasePlayer:CBaseCombatCharacter( clientIndex );
	}


	property int Team
	{
		public get() { return GetClientTeam( this.Index ); }
	}

	property int UserID
	{
		public get() { return GetClientUserId( this.Index ); }
	}
};


stock CBasePlayer Player_FromUserId( int userid )
{
	int clientIndex = GetClientOfUserId( userid );
	return CBasePlayer( clientIndex );
}
