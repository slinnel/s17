//Referee.cpp
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "referee.h"
#include <SDL_image.h>

Referee::Referee(SDL_Renderer* rend, const std::string& filename, float x, float y){
  getTexture(rend, filename);
  refRect.x = x;
  refRect.y = y;
  refRect.h = 90;
  refRect.w = 90;
}

void Referee::getTexture(SDL_Renderer* rend, const std::string& filename) {
  try {
    refTexture = IMG_LoadTexture(rend, filename.c_str());
    if ( refTexture == NULL ) {
      throw std::string("Couldn't load ") + filename;
    }
  }
  catch( const std::string& msg ) { 
    std::cout << msg << std::endl; 
    std::terminate();
  }
}
