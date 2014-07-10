
#if defined __thelpers_client_included
	#endinput
#endif

#define __thelpers_client_included


methodmap Client < Entity
{
	property int Team
	{
		public get() { return GetClientTeam( this.Index ); };
	};;

	property int UserID
	{
		public get() { return GetClientUserId( this.Index ); };
	};;
};
