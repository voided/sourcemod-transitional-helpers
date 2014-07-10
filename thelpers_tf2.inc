
#if defined __thelpers_tf2_included
	#endinput
#endif

#define __thelpers_tf2_included


methodmap TFObject < Entity
{
	public TFObject( int entIndex )
	{
		return TFObject:Entity( entIndex );
	};


	property Client Builder
	{
		public get() { return Client:this.GetPropEnt( Prop_Send, "m_hBuilder" ); };
	};;

	property TFObjectType ObjectType
	{
		public get() { return TFObjectType:this.GetProp( Prop_Send, "m_iObjectType" ); };
	};;

	property int UpgradeLevel
	{
		public get() { return this.GetProp( Prop_Send, "m_iUpgradeLevel" ); };
	};;

	property bool IsMiniBuilding
	{
		public get() { return this.GetProp( Prop_Send, "m_bMiniBuilding" ) == 1; };
	};;
};


stock bool operator==( TFObject oper1, Entity oper2 )
{
	return Entity:oper1 == oper2;
}

stock bool operator!=( TFObject oper1, Entity oper2 )
{
	return !( oper1 == oper2 );
}
