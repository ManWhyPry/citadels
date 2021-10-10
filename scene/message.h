#ifndef CITADELS_SCENE_MESSAGE_H_
#define CITADELS_SCENE_MESSAGE_H_

#include "../scene.h"

struct scene_message {
    struct scene    super;
    struct context* context;
    void*           window;
    struct scene*   base;
    char*           message;
    int             message_len;
    int             has_close;
};

struct scene_message*  scene_message_new          (struct scene* base, struct context* context, char* message);
void                   scene_message_handle_input (struct scene* self);
struct scene*          scene_message_update       (struct scene* self);
void                   scene_message_render       (struct scene* self);
void                   scene_message_free         (struct scene* self);

#endif//CITADELS_SCENE_MESSAGE_H_
