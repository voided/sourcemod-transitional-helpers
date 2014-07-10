
#if defined __thelpers_client_included
	#endinput
#endif

#define __thelpers_client_included


methodmap Client < Entity
{
	public Client( int clientIndex )
	{
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