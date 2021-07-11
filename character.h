#ifndef CHARACTER_H
#define CHARACTER_H

#include "action.h"

#define ACTION_COUNT 9
#define ATTACK_RANGE 32
#define MOVE_SPEED 1
#define JUMP_SPEED 3

enum action_state {
	ACTION_NONE,
	ACTION_PUNCH_HIGH,
	ACTION_PUNCH_MID,
	ACTION_PUNCH_LOW,
	ACTION_KICK_HIGH,
	ACTION_KICK_MID,
	ACTION_KICK_LOW,
	ACTION_JUMP_LEFT,
	ACTION_JUMP_RIGHT
	// ACTION_BLOCK_HIGH,
	// ACTION_BLOCK_MID,
	// ACTION_BLOCK_LOW
};

typedef struct {
	int health;
	int x;
	int y;

	enum action_state action;
	int action_timer;
	int current_frame;
	Action *action_list[ACTION_COUNT];

	int *sprite;

} Character;

void start_action(Character *character, int action);
void play_animation(Character *character);
Action* current_action(Character *character);
void try_attack(Character *character, Character *target);
// int is_blocking(Character *character, Character *attacker);
int choose_ai_attack(Character *character);

#endif
