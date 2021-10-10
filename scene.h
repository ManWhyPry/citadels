#ifndef CIDADELS_SCENE_H_
#define CIDADELS_SCENE_H_

#include "context.h"

struct scene {
    void          (*handle_input) (struct scene* self);
    struct scene* (*update)       (struct scene* self);
    void          (*render)       (struct scene* self);
    void          (*free)         (struct scene* self);
};

#endif//CIDADELS_SCENE_H_
