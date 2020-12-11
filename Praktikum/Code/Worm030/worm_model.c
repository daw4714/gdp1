// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
#include <curses.h>
#include "worm.h"
#include "board_model.h"
#include "worm_model.h"

// The worm model


//********************************************************************************************
// Global variables
// ********************************************************************************************

// Data defining the worm
// They will become components of a structure, later
// Last usable index into the arrays
// theeorm_wormpos_y and theworm_wormpos_x
int theworm_maxindex;

//An index into the array for the worm's head position
//0 <= theworm_headindex <= theworm_maxindex
int theworm_headindex;
// Array of y positions for worm elements
int theworm_wormpos_y[WORM_LENGTH];
// Array of x positions for worm elements
int theworm_wormpos_x[WORM_LENGTH];
// The current heading of the worm
// These are offsets from the set {-1,0,+1}
int theworm_dx;
int theworm_dy;

enum ColorPairs theworm_wcolor;
// Functions concerning the management of the worm data
extern int initializeWorm(int len_max, int headpos_y, int headpos_x, enum WormHeading dir, enum ColorPairs color);//d
extern void showWorm();
extern void cleanWormTail();
extern void moveWorm(enum GameStates* agame_state);//d
extern bool isInUseByWorm(int new_headpos_y, int new_headpos_x);
extern void setWormHeading(enum WormHeading dir);

