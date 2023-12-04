#include "../../include/objects/objects.h"
#include <stdlib.h>
#include <time.h>

Objects objects_init(Map* map) {
    Objects objects;
    objects.objects = (Object*) malloc(sizeof (Object) * OBJ_INITIAL_CAP);
    objects.len = 0;
    objects.cap = OBJ_INITIAL_CAP;
    objects.highest_id = 0;

    srand(time(NULL));

    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (map->tiles[i][j].kind == Grass) {
                if ((rand() % 100 + 1) < SPAWN_RATE_TREE) {
                    Object o = object_create(i, j, objects.highest_id, Tree);
                    objects_add(&objects, o);
                }
            }
        }
    }

    return objects;
}

void objects_add(Objects* objects, Object object) {
    if (objects->len == objects->cap) {
        objects->objects = (Object*) realloc(objects->objects, sizeof (Object) * (objects->cap + OBJ_REALLOC_RATE));
        objects->cap += OBJ_REALLOC_RATE;
    }
    objects->objects[objects->len] = object;
    objects->len += 1;
    objects->highest_id += 1;
}

void objects_remove(Objects* objects, int id) {
    if (objects->len == 0) {
        return;
    } else if (objects->len == 1) {
        objects->len = 0;
        if (objects->cap != OBJ_INITIAL_CAP) {
            objects->objects = (Object*) realloc(objects->objects, sizeof (Object) * OBJ_INITIAL_CAP);
        }
    } else {
        for (int i = 0; i < objects->len; i++) {
            if (objects->objects[i].id == id) {
                for (int j = i; j < objects->len; j++) {
                    if (j != objects->len - 1) {
                        objects->objects[j] = objects->objects[j + 1];
                    }
                }
            }
        }
        objects->len -= 1;
        if (objects->cap > objects->len + OBJ_REALLOC_THRESHOLD) {
           objects->objects = (Object*) realloc(objects->objects, sizeof (Object) * (objects->len + OBJ_REALLOC_RATE));
           objects->cap = objects->len + OBJ_REALLOC_RATE;
        }
    }
}

void objects_deinit(Objects* objects) {
    free(objects->objects);
}
