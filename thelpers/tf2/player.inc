
#if defined __thelpers_tf2_player_included
	#endinput
#endif

#define __thelpers_tf2_player_included


methodmap CTFPlayer < CBasePlayer
{
	public CTFPlayer( int clientIndex )
	{
		return CTFPlyer:CBasePlayer( clientIndex );
	}

	// todo
};
