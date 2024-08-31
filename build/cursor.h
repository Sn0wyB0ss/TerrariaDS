
//{{BLOCK(cursor)

//======================================================================
//
//	cursor, 16x16@8, 
//	+ palette 256 entries, not compressed
//	+ bitmap not compressed
//	Total size: 512 + 256 = 768
//
//	Time-stamp: 2024-08-31, 13:56:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CURSOR_H
#define GRIT_CURSOR_H

#define cursorBitmapLen 256
extern const unsigned int cursorBitmap[64];

#define cursorPalLen 512
extern const unsigned short cursorPal[256];

#endif // GRIT_CURSOR_H

//}}BLOCK(cursor)
