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

// Player actions

const Action player_stand = {
	1,
	0,
	0,
	{(int*)player_standTiles}
};

const Action player_punch_high = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)player_punch_highTiles,
		(int*)player_punch_highTiles,
		(int*)player_punch_highTiles,
		(int*)player_punch_highTiles,
		(int*)player_punch_highTiles,
		(int*)player_punch_highTiles
	}
};

const Action player_punch_mid = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)player_punch_midTiles,
		(int*)player_punch_midTiles,
		(int*)player_punch_midTiles,
		(int*)player_punch_midTiles,
		(int*)player_punch_midTiles,
		(int*)player_punch_midTiles
	}
};

const Action player_punch_low = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)player_punch_lowTiles,
		(int*)player_punch_lowTiles,
		(int*)player_punch_lowTiles,
		(int*)player_punch_lowTiles,
		(int*)player_punch_lowTiles,
		(int*)player_punch_lowTiles
	}
};

const Action player_kick_high = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)player_kick_highTiles,
		(int*)player_kick_highTiles,
		(int*)player_kick_highTiles,
		(int*)player_kick_highTiles,
		(int*)player_kick_highTiles,
		(int*)player_kick_highTiles
	}
};

const Action player_kick_mid = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)player_kick_midTiles,
		(int*)player_kick_midTiles,
		(int*)player_kick_midTiles,
		(int*)player_kick_midTiles,
		(int*)player_kick_midTiles,
		(int*)player_kick_midTiles
	}
};

const Action player_kick_low = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)player_kick_lowTiles,
		(int*)player_kick_lowTiles,
		(int*)player_kick_lowTiles,
		(int*)player_kick_lowTiles,
		(int*)player_kick_lowTiles,
		(int*)player_kick_lowTiles
	}
};

const Action player_block_high = {
	10, // Time
	2, // Impact
	0, // Damage
	{
		(int*)player_block_highTiles,
		(int*)player_block_highTiles,
		(int*)player_block_highTiles,
		(int*)player_block_highTiles,
		(int*)player_block_highTiles,
		(int*)player_block_highTiles
	}
};

const Action player_block_mid = {
	10, // Time
	2, // Impact
	0, // Damage
	{
		(int*)player_block_midTiles,
		(int*)player_block_midTiles,
		(int*)player_block_midTiles,
		(int*)player_block_midTiles,
		(int*)player_block_midTiles,
		(int*)player_block_midTiles
	}
};

const Action player_block_low = {
	10, // Time
	2, // Impact
	0, // Damage
	{
		(int*)player_block_lowTiles,
		(int*)player_block_lowTiles,
		(int*)player_block_lowTiles,
		(int*)player_block_lowTiles,
		(int*)player_block_lowTiles,
		(int*)player_block_lowTiles
	}
};


// Enemy actions

const Action enemy_stand = {
	1,
	0,
	0,
	{(int*)enemy_standTiles}
};

const Action enemy_punch_high = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)enemy_punch_highTiles,
		(int*)enemy_punch_highTiles,
		(int*)enemy_punch_highTiles,
		(int*)enemy_punch_highTiles,
		(int*)enemy_punch_highTiles,
		(int*)enemy_punch_highTiles
	}
};

const Action enemy_punch_mid = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)enemy_punch_midTiles,
		(int*)enemy_punch_midTiles,
		(int*)enemy_punch_midTiles,
		(int*)enemy_punch_midTiles,
		(int*)enemy_punch_midTiles,
		(int*)enemy_punch_midTiles
	}
};

const Action enemy_punch_low = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)enemy_punch_lowTiles,
		(int*)enemy_punch_lowTiles,
		(int*)enemy_punch_lowTiles,
		(int*)enemy_punch_lowTiles,
		(int*)enemy_punch_lowTiles,
		(int*)enemy_punch_lowTiles
	}
};

const Action enemy_kick_high = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)enemy_kick_highTiles,
		(int*)enemy_kick_highTiles,
		(int*)enemy_kick_highTiles,
		(int*)enemy_kick_highTiles,
		(int*)enemy_kick_highTiles,
		(int*)enemy_kick_highTiles
	}
};

const Action enemy_kick_mid = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)enemy_kick_midTiles,
		(int*)enemy_kick_midTiles,
		(int*)enemy_kick_midTiles,
		(int*)enemy_kick_midTiles,
		(int*)enemy_kick_midTiles,
		(int*)enemy_kick_midTiles
	}
};

const Action enemy_kick_low = {
	30, // Time
	15, // Impact
	10, // Damage
	{
		(int*)enemy_kick_lowTiles,
		(int*)enemy_kick_lowTiles,
		(int*)enemy_kick_lowTiles,
		(int*)enemy_kick_lowTiles,
		(int*)enemy_kick_lowTiles,
		(int*)enemy_kick_lowTiles
	}
};

const Action enemy_block_high = {
	10, // Time
	2, // Impact
	0, // Damage
	{
		(int*)enemy_block_highTiles,
		(int*)enemy_block_highTiles,
		(int*)enemy_block_highTiles,
		(int*)enemy_block_highTiles,
		(int*)enemy_block_highTiles,
		(int*)enemy_block_highTiles
	}
};

const Action enemy_block_mid = {
	10, // Time
	2, // Impact
	0, // Damage
	{
		(int*)enemy_block_midTiles,
		(int*)enemy_block_midTiles,
		(int*)enemy_block_midTiles,
		(int*)enemy_block_midTiles,
		(int*)enemy_block_midTiles,
		(int*)enemy_block_midTiles
	}
};

const Action enemy_block_low = {
	10, // Time
	2, // Impact
	0, // Damage
	{
		(int*)enemy_block_lowTiles,
		(int*)enemy_block_lowTiles,
		(int*)enemy_block_lowTiles,
		(int*)enemy_block_lowTiles,
		(int*)enemy_block_lowTiles,
		(int*)enemy_block_lowTiles
	}
};
