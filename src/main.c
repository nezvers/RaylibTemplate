/*******************************************************************************************
*
*   raylib [textures] example - sprite button
*
*   Example complexity rating: [★★☆☆] 2/4
*
*   Example originally created with raylib 2.5, last time updated with raylib 2.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "raylib.h"


#define NUM_FRAMES  3       // Number of frames (rectangles) for the button sprite texture


Sound fxButton;
Texture2D button;
// Define frame rectangle for drawing
float frameHeight;
Rectangle sourceRec;
const int screenWidth = 800;
const int screenHeight = 450;
// Define button bounds on screen
Rectangle btnBounds;

int btnState = 0; // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void UpdateFrame();

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "RaylibTemplate - Sprite button");

    InitAudioDevice();      // Initialize audio device

    fxButton = LoadSound(RESOURCES_PATH"buttonfx.wav");   // Load button sound
    button = LoadTexture(RESOURCES_PATH"button.png"); // Load button texture
    frameHeight = (float)button.height/NUM_FRAMES;
    sourceRec = (Rectangle){ 0, 0, (float)button.width, frameHeight };
    btnBounds = (Rectangle){ screenWidth/2.0f - button.width/2.0f, screenHeight/2.0f - button.height/NUM_FRAMES/2.0f, (float)button.width, frameHeight };

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(UpdateFrame, 0, 1);
    #else
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()){    // Detect window close button or ESC key
        UpdateFrame();
    }
    #endif
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(button);  // Unload button texture
    UnloadSound(fxButton);  // Unload sound

    CloseAudioDevice();     // Close audio device

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void UpdateFrame(){
    // Update
    //----------------------------------------------------------------------------------
    Vector2 mousePoint = GetMousePosition();
    bool btnAction = false;

    // Check button state
    if (CheckCollisionPointRec(mousePoint, btnBounds))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
        else btnState = 1;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
    }
    else btnState = 0;

    if (btnAction)
    {
        PlaySound(fxButton);

        // TODO: Any desired action
    }

    // Calculate button frame rectangle to draw depending on button state
    sourceRec.y = btnState*frameHeight;
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE); // Draw button frame

    EndDrawing();
    //----------------------------------------------------------------------------------
}