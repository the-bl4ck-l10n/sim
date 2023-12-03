#include "../../include/interface/interface.h"

WINDOW* interface_init() {
    WINDOW* w = initscr();
    noecho();
    curs_set(0);
    raw();

    clear();
    refresh();

    return w;
}

void interface_deinit() {
    endwin();
}
