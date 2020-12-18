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

// The board model
void placeItem(int y, int x, chtype symbol, enum ColorPairs color_pair){
  move(y,x);
  attron(COLOR_PAIR(color_pair));
  addch(SYMBOL_WORM_INNER_ELEMENT);
  attroff(COLOR_PAIR(color_pair));
}
//Getters
int getLastRow(){
  return LINES-1;}

  int getLastCol(){
    return COLS-1;
  }


