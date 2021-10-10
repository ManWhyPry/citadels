#ifndef CITADELS_CONTEXT_H_
#define CITADELS_CONTEXT_H_

struct context {
    void* (*create)        (struct context* self, int x, int y, int width, int height);
    void  (*destroy)       (struct context* self, void* window);
    void  (*erase)         (struct context* self, void* window);
    void  (*setchar)       (struct context* self, void* window, int x, int y, char ch);
    void  (*print)         (struct context* self, void* window, int x, int y, char* str);
    void  (*refresh)       (struct context* self, void* window);
    int   (*getch_block)   (struct context* self, void* window);
    int   (*getch_noblock) (struct context* self, void* window);
    void  (*free)          (struct context* self);
};

#endif//CITADELS_CONTEXT_H_
