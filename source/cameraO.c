#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "cameraO.h"

// Update's the camera's position relative to the player
void CameraUpdate(Camera* camera, Player* p, Map* map)
{

	// set constants for middle of screen

	const int SCREEN_MID_WIDTH = SCREEN_WIDTH / 2;
	const int SCREEN_MID_HEIGHT = SCREEN_HEIGHT / 2;
 
	// update the camera

	camera->x = p->x - SCREEN_MID_WIDTH;
	camera->y = p->y - SCREEN_MID_HEIGHT;
	
	// limit camera X values

	if ( camera->x < 0 ) camera->x = 0;

	if ( camera->x > ((map->width-2) * TILESIZE) - SCREEN_WIDTH )
	{
		camera->x = ((map->width-2) * TILESIZE) - SCREEN_WIDTH;
	}
	
	// limit camera Y values

	if ( camera->y < 0 ) camera->y = 0;

	if ( camera->y > ((map->height-2) * TILESIZE ) - SCREEN_HEIGHT )
	{
		camera->y = ((map->height-2) * TILESIZE ) - SCREEN_HEIGHT;
	}
	
	// calculate level starting tiles

	camera->tile_x = camera->x / TILESIZE; 
	camera->tile_y = camera->y / TILESIZE; 
	
	// calculate tile pixel offsets
	// Only works with power of 2 tilesize
	// use "%" for non-power of 2 sizes
	camera->pixel_x = camera->x & (TILESIZE - 1);
	camera->pixel_y = camera->y & (TILESIZE - 1);
	
}
