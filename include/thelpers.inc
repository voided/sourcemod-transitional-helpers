
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
#elseif defined GAME_CSS
	// css doesn't directly use econ entities, but has attribute containers
	#define GAME_ECON

	#include <cstrike>
#endif


// require transitional api for our includes
#pragma newdecls required


// generic sdk includes
#include "include/entity.inc"
#include "include/animating.inc"

#if defined GAME_ECON
	// econ has to be included fairly early, as other entity methodmaps rely on it
	#include "include/econ/econ.inc"
#endif

#include "include/combatweapon.inc"
#include "include/combatcharacter.inc"
#include "include/player.inc"

#include "include/gamerules.inc"


// game includes
#if defined GAME_TF2
	#include "include/tf2/tf2.inc"
#elseif defined GAME_CSS
	#include "include/css/css.inc"
#endif


// reset
#pragma newdecls optional
