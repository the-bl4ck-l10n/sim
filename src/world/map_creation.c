#include "../../include/world/world.h"

void map_create(Tile map[MAP_ROWS][MAP_COLS]) {
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (
                    (i >= 0 && i < WATER_PADDING) ||
                    (i >= MAP_ROWS - WATER_PADDING && i < MAP_ROWS) ||
                    (j >= 0 && j < WATER_PADDING) ||
                    (j >= MAP_COLS - WATER_PADDING && j < MAP_COLS)
                ) {
                map[i][j] = tile_create(Water);
            } else {
                map[i][j] = tile_create(Grass);
            }
        }
    }
}
