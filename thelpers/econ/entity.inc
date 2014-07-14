
#if defined __thelpers_econ_entity_included
	#endinput
#endif

#define __thelpers_econ_entity_included


methodmap CEconEntity < CBaseAnimating
{
	/**
	 * Create a CEconEntity instance from the given entity index.
	 *
	 * @param entIndex		The entity index to bind this methodmap to. Can be an invalid entity index.
	 *						You can use the CBaseEntity.IsValid property to check if the given entity is valid or not.
	*/
	public CEconEntity( int entIndex )
	{
		return CEconEntity:CBaseAnimating( entIndex );
	}


	/**
	 * Gets the item definition index of this econ entity.
	*/
	property int ItemIndex
	{
		public get() { return this.GetProp( Prop_Send, "m_iItemDefinitionIndex" ); }
	}

	/**
	 * Gets the item level of this econ entity.
	*/
	property int ItemLevel
	{
		public get() { return this.GetProp( Prop_Send, "m_iEntityLevel" ); }
	}
	/**
	 * Gets the item quality of this econ entity.
	*/
	property int ItemQuality
	{
		public get() { return this.GetProp( Prop_Send, "m_iEntityQuality" ); }
	}

	/**
	 * Gets the Steam Account ID of the owner of this econ entity.
	*/
	property int AccountID
	{
		public get() { return this.GetProp( Prop_Send, "m_iAccountID" ); }
	}


#if 0
	// would be nice to have this, but include order currently hoses us
	public CBasePlayer GetOwningPlayer()
	{
		for ( int client = 1 ; client <= MaxClients ; ++client )
		{
			CBasePlayer player = CBasePlayer( client );

			if ( player.GetAccountID() == this.AccountID )
				return player;
		}

		return CBasePlayer:INVALID_ENTITY;
	}
#endif

};
