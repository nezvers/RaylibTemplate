#include "app_state.h"

#ifdef PLATFORM_WEB
    #include <emscripten/emscripten.h>
#endif

void MainInit(){
    current_app_state->enter();
}

void MainUpdate(){
    if (current_app_state->update != NULL){
        current_app_state->update();
    }
}

void MainClose(){
    if (current_app_state->exit != NULL){
        current_app_state->exit();
    }
}

int main(void){
    MainInit();
    
#ifdef PLATFORM_WEB
    emscripten_set_main_loop(UpdateFrame, 0, 1);
#else
    // Main game loop
    while (!current_app_state->stop_app()){    // Detect window close button or ESC key
        MainUpdate();
    }
#endif

    MainClose();
    return 0;
}


