#include "../../include/world/tile.h"

Tile tile_create(TileKind kind) {
    Tile tile;
    tile.kind = kind;

    return tile;
}
