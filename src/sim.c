#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../include/settings.h"
#include "../include/world/world.h"
#include "../include/objects/objects.h"
#include "../include/interface/interface.h"

int main(void) {
    Tile map[MAP_ROWS][MAP_COLS];
    map_create(map);

    Objects objects = objects_init(map);

    WINDOW* w = interface_init();
    Canvas canvas = canvas_init(w);

    bool running = true;

    while (running) {
        canvas_update(&canvas);
        canvas_draw(&canvas, map, &objects);

        char k = getch();
        if (k == 'q') {
            running = false;
        } else if (k == 'w') {
            if (canvas.map_pos_row > 0) {
                canvas.map_pos_row -= 1;
            }
        } else if (k == 'a') {
            if (canvas.map_pos_col > 0) {
                canvas.map_pos_col -= 1;
            }
        } else if (k == 's') {
            if (canvas.map_pos_row + canvas.height < MAP_ROWS) {
                canvas.map_pos_row += 1;
            }
        } else if (k == 'd') {
            if (canvas.map_pos_col + canvas.width < MAP_COLS) {
                canvas.map_pos_col += 1;
            }
        }
    }

    interface_deinit();
    objects_deinit(&objects);
    return 0;
}
