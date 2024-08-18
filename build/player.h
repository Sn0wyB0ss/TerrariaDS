
//{{BLOCK(player)

//======================================================================
//
//	player, 512x32@8, 
//	+ palette 256 entries, not compressed
//	+ bitmap not compressed
//	Total size: 512 + 16384 = 16896
//
//	Time-stamp: 2024-08-17, 15:12:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PLAYER_H
#define GRIT_PLAYER_H

#define playerBitmapLen 16384
extern const unsigned int playerBitmap[4096];

#define playerPalLen 512
extern const unsigned short playerPal[256];

#endif // GRIT_PLAYER_H

//}}BLOCK(player)
