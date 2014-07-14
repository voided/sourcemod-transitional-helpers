
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


// figure out what game we are, and what features are enabled
#if defined GAME_TF2
	// tf2 uses econ entities
	#define GAME_ECON

	#include <tf2>
	#include <tf2_stocks>
#endif


// require transitional api for our includes
#pragma newdecls required


// generic sdk includes
#include "thelpers/entity.inc"
#include "thelpers/animating.inc"

#if defined GAME_ECON
	// econ has to be included fairly early, as other entity methodmaps rely on it
	#include "thelpers/econ/econ.inc"
#endif

#include "thelpers/combatweapon.inc"
#include "thelpers/combatcharacter.inc"
#include "thelpers/player.inc"


// game includes
#if defined GAME_TF2
	#include "thelpers/tf2/tf2.inc"
#endif


// reset
#pragma newdecls optional
