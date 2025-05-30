#include "game.h"


const int screen_width = 800;
const int screen_height = 450;
const char* window_title = "RaylibTemplate - Sprite button";

GameState* current_game_state = &example_button;

void TransitionGameState(GameState* value){
    if (current_game_state != NULL && current_game_state->exit != NULL){
        current_game_state->exit();
    }
    current_game_state = value;
    if (current_game_state != NULL && current_game_state->enter != NULL){
        current_game_state->enter();
    }
}