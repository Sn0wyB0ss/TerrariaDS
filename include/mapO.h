#ifndef MAPO__H
#define MAPO__H

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "structs.h"

// GRIT auto-genrated arrays of images
#include "tiles.h"

Map* InitMap();
void DrawMap(Map* map, Camera* camera);
#endif