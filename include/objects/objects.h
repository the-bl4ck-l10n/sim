#ifndef OBJECTS_H
#define OBJECTS_H

#include "../world/world.h"

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

Objects objects_init(Map* map);
void objects_add(Objects* objects, Object object);
void objects_remove(Objects* objects, int id);
void objects_deinit(Objects* objects);

#endif
