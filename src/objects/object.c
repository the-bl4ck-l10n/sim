#include "../../include/objects/objects.h"

Object object_create(int row, int col, int id, ObjectKind kind) {
    Object o;
    o.row = row;
    o.col = col;
    o.id = id;
    o.kind = kind;
    return o;
}
