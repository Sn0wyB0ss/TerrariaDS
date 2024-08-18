#ifndef STRUCTS__H
#define STRUCTS__H

#define MAP_WIDTH 32
#define MAP_HEIGHT 18
#define TILESIZE 16

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

typedef struct s_Camera 
{
	int x;
	int y;
	int tile_x;
	int tile_y;
	int pixel_x;
	int pixel_y;
} Camera;


typedef struct s_Player
{

    // Basic Struct Variables

	int x;
	int y;
	int height;
	int width;

    // Physics Variables

	float gravity;
	int jump;
	float speed_x;
	float speed_y;
    float acceleration;
    float decceleration;
    float speed_cap_x;
    float speed_cap_y;
	bool on_floor;

	// Logic Variables

    int state;


    // Animation and Graphics Variables

    glImage textures[1];
	int texture_id;
    int animation_state;
    GL_FLIP_MODE hflip;
    int image_index;
	int is_walking;

} Player;


typedef struct s_Map
{
    unsigned short blocks_array[MAP_WIDTH][MAP_HEIGHT];

	int width;			// dimensions of the map
	int height;
	
	glImage tiles_images[(256/16) * (256/16)];
	int texture_id;
} Map;

typedef struct s_CursorPointer 
{
	int x;
	int y;

	glImage textures[1];
	int texture_id;
} CursorPointer;
#endif