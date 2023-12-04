#include <stdlib.h>

#include "../../include/world/world.h"

Map map_init(int rows, int cols) {
    Map map;

    map.rows = rows;
    map.cols = cols;

    map.tiles = (Tile**)malloc(sizeof (Tile*) * rows);

    for (int i = 0; i < rows; i++) {
        Tile* column = (Tile*)malloc(sizeof (Tile) * cols);
        map.tiles[i] = column;
    }

    return map;
}

void map_deinit(Map* map) {
    for (int i = 0; i < map->rows; i++) {
        free(map->tiles[i]);
    }
    free(map->tiles);
}

void map_create(Map* map) {
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (
                    (i >= 0 && i < WATER_PADDING) ||
                    (i >= map->rows - WATER_PADDING && i < map->rows) ||
                    (j >= 0 && j < WATER_PADDING) ||
                    (j >= map->cols - WATER_PADDING && j < map->cols)
                    
               ) {
               map->tiles[i][j] = tile_create(Water);
            } else {
                map->tiles[i][j] = tile_create(Grass);
            }
        }
    }
}
