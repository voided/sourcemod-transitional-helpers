
#if defined __thelpers_client_included
	#endinput
#endif

#define __thelpers_client_included


methodmap Client < Entity
{
	public Client( int clientIndex )
	{
		if ( clientIndex == 0 )
		{
			return Client:INVALID_ENTITY;
		}
		
		return Client:Entity( clientIndex );
	};


	property int Team
	{
		public get() { return GetClientTeam( this.Index ); };
	};;

	property int UserID
	{
		public get() { return GetClientUserId( this.Index ); };
	};;
};


stock Client Client_FromUserId( int userid )
{
	int clientIndex = GetClientOfUserId( userid );
	return Client( clientIndex );
}


stock bool operator==( Client oper1, Entity oper2 )
{
	return Entity:oper1 == oper2;
}

stock bool operator!=( Client oper1, Entity oper2 )
{
	return !( oper1 == oper2 );
}
