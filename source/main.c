#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "structs.h"
#include "mapO.h"
#include "cameraO.h"
#include "cursorO.h"
#include "playerO.h"

enum GameState {G_MENU,G_OVERWOLRD};

void DSInitialSetup();
void Render(Player* player, Camera* camera, Map* map, CursorPointer* cursor_pointer);

void DSInitialSetup() {
	videoSetMode(MODE_5_3D);
	
	consoleDemoInit();
	
	glScreen2D(); // Initialize GL in 3d mode

	vramSetBankA( VRAM_A_TEXTURE ); 	// set  Bank A to texture (128 kb)

	vramSetBankE(VRAM_E_TEX_PALETTE);  // Allocate VRAM bank for all the palettes
}

void Render(Player* player, Camera* camera, Map* map, CursorPointer* cursor_pointer) {
		iprintf("\x1b[1;1HTerraria DS");
		iprintf("\x1b[2;1HArrow Keys to move");
		//iprintf("\x1b[5;1HTotal Texture size= %i kb", TextureSize / 1024);
		iprintf("\x1b[4;1HPlayerSpeedY = %i", player->speed_y);
		iprintf("\x1b[5;1HPlayerX = %i", player->x);
		iprintf("\x1b[6;1HPlayerY = %i", player->y);
		iprintf("\x1b[8;1HCamTileX = %i", camera->tile_x);
		iprintf("\x1b[9;1HCamTileX = %i", camera->tile_y);

		glBegin2D();
		
		DrawMap(map, camera);
		DrawCursor(cursor_pointer, camera);			
		DrawPlayer(player, camera);
		
		glEnd2D();
		
		glFlush(0);
}

int main( int argc, char *argv[] )
{

	DSInitialSetup();

	// calculate the amount of 
	// memory uploaded to VRAM in KB
	//int TextureSize = tilesBitmapLen +
	//				  cursorBitmapLen+
	//				  playerBitmapLen;

	int key;		// for key input
	int prevKeys;

	// Intialize Entities
	Camera *camera =  malloc(sizeof(Camera));
	Map *map = InitMap();
	Player *player = InitializePlayer();
	CursorPointer *cursor_pointer = InitializeCursor();

	CameraUpdate(camera, player, map);

	while( 1 )
	{

		// Update Inputs
		scanKeys();
		key = keysHeld();

		// Game Logic
		CursorLogic(cursor_pointer, key, prevKeys);
		MapInteraction(cursor_pointer, map, key);
		PlayerLogic(player, map, key);
		CameraUpdate(camera,player,map);

		// Render Logic
		Render(player,camera,map,cursor_pointer);
		swiWaitForVBlank();

		//Exit the Game?
		scanKeys();
		if (keysDown()&(KEY_START|KEY_SELECT)) break;	
	
		//Get The Previous Input
		prevKeys = key;
	}

	return 0;
	
}










