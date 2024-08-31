#include <nds.h>
#include <stdio.h>
#include <gl2d.h>
#include <fat.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "global.h"
#include "mapO.h"
#include "cameraO.h"
#include "cursorO.h"
#include "playerO.h"


enum GameState {G_MENU,G_OVERWOLRD};

//void DSInitialSetup();
//void RenderCoreGameplay(Player* player, Camera* camera, Map* map, CursorPointer* cursor_pointer);

//void SaveWorld(Map* map) {
	
//	char map_data[MAP_WIDTH * MAP_HEIGHT * 2] = "";
//	int y;
//	int x;
//	int data = 0;
//	int j = 0;

//	for (y = 0; y < MAP_HEIGHT; y++) {
//		for (x = 0; x < MAP_WIDTH; x++) {
//			data = map->blocks_array[x][y];
//			map_data[j] = (char)data;
//			j++;
//			strcat(map_data, ",");
//			j++;
//		}
//		strcat(map_data, ";");
//			j++;
//	}

//	if (nitroFSInit(NULL)) {

//	FILE* inf = fopen("file1.txt","wb");

//	fprintf(inf, "%s", map_data);

//	fclose(inf);
//	}
//}



void DSInitialSetup() {
	videoSetMode(MODE_5_3D);
	
	consoleDemoInit();
	
	glScreen2D(); // Initialize GL in 3d mode

	vramSetBankA( VRAM_A_TEXTURE ); 	// set  Bank A to texture (128 kb)

	vramSetBankE(VRAM_E_TEX_PALETTE);  // Allocate VRAM bank for all the palettes
}

void InitGameWorld(Player* player, Camera* camera, Map* map, CursorPointer* cursor_pointer) {
	camera =  malloc(sizeof(Camera));
	InitMap(map);
	InitializePlayer(player);
	InitializeCursor(cursor_pointer);
	CameraUpdate(camera, player->x, player->y, map->width, map->height);
}

void RenderCoreGameplay(Player* player, Camera* camera, Map* map, CursorPointer* cursor_pointer, char* test) {
		iprintf("\x1b[1;1HTerraria DS");
		iprintf("\x1b[2;1HArrow Keys to move");
		//iprintf("\x1b[5;1HTotal Texture size= %i kb", TextureSize / 1024);
		iprintf("\x1b[4;1HPlayerSpeedY = %f", player->speed_y);
		iprintf("\x1b[5;1HPlayerX = %i", player->x);
		iprintf("\x1b[6;1HPlayerY = %i", player->y);
		iprintf("\x1b[8;1HCamTileX = %i", camera->tile_x);
		iprintf("\x1b[9;1HCamTileX = %i", camera->tile_y);
		iprintf("\x1b[10;1HTest = %s", test);

		glBegin2D();
		
		DrawMap(map, camera->tile_x, camera->tile_y, camera->pixel_x, camera->pixel_y);
		DrawCursor(cursor_pointer, camera->x, camera->y);		
		glSprite(0,0,GL_FLIP_NONE, &map->tiles_images[player->inventory->slots[player->inventory->index_x][player->inventory->index_y]]);	
		DrawPlayer(player, camera->x, camera->y);
		
		glEnd2D();
		
		glFlush(0);
}

void RenderMenu() {
	iprintf("\x1b[1;1HTerraria DS");
	iprintf("\x1b[2;1HPress Start to Create a New World");
	iprintf("\x1b[3;1HPress Select to Load a World");

	glBegin2D();
	glEnd2D();
	glFlush(0);
}

void RenderError(char* test) {
	iprintf("\x1b[1;1HERROR");
	iprintf("\x1b[2;1HTest= %s", test);
	glBegin2D();
	glEnd2D();
	glFlush(0);
}

int main( int argc, char *argv[] )
{

	DSInitialSetup();

	int game_state = 0;
	int prev_game_state = 0;
	int change_value_game_state = 0;

	// calculate the amount of 
	// memory uploaded to VRAM in KB
	//int TextureSize = tilesBitmapLen +
	//				  cursorBitmapLen+
	//				  playerBitmapLen;

	char string_file[7] = "test-1";

	if (fatInitDefault()) {
		strcpy(string_file, "workin");
	} else {
		strcpy(string_file, "notwor");
	}

	int key;		// for key input
	int prevKeys;

	// Intialize Entities
	Camera *camera = malloc(sizeof(Camera));
	Map *map = malloc(sizeof(Map));
	Player *player = malloc(sizeof(Player));
	CursorPointer *cursor_pointer =  malloc(sizeof(CursorPointer));
	
	scanKeys();
	prevKeys = keysHeld();
	key = prevKeys;

	while( 1 )
	{

		// Update Inputs
		scanKeys();
		key = keysHeld();

		switch (game_state)
		{
		case 0:
			if (key & KEY_START) {
				change_value_game_state = 1;
				//writeToFile();
			}
			if (key & KEY_SELECT) {

			}
			RenderError(string_file); 
		break;

		case 1:
			// Game Logic
			//RenderMenu();
			if (prev_game_state != game_state) {
				InitGameWorld(player, camera, map, cursor_pointer);
			}
			if ((key & KEY_START) && !(prevKeys & KEY_START) && (prev_game_state == game_state)) {
				//loadFile(string_file);
			}
			CursorLogic(cursor_pointer, key, prevKeys);
			MapInteraction(cursor_pointer->x, cursor_pointer->y, map->blocks_array, player->inventory->slots[player->inventory->index_x][player->inventory->index_y], key);
			PlayerLogic(player, map->blocks_array, key, prevKeys);
			CameraUpdate(camera, player->x, player->y, map->width, map->height);
			RenderCoreGameplay(player,camera,map,cursor_pointer,string_file);
		break;

		default:
			RenderError(string_file);
		break;
		
		}
		// Render Logic
		
		swiWaitForVBlank();
		if ((key&KEY_START) && (key&KEY_SELECT)) break;	
	
		//Get The Previous Input
		prevKeys = key;
		prev_game_state = game_state;
		game_state = change_value_game_state;
	}

	return 0;
	
}