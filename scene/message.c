#include "message.h"

#include <stdlib.h>
#include <string.h>

#define self ((struct scene_message*)_self)

struct scene_message *scene_message_new(struct scene* base, struct context* context, char* message) {
    struct scene_message *scene = malloc(sizeof(struct scene_message));

    scene->super.handle_input = &scene_message_handle_input;
    scene->super.update       = &scene_message_update;
    scene->super.render       = &scene_message_render;
    scene->super.free         = &scene_message_free;

    scene->context = context;

    scene->window = scene->context->create(scene->context, 0, 0, strlen(message) + 4, 3);
    scene->base = base;
    scene->message = message;
    scene->message_len = strlen(message);
    scene->has_close = 0;

    return scene;
}

void scene_message_handle_input(struct scene* _self) {
    int key = self->context->getch_block(self->context, self->window);
    switch (key) {
        case '\n':
            self->has_close = 1;
            break;
    }
}

struct scene* scene_message_update(struct scene* _self) {
    if (self->has_close) {
        struct scene* base = self->base;
        _self->free(_self);
        return base;
    }

    return _self;
}

void scene_message_render(struct scene* _self) {
    self->context->erase(self->context, self->window);

    for (int i = 0; i < self->message_len+4; i++) {
        self->context->setchar(self->context, self->window, i, 0, '-');
        self->context->setchar(self->context, self->window, i, 2, '-');
    }
    self->context->setchar(self->context, self->window, 0, 0, '+');
    self->context->setchar(self->context, self->window, 0, 2, '+');
    self->context->setchar(self->context, self->window, 0, 1, '|');
    self->context->setchar(self->context, self->window, self->message_len-1+4, 1, '|');
    self->context->setchar(self->context, self->window, self->message_len-1+4, 0, '+');
    self->context->setchar(self->context, self->window, self->message_len-1+4, 2, '+');

    self->context->print(self->context, self->window, 2, 1, self->message);

    self->context->refresh(self->context, self->window);
}

void scene_message_free(struct scene* _self) {
    self->context->destroy(self->context, self->window);
    free(_self);
}
