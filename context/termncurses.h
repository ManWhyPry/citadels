#ifndef CITADELS_CONTEXT_TERMNCURSES_H_
#define CITADELS_CONTEXT_TERMNCURSES_H_

#include "../context.h"

struct context_termncurses {
    struct context super;
};

struct context_termncurses* context_termncurses_new           (void);
void*                       context_termncurses_create        (struct context* self, int x, int y, int width, int height);
void                        context_termncurses_destroy       (struct context* self, void* window);
void                        context_termncurses_erase         (struct context* self, void* window);
void                        context_termncurses_setchar       (struct context* self, void* window, int x, int y, char ch);
void                        context_termncurses_refresh       (struct context* self, void* window);
int                         context_termncurses_getch_block   (struct context* self, void* window);
int                         context_termncurses_getch_noblock (struct context* self, void* window);
void                        context_termncurses_free          (struct context* self);

#endif//CITADELS_CONTEXT_TERMNCURSES_H_
