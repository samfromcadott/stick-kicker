#ifndef GBA_REGS_H
#define GBA_REGS_H

#include "gba_types.h"
#include "gba_sprites.h"

#define OAM_Mem                ((OAMEntry*)0x7000000) // Sprites(128), coordinates, size..(total 1Kb)
#define OBJ_PaletteMem        ((u16*)0x5000200) // Sprite Palette(256/16 colors)
#define OAM_Data                 ((u16*)0x6010000) // Sprite data (bitmapped)

#define FrontBuffer     ((u16*)0x6000000) // Front Display Memory (the screen in mode 3-5)
#define BG_PaletteMem          ((u16*)0x5000000) // Background Palette(256/16 colors)
#define TILE_MEM_BG		((u16*)0x6000000)
#define TILE_MEM_OBJ	((u16*)0x6010000)

#define REG_DISPCNT         *(u16*)0x4000000 // Display control mode
#define REG_VCOUNT         *(volatile u16*)0x4000006  // Vertical control sync
#define vsync() while(REG_VCOUNT != 160);

#endif
