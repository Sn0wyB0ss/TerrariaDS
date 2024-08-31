#ifndef MAPO__H
#define MAPO__H

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "global.h"

// GRIT auto-genrated arrays of images
#include "tiles.h"

typedef struct s_Map
{
    unsigned short blocks_array[MAP_WIDTH][MAP_HEIGHT];

	int width;			// dimensions of the map
	int height;
	
	glImage tiles_images[(256/16) * (256/16)];
	int texture_id;
} Map;


void InitMap(Map* map);
void MapInteraction(int cursor_pointer_x, int cursor_pointer_y, unsigned short blocks_array[MAP_WIDTH][MAP_HEIGHT] , int selected_block, int key);
void DrawMap(Map* map, int camera_tile_x, int camera_tile_y, int camera_pixel_x, int camera_pixel_y);
#endif