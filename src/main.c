#include "raylib.h"
#include "game.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void MainInit(){
    InitWindow(screen_width, screen_height, window_title);
    current_game_state->enter();
}

void MainUpdate(){
    if (current_game_state->update != NULL){
        current_game_state->update();
    }
}

void MainClose(){
    if (current_game_state->exit != NULL){
        current_game_state->exit();
    }
    CloseWindow();
}

int main(void){
    MainInit();
    
    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(UpdateFrame, 0, 1);
    #else
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()){    // Detect window close button or ESC key
        MainUpdate();
    }
    #endif

    MainClose();
    return 0;
}


