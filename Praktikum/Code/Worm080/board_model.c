// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// The board model

#include <curses.h>
#include "worm.h"
#include "board_model.h"
#include "messages.h" // to use showDialog()
#include <stdlib.h>
// *************************************************
// Placing and removing items from the game board
// Check boundaries of game board
// *************************************************

// Place an item onto the curses display.
void placeItem(struct board* aboard, int y, int x, enum BoardCodes board_code, chtype symbol, enum ColorPairs color_pair) {

    //  Store item on the display (symbol code)
    move(y, x);                         // Move cursor to (y,x)
    attron(COLOR_PAIR(color_pair));     // Start writing in selected color
    addch(symbol);                      // Store symbol on the virtual display
    attroff(COLOR_PAIR(color_pair));    // Stop writing in selected color
    aboard->cells[y][x] = board_code;   // Im Array cells abspeichern, dass an Position(y,x) board_code liegt
}

// Getters

// Get the last usable row on the display
int getLastRowOnBoard(struct board* aboard) {
    return aboard->last_row;
}

// Get the last usable column on the display
int getLastColOnBoard(struct board* aboard) {
    return aboard->last_col; 
}

// Get Number of Food Items
int getNumberOfFoodItems(struct board* aboard){
  return aboard->food_items;
}

//Get Codes for the Content at struct position
enum BoardCodes getContentAt(struct board* aboard, struct pos position){
  return aboard->cells[position.y][position.x];
}

// Setters

void setNumberOfFoodItems(struct board* aboard, int n){
  aboard->food_items = n;
}

void decrementNumberOfFoodItems(struct board* aboard){
  aboard->food_items = aboard->food_items -1;
}

// Initializer

// Board
enum ResCodes initializeBoard(struct board* aboard) {
int y;
// Maximal index of a row, reserve space for message area
aboard->last_row = LINES - ROWS_RESERVED - 1;
// Maximal index of a column
aboard->last_col = COLS - 1;
// Check dimensions of the board
if ( aboard->last_col < MIN_NUMBER_OF_COLS - 1 ||
aboard->last_row < MIN_NUMBER_OF_ROWS - 1) {
char buf[100];
sprintf(buf,"Das Fenster ist zu klein: wir brauchen %dx%d",
MIN_NUMBER_OF_COLS , MIN_NUMBER_OF_ROWS + ROWS_RESERVED );
showDialog(buf,"Bitte eine Taste druecken");
return RES_FAILED;
}
// Allocate memory for 2-dimensional array of cells
// Alloc array of rows
aboard->cells = malloc(sizeof(enum BoardCodes*)*ROWS_RESERVED);   // Hier Speicher allozieren
if (aboard->cells == NULL) {
showDialog("Abbruch: Zu wenig Speicher","Bitte eine Taste druecken");
exit(RES_FAILED); // No memory -> direct exit
}
for (y = 0; y < ROWS_RESERVED ; y++) {
// Allocate array of columns for each y (Row)
aboard->cells[y] = malloc(sizeof(enum BoardCodes)*COLS); // Hier Speicher allozieren
if (aboard->cells[y] == NULL) {
 showDialog("Abbruch: Zu wenig Speicher","Bitte eine Taste druecken");
exit(RES_FAILED); // No memory -> direct exit

}
}
return RES_OK;
}
// Level

enum ResCodes initializeLevel(struct board* aboard) {
  int y;
  int x;
  //Fill board and screen buffer with empty cells
  for (y=0; y <= aboard->last_row; y++){
    for (x=0; x <= aboard->last_col; x++){
      placeItem(aboard, y, x, BC_FREE_CELL, SYMBOL_FREE_CELL, COLP_FREE_CELL);
    }
  }
  // Seperate the Message area onscreen (Use of placeItem() not allowed (outside board)
  y = aboard->last_row +1;
  for(x=0; x <= aboard->last_col; x++){
    move(y,x);
    attron(COLOR_PAIR(COLP_BARRIER));
    addch(SYMBOL_BARRIER);
    attroff(COLOR_PAIR(COLP_BARRIER));
  }
  // Line at the rightmost colum of board
  for(y=0; y <= aboard->last_row; y++){
    placeItem(aboard, y, aboard->last_col, BC_BARRIER, SYMBOL_BARRIER, COLP_BARRIER);
  }
  // Barriers
  x = (aboard->last_col) / 3 - 2;
  for(y=3; y < 13; y++){
    placeItem(aboard, y, x, BC_BARRIER, SYMBOL_BARRIER, COLP_BARRIER);
  }
  x = (aboard->last_col) *2 /3 ;
  for(y= 8; y < 18; y++){
    placeItem(aboard, y, x, BC_BARRIER, SYMBOL_BARRIER, COLP_BARRIER);
  }
  // Food
  placeItem(aboard, 3, 3,  BC_FOOD_1, SYMBOL_FOOD_1, COLP_FOOD_1);
  placeItem(aboard, 23, 11,  BC_FOOD_1, SYMBOL_FOOD_1, COLP_FOOD_1);
  placeItem(aboard, 4, 10, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, 10, 3, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, 7, 9, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, 5, aboard->last_col-4, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, 6, 6, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, 5, 7, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, 9, 4, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, 8, 1, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  


  // Initialize number of Food Items
  aboard->food_items = 10;
  return RES_OK;
}

















