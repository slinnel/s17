//Banner.cpp
#include "banner.h"
#include <SDL.h>
#include <SDL_image.h>

inline float clamp(const float val, const float lo, const float hi){
  return val <= lo ? lo : ( val >= hi ? hi : val);
}
//default constructor
Banner::Banner(SDL_Renderer* rend, const std::string& filename, 
	float x, float y, int vel): xPos(x), xVel(vel){
  getTexture(rend, filename);
  bannerRect.x = x;
  bannerRect.y = y;
  bannerRect.h = 100;
  bannerRect.w = 400;
}
//Destroys and creates the new texture of the banner
void Banner::getTexture(SDL_Renderer* rend, const std::string& filename) {
  SDL_DestroyTexture(bannerTexture);
  try {
    bannerTexture = IMG_LoadTexture(rend, filename.c_str());
    if ( bannerTexture == NULL ) {
      throw std::string("Couldn't load ") + filename;
    }
  }
  catch( const std::string& msg ) { 
    std::cout << msg << std::endl; 
    std::terminate();
  }
}
//Updates the bannerRect moving across the screen
void Banner::updateBanner(Clock &gameClock){
  unsigned int DT = gameClock.getDT();
  float dx = xVel * DT * 0.001;
  xPos -= dx; //move the banner linear across the screen
  bannerRect.x = xPos;
}
