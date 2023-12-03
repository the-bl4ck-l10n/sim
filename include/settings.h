#ifndef SETTINGS_H
#define SETTINGS_H

// Map
#define MAP_ROWS 20 
#define MAP_COLS 60
#define WATER_PADDING (((MAP_ROWS + MAP_COLS) / 2) / 10)

// Objects
#define OBJ_INITIAL_CAP 10 // how much memory is initially allocated
#define OBJ_REALLOC_RATE 5 // how much memory is reallocated when growing
#define OBJ_REALLOC_THRESHOLD (OBJ_REALLOC_RATE * 2) // how much difference there has to be between the length and capacity until memory is freed

#endif
