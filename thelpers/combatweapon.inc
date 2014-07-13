
#if defined __thelpers_combatweapon_included
	#endinput
#endif

#define __thelpers_combatweapon_included


/**
 * Entity methodmap from which all weapon entities derive from.
*/
methodmap CBaseCombatWeapon < CBaseAnimating // todo: should derive from CEconEntity in econ games
{
	/**
	 * Create a CBaseCombatWeapon instance from the given entity index.
	 *
	 * @param entIndex		The entity index to bind this methodmap to. Can be an invalid entity index.
	 *						You can use the CBaseEntity.IsValid property to check if the given entity is valid or not.
	*/
	public CBaseCombatWeapon( int entIndex )
	{
		return CBaseCombatWeapon:CBaseAnimating( entIndex );
	}


	// todo
};
