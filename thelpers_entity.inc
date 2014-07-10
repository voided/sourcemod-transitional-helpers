
#if defined __thelpers_entity_included
	#endinput
#endif

#define __thelpers_entity_included


methodmap Entity
{
	public Entity( int entIndex )
	{
		return Entity:EntIndexToEntRef( entIndex );
	};


	property int EntIndex
	{
		public get() { return EntRefToEntIndex( _:this ); };
	};;

	property bool IsValid
	{
		public get() { return IsValidEntity( _:this ); };
	};;


	public int GetProp( PropType propType, const char[] propName, int size = 4, int element = 0 )
	{
		return GetEntProp( _:this, propType, propName, size, element );
	};
	public float GetPropFloat( PropType propType, const char[] propName, int element = 0 )
	{
		return GetEntPropFloat( _:this, propType, propName, element );
	};
	public Entity GetPropEnt( PropType propType, const char[] propName, int element = 0 )
	{
		int entIndex = GetEntPropEnt( _:this, propType, propName, element );
		return Entity( entIndex );
	};
	public void GetPropVector( PropType propType, const char[] propName, float vec[ 3 ], int element = 0 )
	{
		GetEntPropVector( _:this, propType, propName, vec, element );
	};
	public void GetPropString( PropType propType, const char[] propName, char[] buffer, int maxBuffer, int element = 0 )
	{
		GetEntPropString( _:this, propType, propName, buffer, maxBuffer, element );
	};

	public void SetProp( PropType propType, const char[] propName, int value, int size = 4, int element = 0 )
	{
		SetEntProp( _:this, propType, propName, value, size, element );
	};
	public void SetPropFloat( PropType propType, const char[] propName, float value, int element = 0 )
	{
		SetEntPropFloat( _:this, propType, propName, value, element );
	};
	public void SetPropEnt( PropType propType, const char[] propName, Entity value, int element = 0 )
	{
		SetEntPropEnt( _:this, propType, propName, value, element );
	};
	public void SetPropVector( PropType propType, const char[] propName, const float vec[ 3 ], int element = 0 )
	{
		SetEntPropVector( _:this, propType, propName, vec, eleemnt );
	};
	public int SetPropString( PropType propType, const char[] propName, const char[] buffer )
	{
		return SetEntPropString( _:this, propType, propName, buffer );
	};
};

stock Entity Entity_CreateByName( const char[] className, int forceEdictIndex = -1 )
{
	int entIndex = CreateEntityByName( className, forceEdictIndex );
	return Entity( entIndex );
}
