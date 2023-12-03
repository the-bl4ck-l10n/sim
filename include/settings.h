#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdbool.h>

// Map
// FIXME: MAP_ROWS, MAP_COLS cannot be smaller than the terminal size
#define MAP_ROWS 40 // the map's height
#define MAP_COLS 150 // the map's width
#define WATER_PADDING (((MAP_ROWS + MAP_COLS) / 2) / 20) // how much water is around the central landmass

// Objects
#define OBJ_INITIAL_CAP 10 // how much memory is initially allocated
#define OBJ_REALLOC_RATE 5 // how much memory is reallocated when growing
#define OBJ_REALLOC_THRESHOLD (OBJ_REALLOC_RATE * 2) // how much difference there has to be between the length and capacity until memory is freed
// spawn rates in %
#define SPAWN_RATE_TREE 10

#endif
