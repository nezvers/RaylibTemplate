#ifndef GAME_H
#define GAME_H

#include "stddef.h"

typedef struct{
    void (*enter)();
    void (*update)();
    void (*exit)();
} GameState;

extern const char* window_title;
extern const int screen_width;
extern const int screen_height;

extern GameState* current_game_state;
extern GameState example_button;

void TransitionGameState(GameState* value);

#endif // GAME_H