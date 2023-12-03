#include "../../include/interface/interface.h"
#include <curses.h>

Input get_input() {
    int k = getch();
    switch (k) {
        case 'w':
            return Up;
        case 'a':
            return Left;
        case 's':
            return Down;
        case 'd':
            return Right;
        case 27:
            return Back;
        // FIXME: Backspace key doesn't work
        case KEY_BACKSPACE:
            return Back;
        case ' ':
            return Space;
        default:
            return ParseError;
    }
}
