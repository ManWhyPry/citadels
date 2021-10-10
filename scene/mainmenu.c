#include "mainmenu.h"

#include "message.h"
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
    scene->selected = 0;

    return scene;
}

void scene_mainmenu_handle_input(struct scene* _self) {
    int key = self->context->getch_block(self->context, self->window);
    switch (key) {
        case '1':
            self->selected = 1;
            break;
        case '2':
            self->selected = 2;
            break;
        case '3':
            self->selected = 3;
            break;
    }
}

struct scene* scene_mainmenu_update(struct scene* _self) {
    switch (self->selected) {
        case 1:
            self->selected = 0;
            return (struct scene*)scene_message_new(_self, self->context, "Not implemented");
        case 2:
            self->selected = 0;
            return (struct scene*)scene_message_new(_self, self->context, "Not implemented");
        case 3:
        _self->free(_self);
            return NULL;
    }
    return _self;
}

void scene_mainmenu_render(struct scene* _self) {
    self->context->erase(self->context, self->window);
    self->context->print(self->context, self->window, 0, 0, "CITADELS - Roguelike RPG");
    self->context->print(self->context, self->window, 0, 1, "1) New Game");
    self->context->print(self->context, self->window, 0, 2, "2) About");
    self->context->print(self->context, self->window, 0, 3, "3) Quit");
    self->context->refresh(self->context, self->window);
}

void scene_mainmenu_free(struct scene* _self) {
    self->context->destroy(self->context, self->window);
    free(_self);
}
