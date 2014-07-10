
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


// require transitional api for our includes
#pragma newdecls required

#include "thelpers_entity.inc"
#include "thelpers_client.inc"

// reset
#pragma newdecls optional
