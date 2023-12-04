#include "../include/settings.h"
#include "../include/world/world.h"
#include "../include/objects/objects.h"
#include "../include/interface/interface.h"

int main(void) {
    Map map = map_init(MAP_ROWS, MAP_COLS);
    map_create(&map);

    Objects objects = objects_init(&map);

    // TODO: generate a more intricate world

    // TODO: implement entities

    // TODO: implement structures

    // TODO: implement colors
    // TODO: implement message feed
    WINDOW* w = interface_init();
    Canvas canvas = canvas_init(w);

    int sim_steps = 1;

    bool running = true;

    while (running) {
        canvas_update(&canvas);
        // TODO: draw ui (message feed, tooltip bar, sidebar)
        canvas_draw(&canvas, &map, &objects);

        // TODO: implement state logic (global variables? enum?)

        Input input = get_input();
        switch (input) {
            case Up:
                if (canvas.map_offset_rows > 0) {
                    canvas.map_offset_rows -= 1;
                }
                break;
            case Left:
                if (canvas.map_offset_cols > 0) {
                    canvas.map_offset_cols -= 1;
                }
                break;
            case Down:
                if (canvas.map_offset_rows + canvas.map_height < MAP_ROWS) {
                    canvas.map_offset_rows += 1;
                }
                break;
            case Right:
                if (canvas.map_offset_cols + canvas.map_width < MAP_COLS) {
                    canvas.map_offset_cols += 1;
                }
                break;
            case Space:
                // TODO: next sim step(s)
                break;
            case Back:
                running = false;
                break;
            case ParseError:
                break;
        }
    }

    interface_deinit();
    map_deinit(&map);
    objects_deinit(&objects);
    return 0;
}
