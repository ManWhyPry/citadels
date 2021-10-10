#include "scene.h"
#include "context.h"
#include "scene/mainmenu.h"
#include "context/termncurses.h"

int main(void) {
    struct context* context = (struct context*)context_termncurses_new();
    struct scene*   scene   = (struct scene*)scene_mainmenu_new(context);

    while (scene)
    {
        scene->render(scene);
        scene->handle_input(scene);
        scene = scene->update(scene);
    }
    
    context->free(context);
    return 0;
}
