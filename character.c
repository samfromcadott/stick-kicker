#include "character.h"
#include <stdlib.h>

void start_action(Character *character, int action) {
	character->action = action;
	character->action_timer = character->action_list[action]->time;

}

void play_animation(Character *character) {
	Action *action = current_action(character);
	character->current_frame = (character->current_frame + 1) % action->time;
	character->sprite = action->frames[character->current_frame/5]; // Limit to 12 FPS

	if (character->action == ACTION_JUMP_LEFT)
		character->x-=JUMP_SPEED;
	else if (character->action == ACTION_JUMP_RIGHT)
		character->x+=JUMP_SPEED;

}

Action* current_action(Character *character) {
	return character->action_list[character->action];

}

void try_attack(Character *character, Character *target) {
	if (abs(character->x - target->x) <= ATTACK_RANGE && character->current_frame == current_action(character)->impact) {
		target->health -= current_action(character)->damage;
	}
}

// int is_blocking(Character *character, Character *attacker) {
// 	if (character->current_frame >= current_action(character)->impact && attacker->current_frame < current_action(attacker)->impact) {
// 		if ( character->action == ACTION_BLOCK_MID && (attacker->action == ACTION_PUNCH_MID || attacker->action == ACTION_KICK_MID) )
// 			return 1;
// 	}
//
// 	return 0;
//
// }

int choose_ai_attack(Character *character) {
	int choices[] = {1, 1, 1, 10, 1, 1};
	int sum = 0;
	for(int i=0; i<6; i++) {
		sum += choices[i];
	}
	int r = rand() % 6;
	for(int i=0; i<6; i++) {
		if(r < choices[i])
			return i+1;
		r -= choices[i];
	}
}
