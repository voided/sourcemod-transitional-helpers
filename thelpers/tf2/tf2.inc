
#if defined __thelpers_tf2_included
	#endinput
#endif

#define __thelpers_tf2_included



// everything the tf2 related includes require
#include <tf2>
#include <tf2_stocks>


// require transitional api for our includes
#pragma newdecls required

// tf2 related includes
#include "thelpers/tf2/player.inc"
#include "thelpers/tf2/objects.inc"

// reset
#pragma newdecls optional