
#if defined __thelpers_combatweapon_included
	#endinput
#endif

#define __thelpers_combatweapon_included


// todo: should derive from CEconEntity in econ games
methodmap CBaseCombatWeapon < CBaseAnimating
{
	public CBaseCombatWeapon( int entIndex )
	{
		return CBaseCombatWeapon:CBaseAnimating( entIndex );
	};


	// todo
};
