#include "mainmenu.h"

#include <stdlib.h>

#define self ((struct scene_mainmenu*)_self)

struct scene_mainmenu *scene_mainmenu_new(struct context* context) {
    struct scene_mainmenu *scene = malloc(sizeof(struct scene_mainmenu));

    scene->super.handle_input = &scene_mainmenu_handle_input;
    scene->super.update       = &scene_mainmenu_update;
    scene->super.render       = &scene_mainmenu_render;
    scene->super.free         = &scene_mainmenu_free;

    scene->context = context;

    scene->window = scene->context->create(scene->context, 0, 0, 80, 60);

    return scene;
}

void scene_mainmenu_handle_input(struct scene* _self) {
    self->context->getch_block(self->context, self->window);
}

struct scene* scene_mainmenu_update(struct scene* _self) {
    _self->free(_self);
    return NULL;
}

void scene_mainmenu_render(struct scene* _self) {
    self->context->erase(self->context, self->window);
    self->context->print(self->context, self->window, 0, 0, "Hello, World");
    self->context->refresh(self->context, self->window);
}

void scene_mainmenu_free(struct scene* _self) {
    self->context->destroy(self->context, self->window);
    self->context->free(self->context);
    free(_self);
}
