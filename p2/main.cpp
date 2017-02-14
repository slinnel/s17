#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "background.h"
#include "clock.h"
// #include "Football.h"
// #include "Referee.h"
#include "frameGenerator.h"
const int X_POS = 350;
const int Y_POS = 390;
const float X_VEL = 150.0;
// Approximately 60 frames per second: 60/1000
const unsigned int DT = 17u; // ***

SDL_Texture* getTexture(SDL_Renderer* rend, const std::string& filename) {
  try {
    SDL_Texture *texture = IMG_LoadTexture(rend, filename.c_str());
    if ( texture == NULL ) {
      throw std::string("Couldn't load ") + filename;
    }
    return texture;
  }
  catch( const std::string& msg ) { 
    std::cout << msg << std::endl; 
    std::terminate();
  }
}

void draw(SDL_Renderer* rend, SDL_Texture* back, SDL_Texture* star,
          const SDL_Rect& dstrect) {
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, back, NULL, NULL);
  SDL_RenderCopy(rend, star, NULL, &dstrect);
  SDL_RenderPresent(rend);
}

inline float clamp(const float val, const float lo, const float hi){
  return val <= lo ? lo : ( val >= hi ? hi : val);
}

void update(SDL_Rect& dstrect, FrameGenerator& frameGen, bool makeVideo, float &fakeX, Clock& gameClock) {
  static float x = X_POS;
  static float y = Y_POS;

  if(!gameClock.updateClock()) return;

  // Generate a frame:
  if ( makeVideo ) frameGen.makeFrame();

  float dx = X_VEL * DT * 0.001;
  fakeX += dx;
  if(fakeX < 550){
    float dy = sqrt((350*350)-((fakeX-350)*(fakeX-350)));
    y = dy;
    y = HEIGHT - y;
  }
  x = clamp(x,0.f,WIDTH-dstrect.w);
  y = clamp(y,0.f,HEIGHT-dstrect.h);
  
  dstrect.y = y;
}

int main( ) {
  int posX = 100, posY = 100;
  float fakeX = 0;
  SDL_Init(SDL_INIT_VIDEO);
  Clock gameClock;

  SDL_Window *window = 
    SDL_CreateWindow("Field Goal Animation", posX, posY, WIDTH, HEIGHT, 0);

  SDL_Renderer *renderer = 
    SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  Background bg(renderer, "images/bkgrnd.png");

  SDL_Texture *football = getTexture(renderer, "images/college_football.png");

  SDL_Event event;
  const Uint8* keystate;
  int nKeys=-1;
  SDL_Rect dstrect = {X_POS, Y_POS, 32, 32};
  bool makeVideo = false;
  bool done = false;
  FrameGenerator frameGen(renderer, window);
  int counter = 0;
  while ( !done ) {
    while ( SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = true;
      }
      keystate = SDL_GetKeyboardState(&nKeys);
      if (keystate[SDL_SCANCODE_ESCAPE]) { 
        done = true; 
      }
      if (keystate[SDL_SCANCODE_F4]) { 
        makeVideo = true;
      }
    }
    if(counter % 30 < 10)
      football = IMG_LoadTexture(renderer, "images/college_football.png");
    else if(counter % 30 < 20)
      football = IMG_LoadTexture(renderer, "images/college_football2.png");
    else 
      football = IMG_LoadTexture(renderer, "images/college_football3.png");
    counter++;
    draw(renderer, bg.getBG(), football, dstrect);
    update(dstrect, frameGen, makeVideo, fakeX, gameClock);
  }

  SDL_DestroyTexture(football);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
