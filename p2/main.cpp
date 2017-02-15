//Stephen Linnell
// Main.cpp
// Project 2

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "background.h"
#include "football.h"
#include "referee.h"
#include "frameGenerator.h"
#include "banner.h"
const int X_POS = 350;
const int Y_POS = 0;
const float X_VEL = 200.0;
//draws the objects on the renderer
void draw(SDL_Renderer* rend, SDL_Texture* back, Football &fb,
          const SDL_Rect& fbRect, SDL_Texture* ref, const SDL_Rect& refRect,
           SDL_Texture* ref2, const SDL_Rect& ref2Rect,
           SDL_Texture* ban, const SDL_Rect& banRect) {
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, back, NULL, NULL);
  SDL_RenderCopy(rend, fb.getFB(), NULL, &fbRect);
  if(!fb.isMoving()){
    SDL_RenderCopy(rend, ref, NULL, &refRect);
    SDL_RenderCopy(rend, ref2, NULL, &ref2Rect);
    SDL_RenderCopy(rend, ban, NULL, &banRect);

  }
  SDL_RenderPresent(rend);
}

inline float clamp(const float val, const float lo, const float hi){
  return val <= lo ? lo : ( val >= hi ? hi : val);
}

int main( ) {
  int posX = 100, posY = 100;
  SDL_Init(SDL_INIT_VIDEO);

  Clock gameClock;  //start the game clock
  std::pair<int, int> windowSize(WIDTH, HEIGHT); //window size

  std::vector<std::string> fbFileNames; //football name vector
  fbFileNames.push_back("images/college_football.png");
  fbFileNames.push_back("images/college_football2.png");
  fbFileNames.push_back("images/college_football3.png");

  SDL_Window *window = 
    SDL_CreateWindow("Field Goal Animation", posX, posY, WIDTH, HEIGHT, 0);

  SDL_Renderer *renderer = 
    SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  //create the sprites
  Background bg(renderer, "images/bkgrnd.png");
  Football fb(fbFileNames, renderer, X_POS, Y_POS, X_VEL);
  Referee ref(renderer,"images/ref.png", 230, 175);
  Referee ref2(renderer,"images/refFlip.png", 380, 175);
  Banner ban(renderer, "images/itsgood.png", 700, 280, 800);
  
  SDL_Event event;
  const Uint8* keystate;
  int nKeys=-1;
  bool makeVideo = true;
  bool done = false;
  FrameGenerator frameGen(renderer, window);
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
    if ( makeVideo ) frameGen.makeFrame();

    draw(renderer, bg.getBG(), fb, fb.getRect(), ref.getRef(),
       ref.getRect(), ref2.getRef(), ref2.getRect(), ban.getBan(), ban.getRect());
    if(gameClock.updateClock()){
      fb.updateFootball(renderer, gameClock, windowSize);
      if(!fb.isMoving())
        ban.updateBanner(gameClock);
    }
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
