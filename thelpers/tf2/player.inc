
#if defined __thelpers_tf2_player_included
	#endinput
#endif

#define __thelpers_tf2_player_included


/**
 * Entity class that all TF2 player entities derive from.
*/
methodmap CTFPlayer < CBasePlayer
{
	/**
	 * Create a CTFPlayer instance from the given client index.
	 *
	 * @param clientIndex	The client index to bind this methodmap to. Can be an invalid client index.
	 *						You can use the CBaseEntity.IsValid property to check if the given client is valid or not.
	*/
	public CTFPlayer( int clientIndex )
	{
		return CTFPlyer:CBasePlayer( clientIndex );
	}


	/**
	 * Gets the team this player belongs to.
	*/
	property TFTeam Team
	{
		public get() { return TFTeam:GetClientTeam( this.Index ); }
	}

	/**
	 * Gets the player class of this player instance.
	*/
	property TFClassType Class
	{
		public get() { return TF2_GetPlayerClass( this.Ref ); }
	}

	/**
	 * Sets the client's player class.
	 *
	 * @param class			The TF2 class to set the player to.
	 * @param persistent	If true, this sets the player's desired class so it sticks after death.
	*/
	public void SetClass( TFClassType class, bool persistent = true )
	{
		TF2_SetPlayerClass( this.Ref, class, _, persistent );
	}

};
