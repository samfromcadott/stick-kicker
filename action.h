#ifndef ACTION_H
#define ACTION_H

typedef struct {
	int time; // Total number of frames
	int impact; // Frame when impact occurs
	int damage;
	int *frames[128];

} Action;

#endif
