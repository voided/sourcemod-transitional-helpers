## SM Transitional API Helpers

A set of helper include files for cleverly (or abusively) working with the SM transitional API.

These helpers define a hierarchical structure of methodmaps that attempt to emulate the class hierarchy of Source engine entities. Modders should feel right at home by seeing familiar class names such as `CBaseCombatWeapon`, `CBasePlayer`, etc.

## Usage

Include thelpers:

```sourcepawn
#define GAME_TF2 // required to pull in tf2 related helpers
#include <thelpers>
```

Go wild:

```sourcepawn
public void OnClientPutInServer( int client )
{
  CBasePlayer player = new CBasePlayer( client );

  char steamId[ 128 ];
  player.GetSteamID( AuthId_Steam2, steamId, sizeof( steamId ) );

  PrintToServer( "%N's steam id: %s", player.Index, steamId );

  // do some tf2 specific stuff
  CTFPlayer tfPlayer = view_as<CTFPlayer>( player ); // "downcast" to a CTFPlayer object
  tfPlayer.SetClass( TFClassType_Medic );

  // we didn't like them anyway
  ServerCommand( "sm_kick #%d", player.UserID );
}
```

## Documentation

The include files themselves are highly documented with doxygen-like comments. Simply browse [around the tree](https://github.com/VoiDeD/sourcemod-transitional-helpers/tree/master/thelpers).

### Supported Games

The API aims to be game-agnostic where possible to support all possible games. However, it is possible to enable game specific features by `#defining GAME_X` before including the thelpers files.

Currently only TF2 and some CS:S specific additions have been implemented (enabled with the `GAME_TF2` and `GAME_CSS` defines respectively), but pull requests for other games are welcome!

If your game uses econ entities, you can enable econ functionality with `#define GAME_ECON`. This is defined by default for games that have econ entities.

## Considerations

- This library likely won't have much active development, but PRs are still welcome.

### Methodmaps, `null`, & `INVALID_ENTITY`

The thelpers methodmaps originally "creatively" utilized the functionality of `__nullable__` to allow comparisons with `null` to check entity validity.

SourceMod has since updated the syntax to disallow this, so the supported way forward is to perform comparison checks against the `INVALID_ENTITY` constant in this library.

While `__nullable__` now has no useful use in thelpers, the methodmap definitions will remain nullable to support existing consumers who are using the `new ...()` syntax to construct the methodmaps.
