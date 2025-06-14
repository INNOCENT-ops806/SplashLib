
#include "../include/Splash.h"
#include <raylib.h>

Splash::Splash() {
  scarfy = LoadTexture("scarfy.png");
  int w = GetScreenWidth();
  int h = GetScreenHeight();
  int PADDING = w / 10;
  int base = (w / 2 - w / 2) + PADDING;
  position = {base * 1.0f, (h / 2.0f) - h / 20.0f};
  frameRec = {0.0f, 0.0f, (float)scarfy.width / 6, (float)scarfy.height};
}

Splash::~Splash() {
  if (IsTextureValid(scarfy)) {
    UnloadTexture(scarfy);
  }
}

bool Splash::isComplete() { return done; }

void Splash::draw() {
  framesCounter++;

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    if (currentFrame > 5)
      currentFrame = 0;

    frameRec.x = (float)currentFrame * (float)scarfy.width / 6;
  }

  const int MAX_FRAME_SPEED = 15;
  const int MIN_FRAME_SPEED = 1;

  if (framesSpeed > MAX_FRAME_SPEED)
    framesSpeed = MAX_FRAME_SPEED;
  else if (framesSpeed < MIN_FRAME_SPEED)
    framesSpeed = MIN_FRAME_SPEED;

  int w = GetScreenWidth();
  int h = GetScreenHeight();
  int PADDING = w / 10;
  int base = (w / 2 - w / 2) + PADDING;

  if (position.x < 170 * 6.5) {
    position.x++;
    DrawText("Grass Games", base, h / 2 + h / 4, 170, MAGENTA);
    DrawTextureRec(scarfy, frameRec, position,
                   WHITE); // Draw part of the texture
    DrawRectangle(base, (h / 2) * 2 + h / 8,
                  xPerc < 170 * 6.5 ? xPerc++ : xPerc, 20, RED);
  } else {
    DrawText("Game Loaded", base, h / 2 + h / 4, 170, MAGENTA);
    done = !done;
  }
}
