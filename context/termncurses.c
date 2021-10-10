#include "termncurses.h"

#include <stdlib.h>
#include <ncurses.h>

#define self ((struct context_termncurses*)_self)

struct context_termncurses* context_termncurses_new(void) {
    struct context_termncurses* context = malloc(sizeof(struct context_termncurses));
    
    context->super.create        = &context_termncurses_create;
    context->super.destroy       = &context_termncurses_destroy;
    context->super.erase         = &context_termncurses_erase;
    context->super.setchar       = &context_termncurses_setchar;
    context->super.refresh       = &context_termncurses_refresh;
    context->super.getch_block   = &context_termncurses_getch_block;
    context->super.getch_noblock = &context_termncurses_getch_noblock;
    context->super.free                 = &context_termncurses_free;

    initscr();
    cbreak();
    noecho();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);

    return context;
}

void* context_termncurses_create(struct context* _self, int x, int y, int width, int height) {
    WINDOW* window = newwin(height, width, y, x);
    intrflush(window, FALSE);
    keypad(window, TRUE);
    return window;
}

void context_termncurses_destroy(struct context* _self, void* window) {
    delwin(window);
}

void context_termncurses_erase(struct context* _self, void* window) {
    werase(window);
}

void context_termncurses_setchar(struct context* _self, void* window, int x, int y, char ch) {
    mvwaddch(window, y, x, ch);
}

void context_termncurses_refresh(struct context* _self, void* window) {
    wrefresh(window);
}

int context_termncurses_getch_block(struct context* _self, void* window) {
    wtimeout(window, -1);
    return wgetch(window);
}

int context_termncurses_getch_noblock(struct context* _self, void* window) {
    wtimeout(window, 0);
    return wgetch(window);
}

void context_termncurses_free(struct context* _self) {
    endwin();
    free(_self);
}
