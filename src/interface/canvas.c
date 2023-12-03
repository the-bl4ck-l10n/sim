#include "../../include/interface/interface.h"

Canvas canvas_init(WINDOW* main_window) {
    int max_y;
    int max_x;
    getmaxyx(main_window, max_y, max_x);

    Canvas c;

    c.main_window = main_window;

    c.height = max_y;
    c.width = max_x;

    c.map_pos_row = 0;
    c.map_pos_col = 0;

    c.map_offset_rows = 0;
    c.map_offset_cols = 0;

    c.map_height = max_y;
    c.map_width = max_x;

    return c;
}

void canvas_update(Canvas* canvas) {
    int max_y;
    int max_x;
    getmaxyx(canvas->main_window, max_y, max_x);
    
    canvas->height = max_y;
    canvas->width = max_x;

    canvas->map_height = max_y;
    canvas->map_width = max_x;
}

void canvas_draw(Canvas* canvas, Tile map[MAP_ROWS][MAP_COLS], Objects* objects) {
    clear();
    canvas_draw_map(canvas, map);
    canvas_draw_objects(canvas, objects);
    refresh();
}

void canvas_draw_map(Canvas* canvas, Tile map[MAP_ROWS][MAP_COLS]) {
    int start_pos_row = canvas->map_pos_row;
    int start_pos_col = canvas->map_pos_col;

    int height = canvas->map_height;
    int width = canvas->map_width;

    int offset_rows = canvas->map_offset_rows;
    int offset_cols = canvas->map_offset_cols;

    for (int i = start_pos_row; i < height; i++) {
        for (int j = start_pos_col; j < width; j++) {
            move(i, j);
            switch (map[i + offset_rows][j + offset_cols].kind) {
                case Water:
                    printw("~");
                    break;
                case Grass:
                    printw("\"");
                    break;
                default:
                    printw("?");
                    break;
            }
        }
    }
}

void canvas_draw_objects(Canvas* canvas, Objects* objects) {
    if (objects->len == 0) return;

    int start_pos_row = canvas->map_pos_row;
    int start_pos_col = canvas->map_pos_col;

    int height = canvas->map_height;
    int width = canvas->map_width;

    int offset_rows = canvas->map_offset_rows;
    int offset_cols = canvas->map_offset_cols;

    for (int i = 0; i < objects->len; i++) {
        int obj_row = objects->objects[i].row;
        int obj_col = objects->objects[i].col;

        int obj_display_row = start_pos_row + (obj_row < offset_rows ? obj_row : obj_row - offset_rows);
        int obj_display_col = start_pos_col + (obj_col < offset_cols ? obj_col : obj_col - offset_cols);

        if (obj_display_row < height && obj_display_col < width) {
            move(obj_display_row, obj_display_col);
            switch (objects->objects[i].kind) {
                case Tree:
                    printw("^");
                    break;
                default:
                    printw("?");
                    break;
            }
        }
    }
}
