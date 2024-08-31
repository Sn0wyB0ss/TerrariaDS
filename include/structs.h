#ifndef STRUCTS__H
#define STRUCTS__H


#include <nds.h>
#include <stdio.h>
#include <gl2d.h>


typedef struct s_Inventory {
	unsigned short slots[INVETORY_WIDTH][INVETORY_HEIGHT];
	int index_x;
	int index_y;
} Inventory;


typedef struct s_Map
{
    unsigned short blocks_array[MAP_WIDTH][MAP_HEIGHT];

	int width;			// dimensions of the map
	int height;
	
	glImage tiles_images[(256/16) * (256/16)];
	int texture_id;
} Map;


#endif