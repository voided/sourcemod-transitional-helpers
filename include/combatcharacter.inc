
#if defined __thelpers_combatcharacter_included
	#endinput
#endif

#define __thelpers_combatcharacter_included

// CBaseCombatCharacter technically derives from CBaseFlex, but there likely isn't much that's useful from serverside plugins
// may revisit implementing flex if the need arises

/**
 * Entity methodmap that all combat characters derive from, including NPCs and players.
*/
methodmap CBaseCombatCharacter __nullable__ < CBaseAnimating
{
	/**
	 * Create a CBaseCombatCharacter instance from the given entity index.
	 *
	 * @param entIndex		The entity index to bind this methodmap to. Can be an invalid entity index.
	 *						You can use the CBaseEntity.IsValid property to check if the given entity is valid or not.
	*/
	public CBaseCombatCharacter( int entIndex )
	{
		return view_as<CBaseCombatCharacter>( new CBaseAnimating( entIndex ) );
	}


	/**
	 * Gets or sets the active weapon of this combat character instance.
	*/
	property CBaseCombatWeapon ActiveWeapon
	{
		public get() { return view_as<CBaseCombatWeapon>( this.GetPropEnt( Prop_Send, "m_hActiveWeapon" ) ); }
		public set( CBaseCombatWeapon weapon ) { this.SetPropEnt( Prop_Send, "m_hActiveWeapon", weapon ); }
	}


	/**
	 * Gets the weapon entity in a combat character's specific weapon slot.
	 * 
	 * @param slot		The slot index to retrieve the weapon of.
	 * 
	 * @return	The weapon entity in the combat character's slot.
	*/
	public CBaseCombatWeapon GetWeaponInSlot( int slot )
	{
		return new CBaseCombatWeapon( GetPlayerWeaponSlot( this.Index, slot ) );
	}

	/**
	 * Equips the combat character with the provided weapon.
	 * 
	 * @param weapon	The weapon to equip onto the combat character.
	 */
	public void EquipWeapon( CBaseCombatWeapon weapon )
	{
		EquipPlayerWeapon( this.Index, weapon.Index );
	}
};
