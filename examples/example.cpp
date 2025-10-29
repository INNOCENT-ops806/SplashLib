#include "Splash.h"//:NOTE: The Splashlib header file
#include <iostream>
#include <raylib.h>//:NOTE: This must be included because the library uses it

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900
#define FPS 60
#define BACKGROUND_COLOR Color{81, 180, 143}

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Splashlib Usage Example");
  SetTargetFPS(FPS);

  bool inSplashState = true;//:NOTE: It is a better practice to use a variable for state checking
  std::cout << "Starting Splashlib demo" << std::endl;

  Splash *splash = new Splash();
  while (!WindowShouldClose()) {

    if (inSplashState) {
      if (splash->isComplete()) {//:HACK: Check if the Splash is done
        delete splash;
        splash = nullptr;
        inSplashState = false;
      }
    }
    BeginDrawing();
    ClearBackground(BACKGROUND_COLOR);

    if (inSplashState) {
      splash->draw();
    } else {
      DrawText("Welcome to the Game!", 200, 200, 30, RAYWHITE);
      DrawText("Press ESC to close.", 300, 300, 20, RAYWHITE);
    }
    EndDrawing();
  }

  //:NOTE: Final cleanup
  if (splash != nullptr) {
    delete splash;
  }
  CloseWindow();
  return 0;
}
