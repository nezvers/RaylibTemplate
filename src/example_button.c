#include "game.h"
#include "raylib.h"

#define NUM_FRAMES  3       // Number of frames (rectangles) for the button sprite texture
Sound fxButton;
Texture2D button;
// Define frame rectangle for drawing
float frameHeight;
Rectangle sourceRec;
// Define button bounds on screen
Rectangle btnBounds;


static void Enter(){
    InitAudioDevice();      // Initialize audio device

    fxButton = LoadSound(RESOURCES_PATH"buttonfx.wav");   // Load button sound
    button = LoadTexture(RESOURCES_PATH"button.png"); // Load button texture
    frameHeight = (float)button.height/NUM_FRAMES;
    sourceRec = (Rectangle){ 0, 0, (float)button.width, frameHeight };
    btnBounds = (Rectangle){ screen_width/2.0f - button.width/2.0f, screen_height/2.0f - button.height/NUM_FRAMES/2.0f, (float)button.width, frameHeight };
}

static void Update(){
    static int btnState = 0; // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
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

    sourceRec.y = btnState*frameHeight;

    BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE); // Draw button frame

    EndDrawing();
}

static void Exit(){
    UnloadTexture(button);
    UnloadSound(fxButton);
    CloseAudioDevice();
}

GameState example_button = {Enter, Update, Exit};