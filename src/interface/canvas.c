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

    return c;
}

void canvas_update(Canvas* canvas) {
    int max_y;
    int max_x;
    getmaxyx(canvas->main_window, max_y, max_x);
    
    canvas->height = max_y;
    canvas->width = max_x;
}

void canvas_draw(Canvas* canvas, Tile map[MAP_ROWS][MAP_COLS], Objects* objects) {
    canvas_draw_map(canvas, map);
}

void canvas_draw_map(Canvas* canvas, Tile map[MAP_ROWS][MAP_COLS]) {
    for (int i = canvas->map_pos_row; i < canvas->height - 1 && i < MAP_ROWS - 1; i++) {
        for (int j = canvas->map_pos_col; j < canvas->width - 1 && j < MAP_COLS - 1; i++) {
            move(i - canvas->map_pos_row, j - canvas->map_pos_col);
            switch (map[i][j].kind) {
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
