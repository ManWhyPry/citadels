#ifndef CITADELS_SCENE_MAINMENU_H_
#define CITADELS_SCENE_MAINMENU_H_

#include "../scene.h"

struct scene_mainmenu {
    struct scene    super;
    struct context* context;
    void*           window;
    int             selected;
};

struct scene_mainmenu* scene_mainmenu_new          (struct context* context);
void                   scene_mainmenu_handle_input (struct scene* self);
struct scene*          scene_mainmenu_update       (struct scene* self);
void                   scene_mainmenu_render       (struct scene* self);
void                   scene_mainmenu_free         (struct scene* self);

#endif//CITADELS_SCENE_MAINMENU_H_
