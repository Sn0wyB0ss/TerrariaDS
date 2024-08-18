#ifndef PLAYERO__H
#define PLAYERO__H

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "structs.h"

// GRIT auto-genrated arrays of images
#include "player.h"

enum PlayerState { P_IDLE, P_ATTACK, P_INVENTORY};
enum PlayerAnimationState {P_ANIM_IDLE, P_ANIM_ATTACK};

Player* InitializePlayer();
void PlayerLogic(Player* player, Map* map, int key);
void DetectHorizontalCollision(Map* map, Player* p, int x, int y);
void DetectVerticalCollision(Map* map, Player* p, int x, int y);
void DetectPlayerCollision(Map* map, Player* p);
void DrawPlayer(Player* player,Camera* camera);
#endif