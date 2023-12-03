#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>

#include "../include/settings.h"
#include "../include/world/world.h"
#include "../include/objects/objects.h"

int main(void) {
    Tile map[MAP_ROWS][MAP_COLS];
    map_create(map);

    Objects objects = objects_init(map);

    initscr();
    noecho();

    while (true) {
        clear();

        for (int i = 0; i < MAP_ROWS; i++) {
            for (int j = 0; j < MAP_COLS; j++) {
                move(i, j);
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

        refresh();

        char k = getch();
        if (k == 'q') {
            break;
        }
    }

    endwin();

    objects_deinit(&objects);
    return 0;
}
