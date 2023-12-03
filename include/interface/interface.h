#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdbool.h>
#include <ncurses.h>

#include "../settings.h"
#include "../world/world.h"
#include "../objects/objects.h"

typedef enum{
    Up,
    Left,
    Down,
    Right,
    Back,
    Space,
    ParseError,
}Input;

typedef enum{
    NewSim,
    ExitProgram,
}MainMenuExitCode;

typedef struct{
    WINDOW* main_window;

    int height;
    int width;

    int map_pos_row;
    int map_pos_col;
    int map_offset_rows;
    int map_offset_cols;
    int map_height;
    int map_width;
}Canvas;

WINDOW* interface_init();
void interface_deinit();

MainMenuExitCode main_menu();

Canvas canvas_init(WINDOW* main_window);
void canvas_update(Canvas* canvas);
void canvas_draw(Canvas* canvas, Tile map[MAP_ROWS][MAP_COLS], Objects* objects);
void canvas_draw_map(Canvas* canvas, Tile map[MAP_ROWS][MAP_COLS]);
void canvas_draw_objects(Canvas* canvas, Objects* objects);

Input get_input();

#endif
