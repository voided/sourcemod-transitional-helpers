
#if defined __thelpers_tf2_objects_included
	#endinput
#endif

#define __thelpers_tf2_objects_included


methodmap CBaseObject < CBaseCombatCharacter
{
	public CBaseObject( int entIndex )
	{
		return CBaseObject:CBaseCombatCharacter( entIndex );
	};


	property CTFPlayer Builder
	{
		public get() { return CTFPlayer:this.GetPropEnt( Prop_Send, "m_hBuilder" ); };
	};;

	property TFObjectType ObjectType
	{
		public get() { return TFObjectType:this.GetProp( Prop_Send, "m_iObjectType" ); };
	};;

	property bool IsBuilding
	{
		public get() { return this.GetProp( Prop_Send, "m_bBuilding" ) == 1; };
	};;
	property bool IsPlacing
	{
		public get() { return this.GetProp( Prop_Send, "m_bPlacing" ) == 1; };
	};;
	property bool IsCarried
	{
		public get() { return this.GetProp( Prop_Send, "m_bCarried" ) == 1; };
	};;
	property bool IsDisabled
	{
		public get() { return this.GetProp( Prop_Send, "m_bDisabled" ) == 1; };
	};;
	property bool IsDisposableBuilding
	{
		public get() { return this.GetProp( Prop_Send, "m_bDisposableBuilding" ) == 1; };
	};;
	property bool IsMiniBuilding
	{
		public get() { return this.GetProp( Prop_Send, "m_bMiniBuilding" ) == 1; };
	};;

	property float PercentConstructed
	{
		public get() { return this.GetPropFloat( Prop_Send, "m_flPercentageConstructed" ); };
	};;

	property int UpgradeLevel
	{
		public get() { return this.GetProp( Prop_Send, "m_iUpgradeLevel" ); };
	};;
	property int UpgradeMetal
	{
		public get() { return this.GetProp( Prop_Send, "m_iUpgradeMetal" ); };
	};;

};
