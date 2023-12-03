#ifndef TILE_H
#define TILE_H

typedef enum{
    Empty,
    Water,
    Grass,
    Stone,
}TileKind;

typedef struct{
    TileKind kind; 
}Tile;


Tile tile_create(TileKind kind);

#endif
