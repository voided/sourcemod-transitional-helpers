
/*
 * SM transitional API helpers
 */

#if defined __thelpers_included
	#endinput
#endif

#define __thelpers_included


// include what thelpers requires
#include <sdktools>
#include <halflife>
#include <tf2>


// require transitional api for our includes
#pragma newdecls required


// generic sdk includes
#include "thelpers/entity.inc"
#include "thelpers/animating.inc"
#include "thelpers/combatweapon.inc"
#include "thelpers/combatcharacter.inc"
#include "thelpers/player.inc"

// game includes
#include "thelpers/tf2/tf2.inc"


// reset
#pragma newdecls optional
