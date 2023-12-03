#ifndef OBJECTS_H
#define OBJECTS_H

#include "../settings.h"
#include "../world/tile.h"

typedef enum{
    Tree,
}ObjectKind;


typedef struct{
    int row;
    int col;

    int id;
    ObjectKind kind;
}Object;

Object object_create(int row, int col, int id, ObjectKind kind);


typedef struct{
    Object* objects;
    int len;
    int cap;

    int highest_id;
}Objects;

Objects objects_init(Tile map[MAP_ROWS][MAP_COLS]);
void objects_add(Objects* objects, Object object);
void objects_remove(Objects* objects, int id);
void objects_deinit(Objects* objects);

#endif
