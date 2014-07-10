
#if defined __thelpers_entity_included
	#endinput
#endif

#define __thelpers_entity_included


methodmap Entity
{
	public Entity( int entIndex )
	{
		if ( !IsValidEntity( entIndex ) )
			return Entity:INVALID_ENT_REFERENCE;

		return Entity:EntIndexToEntRef( entIndex );
	};


	property int Index
	{
		public get() { return EntRefToEntIndex( _:this ); };
	};;
	property int Ref
	{
		public get() { return _:this; };
	};;

	property bool IsValid
	{
		public get() { return IsValidEntity( this.Ref ); };
	};;


	public int GetProp( PropType propType, const char[] propName, int size = 4, int element = 0 )
	{
		return GetEntProp( this.Ref, propType, propName, size, element );
	};
	public float GetPropFloat( PropType propType, const char[] propName, int element = 0 )
	{
		return GetEntPropFloat( this.Ref, propType, propName, element );
	};
	public Entity GetPropEnt( PropType propType, const char[] propName, int element = 0 )
	{
		int entIndex = GetEntPropEnt( this.Ref, propType, propName, element );
		return Entity( entIndex );
	};
	public void GetPropVector( PropType propType, const char[] propName, float vec[ 3 ], int element = 0 )
	{
		GetEntPropVector( this.Ref, propType, propName, vec, element );
	};
	public int GetPropString( PropType propType, const char[] propName, char[] buffer, int maxBuffer, int element = 0 )
	{
		return GetEntPropString( this.Ref, propType, propName, buffer, maxBuffer, element );
	};

	public void SetProp( PropType propType, const char[] propName, int value, int size = 4, int element = 0 )
	{
		SetEntProp( this.Ref, propType, propName, value, size, element );
	};
	public void SetPropFloat( PropType propType, const char[] propName, float value, int element = 0 )
	{
		SetEntPropFloat( this.Ref, propType, propName, value, element );
	};
	public void SetPropEnt( PropType propType, const char[] propName, Entity value, int element = 0 )
	{
		SetEntPropEnt( this.Ref, propType, propName, value, element );
	};
	public void SetPropVector( PropType propType, const char[] propName, const float vec[ 3 ], int element = 0 )
	{
		SetEntPropVector( this.Ref, propType, propName, vec, eleemnt );
	};
	public int SetPropString( PropType propType, const char[] propName, const char[] buffer )
	{
		return SetEntPropString( this.Ref, propType, propName, buffer );
	};


	property int Skin
	{
		public get() { return this.GetProp( Prop_Send, "m_nSkin" ); };
		public set( int skin ) { this.SetProp( Prop_Send, "m_nSkin", skin ); };
	};;

	property float ModelScale
	{
		public get() { return this.GetPropFloat( Prop_Send, "m_flModelScale" ); };
		public set( float scale ) { this.SetPropFloat( Prop_Send, "m_flModelScale", scale ); };
	};;


	public void SetModel( const char[] model )
	{
		SetEntityModel( this.Ref, model );
	};
	public int GetModel( char[] buffer, int maxBuffer )
	{
		return this.GetPropString( Prop_Data, "m_ModelName", buffer, maxBuffer );
	};

	public void GetLocalOrigin( float vec[ 3 ] )
	{
		this.GetPropVector( Prop_Send, "m_vecOrigin", vec );
	};
	public void SetLocalOrigin( const float vec[ 3 ] )
	{
		this.SetPropVector( Prop_Send, "m_vecOrigin", vec );
	};
	public void GetLocalAngles( float ang[ 3 ] )
	{
		this.GetPropVector( Prop_Send, "m_angRotation", ang );
	};
	public void SetLocalAngles( const float ang[ 3 ] )
	{
		this.SetPropVector( Prop_Send, "m_angRotation", ang );
	};

	public void GetAbsOrigin( float vec[ 3 ] )
	{
		this.GetPropVector( Prop_Data, "m_vecAbsOrigin", vec );
	};
	public void SetAbsOrigin( const float vec[ 3 ] )
	{
		this.SetPropVector( Prop_Data, "m_vecAbsOrigin", vec );
	};
	public void GetAbsAngles( float ang[ 3 ] )
	{
		this.GetPropVector( Prop_Data, "m_angAbsRotation", ang );
	};
	public void SetAbsAngles( const float ang[ 3 ] )
	{
		this.SetPropVector( Prop_Data, "m_angAbsRotation", ang );
	};

	public bool Spawn()
	{
		return DispatchSpawn( this.Ref );
	};

	public void Teleport( const float origin[ 3 ], const float angles[ 3 ], const float velocity[ 3 ] )
	{
		TeleportEntity( this.Ref, origin, angles, velocity );
	};

	public bool KeyValue( const char[] keyName, const char[] value )
	{
		return DispatchKeyValue( this.Ref, keyName, value );
	};
	public bool KeyValueFloat( const char[] keyName, float value )
	{
		return DispatchKeyValueFloat( this.Ref, keyName, value );
	};
	public bool KeyValueVector( const char[] keyName, const float vec[ 3 ] )
	{
		return DispatchKeyValueVector( this.Ref, keyName, vec );
	};

	public bool AcceptInput( const char[] input, Entity activator = Entity:-1, Entity caller = Entity:-1, int outputid = 0 )
	{
		return AcceptEntityInput( this.Ref, input, activator.Ref, caller.Ref, outputid );
	};

	public void SetParent( Entity parent )
	{
		SetVariantString( "!activator" );
		this.AcceptInput( "SetParent", parent );
	};
	public void SetParentAttachment( const char[] attachmentName )
	{
		SetVariantString( attachmentName );
		this.AcceptInput( "SetParentAttachment" );
	};

	public Entity GetParent()
	{
		return this.GetPropEnt( Prop_Data, "m_pParent" );
	};
	public Entity GetMoveParent()
	{
		return this.GetPropEnt( Prop_Send, "moveparent" );
	};
};


/*const*/ Entity INVALID_ENTITY = Entity:INVALID_ENT_REFERENCE;


stock Entity Entity_CreateByName( const char[] className, int forceEdictIndex = -1 )
{
	int entIndex = CreateEntityByName( className, forceEdictIndex );
	return Entity( entIndex );
}

stock Entity Entity_FindByClassname( Entity startEnt, const char[] className )
{
	int entIndex = FindEntityByClassname( startEnt.Ref, className );
	return Entity( entIndex );
}


stock bool operator==( Entity oper1, Entity oper2 )
{
	return oper1.Ref == oper2.Ref;
}

stock bool operator!=( Entity oper1, Entity oper2 )
{
	return !( oper1 == oper2 );
}
