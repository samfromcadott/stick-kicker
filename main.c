#include <string.h>
#include <stdlib.h>
#include "gba.h"
#include "character.h"
#include "action.h"
#include "character_data.h"

#include "sprites/player_stand.h"
#include "sprites/player_punch_high.h"
#include "sprites/player_punch_mid.h"
#include "sprites/player_punch_low.h"
#include "sprites/player_kick_high.h"
#include "sprites/player_kick_mid.h"
#include "sprites/player_kick_low.h"
#include "sprites/player_block_high.h"
#include "sprites/player_block_mid.h"
#include "sprites/player_block_low.h"

#include "sprites/enemy_stand.h"
#include "sprites/enemy_punch_high.h"
#include "sprites/enemy_punch_mid.h"
#include "sprites/enemy_punch_low.h"
#include "sprites/enemy_kick_high.h"
#include "sprites/enemy_kick_mid.h"
#include "sprites/enemy_kick_low.h"
#include "sprites/enemy_block_high.h"
#include "sprites/enemy_block_mid.h"
#include "sprites/enemy_block_low.h"

int main() {
	SetMode(MODE_0 | OBJ_ENABLE | OBJ_MAP_1D);
	OAMEntry player_entry = {0|0x50|COLOR_256, SIZE_64|0x0F, PRIORITY(2)|PALETTE(0), 0};
	OAMEntry enemy_entry = {0|0x50|COLOR_256, SIZE_64|0x0F, PRIORITY(2)|PALETTE(0)|(256), 0};


	memcpy(OBJ_PaletteMem, enemy_standPal, enemy_standPalLen);

	int next_action = 30; // Time until the AI preforms its next move

	Character player = {
		100, // Health
		60, // x
		80, // y
		ACTION_NONE,
		0, // Action timer
		0, // Current frame
		{
			(Action*)&player_stand,
			(Action*)&player_punch_high,
			(Action*)&player_punch_mid,
			(Action*)&player_punch_low,
			(Action*)&player_kick_high,
			(Action*)&player_kick_mid,
			(Action*)&player_kick_low,
			(Action*)&enemy_stand,
			(Action*)&enemy_stand
			// (Action*)&player_block_high,
			// (Action*)&player_block_mid,
			// (Action*)&player_block_low
		},
		(int*)player_standTiles, // Sprite
	};

	Character enemy = {
		100, // Health
		150, // x
		80, // y
		ACTION_NONE,
		0, // Action timer
		0,  // Current frame
		{
			(Action*)&enemy_stand,
			(Action*)&enemy_punch_high,
			(Action*)&enemy_punch_mid,
			(Action*)&enemy_punch_low,
			(Action*)&enemy_kick_high,
			(Action*)&enemy_kick_mid,
			(Action*)&enemy_kick_low,
			(Action*)&enemy_stand,
			(Action*)&enemy_stand
			// (Action*)&enemy_block_high,
			// (Action*)&enemy_block_mid,
			// (Action*)&enemy_block_low
		},
		(int*)enemy_standTiles, // Sprite
	};

	while (1) {
		vsync();

		// Player update
		//================
		if (player.action_timer > 0)
			player.action_timer--;

		if (player.action_timer == 0 && player.action != ACTION_NONE)
			start_action(&player, ACTION_NONE);

		// Damage enemy
		try_attack(&player, &enemy);

		// Player input
		if (player.action == ACTION_NONE  && player.health > 0) {
			if ( !keyDown(KEY_LEFT) && !keyDown(KEY_RIGHT) ) {
				// Punching
				if ( keyDown(KEY_A) ) {
					if ( keyDown(KEY_UP) )
						start_action(&player, ACTION_PUNCH_HIGH);
					else if ( keyDown(KEY_DOWN) )
						start_action(&player, ACTION_PUNCH_LOW);
					else
						start_action(&player, ACTION_PUNCH_MID);

				}

				// Kicking
				if ( keyDown(KEY_B) ) {
					if ( keyDown(KEY_UP) )
						start_action(&player, ACTION_KICK_HIGH);
					else if ( keyDown(KEY_DOWN) )
						start_action(&player, ACTION_KICK_LOW);
					else
						start_action(&player, ACTION_KICK_MID);

				}

				// Blocking
				// if ( keyDown(KEY_L) || keyDown(KEY_R) ) {
				// 	if ( keyDown(KEY_UP) )
				// 		start_action(&player, ACTION_BLOCK_HIGH);
				// 	else if ( keyDown(KEY_DOWN) )
				// 		start_action(&player, ACTION_BLOCK_LOW);
				// 	else
				// 		start_action(&player, ACTION_BLOCK_MID);
				//
				// }

			}

			// Movement
			if ( keyDown(KEY_LEFT) && player.x > 32)
				player.x-=MOVE_SPEED;
			if ( keyDown(KEY_RIGHT) && player.x < enemy.x )
				player.x+=MOVE_SPEED;

		}

		play_animation(&player);

		// Enemy update
		//================
		if (enemy.action_timer > 0)
			enemy.action_timer--;

		if (next_action > 0)
			next_action--;

		if (enemy.action_timer == 0 && enemy.action != ACTION_NONE) {
			next_action = 30; // Reset the timer
			enemy.action = ACTION_NONE;
			start_action(&enemy, ACTION_NONE);

		}

		// Damage player
		try_attack(&enemy, &player);

		// Choose action
		if (enemy.action == ACTION_NONE && enemy.health > 0) {
			int dist = abs(enemy.x - player.x);

			// Move toward player
			if (dist > ATTACK_RANGE) {
				enemy.x-=MOVE_SPEED;
			}

			// Attack
			if (next_action == 0 && dist <= ATTACK_RANGE) {
				int choice = choose_ai_attack(&enemy);
				start_action(&enemy, choice);
			}

		}

		play_animation(&enemy);

		// Graphics update
		//=================

		// Drawing player sprite
		memcpy(&TILE_MEM_OBJ[0], player.sprite, player_standTilesLen);
		player_entry.attribute1 = (player_entry.attribute1&(~0xFF))|player.x-32;
		memcpy(&OAM_Mem[0], &player_entry, sizeof(OAMEntry));

		// Drawing enemy sprite
		memcpy(&TILE_MEM_OBJ[player_standTilesLen], enemy.sprite, enemy_standTilesLen);
		enemy_entry.attribute1 = (enemy_entry.attribute1&(~0xFF))|enemy.x-32;
		memcpy(&OAM_Mem[1], &enemy_entry, sizeof(OAMEntry));

	}

	return 0;

}
