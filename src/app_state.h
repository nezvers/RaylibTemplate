#ifndef GAME_H
#define GAME_H

#include "stddef.h"
#include "stdbool.h"

typedef struct{
    void (*enter)();
    void (*update)();
    void (*exit)();
    bool (*stop_app)();
} AppState;

extern const char* window_title;
extern const int screen_width;
extern const int screen_height;

extern AppState* current_app_state;
extern AppState example_button;

void TransitionGameState(AppState* value);

#endif // GAME_H