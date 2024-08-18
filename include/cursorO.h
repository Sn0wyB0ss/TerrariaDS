#ifndef CURSORO__H
#define CURSORO__H

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "structs.h"

#include "cursor.h"

CursorPointer* InitializeCursor();
void CursorLogic(CursorPointer* cursor_pointer, int key, int prev_keys);
void DrawCursor(CursorPointer* cursor_pointer, Camera* camera);
#endif
