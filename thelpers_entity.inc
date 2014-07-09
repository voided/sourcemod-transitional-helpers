
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
		public get()
		{
			return EntRefToEntIndex( _:this );
		};
		public set( int index )
		{
			this = Entity:EntIndexToEntRef( index );
		};
	};;

	property bool IsValid
	{
		public get() { return IsValidEntity( _:this ); };
	};;
};

stock Entity Entity_CreateByName( const char[] className, int forceEdictIndex = -1 )
{
	int entIndex = CreateEntityByName( className, forceEdictIndex );
	return Entity( entIndex );
}
