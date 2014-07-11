
#if defined __thelpers_combatcharacter_included
	#endinput
#endif

#define __thelpers_combatcharacter_included


methodmap CBaseCombatCharacter < CBaseAnimating
{
	public CBaseCombatCharacter( int entIndex )
	{
		return CBaseCombatCharacter:CBaseAnimating( entIndex );
	};


	property CBaseCombatWeapon ActiveWeapon
	{
		public get() { return this.GetPropEnt( Prop_Send, "m_hActiveWeapon" ); };
	};;
};
