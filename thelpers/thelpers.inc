
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
#include "thelpers_entity.inc"
#include "thelpers_animating.inc"
#include "thelpers_combatweapon.inc"
#include "thelpers_combatcharacter.inc"
#include "thelpers_player.inc"

// game includes
#include "thelpers_tf2.inc"


// reset
#pragma newdecls optional
