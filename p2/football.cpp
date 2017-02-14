#include "football.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <SDL_image.h>
#include <vector>
#include <SDL.h>

inline float clamp(const float val, const float lo, const float hi){
  return val <= lo ? lo : ( val >= hi ? hi : val);
}

void Football::updateFootball(Clock &gameClock, bool makeVideo, FrameGenerator &frameGen, std::pair<int, int> windowSize){

  int WIDTH = windowSize.first;
  int HEIGHT = windowSize.second;
  if(!gameClock.updateClock()) return;

  if(makeVideo) frameGen.makeFrame();
  unsigned int DT = gameClock.getDT();

  float dx = X_VEL * DT * 0.001;

  fakeXPos+= dx;

  if(fakeXPos < 550){
    float dy = sqrt(((350*350)-((fakeXPos-350)*(fakeXPos-350)));
    yPos = dy;
    yPos = HEIGHT - yPos;
  }
  xPos = clamp(xPos,0.f,WIDTH-dstrect.w);
  yPos = clamp(yPos,0.f,HEIGHT-dstrect.h);

  dstrect.y = yPos;
}

Football::Football(std::vector<std::string> &fNs, SDL_Renderer *rend, float startX, float startY): startingX(startX)
    , startingY(startY), xPos(startX), yPos(startY), fakeXPos(startX){
      fbTexture = getTexture(rend, fNs.front());
      dstrect.x = startingX;
      dstrect.y = startingY;
      dstrect.h = 32;
      dstrect.w = 32; 
}

SDL_Texture* Football::getTexture(SDL_Renderer* rend, const std::string& filename) {
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
