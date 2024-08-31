#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

#include "inventoryO.h"

void InitInventory(Inventory* inventory) {

    int x;
    int y;

    for (y = 0; y <= INVETORY_HEIGHT; y++)
	{
		for (x = 0; x <= INVETORY_WIDTH; x++) 
		{
            inventory->slots[x][y] = x+1;
        }
    }
    inventory->index_x = 0;
    inventory->index_y = 0;
}

void ShiftActiveSlotLeft(Inventory* inventory) {
    if ((inventory->index_x - 1) < 0) {
        return;
    }
    inventory->index_x--;
}

void ShiftActiveSlotRight(Inventory* inventory){
    if ((inventory->index_x + 1) > 6) {
        inventory->index_x = 0;
        return;
    }
    inventory->index_x++;
}

void ShiftActiveSlotUp(Inventory* inventory) {
    if ((inventory->index_y - 1) < 0) {
        return;
    }
    inventory->index_y--;
}

void ShiftActiveSlotDown(Inventory* inventory){
    if ((inventory->index_y + 1) >= INVETORY_HEIGHT) {
        return;
    }
    inventory->index_y++;
}

void SetItem(Inventory* inventory, unsigned short value) {
    inventory->slots[inventory->index_x][inventory->index_y] = value;
}

unsigned short GetItem(Inventory* inventory) {
    return inventory->slots[inventory->index_x][inventory->index_y];
}