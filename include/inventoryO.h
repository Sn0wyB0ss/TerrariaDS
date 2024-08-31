#ifndef INVENTORYO__H
#define INVENTORYO__H

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "global.h"

typedef struct s_Inventory {
	unsigned short slots[INVETORY_WIDTH][INVETORY_HEIGHT];
	int index_x;
	int index_y;
} Inventory;

void InitInventory(Inventory* inventory);
void ShiftActiveSlotLeft(Inventory* inventory);
void ShiftActiveSlotRight(Inventory* inventory);
void ShiftActiveSlotUp(Inventory* inventory);
void ShiftActiveSlotDown(Inventory* inventory);
void SetItem(Inventory* inventory, unsigned short value);
unsigned short GetItem(Inventory* inventory);
#endif