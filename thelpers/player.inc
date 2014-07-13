
#if defined __thelpers_client_included
	#endinput
#endif

#define __thelpers_client_included


/**
 * Entity methodmap from which all players derive from.
*/
methodmap CBasePlayer < CBaseCombatCharacter
{
	/**
	 * Create a CBasePlayer instance from the given client index.
	 *
	 * @param clientIndex	The client index to bind this methodmap to. Can be an invalid client index.
	 *						You can use the CBaseEntity.IsValid property to check if the given client is valid or not.
	*/
	public CBasePlayer( int clientIndex )
	{
		if ( clientIndex == 0 )
		{
			// special case for client 0 as that is the worldspawn entity, and technically not a valid client
			return CBasePlayer:INVALID_ENTITY;
		}
		
		return CBasePlayer:CBaseCombatCharacter( clientIndex );
	}


	/**
	 * Gets the team this player belongs to.
	*/
	property int Team
	{
		public get() { return GetClientTeam( this.Index ); }
	}

	/**
	 * Gets the UserID of this player.
	*/
	property int UserID
	{
		public get() { return GetClientUserId( this.Index ); }
	}
};


/**
 * Helper function to get a CBasePlayer wrapper from a player of the given UserID.
*/
stock CBasePlayer Player_FromUserId( int userid )
{
	int clientIndex = GetClientOfUserId( userid );
	return CBasePlayer( clientIndex );
}
