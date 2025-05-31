#include "app_state.h"

const int screen_width = 800;
const int screen_height = 450;
const char* window_title = "RaylibTemplate - Sprite button";

AppState* current_app_state = &example_button;

void TransitionGameState(AppState* value){
    if (current_app_state != NULL && current_app_state->exit != NULL){
        current_app_state->exit();
    }
    current_app_state = value;
    if (current_app_state != NULL && current_app_state->enter != NULL){
        current_app_state->enter();
    }
}