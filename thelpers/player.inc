
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

	/**
	 * Is this player connected to the server?
	*/
	property bool IsConnected
	{
		public get() { return IsClientConnected( this.Index ); }
	}
	/**
	 * Is this player in game?
	*/
	property bool IsInGame
	{
		public get() { return IsClientInGame( this.Index ); }
	}
	/**
	 * Is this player fully authorized by Steam?
	*/
	property bool IsAuthorized
	{
		public get() { return IsClientAuthorized( this.Index ); }
	}

	/**
	 * Is this player in SM's kick queue?
	*/
	property bool IsInKickQueue
	{
		public get() { return IsClientInKickQueue( this.Index ); }
	}

	/**
	 * Is this player a fake client (bot)?
	*/
	property bool IsFakeClient
	{
		public get() { return IsFakeClient( this.Index ); }
	}
	/**
	 * Is this player the SourceTV client?
	*/
	property bool IsSourceTV
	{
		public get() { return IsClientSourceTV( this.Index ); }
	}
	/**
	 * Is this player the Replay client?
	*/
	property bool IsReplay
	{
		public get() { return IsClientReplay( this.Index ); }
	}

	/**
	 * Is this player alive?
	*/
	property bool IsAlive
	{
		public get() { return IsPlayerAlive( this.Index ); }
	}
	/**
	 * Is this player spectating?
	 * Note: dead players are considered spectators.
	*/
	property bool IsSpectator
	{
		public get() { return IsClientObserver( this.Index ); }
	}


	/**
	 * Gets the Steam Account ID of this player.
	 *
	 * @param validate		Check Steam back-end validation status.
	*/
	public int GetAccountID( bool validate = true )
	{
		return GetSteamAccountID( this.Index, validate );
	}

	/**
	 * Gets the Steam ID string of this player.
	 *
	 * @param buffer		The character buffer to copy the Steam ID to.
	 * @param maxBuffer		The maximum size of the input buffer.
	 * @param validate		Check Steam back-end validation status.
	 *
	 * @return		True on success, false otherwise.
	*/
	public bool GetSteamID( char[] buffer, int maxBuffer, bool validate = true )
	{
		return GetClientAuthString( this.Index, buffer, maxBuffer, validate );
	}

	/**
	 * Gets the player's display name.
	 *
	 * @param buffer		The buffer to copy the name into.
	 * @param maxBuffer		The maximum size of the buffer.
	 *
	 * @return		True on success, false otherwise.
	*/
	public bool GetName( char[] buffer, int maxBuffer )
	{
		return GetClientName( this.Index, buffer, maxBuffer );
	}

	/**
	 * Gets the player's IP address.
	 *
	 * @param buffer		The buffer to copy the IP into.
	 * @param maxBuffer		The maximum size of the buffer.
	 * @param removePort	If true, the client's port will be excluded from the address.
	 *
	 * @return		True on success, false otherwise.
	*/
	public bool GetIP( char[] buffer, int maxBuffer, bool removePort = true )
	{
		return GetClientIP( this.Index, buffer, maxBuffer, removePort );
	}

	/**
	 * Gets the OBB minimum extent of this player's collision prop.
	 *
	 * @param vec		Vector buffer to store the result in.
	*/
	public void GetMins( float vec[ 3 ] )
	{
		GetClientMins( this.Index, vec );
	}
	/**
	 * Gets the OBB maximum extent of this player's collision prop.
	 *
	 * @param vec		Vector buffer to store the result in.
	*/
	public void GetMaxs( float vec[ 3 ] )
	{
		GetClientMaxs( this.Index, vec );
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
