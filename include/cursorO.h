#ifndef CURSORO__H
#define CURSORO__H

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "global.h"
#include "cursor.h"

typedef struct s_CursorPointer 
{
	int x;
	int y;

	glImage textures[1];
	int texture_id;
} CursorPointer;

void InitializeCursor(CursorPointer* cursor_pointer);
void CursorLogic(CursorPointer* cursor_pointer, int key, int prev_keys);
void DrawCursor(CursorPointer* cursor_pointer, int camera_x, int camera_y);
#endif
