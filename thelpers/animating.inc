
#if defined __thelpers_animating_included
	#endinput
#endif

#define __thelpers_animating_included


methodmap CBaseAnimating < CBaseEntity
{
	public CBaseAnimating( int entIndex )
	{
		return CBaseAnimating:CBaseEntity( entIndex );
	}


	property int Skin
	{
		public get() { return this.GetProp( Prop_Send, "m_nSkin" ); }
		public set( int skin ) { this.SetProp( Prop_Send, "m_nSkin", skin ); }
	}
	property int Body
	{
		public get() { return this.GetProp( Prop_Send, "m_nBody" ); }
		public set( int body ) { this.SetProp( Prop_Send, "m_nBody", body ); }
	}

	property float ModelScale
	{
		public get() { return this.GetPropFloat( Prop_Send, "m_flModelScale" ); }
		public set( float scale ) { this.SetPropFloat( Prop_Send, "m_flModelScale", scale ); }
	}


	public void SetModel( const char[] model )
	{
		SetEntityModel( this.Ref, model );
	}
	public int GetModel( char[] buffer, int maxBuffer )
	{
		return this.GetPropString( Prop_Data, "m_ModelName", buffer, maxBuffer );
	}
};
