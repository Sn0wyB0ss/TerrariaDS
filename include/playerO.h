#ifndef PLAYERO__H
#define PLAYERO__H

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "global.h"
#include "inventoryO.h"

// GRIT auto-genrated arrays of images
#include "player.h"


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

	Inventory *inventory;

} Player;

enum PlayerState { P_IDLE, P_ATTACK, P_INVENTORY};
enum PlayerAnimationState {P_ANIM_IDLE, P_ANIM_ATTACK};

void InitializePlayer(Player* player);
void PlayerLogic(Player* player, unsigned short map[MAP_WIDTH][MAP_HEIGHT] , int key, int prev_key);
void DetectHorizontalCollision(unsigned short blocks_array[MAP_WIDTH][MAP_HEIGHT] , Player* p, int x, int y);
void DetectVerticalCollision(unsigned short blocks_array[MAP_WIDTH][MAP_HEIGHT] , Player* p, int x, int y);
void DetectPlayerCollision(unsigned short map[MAP_WIDTH][MAP_HEIGHT] , Player* p);
void DrawPlayer(Player* player, int camera_x, int camera_y);
#endif