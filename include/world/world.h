#ifndef WORLD_H
#define WORLD_H

#include "../settings.h"
#include "./tile.h"

typedef struct{
    Tile** tiles;
    int rows;
    int cols;
}Map;

Map map_init(int rows, int cols);
void map_deinit(Map* map);
void map_create(Map* map);

#endif
