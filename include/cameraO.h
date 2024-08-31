#ifndef CAMERAO__H
#define CAMERAO__H

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "global.h"

typedef struct s_Camera 
{
	int x;
	int y;
	int tile_x;
	int tile_y;
	int pixel_x;
	int pixel_y;
} Camera;

void CameraUpdate(Camera* camera, int p_x, int p_y, int map_width, int map_height);
#endif
